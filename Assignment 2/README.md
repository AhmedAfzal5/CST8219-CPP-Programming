# RasterGraphic in C++ using Container Classes and Overloaded Operators

## Purpose
Holds the GraphicElements of a RasterGraphic using a forward_list class template of unspecified length in dynamic memory.
The forward_list is container class that supports fast insertion and removal of elements and is implemented as a singly-
linked list. In addition, a GraphicElement now has set of Image objects associated with it. A Image object holds the pixel location that it is to be overlayed in the GraphicElement and also the duration for which it should be Imaged. The set of Image objects is held in a vector. 

The program does the following:

* add a new GraphicElement to the RasterGraphic at a position chosen by the user
* delete the first GraphicElement in the RasterGraphic
* show the list of Image details of each GraphicElement 
* concatenate two GraphicElements to make a single GraphicElement with combined Images that
is automatically added to the start of the forward_list

## Screenshots of Program
![Assign 2 Image 1](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%202/Screenshots/assign2-img1.PNG)
![Assign 2 Image 2](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%202/Screenshots/assign2-img2.PNG)
![Assign 2 Image 3](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%202/Screenshots/assign2-img3.PNG)
![Assign 2 Image 4](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%202/Screenshots/assign2-img4.PNG)
![Assign 2 Image 5](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%202/Screenshots/assign2-img5.PNG)
![Assign 2 Image 6](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%202/Screenshots/assign2-img6.PNG)
![Assign 2 Image 7](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%202/Screenshots/assign2-img7.PNG)
