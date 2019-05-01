/**********************************************************************
Filename: Image.cpp
Version: 1.0
Author: Ahmed Afzal
Student #: 040-845-435
Course Name and #: CST8219 - C++ Programming
Lab Section: 303
Assignment #: Assignment 3
Assignment Name: RasterGraphic Project in C++
using Polymorphic Inheritance and RTTI
Due Date: Dec 1, 2018
Submission Date: Dec 1, 2018
Professor's Name: Andrew Tyler
Purpose: create Image objects and display them
List of source and header files: Image.h & Image.cpp
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <string> 
#include <iostream>  

using namespace std;

#include "Image.h"
#include "GPUMemoryImage.h"
#include "SystemMemoryImage.h"

/**************************************************************
Function name: Image
Purpose: initiliaze Image object
Function In parameters: int x, int y, int duration, char* name
Function Out parameters: none
Version: 1.0
Author name: Ahmed Afzal
***************************************************************/
Image::Image(int x, int y, int duration, char* name)
{
	this->pixel_x = x;
	this->pixel_y = y;
	this->duration = duration;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

/**************************************************************
Function name: Image
Purpose: initiliaze another Image object with copy constructor
Function In parameters: Image& image
Function Out parameters: none
Version: 1.0
Author name: Ahmed Afzal
***************************************************************/
Image::Image(const Image& image)
{
	this->pixel_x = image.pixel_x;
	this->pixel_y = image.pixel_y;
	this->duration = image.duration;

	this->name = new char[strlen(image.name) + 1];
	strcpy(this->name, image.name);
}

/**************************************************************
Function name: operator<<
Purpose: display elements in Image
Function In parameters: ostream& os, Image& image
Function Out parameters: ostream& os
Version: 1.0
Author name: Ahmed Afzal
***************************************************************/
ostream& operator<<(ostream& os, Image& image)
{
	/* using try/catch, determine which MemoryImage to display */
	try
	{
		SystemMemoryImage& sys = dynamic_cast<SystemMemoryImage&>(image);
		os << "System Memory Image" << endl;
	}
	catch (const std::bad_cast& e) {
	}

	try
	{
		GPUMemoryImage& gpu = dynamic_cast<GPUMemoryImage&>(image);
		os << "GPU Memory Image. Shader = " << gpu.GetShader() << endl;
	}
	catch (const std::bad_cast& e) {
	}

	os << "\tImage name = " << image.name
		<< "; pixel_x = " << image.pixel_x
		<< "; pixel_y = " << image.pixel_y
		<< "; duration = " << image.duration
		<< endl;

	os << "\tCounting the seconds for the Image: ";

	/* display seconds for Image */
	for (int i = 1; i <= image.duration; i++)
	{
		os << i << ", ";
	}
	os << endl;

	/* get buffer size */
	os << "\tMemory requirements = " << image.BufferSize() << " bytes" << endl;

	return os;
}
