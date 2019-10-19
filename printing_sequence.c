/***********************************************************************************************
                                         PRINTING SEQUENCE
************************************************************************************************/

// Including header files required for the program
#include <stdio.h>

// Defining max input value for the program
#define MAX_VALUE 99999999

// Declaring function prototypes
int ReadVariable(void);
void PrintSequence(int);
int GetTotalDigits(int);
void ClearScanfBuffer (void);


// Main function
int main()
{
    int iNum    = 0;
    char cCont  = 'y';

    printf(" *************************|Printing N/2 or 3N + 1 Sequence|*************************");

    // Loop for re-running the program
    while(cCont == 'y'|| cCont == 'Y')
    {
        // Function for getting user input data
        printf("\n\nEnter the Number (N): ");
        iNum = ReadVariable();

        // Function for printing the sequence
        PrintSequence(iNum);

        printf("\n\nDo You Wish To Continue..Press(Y/y) or Press Any Key To Exit: ");
        scanf(" %c",&cCont);
    }
    return 0;
}

int ReadVariable(int nlimit, int even)
{
    int dtatus = 0;
    int num    = 0;

    iStatus = scanf("%d",&num);

    if (nlimit == 1){

    }
    if (even == 1){

    }
    else{

    }

    // Repeating until a valid input is given
    // Conditions checked is a valid integer positive integer with in a range
    while((1 != iStatus) || (iNum < 1) || (iNum > MAX_VALUE))
    {
        ClearScanfBuffer();
        printf("Enter A Valid Positive Integer (1 - 99999999): ");
        iStatus = scanf(" %d",&iNum);
    }

    // Returning the input number
    return iNum;
}

void PrintSequence(int iNum){

    int iIndex = 0, iLastSeq1 = 4, iLastSeq2 = 2, iLastSeq3 = 1, iCount = 0, iTotalLineCharacter = 0;

    printf("\n============================>>>>>>> | Sequence | <<<<<<<<===========================\n\n");

    // Loop exist when the count = 3, it will be only when the sequence 4, 2, 1 occurred
    while(iCount != 3){

        // Check for initially printing and adding number of digits
        if (iIndex == 0){
            printf("%d, ", iNum);
            iTotalLineCharacter += GetTotalDigits(iNum) + 2;
        }

        // Count increments if n==4
        if (iNum == iLastSeq1)
            iCount++;

        // Logic for calculating sequence if the number is odd 3n + 1 else n/2
        if (iNum % 2 == 0){
            iNum = iNum / 2;
        }
        else{
            iNum = (iNum * 3 ) + 1;
        }

        // Incrementing count if the sequences matches 2, 1 and count 1 and 2 respectively
        if ((iNum == iLastSeq2) && iCount == 1)
            iCount++;
        if ((iNum == iLastSeq3) && iCount == 2)
            iCount++;

        // Checking if the line count greater than 40, if greater printing after line break else printing on the same line
        if ((GetTotalDigits(iNum) + iTotalLineCharacter + 1) > 40){
            printf("\n");
            iTotalLineCharacter = 0;
            printf("%d, ", iNum);
        }

        else{
            printf("%d, ", iNum);
        }

        // Updating line character count
        iTotalLineCharacter += GetTotalDigits(iNum) + 2;
        // Incrementing the loop counter
        iIndex++;

    }
    printf("\n\n====================================================================================\n\n");
}

int GetTotalDigits(int num){
    /*Function for counting number of digits in the number*/
    int iTotalDigits = 0;
    while(num!=0){
        num = num/10;
        iTotalDigits ++;
    }
    return iTotalDigits;
}

void ClearScanfBuffer(void)
{
  /*Clearing scanf buffer to read new values else it will try to
  read from the initial wrong value and will produce all wrong*/

  while ( getchar() != '\n' );
}
