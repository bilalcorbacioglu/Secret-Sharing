/*
**************************************************************************
*                                                                         
*                         Secret Image Sharing                            
*	                   Sır Paylaşımı Algoritması                          
*                                                                         
* Yazar: Bilal Çorbacıoğlu - 2015  				     					  
* 													                      
*                                                                         
* Not: Sır paylaşımı algoritması kullanılarak herhangi bir resmi 		  
* kullanıcılara paylaştıran kod bloğu. Kullanıcılara dağıtılan resimlerin 
* piksel değerleri rastgele olduğu için anlamsız resimler ortaya çıkar.	  
* C++ ta .txt leri oluşturuyorum.Txt to Bmp de başka bir dil kullandım.   
* Bir sonraki aşamada Arayüz hazırlanacak ve anlamsız resimler anlamlı    
* resimlerin içine gömülecektir.								 	      
* 												                          
* Referans gösterilmesi halinde paylaşılabilinir.						  
*                                                                         
**************************************************************************
*/


//Programda, her koşulda 251 tabanında çalıştığımıza lütfen dikkat edin !!!
#include "secret.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include "bitmap_image.hpp"
using namespace std;
int yedek;
int subline;
//Satır sayısını alıyoruz ve next toplam satır sayımızı veriyor.

void secret::satirsayisi(){
    ifstream openFile("pikseller.txt");
    string line;
    next = 0;
    while (getline(openFile, line)) {
    if (line.empty()) continue;

    istringstream iss(line);

    next = 1+next;

  }
  subline = next;

}


void secret::sayigir(){
    ifstream file("pikseller.txt");
    int p;
    satirsayisi();
    semagir();
    //Herbir R G B değerini alıyorum ve işleme sokuyorum
    for(p = 0; p < next;p++){
	getline(file, girdi);
	//cout << "Sifrelenicek Sayinizi Giriniz" << endl;
    girdiuzn = girdi.size();
	//cout<<"TEST "<< girdi <<"  uzunluk :   "<< girdiuzn<<endl;

	fonksyonata();
	paydahesapla();
	paydasec();
	fonksyonbul();
	}}


//Kullanıcıdan şemayı aldım SEMA(SEMAX,SEMAY)
void secret::semagir(){

	//cout << endl << "Semayı girin (kullanicilar,dagitilacaklar)" << endl << " Kullanicilar:\t";
	//cin >> semax;
	//cout << endl << "Dagitacilaklar:\t";
	//cin >> semay;
	semax = 6;
	semay = 3;
	yedek = semay;
	cout << endl;
    //cout<<"Test  "<<"("<<semax<<","<<semay<<")"<<endl<<endl;

}


//Sır paylaşımı alg. gereği fonksyon atamamızı yapıyoruz. Her bir piksele ayrı ayrı fonksyon ataması oluyor.
void secret::fonksyonata(){
    i = 0;
    random = new int[semay-1];
    //cout<<"F(x)="<<girdi;
    for(i=0;i<semay-1;i++){
        random[i] = rand() % 4;
        //cout<<"+"<<random[i]<<"x^"<<i+1;
    }

    //cout<<endl;
}


//Basitce us alma bloğu
int secret::usal(int sayi,int ussu){
    sonuc = 1;
    for(int i=1;i<=ussu;i++){
            sonuc=sonuc*sayi;}
        return sonuc;
}


//Kaç kişi varsa o kadar payda hesaplanıyor.Ardından payda yani hangi kişilere dağıtılacağı seçilecek.
void secret::paydahesapla(){
    i = 0,toplam = 0;
    value = atoi(girdi.c_str());
    d = new int[semax-1];
    for(i=0;i<semax;i++){
            toplam = 0;
            for(j=0;j<semay-1;j++){
                toplam = toplam+random[j]*usal(i+1,j+1) ;
            }
        d[i] = (toplam+value) % 251;	//251 e göre mod aldım çünkü çakışmaları önlemem gerekiyor.
        //cout<<"D"<<i+1<<"=("<<i+1<<","<<d[i]<<")"<<endl;
    }
}


//Aşağıda hangi kişilere dağıtılacağı seçiliyor.Rastgele yaptırıyorum.
void secret::paydasec(){
    //cout<<endl<<"secilen paydalar : "<<endl;

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

        //cout<<"D"<<secilenler[i]<<endl;

        }
    }


    //Lagrange İnterpolasyondan çıkan sonuç double ise integer'a çeviriyorum.251 tabanında çalıştığıma dikkat edin !
void secret::oylemi(double interpolasyon){
                            while(1){
                            if((interpolasyon-(int)interpolasyon) != 0){pay = pay+251; interpolasyon = (pay/payda);}
                            else {interpolasyoni = (int)interpolasyon; break;}

                        }}

