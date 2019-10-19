/***********************************************************************************************
                            SORTING - SEARCHING - TIME COMPELXITY CHECK
************************************************************************************************/

// Including header files required for the program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Declaring prototypes of functions used
int * randomarray(int, int);
int median(int, int *);
void mediansort(int, int *, int *, int *);
int search(int, int, int *);
int chopsearch(int, int, int *, int , int);
double benchmark_naive(int, int, int, int);
double benchmark_chop(int, int, int, int);

// Main Function
int main()
{
    int n, max, i, md, s, pos, j;
    int *pArray, cycle=0, *sorted;

    printf("*********************************| SORTING - SEARCHING - TIME COMPELXITY CHECK |*********************************\n");

    // Entering no: of random variable, max range
    printf("\n\nENTER ARRAY SIZE: ");
    scanf("%d", &n);
    printf("\nENTER MAX RANGE: ");
    scanf("%d", &max);
    // pArray = randomarray(n, max);

    // Allocating size for sorted array
    sorted = (int*) malloc(n * sizeof(int));

    // (d) Calling a printing two times with same input
    for(j=1; j <= 2; j++){
        // Setting seed to get the same array
        srand(18201381);
        cycle = 0;
        pArray = randomarray(n, max);
        printf("\n\nCALL - %d  WITH N=%d & MAX=%d", j, n, max);
        printf("\n-------------------------------\n");

        // Printing random array
        printf("\nRANDOM ARRAY\n");
        for (i=0; i<n; i++){
            printf("%d ", *(pArray+i));
        }

        md = median(n, pArray);
        printf("\nMEDIAN: %d", md);
        mediansort(n, &cycle, pArray, sorted);

        // Printing sorted array
        printf("\nSORTED ARRAY\n");
        for (i=0; i<n; i++){
           printf("%d ", *(sorted+i));
        }
        free(pArray);
    }


    // Searching in sorted array
    printf("\n\nENTER ELEMENT TO SEARCH: ");
    scanf("%d", &s);
    pos = search(s, n, sorted);
    printf("\nELEMENT IS AT POS (NORMAL SEARCH): %d", pos);

    pos = chopsearch(s, n, sorted, 0 , n-1);
    printf("\nELEMENT IS AT POS (CHOP): %d", pos);

    printf("\n\n--------------------------------------------- STARTING TESTS -------------------------------------------------");

    // (i)
    printf("\n\nTEST 1 - SEARCH ELEMENT - 10 | ITERATIONS - 1000000 | NO: OF RANDOM - 2000 | MAX RANGE - 10000 [RUNNING]\n\n");
    printf("TIME(SECONDS) CHOP : %lf", benchmark_chop(2000, 10000, 10, 1000000));
    printf("\nTIME(SECONDS) NAIVE: %lf", benchmark_naive(2000, 10000, 10, 1000000));
    printf("\n\nTEST 2 - SEARCH ELEMENT - 5000 | ITERATIONS - 1000000 | NO: OF RANDOM - 2000 | MAX RANGE - 10000 [RUNNING]\n\n");
    printf("TIME(SECONDS) CHOP : %lf", benchmark_chop(2000, 10000, 5000, 1000000));
    printf("\nTIME(SECONDS) NAIVE: %lf", benchmark_naive(2000, 10000, 5000, 1000000));
    printf("\n\nTEST 3 - SEARCH ELEMENT - 9000 | ITERATIONS - 1000000 | NO: OF RANDOM - 2000 | MAX RANGE - 10000 [RUNNING]\n\n");
    printf("TIME(SECONDS) CHOP : %lf\n", benchmark_chop(2000, 10000, 9000, 1000000));
    printf("\nTIME(SECONDS) NAIVE: %lf", benchmark_naive(2000, 10000, 9000, 1000000));
}

// (a)
int * randomarray(int n, int max)
{
    int *pArray, i, min=0;
    pArray = (int*) malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
       *(pArray + i) = ((int) rand()%(max+1-min))+min;
    }
    return pArray;
}

