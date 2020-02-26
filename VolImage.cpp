#include <string>
#include <iostream>
#include <vector>
#include "volimage.h"
#include <sstream>

using namespace std;
namespace THNGEO002
{

VolImage::VolImage()
{
    width = 0;
    height = 0;
} // default constructor - define in .cpp
VolImage::~VolImage() {} // destructor - define in .cpp file
// populate the object with images in stack and
//set member variables define in .cpp
bool VolImage::readImages(std::string baseName)
{
    string baseNameUrl = "./" + baseName + "/" + baseName + ".data";
    ifstream myfile;
    myfile.open(baseNameUrl, ios::out | ios::app | ios::binary);
    string line;
    vector<int> whn;
    int slicesNo;

    if (myfile.is_open())
    {

        getline(myfile, line);

        std::istringstream ss(line);
        std::string token;
        ss >> width;
        ss >> height;
        ss >> slicesNo;

        myfile.close();

        cout << slicesNo << " " << width << " " << height;
    }
    for (int i = 0; i < slicesNo; i++)
    {
        cout<<i;
    }
            return 0;

}
// compute difference map and write out; define in .cpp
void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {}
// extract slice sliceId and write to output - define in .cpp
void VolImage::extract(int sliceId, std::string output_prefix) {}
// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int VolImage::volImageSize(void) {} // define in .cpp
} // namespace THNGEO002
