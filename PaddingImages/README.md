## Description

You will implement an algorithm widely used in Image Processing: Padding (an addition of borders).
This procedure is a pre-processing of the image that adds a border around the original image with pixels of 0.

You can create a border of any size. For example, on a border of size 2, we add, for each pixel at the edge of the image, 2 pixels towards the edge.

The program will receive the following entries:

Image width.
Image height.
Width * Height pixels of the image, which are integers ranging from 0 to 255.
The size of the border.
As an output, the program should display the image with the padding, and, after skipping a line, the original image.

### Input example
```
3
3
1 1 1
2 2 2
3 3 3
2
```
### Output
```
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 1 1 1 0 0
0 0 2 2 2 0 0
0 0 3 3 3 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

1 1 1
2 2 2
3 3 3
```