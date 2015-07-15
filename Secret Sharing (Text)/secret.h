#ifndef SECRET_H
#define SECRET_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

class secret
{
	public:

	string girdi;
	int girdiuzn;
	void sayigir();
	int semax, semay;
	void semagir();
	int *random,i,j,value;
	void fonksyonata();
	int *d,toplam,sayi,ussu,sonuc;
	int usal(int,int);
	void paydahesapla();
	int *secilenler,rastgele;
	void paydasec();
    void fonksyonbul();
};

#endif
