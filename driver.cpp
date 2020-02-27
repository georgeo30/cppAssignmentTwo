#include <string>
#include <iostream>
#include "volimage.h"
using namespace std;

int main(int argc, char *argv[])
{
    THNGEO002::VolImage v;

    string baseName;

    if (argc == 2)
    {
        v.readImages(argv[1]);

        int bytes = v.volImageSize();
        int sizeOfSlices = v.getSlices();
        cout << "Number of images: " << sizeOfSlices << endl;
        cout << "Number of bytes required: " << bytes << endl;
    }
    else if (argc == 6)
    {
        v.readImages(argv[1]);
        v.diffmap(atoi(argv[3]), atoi(argv[4]), argv[5]);
    }

    else if (argc = 5)
    {
        v.readImages(argv[1]);
        v.extract(atoi(argv[3]), argv[4]);
    }

    else
    {
        cout << "You have entered a invalid input. Please try again" << endl;
    }
    //v.diffmap(1,2,"outputDiffmap");
    //v.extract(1,"outputExtract");

    return 0;
}