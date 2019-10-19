#include <math.h>
#include "Q4_methods.h"

double AreaWithTrapezoidal(int n)
{
   /*
        Receives number of intervals as argument
   */

   float initialSum, lowerLimit = 0, upperLimit = M_PI, x, sum=0.0, point, mulValue;
   int index;
   double area;

   initialSum = sin(lowerLimit) + sin(upperLimit);
   mulValue = (upperLimit - lowerLimit)/ (2 * n);
   point = upperLimit / n;

   // Looping to apply Trapezoidal  formula
   for (index=0; index<=n; index++){
	    x = index * point;
        sum =  sum + 2 * sin(x);
   }
   sum = sum - initialSum;

   // Calculating area
   area = mulValue * sum ;

   return area;
}
