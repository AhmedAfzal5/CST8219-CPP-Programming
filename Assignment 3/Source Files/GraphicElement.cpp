/**********************************************************************
Filename: GraphicElement.cpp
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
Purpose: to create GraphicElements that hold a vector of Image pointers
List of source and header files: GraphicElement.h & GraphicElement.cpp
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Image.h"
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"
#include "GraphicElement.h"

/******************************************************
Function name: GraphicElement
Purpose: initialize GraphicElement object using 
		 a copy constructor
Function In parameters: GraphicElement& ge
Function Out parameters: none
Version: 1.0
Author name: Ahmed Afzal
*******************************************************/
GraphicElement::GraphicElement(const GraphicElement& ge)
{
	fileName = ge.fileName;

	/* for loop to put either a SystemMemoryImage or
	   GPUMemoryImage into the vector */
	for (vector<Image*>::const_iterator i = ge.Images.begin(); i != ge.Images.end(); i++)
	{
		if (SystemMemoryImage *sys = dynamic_cast<SystemMemoryImage*> (*i))
		{
			Images.push_back(new SystemMemoryImage(*sys));
		}
		else if (GPUMemoryImage *gpu = dynamic_cast<GPUMemoryImage*> (*i))
		{
			Images.push_back(new GPUMemoryImage(*gpu));
		}
	}
}

/********************************************************
Function name: operator<<
Purpose: display function using overloaded operator
Function In parameters: ostream& os, GraphicElement& ge
Function Out parameters: ostream& os
Version: 1.0
Author name: Ahmed Afzal
********************************************************/
ostream& operator<<(ostream& os, GraphicElement& ge)
{
	int count = 0;

	vector<Image*>::iterator i;

	os << "\tfileName = " << ge.fileName << endl;

	for (i = ge.Images.begin(); i != ge.Images.end(); i++)
	{
		os << "\tImage #" << count++ << ": " << **i << endl;
	}
	return os;
}
