/**************************************************************
Filename: GraphicElement.cpp
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
Source and Header Files: GraphicElement.cpp & GraphicElement.h
Purpose: to initialize and cleanup the GraphicElement variables
***************************************************************/
#include "GraphicElement.h"

using namespace std;

/***********************************************
Function name: GraphicElement()
Purpose: initialize variables in GraphicElement
Function In parameters: none
Function Out parameters: none
Version: 1.0
Student Name: Ahmed Afzal
************************************************/
GraphicElement::GraphicElement()
{
	fileName = nullptr;
	pNext = nullptr;
}

/***********************************************
Function name: ~GraphicElement()
Purpose: cleanup variables in GraphicElement
Function In parameters: none
Function Out parameters: none
Version: 1.0
Student Name: Ahmed Afzal
************************************************/
GraphicElement::~GraphicElement()
{
	delete this->fileName;
	delete this->pNext;
}