#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../Headers/bitmap_image.hpp"

using namespace std;


void solve(int c,int width,int height){

	int j;
	string openfilenamei;

	for (int j = 0; j < c; ++j)
	{
		string Resultti;
        stringstream convertti;
        convertti << j;
        Resultti = convertti.str();

        openfilenamei = Resultti +".bmp";


	FILE *streamIn;

    streamIn = fopen(openfilenamei.c_str(), "r");


    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, streamIn);

    unsigned int width1 = *(int*)&info[18];
    unsigned int height1 = *(int*)&info[22];

    unsigned char image11[width1*height1][3];
    unsigned int i = 0;
    FILE *fw;
    openfilenamei = "./"+ Resultti +".txt";
    /*if(j == c-1){
    fw = fopen(openfilenamei.c_str(),"w");}*/

    for(i=0;i<width1*height1;i++) {

        image11[i][2] = (getc(streamIn) + image11[i][2])%251;
        image11[i][1] = (getc(streamIn) + image11[i][1])%251;
        image11[i][0] = (getc(streamIn) + image11[i][0])%251;
    }

    if(j == c-1){bitmap_image image(width,height);
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
               image.save_image("new.bmp");}
    //satirsayisi(openfilenamei);
    fclose(streamIn);
}

}

int main()
{
	int image,width,height;
	cout<<"Kac Adet Resmi Birlestirmek Istiyorsunuz"<<endl;
	cin>>image;
	cout<<"Elinizdeki goruntunun genisligini girin"<<endl;
	cin>>width;
	cout<<"Elinizdeki goruntunun yuksekligini girin"<<endl;
	cin>>height;
	solve(image,width,height);

	return 0;
}
