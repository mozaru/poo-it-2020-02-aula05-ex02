#include<iostream>

using namespace std;

#define _MAX_ 100

class TConjunto
{
	private:
		float v[_MAX_];
		int qtd;
		int obterIndice(float n);
	public:
		void ler();
		void mostrar();
		void uniao(TConjunto a, TConjunto b);
		void intersecao(TConjunto a, TConjunto b);
		void subtracao(TConjunto a, TConjunto b);
		bool estacontido(TConjunto a);
		bool contem(TConjunto a);
		bool pertence(float n);
		void inserir(float n);
		void remover(float n);
};

int TConjunto::obterIndice(float n)
{
	bool achou=false;
	int i=0;
	while (!achou && i<qtd)
		if (v[i] == n)
			achou = true;
		else
			i++;
	return achou?i:-1;
}
bool TConjunto::pertence(float n)
{
	return obterIndice(n)!=-1;
}
void TConjunto::inserir(float n)
{
	if (!pertence(n))
	{	
		v[qtd]=n;
		qtd++;	
	}
}
void TConjunto::remover(float n)
{
	int pos = obterIndice(n);
	if (pos!=-1)
	{
		v[pos] = v[qtd-1];
		qtd--;	
	}
}

void TConjunto::ler()
{
	int n;
	cout << "entre com a quantidade de numeros a digitar:";
	cin >> n;
	qtd = 0;
	for(int i=0; i<n; i++)
	{
		float x;
		cout << "x=";
		cin >> x;
		inserir(x);		
	}
}
void TConjunto::mostrar()
{
	cout << "{ ";
	for(int i=0; i<qtd; i++)
		cout << v[i] << " ";
	cout << "}" << endl;
}
void TConjunto::uniao(TConjunto a, TConjunto b)
{
	qtd = 0;
	for(int i=0;i<a.qtd;i++)
		inserir(a.v[i]);
	for(int i=0;i<b.qtd;i++)
		inserir(b.v[i]);
}
void TConjunto::intersecao(TConjunto a, TConjunto b)
{
	qtd = 0;
	for(int i=0;i<a.qtd;i++)
		if (b.pertence(a.v[i]))
			inserir(a.v[i]);
}
void TConjunto::subtracao(TConjunto a, TConjunto b)
{
	qtd = 0;
	for(int i=0;i<a.qtd;i++)
		if (!b.pertence(a.v[i]))
			inserir(a.v[i]);
}
bool TConjunto::estacontido(TConjunto a)
{
	return a.contem(*this);	
}
bool TConjunto::contem(TConjunto a)
{
	bool ok=true;
	for(int i=0;i<a.qtd && ok;i++)
		if (!pertence(a.v[i]))
			ok = false;
	return ok;	
}

int main()
{
	TConjunto a,b,c,d,e;
	int x;
	a.ler();
	b.ler();
	c.uniao(a,b);
	c.mostrar();
	d.intersecao(a,b);
	d.mostrar();
	cout << "d esta contido em a:" << d.estacontido(a) << endl;
	cout << "a contem d:" << a.contem(d) << endl;
	cout << "d esta contido em a:" << d.estacontido(a) << endl;
	cout << "c contem a:" << c.contem(a) << endl;
	cout << "c contem b:" << c.contem(b) << endl;
	cout << "a contem b:" << a.contem(b) << endl;
	cout << "a esta contido em b:" << a.estacontido(b) << endl;
	e.subtracao(a,b);
	e.mostrar();
	do{
		cout << "entre com um valor inteiro:";
			cin >> x;
		cout << x << " pertence ao conjunto A: " << a.pertence(x) << endl;
	}while (x>0);
	return 0;
}