// (b)
int median(int n, int *pArray)
{
    int k, rightCount=0, leftCount=0, equalCount, equal=0, md, t, repPlusLeft, i, j;

    // Finding index of median
    k = ceil((float) n/2);

    // If array size is 1 return array element
    if (n == 1)
        return *pArray;

    // Loop for finding median
    for (i=0; i<n; i++){
        rightCount = 0;
        leftCount = 0;
        equal=0;
        repPlusLeft = 0;
        for (j=0; j<n; j++){
            // Calculating left right and equal count
            if (*(pArray + i)  < *(pArray + j))
                rightCount++;
            else if (*(pArray + i) > *(pArray + j))
                leftCount++;
            else
                equal++;
            // breaks the inner loop if right count > k or leftCount >=k, in these cases current element can't be the median
            if (rightCount > k || leftCount >= k ){
                break;
            }
        }
        // Reducing equal by one (checked with itself)
        if(equal){
            equal = equal - 1;
        }
        // If the equal count is greater than median index then it is the median
        if (equal >= k){
            md = *(pArray + i);
            break;
        }

        // Variable to handle the equal repeated elements
        repPlusLeft = equal + (leftCount + 1);

        // if the array size is even, leftCount should be k-1 also checking if leftCount+equal>middle value in both cases it is the median
        if((n%2 == 0 && leftCount == k - 1) ||(leftCount < k && repPlusLeft >= k)){
            md = *(pArray + i);
            break;
        }
        // if the array size is odd, leftCount == rightCount also checking if leftCount+equal>middle value in both cases it is the median
        if((n%2 != 0 && leftCount == rightCount) || (leftCount < k && repPlusLeft >= k)){
            md = *(pArray + i);
            break;
        }

        // Extra conditions to skip some elements from iterating
        // If leftCount < median index then elements less than current value can't be the median
        // So checking the next adjusting number is less then we skip that element
        if(leftCount < k && (*(pArray + i + 1) < *(pArray + i))){
            i = i + 1;
        }
        // Extra conditions to skip some elements from iterating
        // If leftCount > median index then elements greater than current value can't be the median
        // So checking the next adjusting number is greater then we skip that element
        if(leftCount > k && (*(pArray + i + 1) > *(pArray + i))){
            i = i + 1;
        }
    }
    return md;
}

// (c)
void mediansort(int n, int *cycle, int *arr, int *sorted){

     int k, md=0, pos, i, c, l = 0, ind, mulVal;

     // Middle value index
     k = ceil((float) (n + *cycle)/2);

     // Return from function if n < 1
     if (n < 1)
        return;

     // Calling median function
     md = median(n, arr);

     // Finding the position of median and updating arr

     for(i=0; i < n; i++)
     {
        if(arr[i] == md ){
            pos = i;
            break;
        }
     }
     for(i=pos; i < n-1; i++)
        arr[i] = arr[i+1];
     arr[n-1] = 0;

     // Condition for even array
     if ((n + *cycle) % 2 == 0){
         // Generating index for updating
         ind = pow(-1, *cycle + 1) * ceil((float) *cycle/2);
         *(sorted + (k-1) + ind) = md;
     }
     else{
         // Generating index for odd
         ind = pow(-1, *cycle) * ceil((float) *cycle/2);
         *(sorted + (k-1) + ind) = md;
     }
     *cycle = *cycle + 1;

     mediansort(n - 1, cycle, arr, sorted);

}

// (e)
int search(int i, int n, int *arr){

    int index, pos = -1;

    // Looping through array
    // Breaking the loop if we found the item
    // Breaking the loop if the array element is grater than search element
    for (index=0; index < n; index++){
        if (*(arr + index) == i){
            pos = index + 1;
            break;
        }
        else if(*(arr + index) > i){
            break;
        }
    }

    // Returning position
    return pos;
}

// (f)
int chopsearch(int i, int n, int *arr, int amin, int amax){

    int index, pos = -1, randIndex;

    // Randomly generating random index between min and max
    randIndex = ((int) rand()%(amax + 1 - amin)) + amin;

    if (amax < amin)
        return -1;

    // Recursively calling chop search if i < rand index
    // Returning from function if left hand side empty
    if (i < *(arr + randIndex)){
        if ((randIndex - 1) < amin)
            return -1;
        chopsearch(i, n, arr, amin, randIndex - 1);
    }

    // Recursively calling chop search if i > rand index
    // Returning from function if right hand side empty
    else if(i > *(arr + randIndex)){
        if ((randIndex + 1) > amax)
            return -1;
        chopsearch(i, n, arr, randIndex + 1, amax);
    }

    // Finding the least position
    else if(i == *(arr + randIndex)){
        for(index=amin; amin <= randIndex; index++){
            if (i == *(arr + index)){
                pos = index + 1;
                return pos;
            }
        }
    }

}

