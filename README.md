# Trace-all-the-rays

This is a simple implementation of a ray tracer in C++. 

ppmtest.cpp file sets up a file to test the ppm format which is used to store the scene for this project.
main.cpp sets up the scence, and colours it. 
ray.h implements the ray class and methods.
vec.h implements the vector class and methods. 

Notes:
• Used floats instead of doubles. (either can be used)
• The vectors used currently can only store r,g,b values, but these can be extended in the future to store even more detail as required.
• The PPM file format is:
PPM
numberOfRows numberOfColumns
maxColourVal
RGB triplets for each element. 
