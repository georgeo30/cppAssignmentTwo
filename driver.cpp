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

}