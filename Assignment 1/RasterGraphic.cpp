/**************************************************************
Filename: RasterGraphic.cpp
Version: 1.0
Student Name: Ahmed Afzal
Student #: 040-845-435
Course Name and #: CST8219 - C++ Programming
Lab Section: 303
Assignment #: Assignment 1
Assignment Name: Raster Graphic Project in C++
Due Date: Oct 13, 2018
Submission Date: Oct 13, 2018
Professor's Name: Andrew Tyler
Source and Header Files: RasterGraphic.cpp & RasterGraphic.h
Purpose: to hold data of a raster graphic application using a 
         forward list (linked-list)
***************************************************************/
#include "GraphicElement.h"
#include "RasterGraphic.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

/***********************************************
Function name: RasterGraphic()
Purpose: initialize variables in RasterGraphic
Function In parameters: none
Function Out parameters: none
Version: 1.0
Student Name: Ahmed Afzal
************************************************/
RasterGraphic::RasterGraphic()
{
	GraphicElements = nullptr;
}

/*******************************************************
Function name: InsertGraphicElement()
Purpose: to add a new GraphicElement in the 
         RasterGraphic at a position chosen by the user
Function In parameters: none
Function Out parameters: none
Version: 1.0
Student Name: Ahmed Afzal
********************************************************/
void RasterGraphic::InsertGraphicElement()
{
	char fName[50];

	int counter;
	int counterB = 0;
	int index;
	int size;

	GraphicElement *temp;
	/* allocate memory for GraphicElement */
	temp = new GraphicElement;

	cout << "Insert A GRAPHIC ELEMENT" << endl;
	cout << "Please enter the GraphicElement filename: ";
	cin >> fName;

	/* get length of filename */
	size = strlen(fName) + 1;
	/* allocate memory for filename */
	temp->GetfileName() = new char[size];
	/* copy user-entered filename to GraphicElement filename */
	strcpy(temp->GetfileName(), fName);

	GraphicElement *curr;
	curr = GraphicElements;
	
	/* if there are no GraphicElements, insert one at the head of list */
	if (GraphicElements == nullptr)
	{
		cout << "This is the first GraphicElement in the list" << endl;
		temp->GetpNext() = GraphicElements;
		GraphicElements = temp;
		return;
	}
	else /* the list has GraphicElements, thus add at user chosen positon */
	{
		counter = 0;
		curr = GraphicElements;
		
		/*  get length of list */
		while (curr != nullptr)
		{
			curr = curr->GetpNext();
			counter++;
		}
		curr = GraphicElements;

		cout << "There are " << counter << " GraphicElement(s) in the list." 
			 " Please specify the position(<= " << counter << ") to insert at: ";
		
		cin >> index;

		/* only one GraphicElement in RasterGraphic */
		if (index == 0)
		{
			temp->GetpNext() = GraphicElements;
			GraphicElements = temp;
			return;
		}

		curr = GraphicElements;
		GraphicElement *prev;

		while (counterB < index)
		{
			prev = curr;
			curr = curr->GetpNext();
			counterB++;
		}

		prev->GetpNext() = temp;
		temp->GetpNext() = curr;
		return;
	}
}

/*********************************************
Function name: DeleteGraphicElement()
Purpose: to delete the head of RasterGraphic
Function In parameters: none
Function Out parameters: none
Version: 1.0
Student Name: Ahmed Afzal
**********************************************/
void RasterGraphic::DeleteGraphicElement()
{
	GraphicElement *temp;

	/* if there are no GraphicElements in list */
	if (GraphicElements == nullptr)
	{
		cout << "No GraphicElements in the RasterGraphic" << endl;
	}
	else /* list has more than one, delete only the head of list */
	{
		temp = GraphicElements;
		GraphicElements = temp->GetpNext();

		delete temp->GetfileName();
	}
}

/*******************************************************
Function name: ReportRasterGraphic()
Purpose: report RasterGraphic to show list of 
         GraphicElement details at 1 second intervals
Function In parameters: none
Function Out parameters: none
Version: 1.0
Student Name: Andrew Tyler
********************************************************/
void RasterGraphic::ReportRasterGraphic()
{
	int counter = 0;
	time_t startsec, oldsec, newsec;
	GraphicElement* iterator = GraphicElements;

	if (GraphicElements == 0)
	{
		printf("No GraphicElements in the RasterGraphic\n");
		return;
	}

	cout << "Report the RasterGraphic" << endl;
	startsec = oldsec = time(NULL);
	
	while (iterator)
	{
		newsec = time(nullptr);
		
		if (newsec > oldsec)
		{
			cout << "GraphicElement #" << counter++ << ", time = " << newsec - startsec << "sec" << endl;
			cout << "Image file name = " << iterator->GetfileName() << endl;
			
			iterator = iterator->GetpNext();
			oldsec = newsec;
		}
	}
}