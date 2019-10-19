/***********************************************************************************************
                                         AREA UNDER THE CURVE
************************************************************************************************/

// Including header files required for the program
#include <stdio.h>
#include <math.h>
// Including file containing function prototypes
#include "headers.h"


// Function prototypes
void PrintResult(double, float);
void TabulateValuesWithGivenIntreval();
int ReadVariable(int, int);
void ClearScanfBuffer (void);

// Main
int main(){

    int choice, nLimit, status;
    float area;

    printf("\t***********************| AREA UNDER THE CURVE |*************************");
    printf("\n\n\t1. Trapezoidal Rule\n\t2. Simpson's Rule\n\t3. Gauss Quadrature\n");

    // Choice for methods
    printf("\n\tEnter your method(1-3): ");

    // Reading value using ReadVariable, argument 1 indicates check for limit(0-3)
    choice = ReadVariable(1, 0);

    // Selecting methods based on  user input
    switch(choice)
    {
        case 1:
            printf("\n\n\t------------------------------------------------------------------------");
            printf("\n\t\t\t\t   TRAPEZOIDAL RULE");
            printf("\n\t------------------------------------------------------------------------");
            printf("\n\n\tEnter Number Of Limit: ");
            nLimit= ReadVariable(0, 0);
            area = AreaWithTrapezoidal(nLimit);
            PrintResult(area, 2);
        break;

        case 2:
            printf("\n\n\t------------------------------------------------------------------------");
            printf("\n\t\t\t\t   SIMPSON'S RULE");
            printf("\n\t------------------------------------------------------------------------");
            printf("\n\n\tEnter Number Of Limit: ");
            nLimit= ReadVariable(0, 1);
            area = AreaWithSimpson(nLimit);
            PrintResult(area, 2);
        break;

        case 3:
            printf("\n\n\t------------------------------------------------------------------------");
            printf("\n\t\t\t\t   GUASS QUADRATURE");
            printf("\n\t------------------------------------------------------------------------");
            area = AreaWithGauss();
            PrintResult(area, 2);
        break;

        default:
        break;
    }

    // Tabulating result using given intervals
    TabulateValuesWithGivenIntreval();

    return 0;

}

// Validation method for user inputs
int ReadVariable(int nlimit, int even)
{
    int status = 0, cond;
    int num    = 0;
    char message[100];

    status = scanf("%d",&num);

    // Checking limit 0-3
    if (nlimit){
        while((1 != status) || (num < 0) || (num > 3))
        {
            ClearScanfBuffer();
            printf("\tEnter a valid method (1-3): ");
            status = scanf("%d",&num);
        }
    }

    // Checking even and valid interval
    else if(even){
        while((1 != status) || (num % 2 != 0) || (num < 1))
        {
            ClearScanfBuffer();
            printf("\tEnter a valid interval(even): ");
            status = scanf("%d",&num);
        }
    }

    // Checking valid interval
    else{
        while((1 != status) || (num < 1))
        {
            ClearScanfBuffer();
            printf("\tEnter a valid interval: ");
            status = scanf("%d",&num);
        }
    }

    // Returning the input number
    return num;
}

// Printing actual value and calculated value
void PrintResult(double area, float actual)
{
    printf("\n\n\tCALCULATED AREA : %f", area);
    printf("\n\tACTUAL AREA     : %f", actual);
    printf("\n\n\t------------------------------------------------------------------------");
}

// Tabulating with given intervals
void TabulateValuesWithGivenIntreval()
{
    int nIntervals[4] = {2, 8, 16, 64}, row, column;
    double area;

    printf("\n\n\n\tTABULATING AREA FOR INTERVAL VALUES: N = {2,8,16,64}");
    printf("\n\n\t========================================================================");
    printf("\n\tINTERVALS\tTRAPEZOIDAL\t\tSIMPSON\t\t\tGAUSS");
    printf("\n\t========================================================================");

    // Using for loops to loop through all intervals and apply 3 methods to each
    for (row=0; row < 4; row++)
    {
        printf("\n\t%d", nIntervals[row]);
        for(column=1; column < 4; column++)
        {
            if (column == 1){
                area = AreaWithTrapezoidal(nIntervals[row]);
            }

            else if (column == 2){
                area = AreaWithSimpson(nIntervals[row]);
            }

            else{
                area = AreaWithGauss(nIntervals[row]);
            }

            printf("\t\t%f", area);
        }

    }
    printf("\n\t------------------------------------------------------------------------\n\n");
}

void ClearScanfBuffer(void)
{
  /*Clearing scanf buffer to read new values else it will try to
  read from the initial wrong value and will produce all wrong*/

  while ( getchar() != '\n' );
}

/*
------------------------------ ANALYSING THE RESULT OBTAINED -------------------------------

TRAPEZOIDAL RULE: As the value of n increases the value will come closer to the actual value,
                  i.e for n=2 the value was 1.57 and came closer to 2.00 when n=64.
SIMPSON'S RULE  : In Simpson's rule also the value become closer to 2.00 when the n value
                  increases. It is exact 2.00 when n = 64.
GAUSS QUADRATURE: This rule gives same value 1.935819 for all values of n since we are
                  Calculating for two points i.e formula independent of n.

    From the three rules normal trend is value reach close to actual when n increases, among
that Simpson's have given exact 2.00 for n=64.

*/

