#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

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

    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    int image[width*height][3];
    int i = 0;
    FILE *fw;
    fw = fopen("pikseller.txt","w");
    for(i=0;i<width*height;i++) {
        image[i][2] = getc(streamIn);
        image[i][1] = getc(streamIn);
        image[i][0] = getc(streamIn);
        printf("pixel %d : [%d,%d,%d]\n",i+1,image[i][0],image[i][1],image[i][2]);
        fprintf(fw,"%d\n%d\n%d\n",image[i][0],image[i][1],image[i][2]);

    }

    fclose(streamIn);

    return 0;
}
