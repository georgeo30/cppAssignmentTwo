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
    slicesNo = 0;
} // default constructor - define in .cpp
VolImage::~VolImage() {} // destructor - define in .cpp file
// populate the object with images in stack and
//set member variables define in .cpp
bool VolImage::readImages(std::string baseName)
{
    string baseNameUrl = "./" + baseName + "/" + baseName + ".data";
    ifstream myfile;
    //opening the .data file and going through it
    myfile.open(baseNameUrl, ios::out | ios::app | ios::binary);
    string line;

    //if .data file is open go through and get the width, height and slicesNo
    if (myfile.is_open())
    {

        getline(myfile, line);

        std::istringstream ss(line);
        std::string token;
        ss >> width;
        ss >> height;
        ss >> slicesNo;

        myfile.close();

        cout << slicesNo << " " << width << " " << height << endl;
    }

    for (int i = 0; i < slicesNo; i++)
    {
        string sliceUrl = "./" + baseName + "/" + baseName + to_string(i) + ".raw";
        ifstream rawFile;
        rawFile.open(sliceUrl, ios::binary);

        slices.push_back(new unsigned char *[height + 1]);
        string sliceRow;

        for (int j = 0; j < height; j++)
        {

            slices[i][j] = new unsigned char[width + 1];
            for (int k = 0; k < width; k++)
            {
                slices[i][j][k] = rawFile.get();
            }
        }
        rawFile.close();
    }
    //     ofstream outfile;
    //    outfile.open("afile.dat");
    //     for(int i=0;i<height;i++){
    //         for(int j=0;j<width;j++){
    //             outfile<<slices[0][i][j];
    //         }
    //     }
    return 0;
}
// compute difference map and write out;
void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix)
{

    ofstream outfile;
    outfile.open("output_prefix.raw");
    
            for (int j = 0; j < height; j++)
            {
                for (int k = 0; k < width; k++)
                {
                    outfile << (slices[sliceI][j][k]-slices[sliceJ][j][k]);
                }
            }
        
    
}
// extract slice sliceId and write to output - define in .cpp
void VolImage::extract(int sliceId, std::string output_prefix) {}
// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int VolImage::volImageSize(void) {} // define in .cpp
} // namespace THNGEO002
