#include <string>
#include <iostream>
#include "volimage.h"
using namespace std;

int main(int argc, char *argv[]){
    THNGEO002::VolImage v;
    
    
 
    string baseName;

    if(argc==2){
       
    
    v.readImages(argv[1]);
        int bytes=v.volImageSize();
    int sizeOfSlices=v.getSlices();
    cout<<"Number of images: "<<sizeOfSlices<<endl;
    cout<<"Number of bytes required: "<<bytes<<endl;
    }
    
    //v.diffmap(1,2,"outputDiffmap");
    //v.extract(1,"outputExtract");
    
return 0;
}