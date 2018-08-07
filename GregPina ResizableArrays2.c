//
//  main.c
//  Resizable Arrays
//
//  Created by Gregory Pina on 8/1/18.
//  Copyright © 2018 Gregory Pina. All rights reserved.
//

// --------------------------------------------------------------------------------
// Name: Greg Pina
// Class: SET-151 C1
// Abstract: Resizable Arrays
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
// Part 1
void MakeArray( int** ppaintValues, int* pintArraySize );
void InitializeArray( int* paintValues, int intArraySize );
void PopulateArray( int* paintValues, int intArraySize );
void PrintArray( char* pstrTitle, int* paintValues, int intArraySize );
int FindArrayMaximum( int* paintValues, int intArraySize );
int FindArrayMinimum( int* paintValues, int intArraySize );
int CalculateArrayTotal( int* paintValues, int intArraySize );
int CalculateArrayAverage( int* paintValues, int intArraySize );
void AddValueToEnd( int** ppaintValues, int* pintArraySize, int intValueToAdd );
void AddValueToFront( int** ppaintValues, int* pintArraySize, int intValueToAdd );
void InsertValueAtMiddle( int** ppaintValues, int* pintArraySize, int intValueToInsert, int intInsertAtIndex );
void RemoveValueAtMiddle( int** ppaintValues, int* pintArraySize, int intRemoveAtIndex );
double CalculateStandartDeviation( int* paintValues, int intArraySize );
void DeleteArray( int** ppaintValues, int* pintArraySize );

// --------------------------------------------------------------------------------
//    Name: Main
//    Abstract: This is where the program starts
// --------------------------------------------------------------------------------
int main( )
{
    int intArraySize = 0;
    int* paintValues = 0;
    int intResult = 0;
    double dblStandardDeviation = 0;
    int intValueToAdd = 0;
    int intValueToInsert = 0;
    int intInsertAtIndex = 0;
    int intRemoveAtIndex = 0;
    
    
    // Make array
    MakeArray( &paintValues, &intArraySize );
    
    // Initialize array
    InitializeArray( paintValues, intArraySize );
    
    // Populate array
    PopulateArray( paintValues, intArraySize );
    
    // Print array
    PrintArray( "Print ----------", paintValues, intArraySize );
    
    // Array Maximum
    intResult = FindArrayMaximum( paintValues, intArraySize );
    printf( "Maximum = %d\n\n", intResult );
    printf( "\n" );
    
    // Array Minimum
    intResult = FindArrayMinimum( paintValues, intArraySize );
    printf( "Minimum = %d\n\n", intResult );
    printf( "\n" );
    
    // Array Total
    intResult = CalculateArrayTotal( paintValues, intArraySize );
    printf( "Total = %d\n\n", intResult );
    printf( "\n" );
    
    // Array Average
    intResult = CalculateArrayAverage( paintValues, intArraySize );
    printf( "Average = %d\n\n", intResult );
    printf( "\n" );
    
    // Standard Deviation
    dblStandardDeviation = CalculateStandartDeviation( paintValues, intArraySize );
    printf( "Standard Deviation = %lf\n\n", dblStandardDeviation );
    printf( "\n" );
    
    //Add a value to the end of an array
    AddValueToEnd( &paintValues, &intArraySize, intValueToAdd );
    PrintArray( "New Array after value added to the end: \n\n", paintValues, intArraySize);
    
    //Add a value to the front of an array
    AddValueToFront( &paintValues, &intArraySize,  intValueToAdd );
    PrintArray( "New Array after value added to the front: \n\n", paintValues, intArraySize);
    
    //Insert a value to the middle of the array
    InsertValueAtMiddle( &paintValues, &intArraySize, intValueToInsert, intInsertAtIndex );
    PrintArray( "New Array with value inserted in the middle: \n\n", paintValues, intArraySize);
    
    //Remove a value in the middle of an array
    RemoveValueAtMiddle( &paintValues, &intArraySize, intRemoveAtIndex );
    PrintArray( "New Array with value removed from the middle: \n\n", paintValues, intArraySize);
    
    // Clean up
    DeleteArray( &paintValues, &intArraySize );
    
    system( "pause" );
    
}

