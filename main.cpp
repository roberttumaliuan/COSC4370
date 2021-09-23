/*  
The following code displays the upper half of an ellipse
with the given equation ((x/12)^2) + ((y/6)^2) = 64^2 in 
an image window with dimensions 200 x 200.
*/
#include <iostream>
#include "BMP.h"
#include <cmath>

int main() {
    BMP bmpNew(200,200,false);
    bmpNew.fill_region(0, 0, 200, 200, 0, 0, 0, 0);
    for(int i = 34; i < 167; i++)
    {
        bmpNew.set_pixel(i, (6 * (sqrt((64^2) - (abs(i-100))^2/144))) + 100, 255, 255, 255, 0);
    }
    
  bmpNew.write("output.bmp");
}



