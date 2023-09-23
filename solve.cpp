/** ***************************************************************************
 * @file
 * @brief contains recursive function to solve the given knight problem
 *****************************************************************************/

#include "thpe13.h"


/** ***************************************************************************
    * @author Aryan Raval
    *
    * @par Description
    * A recursive function that finds a solution to a knight visiting every
    * square on a chessboard and stores it in a 2D array.
    *
    * @param[in,out] storage - a dynamically allocated 2D array to store soln.
    * @param[in] size - size of the chessboard.
    * @param[in] nrows - starting postion row of the knight.
    * @param[in] ncols - starting position column of the knight.
    * @param[in] number - the placed number inside storage from 1 to sizexsize.
    *
    * @returns true if successful and false otherwise.
    *
    * @par Example
    * @verbatim
     knghtrecursive (storage,5,2,2,1); // (2,2) starting postion for 5x5 board
     knightrecursive (storage,8,7,6,1); // (7,6) starting position for 8x8 board
      @endverbatim
 *****************************************************************************/

bool knightrecursive(int **&storage, int size, int nrows ,
    int ncols,int number)
{
    int i;

    // decides what step the knight would take next

    int knightx[8] = { -2,-1,1,2,2,1,-1,-2 };
    int knighty[8] = { 1,2,2,1,-1,-2,-2,-1 };

    if (number > size * size)
    {
        return true;  // storage has been filled
    }

    if (storage[nrows][ncols] != 0) //square already occupied or goes beyond
    {
        return false;
    }

    storage[nrows][ncols] = number;  // place the number at the position

    for (i = 0; i < 8; i++) // try all 8 moves for the knight
    {
        if(knightrecursive(storage, size, nrows + knightx[i],
            ncols + knighty[i], number + 1))
        {
            return true; // solution found
        }
    }

    storage[nrows][ncols] = 0;// backtracking
    return false;
}






