# Trace-all-the-rays

This is a simple implementation of a ray tracer in C++.<br />

ppmtest.cpp file sets up a file to test the ppm format which is used to store the scene for this project.<br />
main.cpp sets up the scence, and colours it.<br />
ray.h implements the ray class and methods.<br />
vec.h implements the vector class and methods.<br />
<br />
Notes:<br />
• Used floats instead of doubles. (either can be used)<br />
• The vectors used currently can only store r,g,b values, but these can be extended in the future to store even more detail as required.<br />
• The PPM file format is:<br />
PPM<br />
numberOfRows numberOfColumns<br />
maxColourVal<br />
RGB triplets for each element.<br />
