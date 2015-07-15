#include "secret.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void secret::sayigir(){

	cout<<"Sifrelenicek Sayinizi Giriniz"<<endl;
	cin>>girdi;
    girdiuzn = girdi.size();

	cout<<"TEST "<< girdi <<"  uzunluk :   "<< girdiuzn<<endl;
	}

void secret::semagir(){

	cout << endl << "Semayı girin (kullanicilar,dagitilacaklar)" << endl << " Kullanicilar:\t";
	cin >> semax;
	cout << endl << "Dagitacilaklar:\t";
	cin >> semay;
	cout << endl;
    cout<<"Test  "<<"("<<semax<<","<<semay<<")"<<endl<<endl;

}



void secret::fonksyonata(){
    i = 0;
    random = new int[semay-1];
    cout<<"F(x)="<<girdi;
    for(i=0;i<semay-1;i++){
        random[i] = rand() % 100;
        cout<<"+"<<random[i]<<"x^"<<i+1;
    }

    cout<<endl;
}

int secret::usal(int sayi,int ussu){
    sonuc = 1;
    for(int i=1;i<=ussu;i++){
            sonuc=sonuc*sayi;}
        return sonuc;
}

void secret::paydahesapla(){
    i = 0,toplam = 0;
    value = atoi(girdi.c_str());
    d = new int[semax-1];
    for(i=0;i<semax;i++){
            toplam = 0;
            for(j=0;j<semay-1;j++){
                toplam = toplam+random[j]*usal(i+1,j+1);
            }
        d[i] = toplam+value;
        cout<<"D"<<i+1<<"=("<<i+1<<","<<d[i]<<")"<<endl;
    }
}

void secret::paydasec(){
    cout<<endl<<"secilen paydalar : "<<endl;

    secilenler = new int [semay];


        for(i =0;i<semay;i++){
        rastgele = rand() %semax+1;
            if(i>0){
            for(j=0;j<i;j++){

                if(secilenler[j]==rastgele) {j = -1; rastgele = rand() %semax+1;}
            }
            secilenler[i]=rastgele;
            }
            else secilenler[i] = rastgele;
        //if(secilenler[i-1] != rastgele)
        //secilenler[i]=rastgele;

        cout<<"D"<<secilenler[i]<<endl;

        }
    }

void secret::fonksyonbul(){
        for(i=0;i<semay;i++){
        cout<<i+1<<".Kullanicinin alicagi denklem"<<endl;
        //cout<<d[i]<<" * ";
            for(j=0;j<semay;j++){
                if(secilenler[i]!=secilenler[j]){
                    cout<<"(x-"<<secilenler[j]<<")/("<<secilenler[i]-secilenler[j]<<") *";
                }
            }
        cout<<"********************"<<endl<<endl;

        }
}
