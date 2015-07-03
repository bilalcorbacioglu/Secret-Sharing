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
#include "bitmap_image.hpp"

using namespace std;

int main () {
    FILE *streamIn;
    string openfilenamei;
    cout << "Resminizin adini girin (.bmp girmeyin) (Program ile ayni klasorde bulunmasina dikkat edin )"<<endl;
    cin >> openfilenamei;
    openfilenamei = openfilenamei +".bmp";
    streamIn = fopen(openfilenamei.c_str(), "r");
    if (streamIn == (FILE *)0) {
        printf("File opening error ocurred. Exiting program.\n");
        return 0;
    }

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, streamIn);

    unsigned int width1 = *(int*)&info[18];
    unsigned int height1 = *(int*)&info[22];

    unsigned char image11[width1*height1][3];
    unsigned int i = 0;
    FILE *fw;
    fw = fopen("pikseller.txt","w");

    for(i=0;i<width1*height1;i++) {
        image11[i][2] = getc(streamIn);
        image11[i][1] = getc(streamIn);
        image11[i][0] = getc(streamIn);
        printf("pixel %d : [%d,%d,%d]\n",i+1,image11[i][0],image11[i][1],image11[i][2]);
        fprintf(fw,"%d %d %d\n",image11[i][0],image11[i][1],image11[i][2]);

    }

    fclose(streamIn);
    return 0;
}
