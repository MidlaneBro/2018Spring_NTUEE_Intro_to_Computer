#ifndef __BMPIMG_H__
#define __BMPIMG_H__

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

static const int headerNum = 15;
static const int headerSize[headerNum] = {2,4,4,4,  4,4,4,2,2,4,4,4,4,4,4};
static const string headerInfo[headerNum]
    = {"Identifier","FileSize","Reserved","BitmapDataOffset",
       "BitmapHeaderSize","Width","Height","Planes",
       "BitsPerPixel","Compression","BitmapDataSize","H_Resolution",
       "V_Resolution","UsedColors","ImportantColors"};

class BMPHead{
private:
    char Identifier[2];
    unsigned int    FileSize;
    unsigned int    Reserved;
    unsigned int    BitmapDataOffset;

    unsigned int    BitmapHeaderSize;
    unsigned int    Width;
    unsigned int    Height;
    unsigned short  Planes;
    unsigned short  BitsPerPixel;
    unsigned int    Compression;
    unsigned int    BitmapDataSize;
    unsigned int    H_Resolution;
    unsigned int    V_Resolution;
    unsigned int    UsedColors;
    unsigned int    ImportantColors;
public:
    friend class BMPImg;
    void* pFlag(const int i)const{  //return pointers of flags according to its order(int)
        switch(i){
        default:
        case  0:    return (void*)Identifier;
        case  1:    return (void*)&FileSize;
        case  2:    return (void*)&Reserved;
        case  3:    return (void*)&BitmapDataOffset;
        case  4:    return (void*)&BitmapHeaderSize;
        case  5:    return (void*)&Width;
        case  6:    return (void*)&Height;
        case  7:    return (void*)&Planes;
        case  8:    return (void*)&BitsPerPixel;
        case  9:    return (void*)&Compression;
        case 10:    return (void*)&BitmapDataSize;
        case 11:    return (void*)&H_Resolution;
        case 12:    return (void*)&V_Resolution;
        case 13:    return (void*)&UsedColors;
        case 14:    return (void*)&ImportantColors;
        }
    }
};
class BMPImg{
private:
    BMPHead header;
public:
    unsigned char* data;

    int getWidth()const{return header.Width;}
    int getHeight()const{return header.Height;}
    int getPxlNum()const{return header.Width * header.Height;}
    int getBytesPerPixel()const{return header.BitsPerPixel/8;}

    BMPImg(){}
    BMPImg(const string& picPath){loadPic(picPath);}
    ~BMPImg(){delete [] data;}

    bool loadPic(const string& picPath);
    void printHeader()const{
        for(int i=0;i<headerNum;++i){
            cout<< headerInfo[i]+":";

            if(i==0){
                cout<< header.Identifier[0] << header.Identifier[1];
            }else{
                if(headerSize[i]==4)
                    cout<< *(  (unsigned int*)(header.pFlag(i))  );
                else
                    cout<< *(  (unsigned short*)(header.pFlag(i))  );
            }
            cout<< endl;
        }
    }
    bool RGB2Y();
    bool SobelFilter();
    bool storePic(const string& outPath);
};

#endif // __BMPIMG_H__
