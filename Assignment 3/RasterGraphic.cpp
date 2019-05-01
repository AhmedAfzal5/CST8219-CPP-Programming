/**********************************************************************
Filename: RasterGraphic.cpp
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
Purpose: create GraphicElements in RasterGraphic with forward_list
List of source and header files: RasterGraphic.h & RasterGraphic.cpp
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;

#include "Image.h"
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"

/***************************************
Function name: InsertGraphicElement
Purpose: add elements in RasterGraphic
Function In parameters: none
Function Out parameters: none
Version: 1.0
Author name: Ahmed Afzal
****************************************/
void RasterGraphic::InsertGraphicElement()
{
	vector<Image*> vecImage;

	int count = distance(GraphicElements.begin(), GraphicElements.end());
	int index = 0;

	string tmpFName, tmpShader;
	char* imgName = new char[200];
	int numImages, tmpX, tmpY, tmpDuration, tmpType;

	cout << "Insert a GraphicElement in the RasterGraphic" << endl;
	cout << "Please enter the GraphicElement filename: ";
	cin >> tmpFName;

	cout << "Entering the GraphicElement Images (the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Images: ";
	cin >> numImages;

	/* create image objects */
	for (int i = 0; i < numImages; i++)
	{
		cout << "Please enter pixel x-width for Image # " << i << " pixel_x: ";
		cin >> tmpX;

		cout << "Please enter pixel y-width for Image # " << i << " pixel_y: ";
		cin >> tmpY;

		cout << "Please enter the duration for this Image: ";
		cin >> tmpDuration;

		cout << "Please enter the name for this Image: ";
		cin >> imgName;

		/* choose which MemoryImage to use */
		do
		{
			cout << "Please enter the type for this Image (1 = SystemMemoryImage, 2 = GPUMemoryImage): ";
			cin >> tmpType;
		} while (tmpType <= 0 || tmpType >= 3);

		Image* img(NULL);

		/* if/else statement to determine which MemoryImage to put in Image */
		if (tmpType == 1)
		{
			img = new SystemMemoryImage(tmpX, tmpY, tmpDuration, imgName);
			vecImage.push_back(img);

			cout << endl;
		}
		else if (tmpType == 2)
		{
			cout << "Pleae enter the file name of the assoicated GPU Shader: ";
			cin >> tmpShader;

			img = new GPUMemoryImage(tmpX, tmpY, tmpDuration, imgName, tmpShader);
			vecImage.push_back(img);

			cout << endl;
		}
	}

	delete[] imgName;

	/* GraphicElement object */
	GraphicElement ge(tmpFName, vecImage);

	if (GraphicElements.empty()) /* check if GraphicElements is empty */
	{
		cout << "This is the first GraphicElement in the list" << endl;
		GraphicElements.push_front(ge);
	}
	else /* otherwise, add to specific user-chosen positions */
	{
		if (count > 1)
		{
			cout << "There are " << count << " GraphicElements in the list" << endl;

			do
			{
				cout << "Please specify the position, between 0 and " << count - 1 << " to insert after: ";
				cin >> index;
			} while (index < 0 || index > count - 1);

			forward_list<GraphicElement>::iterator it;
			it = GraphicElements.begin();

			if (index == 0)
				it = GraphicElements.insert_after(it, ge);
			else
			{
				forward_list<GraphicElement>::iterator iter;
				iter = it;
				++iter;
				GraphicElements.insert_after(iter, ge);
			}
		}
		else
		{
			GraphicElements.push_front(ge);
			GraphicElements.reverse();
		}
	}
	cout << endl;
}

/***********************************************
Function name: DeleteGraphicElement
Purpose: delete first element in RasterGraphic
Function In parameters: none
Function Out parameters: none
Version: 1.0
Author name: Ahmed Afzal
************************************************/
void RasterGraphic::DeleteGraphicElement()
{
	if (GraphicElements.empty()) //check if GraphicElements exist
		cout << "GraphicElements is empty" << endl;
	else //delete only head of list
	{
		GraphicElements.pop_front();
		cout << "Delete the first GraphicElement from the RasterGraphic" << endl;
		cout << "GraphicElement deleted" << endl;
	}
}

/******************************************************
Function name: operator<<
Purpose: display RasterGraphic
Function In parameters: ostream& os, RasterGraphic& rg)
Function Out parameters:  ostream& os
Version: 1.0
Author name: Ahmed Afzal
*******************************************************/
ostream& operator<<(ostream& os, RasterGraphic& rg)
{
	/* check if empty */
	if (rg.GraphicElements.empty())
	{
		os << "The RasterGraphic is empty" << endl;
	}
	else /* else, iterate and display elements in RasterGraphic */
	{
		int count = 0;

		os << "RasterGraphic " << rg.name << endl
			<< "Run the RasterGraphic" << endl;

		/* iterator */
		forward_list<GraphicElement>::iterator i;

		for (i = rg.GraphicElements.begin(); i != rg.GraphicElements.end(); i++)
		{
			os << "GraphicElement #" << count++ << ":" << *i << endl;
		}
	}
	os << "Output finished" << endl;
	return os;
}