#include "BMPImg.h"

int main(){
    BMPImg img("liver.bmp");
    img.RGB2Y();
    
    //img.SobelFilter();
    img.storePic("test.bmp");
    return 0;
}
