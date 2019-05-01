/***********************************************************
Filename: ass0.c
Version: 1.0
Student Name: Ahmed Afzal
Student Number: 040-845-435
Course Name and Number: CST8219 - C++ Programming
Lab Section: 303
Assignment Number: 0
Assignment Name: Raster Graphic Project in C
Due Date: September 23, 2018
Submission Date: September 26, 2018
Professor's Name: Andrew Tyler
List of Source and Header Files: ass0.c
Purpose: hold data for a raster graphic application using
		 a forward list in dynamic memory.
***********************************************************/
// ass0.c
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef enum { FALSE = 0, TRUE } BOOL;

struct GraphicElement
{
	char* fileName;
	struct GraphicElement* pNext;
};

struct RasterGraphic
{
	struct GraphicElement* GraphicElements;
};

// Forward declarations
void InitRasterGraphic(struct RasterGraphic*);
void InsertGraphicElement(struct RasterGraphic*);
void DeleteGraphicElement(struct RasterGraphic*);
void ReportRasterGraphic(struct RasterGraphic*);
void CleanUp(struct RasterGraphic*);

int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	struct RasterGraphic RG;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	InitRasterGraphic(&RG);

	while (RUNNING)
	{
		printf("MENU\n 1. Insert a GraphicElement\n 2. Delete the first GraphicElement\n 3. Report the RasterGraphic\n 4. Quit\n");
		scanf("%c", &response);
		switch (response)
		{
		case '1':InsertGraphicElement(&RG); break;
		case '2':DeleteGraphicElement(&RG); break;
		case '3':ReportRasterGraphic(&RG); break;
		case '4':RUNNING = FALSE; CleanUp(&RG); break;
		default:printf("Please enter a valid option\n");
		}
		printf("\n");
		while ((response = getchar()) != '\n' && response != EOF);// clear input buffer
	}
	return 0;
}

/****************************************************************
Function name:		initRasterGraphic
Purpose:			initialize variables in struct RasterGraphic
In parameters:		RasterGraphic pointer
Out parameters:
Version:			1.0
Author:				Ahmed Afzal
*****************************************************************/
void InitRasterGraphic(struct RasterGraphic* pA)
{
	pA->GraphicElements = NULL;
}

/********************************************************************
Function name:		InsertGraphicElement
Purpose:			add a new GraphicElement to the RasterGraphic at
a position chosen by the user
In parameters:		RasterGraphic pointer
Out parameters:
Version:			1.0
Author:				Ahmed Afzal
********************************************************************/
void InsertGraphicElement(struct RasterGraphic* pA)
{
	char fName[50];

	int counter;
	int index;
	int size;

	struct GraphicElement *temp;
	// allocate memory for node
	temp = (struct GraphicElement*)malloc(sizeof(struct GraphicElement));

	printf("Insert a GraphicElement in the RasterGraphic");
	printf("Please enter the GraphicElement filename: ");
	scanf("%s", &fName);

	//get length of filename
	size = strlen(fName) + 1;
	//allocate memory for filename
	temp->fileName = (char *)malloc(size);
	//copy user-entered filename to GraphicElement filename
	strcpy(temp->fileName, fName);

	struct GraphicElement *curr;
	curr = pA->GraphicElements;

	struct GraphicElement *prev;

	//if the list is empty, then insert GraphicElement to head of list
	if (pA->GraphicElements == NULL)
	{
		printf("This is the first GraphicElement in the list");
		temp->pNext = pA->GraphicElements;
		pA->GraphicElements = temp;
		return;
	}
	else /* the list has nodes, thus add at user specified positions */
	{
		counter = 0;
		curr = pA->GraphicElements;

		/* get length of list */
		while (curr != NULL)
		{
			curr = curr->pNext;
			counter++;
		}

		curr = pA->GraphicElements;

		printf("There are %d GraphicElement(s) in the list. Please specifiy the position (<= %d) to insert at:  ", counter, counter);
		scanf("%d", &index);

		/* if there is only one GraphicElement in the list */
		if (index == 0)
		{
			temp->pNext = pA->GraphicElements;
			pA->GraphicElements = temp;
			return;
		}

		int counterB = 0;
		curr = pA->GraphicElements;

		while (counterB < index)
		{
			prev = curr;
			curr = curr->pNext;
			counterB++;
		}

		prev->pNext = temp;
		temp->pNext = curr;
		return;
	}
}

/************************************************************
Function name:		DeleteGraphicElement
Purpose:			delete the first GraphicElement in list
In parameters:		RasterGraphic pointer
Out parameters:
Version:			1.0
Author:				Ahmed Afzal
**************************************************************/
void DeleteGraphicElement(struct RasterGraphic* pA)
{
	struct GraphicElement *temp;

	/* if list is empty */
	if (pA->GraphicElements == NULL)
	{
		printf("No nodes in this list");
	}
	else /* there are nodes in the list */
	{
		temp = pA->GraphicElements;
		pA->GraphicElements = temp->pNext;

		/* free memory of both filename and pointer */
		free(temp->fileName);
		free(temp);
	}
}

/************************************************************************
Function name:		ReportRasterGraphic
Purpose:			report RasterGraphic to show list of GraphicElement
details at a 1 second interval
In parameters:		RasterGraphic pointer
Out parameters:
Version:			1.0
Author:				Ahmed Afzal
************************************************************************/
void ReportRasterGraphic(struct RasterGraphic* pA)
{
	int counter = 0;
	time_t startsec, oldsec, newsec;
	struct GraphicElement* iterator = pA->GraphicElements;

	if (pA->GraphicElements == 0)
	{
		printf("No GraphicElements in the RasterGraphic\n");
		return;
	}

	printf("Report the RasterGraphic\n");
	startsec = oldsec = time(NULL);
	while (iterator)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			printf("GraphicElement #%d, time = %I64d sec\n", counter++, newsec - startsec);
			printf("Image file name = %s\n", iterator->fileName);
			iterator = iterator->pNext;
			oldsec = newsec;
		}
	}
}

/****************************************************************
Function name:		CleanUp
Purpose:			to free all memory
In parameters:		RasterGraphic pointer
Out parameters:
Version:			1.0
Author:				Ahmed Afzal
*****************************************************************/
void CleanUp(struct RasterGraphic* pA)
{
	struct GraphicElement *temp;

	/* no nodes in the list */
	if (pA->GraphicElements == NULL)
	{
		printf("No nodes available");
	}
	else /* there are nodes in the list */
	{
		temp = pA->GraphicElements;

		while ((temp = pA->GraphicElements) != NULL)
		{
			pA->GraphicElements = temp->pNext;

			free(temp->fileName);
			free(temp);
		}
	}
}