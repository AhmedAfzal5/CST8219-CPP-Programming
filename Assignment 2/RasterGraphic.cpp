/*************************************************************************
Filename: RasterGraphic.cpp
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
Purpose: to hold series of GraphicElements that are held in a forward_list
List of source and header files: RasterGraphic.h & RasterGraphic.cpp
**************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Image.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"

/*************************************************
Function name: InsertGraphicElement
Purpose: add new GraphicElements to RasterGraphic
Function In parameters: none
Function Out parameters: none
Version: 1.0
Author: Ahmed Afzal
**************************************************/
void RasterGraphic::InsertGraphicElement() {
	vector<Image> vi;//vector Image
	string fName;
	char iName[100];
	int num, x, y, d;

	cout << "Insert a GraphicElement in RasterGraphic\n"
		"Please enter the GraphicElement filename: ";
	cin >> fName;

	do {
		cout << "Entering the GraphicElement Images (the sets of dimensions and durations)\n"
			"Please enter the number of Images:";

		cin >> num;
	} while (num == -1);

	for (int i = 0; i < num; ++i) {
			cout << "Please enter pixel x for Image #" << i << " pixel_x: ";
			cin >> x;
			cout << "Please enter pixel x for Image #" << i << " pixel_y: ";
			cin >> y;
			cout << "Please enter the duration sec for this Image: ";
			cin >> d;
		cout << "Please enter the name for this Image: ";
		cin >> iName;

		vi.push_back(Image(x, y, d, iName));
	}

	if (GraphicElements.empty()) {
		cout << "This is the first Graphic Element in the list\n";
		GraphicElements.push_front(GraphicElement(fName, vi));
	}
	else {
		GraphicElements.push_front(GraphicElement(fName, vi));
		GraphicElements.reverse();
	}

	cout << endl;
}
/*************************************
Function name: DeleteGraphicElement
Purpose: delete head of list
Function In parameters: none
Function Out parameters: none
Version: 1.0
Author: Ahmed Afzal
**************************************/
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

/****************************************************
Function name: RasterGraphic::operator[]
Purpose: return GraphicElement at specified location
Function In parameters: (unsigned int x
Function Out parameters: GraphicElement*
Version: 1.0
Author: Ahmed Afzal
*****************************************************/
GraphicElement& RasterGraphic::operator[](unsigned int x)
{
	unsigned int count = 0;
	forward_list<GraphicElement>::iterator i;

	/* iterate GraphicElements to get index */
	for (i = GraphicElements.begin(); i != GraphicElements.end(); i++)
	{
		if (x == count++)
		{
			break;
		}
	}
	return *i;
}

/******************************************
Function name: :operator+=
Purpose: add RasterGraphic together
Function In parameters: GraphicElement& ge
Function Out parameters: none
Version: 1.0
Author: Ahmed Afzal
*******************************************/
void RasterGraphic::operator+=(GraphicElement& ge)
{
	GraphicElement tempGE(ge);
	GraphicElements.push_front(tempGE);
	cout << endl;
}

/******************************************************************
Function name: operator<<
Purpose: display RasterGraphic and overloaded operator for ostream
Function In parameters: ostream& os, RasterGraphic& rg
Function Out parameters: ostream& os
Version: 1.0
Author: Ahmed Afzal
*******************************************************************/
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
			os << "GraphicElement #" << count++ << ":" << endl << *i;
		}
		os << endl;
	}
	os << "Output finished" << endl;
	return os;
}