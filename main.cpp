#include <iostream>
using namespace std;

#define SCALE 2
#define BLOCK 3

typedef unsigned int uInt;
typedef unsigned int uChar;

void usage(){

    cerr << "Usage:\n \
    <program> img.jpg <scale> <block> \n";

}

void ensure(int argc, char* argv[]){

}

int main(int argc, char* argv[]){

    ensure(argc, argv);
    double scale = atof(argv[SCALE]);
    uInt block = atoi(argv[BLOCK]);

}