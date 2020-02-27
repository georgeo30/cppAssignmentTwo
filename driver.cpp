#include <string>
#include <iostream>
#include "volimage.h"
using namespace std;

int main(){
    THNGEO002::VolImage v;
    string baseName;
    cout<<"Please input the base name"<<endl;
    getline(cin,baseName);
    
    v.readImages(baseName);
    //v.diffmap(1,2,"outputDiffmap");
    //v.extract(1,"outputExtract");
    int bytes=v.volImageSize();
    int sizeOfSlices=v.getSlices();
    cout<<"Number of images: "<<sizeOfSlices<<endl;
    cout<<"Number of bytes required: "<<bytes<<endl;
return 0;
}