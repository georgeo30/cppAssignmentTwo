Read Me
---------------------------------------------------

Makefile Details:

make : to compile all cpp and header files, please type make into the command line. it will create driver.o VolImage.o and volimage executable.

make run : this will run the executable with default as no optional flags. thus will print out the number of slices and the number of bytes.

make clean : this will remove all .o files and the executable 

---------------------------------------------------

To Run the program through terminal.

1)Assuming you have already typed in "make" and compiled the files

2) you can then test by typing in as specified in the pdf

    example:
            1) to get the number of images and bytes type -> ./volimage MRI
            2) to use the diffmap function type -> ./volimage MRI -d 100 122 output
            3) to use the extract method type -> ./volimage MRI -x 100 output

    **  Please remember to preceed the name of the executable with "./" as shown above  **

    ** Please also note that the default path is brain_mri_raws/basename **
    ** you have to change it in the code if you want to change the path to your basename **


---------------------------------------------------

File structure

driver.cpp : contains the main method which is used to take in the command line input and process accordingly.
VolImage.cpp : class file as declared in the header to handle diffMap, extract and default informaation.
volimage.h : header file for the class VolImage.cpp


---------------------------------------------------

Git Details:

attached within the tar.gz is the .git repo
If this does not open or causes errors to run. Please view the repo on my gitHub which i will make available to public few days after submissions is closed.
GitHub Link : https://github.com/georgeo30/cppAssignmentTwo