// --------------------------------------------------------------------------------
//    Name: MakeArray
//    Abstract: Allocate space for the array
// --------------------------------------------------------------------------------
void MakeArray( int** ppaintValues, int* pintArraySize )
{
    // Get size from user (1-100,000)
    do
    {
        printf( "Enter array size?" );
        scanf( "%d", pintArraySize );
    } while( *pintArraySize < 1 || *pintArraySize > 100000 );
    
    // Create array dynamically
    *ppaintValues = (int*) malloc( sizeof(int) * *pintArraySize );
}


// --------------------------------------------------------------------------------
//    Name: InitializeArray
//    Abstract: Set all values to zero.
// --------------------------------------------------------------------------------
void InitializeArray( int* paintValues, int intArraySize )
{
    int intIndex = 0;
    
    // Initialize array
    for( intIndex = 0; intIndex < intArraySize; intIndex += 1 )
    {
        *( paintValues + intIndex ) = 0;
    }
    
}


// --------------------------------------------------------------------------------
//    Name: PopulateArray
//    Abstract: Populate with values read from the user.
// --------------------------------------------------------------------------------
void PopulateArray( int* paintValues, int intArraySize )
{
    int intIndex = 0;
    
    // Populate array
    printf( "Populate ----------\n" );
    for( intIndex = 0; intIndex < intArraySize; intIndex += 1 )
    {
        printf( "Enter value[ %d ]:", intIndex );
        scanf( "%d", ( paintValues + intIndex ) );
    }
    printf( "\n" );
}


// --------------------------------------------------------------------------------
//    Name: PrintArray
//    Abstract: Print all the values in the array.
// --------------------------------------------------------------------------------
void PrintArray( char* pstrTitle, int* paintValues, int intArraySize )
{
    int intIndex = 0;
    
    printf( "%s\n", pstrTitle );
    for( intIndex = 0; intIndex < intArraySize; intIndex += 1 )
    {
        printf( "Value[ %d ] = %d\n", intIndex, *( paintValues + intIndex ) );
    }
    printf( "\n" );
}


// --------------------------------------------------------------------------------
//    Name: FindArrayMaximum
//    Abstract: Find the largest value in the array
// --------------------------------------------------------------------------------
int FindArrayMaximum( int* paintValues, int intArraySize )
{
    int intIndex = 0;
    int intMaximumValue = 0;
    
    // Default to first array element
    intMaximumValue = *( paintValues + 0 );
    
    // Check each element
    for( intIndex = 0; intIndex < intArraySize; intIndex += 1 )
    {
        // Is larger?
        if( intMaximumValue < *( paintValues + intIndex ) )
        {
            // Yes, save it
            intMaximumValue = *( paintValues + intIndex );
        }
    }
    
    return intMaximumValue;
}



// --------------------------------------------------------------------------------
//    Name: FindArrayMinimum
//    Abstract: Find the smallest value in the array
// --------------------------------------------------------------------------------
int FindArrayMinimum( int* paintValues, int intArraySize )
{
    int intIndex = 0;
    int intMinimumValue = 0;
    
    // Default to first array element
    intMinimumValue = *( paintValues + 0 );
    
    // Check each element
    for( intIndex = 0; intIndex < intArraySize; intIndex += 1 )
    {
        // Is smaller?
        if( intMinimumValue > *( paintValues + intIndex ) )
        {
            // Yes, save it
            intMinimumValue = *( paintValues + intIndex );
        }
    }
    
    return intMinimumValue;
}



// --------------------------------------------------------------------------------
//    Name: CalculateArrayTotal
//    Abstract: Add all the values in the array and return the total.
// --------------------------------------------------------------------------------
int CalculateArrayTotal( int* paintValues, int intArraySize )
{
    int intIndex = 0;
    int intTotal = 0;
    
    // Calculate Total
    for( intIndex = 0; intIndex < intArraySize; intIndex += 1 )
    {
        intTotal += *( paintValues + intIndex );
    }
    
    return intTotal;
}


