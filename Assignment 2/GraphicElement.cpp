/**********************************************************************
Filename: GraphicElement.cpp
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
Purpose: to create GraphicElements of a RasterGraphic application
         using a forward_list class template of unspecified length
		 in dynamic memory
List of source and header files: GraphicElement.h & GraphicElement.cpp
***********************************************************************/
#include <iostream>
#include <vector>
#include <string> 

using namespace std;

#include "Image.h"
#include "GraphicElement.h"

/*****************************************
Function name: operator+
Purpose: go through elements of Images
Function In parameters: GraphicElement& ge
Function Out parameters: GraphicEleent
Version: 1.0
Author: Ahmed Afzal
******************************************/
GraphicElement GraphicElement:: operator+(GraphicElement& ge) {
	vector<Image> vImage;
	vector<Image>::iterator iterate;
	int i = 0;

	for (i = 0; i < Images.size(); ++i)
		vImage.push_back(Image(Images.at(i)));

	for (i = 0; i < ge.Images.size(); ++i)
		vImage.push_back(Image(ge.Images.at(i)));

	GraphicElement element(fileName + "_" + ge.fileName, vImage);
	return element;
}

/*******************************************************
Function name: operator<<
Purpose: display information ins GraphicElement 
Function In parameters: ostream& os, GraphicElement& ge
Function Out parameters: ostream& os
Version: 1.0
Author: Ahmed Afzal
********************************************************/
ostream& operator<<(ostream& os, GraphicElement& ge)
{
	/* iterator */
	vector<Image>::iterator i;

	int counter = 0;

	os << "    filename = " << ge.fileName << endl;

	/* iterate and display elements in GraphicElement */
	for (i = ge.Images.begin(); i != ge.Images.end(); i++)
		os << "    Image #" << counter++ << ":" << *i << endl;

	return os;
}