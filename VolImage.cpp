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
} // default constructor
VolImage::~VolImage() {} // destructor
// populate the object with images in stack and
//set member variables
bool VolImage::readImages(std::string baseName)
{
    string baseNameUrl = "./brain_mri_raws/" + baseName + ".data";
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

    }

    for (int i = 0; i < slicesNo; i++)
    {
        string sliceUrl = "./brain_mri_raws/" + baseName + to_string(i) + ".raw";
        ifstream rawFile;
        rawFile.open(sliceUrl, ios::binary);
        sum=sum+sizeof(slices[i]);
        slices.push_back(new unsigned char *[height]);
        string sliceRow;

        for (int j = 0; j < height; j++)
        {
            sum=sum+sizeof(slices[i][j]);
            slices[i][j] = new unsigned char[width];
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
    outfile.open(output_prefix + ".raw");

    for (int j = 0; j < height; j++)
    {
        for (int k = 0; k < width; k++)
        {
            outfile << (unsigned char)(abs((float)slices[sliceI][j][k] - (float)slices[sliceJ][j][k]) / 2);
        }
        //outfile<<endl;
    }
    outfile.close();
}
// extract slice sliceId and write to output
void VolImage::extract(int sliceId, std::string output_prefix)
{
    ofstream outfile;
    outfile.open(output_prefix + ".data");

    outfile << to_string(width) + " " + to_string(height) + " 1";
    outfile.close();
    outfile.open(output_prefix + ".raw");
    for (int j = 0; j < height; j++)
    {
        for (int k = 0; k < width; k++)
        {
            outfile << slices[sliceId][j][k];
        }
        //outfile<<endl;
    }
}
// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int VolImage::volImageSize(void) {
    return (width*height*slicesNo)+sum;
} 
int VolImage::getSlices(void){
    return slicesNo;
}
} // namespace THNGEO002
