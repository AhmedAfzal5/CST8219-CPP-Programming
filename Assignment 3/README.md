# RasterGraphic Project in C++ using Polymorphic Inheritance and RTTI

## Purpose
This is a development of assignment 2. It works in a very similar way but with the addition of
two new classes SystemMemoryImage and GPUMemoryImage, that are derived from the abstract base
class Image. Like assignment 2, it is a console application that holds the GraphicElements of a
RasterGraphic application (there is no actual graphics in the assignment) in a forward_list class
template of unspecified length in dynamic memory. Each GraphicElement now holds a vector of
Image* pointers that are the addresses of the Image objects that are actually SystemMemoryImage or
GPUMemoryImage objects. Polymorphic inheritance ensures that any Image* in the vector will call the
correct overridden polymorphic function (Buffersize() in this case) for the actual object it points to.
Also a SystemMemoryImage object uses more memory than a GPUMemoryImage object because they
reside in different memory locations in the computer: in system memory or GPU local memory
respectively. A GPUMemoryImage object also has a shader file that is a small fragment of code that
executes for each pixel in the Image buffer.
Therefore you will use an expression like
Images[i]->BufferSize()
to cause one of the Image* in the GraphicElement vector to calculate the buffer size of the
SystemMemoryImage or GPUMemoryImage it points to without needing to identify what type of Image it
really is. The polymorphic function that actually executes is the correct one for the object type, selected
through the virtual function table of the object.
In places where you need to identify the type of Image (SystemMemoryImage or GPUMemoryImage),
but not where polymorphism is appropriate, use dynamic_cast<>.
To focus on the polymorphic aspects of this final assignment, some of the overloaded operators used in
Assignment 2 have been removed.
Part of the code is shown on the next page; it is also on Brightspace in a text file that you can copy and
paste. Do not change this code. You MUST use this code without modification (not a single character
changed): no code added or removed, no new global variables or functions, no new classes, no
macros, no defines and no statics. Your task is to implement, using C++, only the RasterGraphic,
GraphicElement and Image class member functions and the global insertion operators and not add
any new ones. Everything you write and submit is in the files: RasterGraphic.cpp, GraphicElement.cpp
and Image.cpp.
The RasterGraphic is a series of GraphicElements held in a forward_list. Each GraphicElement
holds its list of Image* in a vector. There are now two types of Image, as detailed above, both
subclasses of the abstract base class Image. Each Image object contains its Image time which is set by
the user. You can:
 Add a new GraphicElement to the RasterGraphic at a position in the forward list selected by
the user
 Delete the first GraphicElement in the RasterGraphic
 Run the RasterGraphic to show the list of Image details of each GraphicElement one after
another at the Image intervals specified by the user when the Image was entered – note that the
output counts up the seconds using a timer as was done in assignment 1 onwards.
 Quit

## Screenshots of Program
![Assign 3 Image 1](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%203/Screenshots/assign3-img1.PNG)
![Assign 3 Image 2](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%203/Screenshots/assign3-img2.PNG)
![Assign 3 Image 3](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%203/Screenshots/assign3-img3.PNG)
![Assign 3 Image 4](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%203/Screenshots/assign3-img4.PNG)
![Assign 3 Image 5](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%203/Screenshots/assign3-img5.PNG)
![Assign 3 Image 6](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%203/Screenshots/assign3-img6.PNG)
![Assign 3 Image 7](https://github.com/AhmedAfzal5/CST8219-CPP-Programming/blob/master/Assignment%203/Screenshots/assign3-img7.PNG)
