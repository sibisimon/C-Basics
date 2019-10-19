// Including header files
#include <math.h>
#include "Q4_methods.h"

double AreaWithSimpson(int n)
{
    /*
        Receives number of intervals as argument
    */

    float initialSum, lowerLimit = 0, upperLimit = M_PI, x, sum1=0.0, sum2=0.0, point, mulValue;
    int index;
    double area;

    initialSum = sin(lowerLimit) + sin(upperLimit);
    mulValue = ((upperLimit - lowerLimit) / n) / 3;
    point = upperLimit / n;

    // Looping to apply Simpson formula
    for (index=1; index<=n-1; index++){
	    x = index * point;
	    if (index % 2 == 0)
        {
            sum1 =  sum1 + 2 * sin(x);
        }
        else{
            sum2 =  sum2 + 4 * sin(x);
        }
   }

   // Calculating final area
   area = mulValue * (initialSum + sum1 + sum2);

   return area;
}
