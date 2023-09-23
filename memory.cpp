/** ***************************************************************************
 * @file
 * @brief contains functions to dynamically allocate and free up memory
 *****************************************************************************/

#include "thpe13.h"


/** ***************************************************************************
   * @author Aryan Raval
   *
   * @par Description
   * This function dynamically allocates a 2D array to store the solution of
   * the knight porblem.
   *
   * @param[in]     size - (size of the chessboard) + 4 .
   * @param[in,out] storage - a 2D array which is to be dynamically allocated.
   *
   *
   * @par Example
   * @verbatim
    dynamic(5,storage); // creates a 2D array of size 5x5
    dynamic(7,storage); // creates a 2D array of size 7x7  
     @endverbatim
 *****************************************************************************/


void dynamic(int size , int **&storage)
{
    int i;
    storage = new(nothrow) int*[size];  // creates a 1D array

    if (storage == nullptr)
    {
        cout << "Unable to allocate memory" << endl;
        delete[] storage;
        exit(0);
    }

    for (i = 0; i < size; i++)
    {
        storage[i] = new(nothrow) int[size];  // creates a 2D array

        if (storage[i] == nullptr)
        {
            cout << "Unable to allocate memory" << endl;
            freeup(size, storage);
            exit(0);
        }
    }
}


/** ***************************************************************************
   * @author Aryan Raval
   *
   * @par Description
   * This function frees up the dynamically alloted 2D array 
   *
   * @param[in]     size - (size of chessboard) + 4.
   * @param[in,out] storage - a 2D array which is to be freed from memory.
   *
   *
   * @par Example
   * @verbatim
    freeup (5,storage);  // deletes 5x5 2D array from memory
    freeup (7,storage);  // deletes 7x7 2D array from memory
     @endverbatim
 *****************************************************************************/


void freeup(int size, int**& storage)
{
    int i;

    if (storage == nullptr) // checks if its already deleted
    {
        return;
    }

    for (i = 0; i < size; i++)  // deletes and clears memory
    {
        delete[] storage[i]; 
    }
    delete[] storage;
}