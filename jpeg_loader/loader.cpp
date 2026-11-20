#include "CImg.h"
#include <iostream>
#include <cstdint>
#include <fstream>
using namespace std;
using namespace cimg_library;

#define RED 0
#define GREEN 1
#define BLUE 2

typedef unsigned char uChar;
typedef unsigned int uInt;

struct pixelInfo{
    uChar r, g, b;
    pixelInfo(uChar _r, uChar _g, uChar _b) : r(_r), g(_g), b(_b) {}
    uChar to_gray_scale(int method = 2){
        if(method < 0 and method > 2){
            cerr << "unexpected method index\n";
            exit(1);
        }
        if(method == 0){
            // Average
            return r / 3 + b / 3 + g / 3 + (r % 3 + b % 3 + g % 3) / 3;
        } else if(method == 1){
            // Channel dependant luminance perception
            return (uChar) (0.2126 * (float) r) + uChar (0.7152 * (float) g) + uChar (0.0722 * (float) b);
        } else if(method == 2){
            // Linear approximation of gamma and perceptual luminance corrected
            return (uChar) (0.299 * (float) r) + uChar (0.587 * (float) g) + uChar (0.114 * (float) b);
        }
        return 0;
    }
};

void usage(){
    cerr << "Usage:\n \
    <loader> img.jpg\n";
}

int main(int argc, char* argv[]){

    if(argc != 2){
        usage();
        exit(1);
    }

    char* img_file = argv[1];

    CImg<uChar> img(img_file);
    uInt width = img.width();
    uInt height = img.height();

    // string outfile = "out.txt";
    // ofstream outFileObj(outfile);

    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){

            uChar* rp = img.data(j, i, 0, RED);
            uChar r = *rp;
            
            uChar* gp = img.data(j, i, 0, GREEN);
            uChar g = *gp;
            
            uChar* bp = img.data(j, i, 0, BLUE);
            uChar b = *bp;

            pixelInfo info(r, g, b);

            cout << info.to_gray_scale() << ' ';
        }
        cout << '\n';
    }
}