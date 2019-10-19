// Including required headers files
#include <math.h>
#include "Q4_methods.h"


double AreaWithGauss()
{
    /* Takes no interval parameter as the formula is for 2 point */
    float lowerLimit = 0, upperLimit = M_PI, h, k, x1, x2;
    double area;

    h = (upperLimit - lowerLimit) / 2;
    k = lowerLimit + h;
    x1 = k - (h/sqrt(3));
    x2 = k + (h/sqrt(3));

    // Calculating areas
    area = h * (sin(x1) + sin(x2));

    return area;
}
