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

// const string grad_src = ".-,`'\"_:;~^=|/\\)>(<+i!?t}l{v]sI[cx1zj\%e7roanfuJ$CT3qypY6L9*bgS2d5OXVFGkmhPwAQ48&EUDZHKR@BWN#0M";

const string grad = "...-,`'\"_:;~^=|/\\)>>>>>(<+i!?t}l{v]ssssssI[cx1zj\%e7roanfuJ$CT3qypY6L9*bgS2d5OXVFGkmmmmhPwAAAAAQ48&EEEEEUDZHKR@BWN##00000MMMMMMMM";

char mapper(uChar x){

    return grad[x / 2];

}

uChar to_gray_scale(uChar r, uChar g, uChar b, int method = 0){

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

}

void usage(){
    cerr << "Usage:\n \
    <loader> img.jpeg method or <loader> img.jpeg method <height_from> <height_to> <width_from> <width_to\n \
    method of greyscale is one of: \n \
    0 (average), \n \
    1 (Channel dependant luminance perception), \n \
    2 (Linear approximation of gamma and perceptual luminance corrected)\n";
}

int main(int argc, char* argv[]){
    
    if(argc != 3 and argc != 7){
        usage();
        exit(1);
    }

    char* img_file = argv[1];

    int method = atoi(argv[2]);

    if(method < 0 or method > 2){
        usage();
        exit(1);
    }

    CImg<uChar> img(img_file);
    unsigned int width = img.width();
    unsigned int height = img.height();

    int in_h_from = 1, in_h_to = height,
        in_w_from = 1, in_w_to = width;
        
    if(argc == 7){
        in_h_from = atoi(argv[3]), in_h_to = (atoi(argv[4])),
            in_w_from = atoi(argv[5]), in_w_to = atoi(argv[6]);
        if(in_h_from < 0 or in_h_from > height or in_h_to < 0 or in_h_to > height or in_h_to < in_h_from){
            cerr << "height range invalid\n";
            exit(1);
        }
        if(in_w_from < 0 or in_w_from > width or in_w_to < 0 or in_w_to > width or in_w_to < in_w_from){
            cerr << "width range invalid\n";
            exit(1);
        }
    }

    cout << in_h_from << ' ' << in_h_to << '\n';
    cout << in_w_from << ' ' << in_w_to << '\n';

    string outfile = "out.txt";
    ofstream outFileObj(outfile);

    for(int i = in_h_from - 1;i < in_h_to;i++){
        for(int j = in_w_from - 1;j < in_w_to;j++){
            uChar* rp = img.data(j, i, 0, RED);
            uChar r = *rp;
            
            uChar* gp = img.data(j, i, 0, GREEN);
            uChar g = *gp;
            
            uChar* bp = img.data(j, i, 0, BLUE);
            uChar b = *bp;
            
            char ch = mapper(to_gray_scale(r, g, b, method));

            outFileObj << ch;
            cout << ch;

            // uChar mx = max({r, b, g});
            // cout << mapper(mx);
            
            // uChar mn = min({r, b, g});
            // cout << mapper(mn);

        }
        outFileObj << '\n';
        cout << '\n';
    }
}