// (g)
double benchmark_naive(int n, int max, int s, int mult)
{
    int i, *arr, *sorted, cycle=0;

    clock_t start, end;
    double timeUsed;

    // Allocating size for sorted array
    sorted = (int*) malloc(n * sizeof(int));

    // Starting clock
    start = clock();

    // Calling randomarray, mediansort, normal search
    for (i=0; i<mult; i++){
        // Median and median sort is taking too much time
        // The random array generation and mediansort is limited to 10 times
        if(i%100000 == 0){
            cycle=0;
            // Array is changing each time randomarray() is called, hence srand(time(NULL)) not given
            arr = randomarray(n, max);
            mediansort(n, &cycle, arr, sorted);
            free(arr);
        }
        search(s, n, sorted);
    }

    end = clock();

    // Calculating time used
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Free allocated memory
    free(sorted);

    return timeUsed;
}


// (h)
double benchmark_chop(int n, int max, int s, int mult)
{
    int i, *arr, *sorted, cycle=0;

    clock_t start, end;
    double timeUsed;

    // Allocating memory
    sorted = (int*) malloc(n * sizeof(int));

    // Starting clock
    start = clock();

    // Calling randomarray, mediansort, normal search
    for (i=0; i<mult; i++){
         // Median and median sort is taking too much time
        // The random array generation and mediansort is limited to 10 times
        if(i%100000 == 0){
            cycle=0;
            // Array is changing each time randomarray() is called, hence srand(time(NULL)) not given
            arr = randomarray(n, max);
            mediansort(n, &cycle, arr, sorted);
            free(arr);
        }
        chopsearch(s, n, sorted, 0, n-1);
    }

    // End clock
    end = clock();

    // Calculating time used
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;

     // Free allocated memory
    free(sorted);

    return timeUsed;
}


// (i) Analysis of the result

/*
  MEDIAN ()
  ---------
  The performance of median function is very poor, since it has two nested loops both running 0 to length of array - 1.
  So, if the length of array is large, it will take more time to find median. Time complexity of this function is in Big O notation is
  O(n^2) (worst case).
  Best Case:  Median is found at the first position of the random array
  Average Case: Median is found at the middle position of the random array
  Worst Case:  Median is found at the last position of the random array

  MEDIANSORT ()
  -------------

  A recursive function is implemented for finding the sorted array. But a recursive function will not give any significant time boost
  comparing with the for loop. So median sort itself is time consuming and also it's calling the median function from it which makes
  the situation even worser. So, complexity will be O(n^2) and O(n^2)(median).

  SEARCH ()
  ------------

  In Search logic, it runs through the array till the match is found so the time complexity is O(n)(worst case).
  Best Case:  Search element is found at the first position of the random array O(1)
  Average Case: Search element is found at the middle position of the random array O(n/2)
  Worst Case:  Search element is found at the last position of the random array O(n)

  CHOPSEARCH ()
  -------------

  Chop search is a recursive function which perform search in array between two index. That is in all case time complexity will be O(log n).


  TEST RESULTS
  ------------
  TEST 1 - SEARCH ELEMENT - 10 | ITERATIONS - 10000 | NO: OF RANDOM - 2000 | MAX RANGE - 10000 [RUNNING]

  TIME(SECONDS) CHOP : 73.160000
  TIME(SECONDS) NAIVE: 73.010000

  TEST 2 - SEARCH ELEMENT - 5000 | ITERATIONS - 10000 | NO: OF RANDOM - 2000 | MAX RANGE - 1000000 [RUNNING]

  TIME(SECONDS) CHOP : 73.270000
  TIME(SECONDS) NAIVE: 78.480000

  TEST 3 - SEARCH ELEMENT - 9000 | ITERATIONS - 10000 | NO: OF RANDOM - 2000 | MAX RANGE - 1000000 [RUNNING]

  TIME(SECONDS) CHOP : 73.940000
  TIME(SECONDS) NAIVE: 83.130000

  The First test (10) results indicates time taken for naive and chop are similar since 10 is in the start of the array. But the
  difference increases for second test (5000) and naive search takes more time. And the worst case for naive is when search element is 9000.
  The time complexity for chop is almost dame all case.

*/
