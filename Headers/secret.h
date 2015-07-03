#ifndef SECRET_H
#define SECRET_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <typeinfo>
using namespace std;

class secret
{
	public:

	string girdi,filename;
	int girdiuzn;
	int next;
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
	double payda,pay;
	double interpolasyon;
	int interpolasyoni;
	void oylemi(double);
    void satirsayisi();
    void fonksyonbul();
    int getInt(void);

};

class pixel:public secret
	{
	public:
	    string filenamet,openfilename,openfilenamei,openfilenamede;
	    int nextt;
		int it,jt,pt;
		int r, g, b, i;
		int valuet;
		int *rgbarray;
		void translate();
		void imagetranslate();
        void del();
	};

#endif