/***********************************************************************************************
                                        Geometric Sequence
************************************************************************************************/

// Header files
#include <stdio.h>
#include <math.h>


// Function prototypes
float FindGoemetricSumWithFormula(int, float, float);
float FindCalculatedSum(int, float, float);
void PrintDetails(int, float, float, int, float, float);


void main(void){

    float r, a;
    float fGmFormulaSum = 0.0, fOrginalSum = 0.0;
    int n, index;

    printf(" ***************************|Geometric Sequence|***************************\n");

    // Loop for 3 cases of values
    for(index=1; index<=3; index++){

        // Switch case for selecting 3 cases
        switch(index){
            case 1:
                n = 10000;
                a = 2.0;
                r = 0.01;
                // Calculating with formula
                fGmFormulaSum = FindGoemetricSumWithFormula(n, a, r);
                // Calculating with with a loop
                fOrginalSum = FindCalculatedSum(n, a, r);
                // Printing details
                PrintDetails(1, fGmFormulaSum, fOrginalSum, n, a, r);
            break;

            case 2:
                n = 500;
                a = 0.01;
                r = 1.1;
                // Calculating with formula
                fGmFormulaSum = FindGoemetricSumWithFormula(n, a, r);
                // Calculating with with a loop
                fOrginalSum = FindCalculatedSum(n, a, r);
                // Printing details
                PrintDetails(2, fGmFormulaSum, fOrginalSum, n, a, r);
            break;

            case 3:
                n = 100;
                a = 0.0001;
                r = 2.0;
                 // Calculating with formula
                fGmFormulaSum = FindGoemetricSumWithFormula(n, a, r);
                // Calculating with with a loop
                fOrginalSum = FindCalculatedSum(n, a, r);
                // Printing details
                PrintDetails(3, fGmFormulaSum, fOrginalSum, n, a, r);
            break;

            default:
            break;

        }
    }
}

float FindGoemetricSumWithFormula(int n, float a, float r){
    // Calculating using formula
    float fSum = 0.0;
    fSum += (a * (1 - pow(r, n + 1))/ (1 - r));
    return fSum;
}

float FindCalculatedSum(int n, float a, float r){
    float fSum = 0.0;
    int iIndex = 0;
    for (iIndex; iIndex <= n; iIndex++){
        fSum += (a * pow(r, iIndex));
    }
    return fSum;
}

void PrintDetails(int i, float formulaSum, float originalSum, int n, float a, float r){
    // Print function for printing details
    printf("\n===============================| CASE - %d |================================\n", i);
    printf("N               : %d\n", n);
    printf("A               : %f\n", a);
    printf("R               : %f\n", r);
    printf("FORMULA SUM     : %f\n", formulaSum);
    printf("CALCULATED SUM  : %f\n", originalSum);
    printf("DIFFERENCE      : %f",   formulaSum - originalSum);
    printf("\n---------------------------------------------------------------------------");
}

/*
Analysis of the output

    When using float the difference was large for the first and second case. These may be of the additional
    errors introduced by arithmetic operation. So, even if the error in each step is small it get
    accumulated for large computation. The if we use double or long double for the calculated sum the result
    will have more precision and out seems to be more similar for both methods.

    Taking in account of geometric sequence if the r value is grater 1 it diverges. If less than it converges.
    Here, in case 1 and 2 the value of r is more than 1.
*/
