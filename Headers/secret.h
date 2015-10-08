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
	int next,p;
	void sayigir();
	int semax, semay;
	void semagir();
	int *random,i,j,value; //*random : "The random value function"
	void fonksyonata();
	int *partition,toplam,sayi,ussu;
	void paydahesapla();
	int *selectedpartition,rastgele;
	void paydasec();
	double payda,pay; //Interpolasyonda matematiksel olarak pay ve payda
	double interpolasyon;
	int tut;
	int interpolasyonint;
	int results;
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