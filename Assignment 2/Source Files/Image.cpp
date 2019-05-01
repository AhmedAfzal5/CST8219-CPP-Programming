/*************************************************************************
Filename: Image.cpp
Version: 1.0
Author: Ahmed Afzal
Student #: 040-845-435
Course Name and #: CST8219 - C++ Programming
Lab Section: 303
Assignment #: Assignment 2
Assignment Name: RasterGraphic in C++ using
				 Container Classess and Overloaded Operators
Due Date: Nov 10, 2018
Submission Date: Nov 10, 2018
Professor's Name: Andrew Tyler
Purpose: holds the pixel location that is overlayed in the GraphicElement
         and duraiton for which it should be Imaged.
List of source and header files: Image.h & Image.cpp
**************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "Image.h"

/************************************************
Function name: Image
Purpose: initialize object of Image
Function In parameters: int x, int y, 
                        int duration, char* name
Function Out parameters: none
Version: 1.0
Author: Ahmed Afzal
*************************************************/
Image::Image(int x, int y, int duration, char* name)
{
	this->pixel_y = y;
	this->pixel_x = x;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];

	strcpy(this->name, name);
}

/*****************************************************
Function name: Image
Purpose: the copy constructor for initializing another
         object of Image
Function In parameters: const Image& image
Function Out parameters: none
Version: 1.0
Author: Ahmed Afzal
******************************************************/
Image::Image(const Image& image)
{
	this->pixel_y = image.pixel_y;
	this->pixel_x = image.pixel_x;
	this->duration = image.duration;
	this->name = new char[strlen(image.name) + 1];

	strcpy_s(this->name, (strlen(image.name) + 1), image.name);
}

/*************************************
Function name: ~Image
Purpose: delete all memory of Image
Function In parameters: none
Function Out parameters: none
Version: 1.0
Author: Ahmed Afzal
**************************************/
Image::~Image()
{
	delete[] name;
}

/****************************************************************
Function name: operator<<
Purpose: overloaded operator to display elements in Image class
Function In parameters: ostream& os, Image& image
Function Out parameters: ostream& os
Version: 1.0
Author: Ahmed Afzal
*****************************************************************/
ostream& operator<<(ostream& os, Image& image)
{
	os << "    name = " << image.name
		<< "; pixel_x = " << image.pixel_x
		<< "; pixel_y = " << image.pixel_y
		<< "; duration = " << image.duration << endl;

	/* display seconds of Image */
	os << "    Counting the seconds for this Image: ";

	for (int i = 1; i <= image.duration; i++)
	{
		os << i << ", ";
	}
	return os;
}
