CC=g++
LIB=-std=c++11
create: volimage.h VolImage.cpp driver.cpp
	$(CC) $(LIB) volimage.h VolImage.cpp driver.cpp -c
	$(CC) $(LIB) driver.o volImage.o -o volimage

run:
	./volimage MRI

clean:
	rm volImage.o
	rm driver.o
	rm volimage.h.gch
	rm myprog
