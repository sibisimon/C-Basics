/***********************************************************************************************
                                         QUESTION 3
************************************************************************************************/

// Including header files required for the program
#include <stdio.h>

// Declaring prototypes of functions used
double FindDeterminantOf3By3(float [3][3]);
void GenerateHilbertMatrix(float [4][4]);
double FindDeterminantOfHilbertMatrix(float [4][4]);
void GetSubMatrix(float [4][4], float [3][3], int);
void DisplayMatrix(float [4][4]);

// Main function
int main()
{
    printf(" *************************|HILBERT MATRIX AND DETERMINANT|*************************");

    float hilbertMat[4][4];
    double hilbertDeterminant;

    // Generating Hilbert matrix
    GenerateHilbertMatrix(hilbertMat);

    // (d)
    // Displaying Hilbert matrix
    DisplayMatrix(hilbertMat);
    // Determinant of the matrix
    hilbertDeterminant = FindDeterminantOfHilbertMatrix(hilbertMat);

    printf("\n-----------------------------------------------------------------------------------");
    printf("\nDETERMINANT OF HILBERT MATRIX: %e", hilbertDeterminant);
    printf("\n-----------------------------------------------------------------------------------\n\n");


}

// (a)
// Function for finding determinant of a 3 by 3 function
double FindDeterminantOf3By3(float mat[3][3])
{
    double detFinal, detA, detB, detC;
    detA = mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[2][1] * mat[1][2]));
    detB = mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[2][0] * mat[1][2]));
    detC = mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[2][0] * mat[1][1]));

    // Calculating determinant
    detFinal = detA - detB + detC;

    return detFinal;
}

// (b)
// Displaying Hilbert Matrix with the help of nested loops
void GenerateHilbertMatrix(float hilbertMat[4][4])
{
    int row, col;

    for(row=0;row<4;row++)
    {
		for(col=0;col<4;col++)
		{
			hilbertMat[row][col]=(float)1.0/((row+1)+(col+1)-1.0);
		}
	}
}

// (c)
// Calculating determinant of Hilbert matrix
double FindDeterminantOfHilbertMatrix(float hilbertMat[4][4])
{
    float subMatA[3][3], subMatB[3][3], subMatC[3][3], subMatD[3][3];
    double detA, detB, detC, detD, finalDet;

    // Getting four sub matrices from Hilbert matrix
    // Parameters are 1. HilbertMatrix 2. Matrix to store 3. Column to avoid
    GetSubMatrix(hilbertMat, subMatA, 0);
    GetSubMatrix(hilbertMat, subMatB, 1);
    GetSubMatrix(hilbertMat, subMatC, 2);
    GetSubMatrix(hilbertMat, subMatD, 3);

    // Finding determinant of Hilbert matrix
    detA = hilbertMat[0][0] * FindDeterminantOf3By3(subMatA);
    detB = hilbertMat[0][1] * FindDeterminantOf3By3(subMatB);
    detC = hilbertMat[0][2] * FindDeterminantOf3By3(subMatC);
    detD = hilbertMat[0][3] * FindDeterminantOf3By3(subMatD);
    finalDet = detA - detB + detC - detD;

    return finalDet;

}

// Function for generating sub matrix of Hilbert matrix
void GetSubMatrix(float hilbertMat[4][4], float subMat[3][3], int avoidCol)
{
    int sRow=0, sCol=0, row, col;

    for (row = 1; row <= 3; row++)
    {
        for (col = 0; col <= 3; col++)
        {   // Avoiding column
            if (col != avoidCol)
            {
                // Writing sub matrix to passed matrix
                subMat[sRow][sCol++] = hilbertMat[row][col];

                // Incrementing row of sub matrix if max size of col is reached and making col = 0
                if (sCol == 3)
                {
                    sCol = 0;
                    sRow++;
                }
            }
        }
    }
}

// Display method for displaying a 4 * 4 matrix
void DisplayMatrix(float mat[4][4])
{
    int rowCount, columnCount  = 0;
    printf("\n\n--------------------------------- HILBERT MATRIX ----------------------------------\n\n");
    for(rowCount = 0;rowCount <= 3;rowCount++ )
    {
        for(columnCount = 0;columnCount <=3;columnCount++)
        {
            printf(" %-10f ",mat[rowCount][columnCount]);
        }
        printf("\n");
    }
    printf("\n-----------------------------------------------------------------------------------");
}
