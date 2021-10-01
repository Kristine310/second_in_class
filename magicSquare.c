#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int isMagicSquare(int array[3][3])
{
    //Row sums
    int rowSum1 = 0;
    int rowSum2 = 0;
    int rowSum3 = 0;
    for(int row = 0; row < 3; row++)
    {
        rowSum1 = rowSum1 + array[0][row];
        rowSum2 = rowSum2 + array[1][row];
        rowSum3 = rowSum3 + array[2][row];
    }
    //Column sums
    int colSum1 = 0;
    int colSum2 = 0;
    int colSum3 = 0;
    for (int i = 0; i < 3; i++)
    {
        colSum1 = colSum1 + array[i][0];
        colSum2 = colSum2 + array[i][1];
        colSum3 = colSum3 + array[i][2];
    }
    //Diagonal sums
    int diagSum1 = 0;
    int diagSum2 = 0;
    for (int i = 0; i < 3; i++)
    {
        diagSum1 = diagSum1 + array[i][i];
        diagSum2 = diagSum2 + array[i][2-i];
    }
    //Test Rows
    int rowTrue = 0;
    if (rowSum1 == rowSum2)
    {
        if (rowSum1 == rowSum3)
        {
            if (rowSum2 == rowSum3)
                rowTrue = rowSum1;
        }
    }
    //Test columns
    int colTrue = 0;
    if (colSum1 == colSum2)
    {
        if (colSum1 == colSum3)
        {
            if (colSum2 == colSum3)
                colTrue = colSum1;
        }
    }
    //Test diagonals
    int diagTrue = 0;
    if (diagSum1 == diagSum2)
        diagTrue = diagSum1;
    //Test all
    if ((rowTrue > 0) && (colTrue > 0) && (diagTrue > 0))
    {
        if (rowTrue == colTrue)
        {
            if (rowTrue == diagTrue)
            {
                if (colTrue == diagTrue)
                    return 1;
                else
                    return -1;
            }
            else
                return -1;
        }
        else
            return -1;
    }
    else
        return -1;
}

//Create a random 2d array

int main()
{
    int count = 0;
    time_t t;
    srand((unsigned) time(&t));
    int square[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            square[i][j] = 0;
        }
    }

    //Begin loop to find a magic square
    int randRow;
    int randColu;
    int trueSquare = -1;
    int num = 1;
    while (trueSquare == -1)
    {
        //Increment number of times while loop has run by 1
        count++;

        //Create a random square with number 1-9
        do 
        {
            randRow = rand() % 3;
            randColu = rand() % 3;
            if (square[randRow][randColu] == 0)
            {
                square[randRow][randColu] = num;
                num++;
            }
        } while (num <= 9);

        //Test if square is a magic square
        if (isMagicSquare(square) > 0)
        {
            trueSquare = 1;
            for (int row = 0; row < 3; row++)
            {
                for (int column = 0; column < 3; column++)
                {
                    if (column == 0)
                        printf("[%d ", square[row][column]);
                    else if (column == 2)
                        printf("%d]", square[row][column]);
                    else
                        printf("%d ", square[row][column]);
                }
                printf("\n");
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    square[i][j] = 0;
                }
            }
            num = 1;
        }
    }
    //Print out number of times while loop ran
    printf("Number of squares tested: %d\n", count);
    return 0;
}