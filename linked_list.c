/***********************************************************************************************
                                         LINKED LIST
************************************************************************************************/

// Including header files required for the program
#include <stdio.h>
#include <stdlib.h>


struct cell{
// Queue
int content;
struct cell *next;
};

// Instead of typing 'struct cell'  we can use cell
typedef struct cell cell;

// Declaring prototypes of functions used
cell* newcell(int n);
cell* push(cell *, int n);
int deallocatelist(cell *);
int countcells(cell *);
int pop(cell *);
void printlist(cell *);
int printlistreverse(cell *);
int sumit(cell *);



// Main function
int main()
{
    printf("******************************| LINKED QUEUES |**********************************\n");

    int n, sum, i, count;
    cell *pCell;
// (b) New cell
    printf("\n==============================");
    printf("\n        STEP 1: NEWCELL       ");
    printf("\n==============================\n");
    pCell = newcell(36);
    printf("\nCell content: %d", pCell -> content);
    printf("\n\n------------------------------\n\n");

// (c) Pushing
    printf("\n==============================");
    printf("\n  STEP 2: PUSH (1, 6, 12, 4)");
    printf("\n==============================\n");
    pCell = push(pCell, 1);
    pCell = push(pCell, 6);
    pCell = push(pCell, 12);
    pCell = push(pCell, 4);
    printf("\nPushed elements successfully");
    printf("\nNumber of cells: %d: ", countcells(pCell));
    printf("\n\n------------------------------\n\n");

//   (f) pop
     printf("\n==============================");
     printf("\n   STEP 3: POP (36)");
     printf("\n==============================\n");
     i = pop(pCell);
     printf("\nPopped the content %d", i);
     printf("\nNumber of cells: %d: ", countcells(pCell));
     printf("\n\n------------------------------\n\n");

//  (e) Count cells
     printf("\n==============================");
     printf("\n     STEP 4: NO: CELLS");
     printf("\n==============================\n");
     printf("\nNumber of cells: %d: ", countcells(pCell));
     printf("\n\n------------------------------\n\n");

//  (h) Reverse print list
     printf("\n==============================");
     printf("\n STEP 5: PRINTING REVERSE LIST");
     printf("\n==============================\n");
     printf("\nReverse list is: ");
     printlistreverse(pCell);
     printf("\n\n------------------------------\n\n");


//  (g) Print List
     printf("\n==============================");
     printf("\n    STEP 6: PRINTING LIST");
     printf("\n==============================\n");
     printf("\nList is: ");
     printlist(pCell);
     printf("\n\n------------------------------\n\n");

//   (i)  Sum
     printf("\n==============================");
     printf("\n        STEP 7: SUM");
     printf("\n==============================\n");
     sum = sumit(pCell);
     printf("\nSum is: %d", sum);
     printf("\n\n------------------------------\n\n");

//  (d) deallocating
     printf("\n==============================");
     printf("\n   STEP 8: DEALLOCATING");
     printf("\n==============================\n");
     count  = deallocatelist(pCell);
     printf("\nNo: of memory(cell) freed: %d", count);
     printf("\n\n------------------------------\n\n");
     exit(0);

     return 0;

}

cell* newcell(int n)
{
    cell * pCell;

    // Allocating memory for one cell
    pCell = (cell*)malloc(sizeof(cell));

    pCell -> content = n;
    pCell -> next = NULL;

    // Returning cell with value n and next=NULL
    return pCell;
}

cell* push(cell *pCell, int n)
{
    cell * newCell;

    // Creating new cell with value n
    newCell = newcell(n);

    // New cells next is assigned with previous cells address
    newCell->next = pCell;

    // returning new cell base address
    return newCell;
}

void printlist(cell *pCell)
{

    if(pCell == NULL)
    {
        printf("QUEUE IS EMPTY");
    }

    else
    {
        // Iterating over list to print the content
        while(pCell != NULL)
        {
            printf("%d ", pCell->content);
            pCell = pCell->next;
        }
    }

}

int printlistreverse(cell *pCell)
{

    if((pCell == NULL))
    {
        return 0;
    }
    // print the list after head node
    // The last node will be at the top of the recursive stack, so printing after the recursive call will give reversed list
    printlistreverse(pCell->next);
    // After everything else is printed, print head
    printf("%d ", pCell->content);

}

int countcells(cell *pCell)
{
    int count = 0;

    // Looping through each cell and counting the cells
    while(pCell != NULL)
    {
        pCell = pCell->next;
        count = count + 1;
    }
    return count;
}

int deallocatelist(cell *pCell)
{
    cell *pTemp;
    int count = 0;

    // Loops through and assigns each cell to a temp cell frees and frees current cell
    // Repeatedly do this till last element is reached.
    while(pCell != NULL)
    {
       pTemp = pCell->next;
       free(pCell);
       pCell = pTemp;
       count =  count + 1;
    }

    return count;
}

int pop(cell *pCell)
{
    cell* pLast;
    cell* pSLast;
    int content;

    // pSLast - to store second last cell
    pSLast = pCell;

    // Returns empty if its empty
    if (pSLast == NULL){
        printf("\n\nQUEUE IS EMPTY");
        return 0;
    }

    // If the passed list has only one cell
    else if (pSLast->next == NULL)
    {
        content = pSLast->content;
        free(pSLast);
    }

    // Looping until second last element
    // Then free the last element
    // Make next of second last element to null

    else
    {
        while (pSLast->next->next != NULL)
        {
            pSLast = pSLast->next;
        }
        pLast = pSLast->next;
        content = pLast->content;
        free(pLast);
        pSLast->next = NULL;
    }

    // Returning content of last element
    return content;
}

int sumit(cell *pCell)
{
    int sum = 0;

    if(pCell == NULL)
       return -1;

    else
    {   // Looping through and summing up the content of each cell
        while(pCell!= NULL)
        {
            sum += pCell->content;
            pCell = pCell->next;
        }
    }
    return sum;
}