// --------------------------------------------------------------------------------
//    Name: CalculateArrayAverage
//    Abstract: Calculate the average array value
// --------------------------------------------------------------------------------
int CalculateArrayAverage( int* paintValues, int intArraySize )
{
    int intTotal = 0;
    int intAverage = 0;
    
    intTotal = CalculateArrayTotal( paintValues, intArraySize );
    
    intAverage = intTotal / intArraySize;
    
    return intAverage;
}


// --------------------------------------------------------------------------------
// Name: CalculateStandartDeviation
// Abstract:Calculate standart deviation
//  The formula is Q=((SUM(X-Xave) ^2) / n) ^ 1/2
//  which can be implemented using the following steps:
//    1) Find the average(mean) value in the list
//    2) For each number in the array, substract the average(mean) and square the result
//  3) Sum the results from step #2
//  4) Calculate the average for the results in step #3
//  5) Take the square root of step #4
// --------------------------------------------------------------------------------
double CalculateStandartDeviation( int* paintValues, int intArraySize )
{
    double dblStandardDeviation = 0;
    double dblAverage = 0;
    int intIndex = 0;
    double dblDifference = 0;
    double dblDifferenceSquared = 0;
    double dblSumOfDifferencesSquared = 0;
    double dblAverageDifference = 0;
    
    // Step #1: Average
    dblAverage = CalculateArrayAverage( paintValues, intArraySize );
    
    // Step #2 and 3: Difference and Sum
    for( intIndex = 0; intIndex < intArraySize; intIndex += 1 )
    {
        // Step #2: difference squared
        dblDifference = *( paintValues + intIndex ) - dblAverage;
        dblDifferenceSquared = pow( dblDifference , 2.0 );
        
        // Step #3: Sum of differences squared
        dblSumOfDifferencesSquared += ( dblDifferenceSquared );
    }
    
    // Step #4: Average Difference
    dblAverageDifference = dblSumOfDifferencesSquared / intArraySize;
    
    // Step #5: Yeah!  Standard Deviation
    dblStandardDeviation = sqrt(dblAverageDifference);
    
    return dblStandardDeviation;
}

// --------------------------------------------------------------------------------
//    Name: AddValueToEnd
//    Abstract: Adds a value to end of array and prints out new array.
// --------------------------------------------------------------------------------
void AddValueToEnd( int** ppaintValues, int* pintArraySize, int intValueToAdd)
{
    int intNewSize = 0;
    int* paintNewValues = 0;
    int intIndex = 0;
    
    printf("What value would you like to add to the array?\n\n");
    scanf("%d", &intValueToAdd);
    
    //Allocate block of memory size + 1
    intNewSize = *pintArraySize + 1;
    paintNewValues = (int*) malloc( sizeof (int) * intNewSize );
    
    //Copy all the values from the old array into the new array
    for( intIndex = 0; intIndex < *pintArraySize; intIndex += 1)
    {
        *( paintNewValues + intIndex ) = *( *ppaintValues + intIndex );
    }
    
    //Set the last array element value
    *( paintNewValues + intIndex ) = intValueToAdd;
    
    //Delete old array
    free( *ppaintValues );
    *ppaintValues = 0;
    
    //Assign pointer to new array variable passed in
    *ppaintValues = paintNewValues;
    *pintArraySize += 1;
    
}

// --------------------------------------------------------------------------------
//    Name: AddValueToFront
//    Abstract: Adds a value to front of array and prints out new array.
// --------------------------------------------------------------------------------
void AddValueToFront( int** ppaintValues, int* pintArraySize, int intValueToAdd )
{
    int intNewSize = 0;
    int* paintNewValues = 0;
    int intIndex = 0;
    
    printf("What value would you like to add to the array?\n\n");
    scanf("%d", &intValueToAdd);
    
    //Allocate block of memory size + 1
    intNewSize = *pintArraySize + 1;
    paintNewValues = (int*) malloc( sizeof (int) * intNewSize );
    
    //Set the first array element value
    *( paintNewValues + 0 ) = intValueToAdd;
    
    //Copy all the values from the old array into the new array
    for( intIndex = 0; intIndex < *pintArraySize; intIndex += 1)
    {
        *( paintNewValues + intIndex + 1 ) = *( *ppaintValues + intIndex );
    }
    
    
    
    //Delete old array
    free( *ppaintValues );
    *ppaintValues = 0;
    
    //Assign pointer to new array variable passed in
    *ppaintValues = paintNewValues;
    *pintArraySize += 1;
    
}