//Kullanıcıların alacağı yeni piksel değerleri aşağıda hesaplanıp .txt yazılacak.
void secret::fonksyonbul(){

        int tut;
        for(i=0;i<semay;i++){

        ofstream dosya;
        payda = 1;
        pay = 1;
        //cout<<i+1<<".Kullanicinin alicagi denklem"<<endl;

            for(j=0;j<semay;j++){
                if(secilenler[i]!=secilenler[j]){
                    pay = -secilenler[j]*pay;
                    payda = (secilenler[i]-secilenler[j])*payda;
                    interpolasyon = (pay/payda);

                    //cout<<"(x-"<<secilenler[j]<<")/("<<secilenler[i]-secilenler[j]<<") *";
                    tut = secilenler[i];
                }}
        oylemi(interpolasyon);	//KONTROL çıkan değerin double olması ihtimaline karşı kontrol ettiriyorum.Double ise integer'a çeviriyorum.
        //cout<<"***********"<<payda<<"***"<<pay<<"***"<<"*"<<interpolasyoni<<"**"<<endl<<endl;
        int sonucc = ((interpolasyoni * d[tut-1]) % 251);   //Dağıtacağım piksellerim
        //Negatif aşağıda kesin
        if((sonucc < 0)){sonucc = sonucc +251;}
        else {sonucc = ((interpolasyoni * d[tut-1]) % 251);}
        //cout<<endl<<sonucc<<endl;

            string Result;
            stringstream convert;
            convert << i;
            Result = convert.str();

        //1.txt 2.txt 3.txt ...
        filename = Result + ".txt";
        //cout<<endl<<filename<<endl;

        dosya.open(filename.c_str(), ios::out | ios::binary| ios::app);
        dosya << sonucc << endl;
        }
}


void pixel::translate(){
    //ASLINDA BUNA GEREK KALMADI MIRAS ALDIGIM ICIN SATIR SAYIM BELLI

    //totaline
    ifstream openFilet("pikseller.txt");
    string linet;

    while (getline(openFilet, linet)) {
    if (linet.empty()) continue;

    istringstream iss(linet);

    nextt = 1+nextt;

  }
  rgbarray = new int[nextt];


//translate
//FILE *fwt;
//fwt = fopen("pixel.txt","w");

for(pt=0;pt<yedek;pt++){
        string Resultt;
        stringstream convertt;
        convertt << pt;
        Resultt = convertt.str();

        openfilename = Resultt+".txt";
                //Assignment
                it = 0;
                ifstream openFile1t(openfilename.c_str());
                string line1t;

                while (getline(openFile1t, line1t)) {
                if (line1t.empty()) continue;
                istringstream iss(line1t);
                valuet = atoi(line1t.c_str());
                rgbarray[it]  = valuet;

                it++;}
                //1.txt 2.txt 3.txt ...
        filenamet = Resultt + Resultt +".txt";
        //cout<<endl<<filenamet<<endl;
    ofstream txtt;
    txtt.open(filenamet.c_str(), ios::out | ios::app);
    it = 0;
    jt = 0;

        for (it = 0; it < nextt; ++it)
        {

            if(jt == 1 || jt == 0){
                txtt<<rgbarray[it] << " ";
                jt++;
            }
            else if (jt == 2){
                txtt<<rgbarray[it];
                jt++;
            }
            else if(jt == 3){
                txtt<<endl;
                jt=0;
                it = it-1;
            }
        }
}
imagetranslate();
}
void pixel::del(){
    it =0;
    for(it=0;it<yedek;it++){
        string Resulttde;
        stringstream converttde;
        converttde << it;
        Resulttde = converttde.str();

        openfilenamede = Resulttde +".txt";
        remove(openfilenamede.c_str());
        //cout<<"Remove : "<<openfilenamede<<endl;
        openfilenamede = Resulttde + Resulttde +".txt";
        remove(openfilenamede.c_str());;
        //cout<<"Remove : "<<openfilenamede<<endl;
    }
}

void pixel::imagetranslate(){
    subline =subline / 3;
    //cout<<"Subline : "<<subline<<endl; //+1 koyuyor islemleri ona gore yapmaliyiz satir sayim
    pt = 0;
    for(pt=0; pt<yedek; pt++){
        string Resultti;
        stringstream convertti;
        convertti << pt;
        Resultti = convertti.str();

        openfilenamei = "./"+ Resultti +".txt";

    FILE *imagee;

    imagee = fopen(openfilenamei.c_str(), "r");


    unsigned char image11[subline][3];

    for (i=0; fscanf (imagee, "%d %d %d", &r, &g, &b) == 3; ++i) {
        image11[i][0] = r;
        image11[i][1] = g;
        image11[i][2] = b;
        //printf("pixel %d : [%d,%d,%d]\n",i+1,image11[i][0],image11[i][1],image11[i][2]);
    }

fclose(imagee);


    bitmap_image image(512,512);   //1.si yukseklik 2.si genislik
               image_drawer draw(image);
				int k = 0;
                for (unsigned int d = 0; d < image.width(); ++d)
               {
                  for (unsigned int m = 0; m < image.height(); ++m)
                  {
                  		image.set_pixel(d,m,image11[k][0],image11[k][1],image11[k][2]);
                    k++;

                  }
               }
               openfilenamei = Resultti+".bmp";
               image.save_image(openfilenamei.c_str());



}del();
cout<<"Finish"<<endl;
}


