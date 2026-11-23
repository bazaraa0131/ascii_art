#ifndef IMG_LOADER
#define IMG_LOADER

#include<vector>

typedef unsigned char uChar;
typedef unsigned int uInt;

class pixelInfo{
    private: 
        uChar r, g, b;
    public:
        pixelInfo();
        pixelInfo(uChar _r, uChar _g, uChar _b);
        uChar to_gray_scale(int method);
};

std::vector<std::vector<pixelInfo> > loader(char* img_file);

#endif