
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