// --------------------------------------------------------------------------------
//    Name: Insert Value At Middle
//    Abstract: Adds a value to array and prints out new array.
// --------------------------------------------------------------------------------
void InsertValueAtMiddle( int** ppaintValues, int* pintArraySize, int intValueToInsert, int intInsertAtIndex )
{
    int intNewSize = 0;
    int* paintNewValues = 0;
    int intIndex = 0;
    
    printf("What value would you like to add to the array?\n\n");
    scanf("%d", &intValueToInsert);
    
    printf("What position would you like the value to be @?\n\n");
    scanf("%d", &intInsertAtIndex);
    
    //Boundary check insert at index
    if( intInsertAtIndex <              0 ) intInsertAtIndex = 0;
    if( intInsertAtIndex > *pintArraySize ) intInsertAtIndex = *pintArraySize;
    
    //Allocate block of memory size + 1
    intNewSize = *pintArraySize + 1;
    paintNewValues = (int*) malloc( sizeof (int) * intNewSize );
    
    //Copy old values into new array up to insertat
    for( intIndex = 0; intIndex < intInsertAtIndex; intIndex += 1)
    {
        *( paintNewValues + intIndex ) = *( *ppaintValues + intIndex );
    }
    
    //insert value
    *( paintNewValues + intIndex ) = intValueToInsert;

    
    //Copy old values from insert point to the end
    for( intIndex = intInsertAtIndex; intIndex < *pintArraySize; intIndex += 1)
    {
        *( paintNewValues + intIndex + 1 ) = *( *ppaintValues + intIndex );
    }
    
    //Delete old array
    free( *ppaintValues );
    *ppaintValues = 0;
    
    //Assign pointer to new array to the variable passed in
    *ppaintValues = paintNewValues;
    *pintArraySize += 1;

    
}
// --------------------------------------------------------------------------------
//    Name: Remove Value At Middle
//    Abstract: Removes a value of array and prints out new array.
// --------------------------------------------------------------------------------
void RemoveValueAtMiddle( int** ppaintValues, int* pintArraySize, int intRemoveAtIndex )
{
    int intNewSize = 0;
    int* paintNewValues = 0;
    int intIndex = 0;
    
    printf("What position would you like the value to be @?\n\n");
    scanf("%d", &intRemoveAtIndex);
    
    //Boundary check insert at index
    if( intRemoveAtIndex <                  0 ) intRemoveAtIndex = 0;
    if( intRemoveAtIndex > *pintArraySize  - 1) intRemoveAtIndex = *pintArraySize - 1;
    
    //Allocate block of memory size - 1
    intNewSize = *pintArraySize - 1;
    paintNewValues = (int*) malloc( sizeof (int) * intNewSize );
    
    //Copy old values into new array up to removeat
    for( intIndex = 0; intIndex < intRemoveAtIndex; intIndex += 1)
    {
        *( paintNewValues + intIndex ) = *( *ppaintValues + intIndex );
    }
    
    //Copy old values from remove point to the end
    for( intIndex = intRemoveAtIndex + 1; intIndex < *pintArraySize; intIndex += 1)
    {
        *( paintNewValues + intIndex - 1 ) = *( *ppaintValues + intIndex );
    }
    
    //Delete old array
    free( *ppaintValues );
    *ppaintValues = 0;
    
    //Assign pointer to new array to the variable passed in
    *ppaintValues = paintNewValues;
    *pintArraySize -= 1;
}

// --------------------------------------------------------------------------------
//    Name: DeleteArray
//    Abstract: Free the memory and set pointer and size to zero.
// --------------------------------------------------------------------------------
void DeleteArray( int** ppaintValues, int* pintArraySize )
{
    // Delete array and fold the knife
    free( *ppaintValues );
    *ppaintValues = 0;
    
    *pintArraySize = 0;
}

