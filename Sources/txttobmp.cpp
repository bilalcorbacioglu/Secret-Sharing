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
int next;

void satirsayisi(){
    ifstream openFile("pikseller.txt");
    string line;

    while (getline(openFile, line)) {
    if (line.empty()) continue;

    istringstream iss(line);

    next = 1+next;

  }
}

int main () {
    FILE *streamIn;
    satirsayisi();
    streamIn = fopen("./pikseller.txt", "r");
    if (streamIn == (FILE *)0) {
        printf("File opening error ocurred. Exiting program.\n");
        return 0;
    }

    unsigned char image11[next][3];
    int r, g, b, i;
    for (i=0; fscanf (streamIn, "%d %d %d", &r, &g, &b) == 3; ++i) {
        image11[i][0] = r;
        image11[i][1] = g;
        image11[i][2] = b;
        printf("pixel %d : [%d,%d,%d]\n",i+1,image11[i][0],image11[i][1],image11[i][2]);
    }

fclose(streamIn);


    bitmap_image image(1000,616);
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
               image.save_image("new.bmp");


    return 0;
}
