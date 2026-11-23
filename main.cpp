#include <iostream>
#include "jpeg_loader/loader.h"

using namespace std;

#define SCALE 2
#define BLOCK 3

typedef unsigned int uInt;
typedef unsigned char uChar;

void usage(){

    cerr << "Usage:\n \
    <program> img.jpg <scale> <block> \n";

}

void ensure(int argc, char* argv[]){

}

int main(int argc, char* argv[]){

    ensure(argc, argv);
    // double scale = atof(argv[SCALE]);
    // uInt block = atoi(argv[BLOCK]);

    vector<vector<pixelInfo> > img_info = loader(argv[1]);

    if(!img_info.size()){
        cerr << "Loader gave empty img info\n";
        exit(1);
    }

    cout << img_info.size() << ' ' << img_info.back().size() << '\n';

}