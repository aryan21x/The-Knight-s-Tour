/** ***************************************************************************
 * @file
 * @brief contains different functions needed for the program
 *****************************************************************************/

#include "thpe13.h"

/** ***************************************************************************
  * @author Aryan Raval
  *
  * @par Description.
  * This function displays the menu and takes the input choice from the user.
  * It then calls other funcions to solve the knight problem and display it
  * on the screen.
  *
  * @param[in,out] out - ostream to cout on the screen.
  * @param[in,out] size - the size of the chessboard.
  * @param[in,out] srows - the starting row of the knight.
  * @param[in,out] scols - the starting column of the knight.
  *
  *
  * @par Example
  * @verbatim
   printscrn (cout,8,7,7); // is the default way of calling the function
  
    @endverbatim
 *****************************************************************************/


void printscrn(ostream &out,int &size, int &srows, int &scols)
{
    int choice, boardsize, row, col;
    int** storage = nullptr;
    bool soln;

    out << "1) Change board size from " << size << "x" << size << endl;
    out << "2) Change starting location from (" 
        << srows << ", " << scols << ")" << endl;
    out << "3) Exit and solve tour" << endl;
    out << "Enter Choice: ";
    cin >> choice;
    out << endl;

    if (choice == 1)  // checks validity of board size and stores it
    {
        out << "Enter the size of the NxN Board (>3): ";
        cin >> boardsize;
        out << endl;
        if (boardsize < srows || boardsize < scols)
        {
            out << "Board size is invalid" << endl << endl;
            return;
        }
        size = boardsize;
        return;
    }  

    if (choice == 2) // checks the validity of coordinates and stores them
    {
        out << "Enter Starting Coordinates (row, col): ";
        cin >> row;
        cin >> col;
        out << endl;

        if (row > size || col > size)
        {
            out << "Invalid starting coordinates" << endl << endl;
            return;
        }
        srows = row;
        scols = col;
        return;
    }

    if (choice == 3)  // will execute the algorithm and exit
    {
        storagecreate(size,storage);
        soln = knightrecursive(storage, size, srows + 2, scols + 2, 1);
        touroutputs(cout, size, srows, scols, storage, soln);//output to scrn
        freeup(size + 4, storage);
        exit(0);
    }
    else
    {
        cout << "Invalid option" << endl << endl;
        return;
    }
}


/** ***************************************************************************
  * @author Aryan Raval
  *
  * @par Description.
  * This function would take input vaLues from a ifstream file that contains
  * size , row and column in that particular order to solve the knight problem.
  *
  * @param[in,out]  fin - ifstream file opened for input containing tours.
  *
  *
  * @par Example
  * @verbatim
   fileinput(fin);
  
    @endverbatim
 *****************************************************************************/


void fileinput(ifstream& fin)
{
    size_t pos;
    string temp;
    string temp2;
    bool soln = true;
    int count = 1;  // for keeping track of the tour number

    int size = 0, srows = 0, scols = 0;

    int** storage = nullptr;

    ofstream fout;

    fout.open("Solutions.tours", ios::trunc);

    if (!fout.is_open())
    {
        cout << "Unable to open the file: " << "Solutions.tour" << endl;
        exit(0);
    }

    while (getline(fin, temp) && getline(fin,temp2) )
    {
        size = stoi(temp);// stores the size of board

        // stores the starting rows and cols

        pos = temp2.find(" ");
        srows = stoi(temp2.substr(0, pos));
        scols = stoi(temp2.substr(pos + 1));

        if (size == 0)  // if the file has nothing in it
        {
            return;
        }
        storagecreate(size,storage);
        soln = knightrecursive(storage, size, srows + 2, scols + 2, 1);
        touroutputf(fout, size, srows, scols, storage, soln, count);
        count++;
        freeup(size + 4, storage);
    }
}


/** ***************************************************************************
  * @author Aryan Raval
  *
  * @par Description.
  * This function will use the 2D array of storage to print out the solution 
  * of the knight problem to the screen.
  *
  * @param[in,out] out - ostream to ouput on the screen.
  * @param[in]    size - size of the chess board.
  * @param[in] srows - starting row of the knight postiion.
  * @param[in] scols - starining column of the knight position.
  * @param[in] storage - a 2D array to hold the solution.
  * @param[in] soln - a bool value for solution and no solution.
  *
  *
  * @par Example
  * @verbatim
   touroutputs(cout,5,2,2,storage,soln);
   touroutputs(cout,8,7,7,storage,soln);
  
    @endverbatim
 *****************************************************************************/


void touroutputs(ostream& out, int size, int srows,
    int scols, int **storage, bool soln)
{
    int i, j;
    int count = 0; // keeps track of end lines to ouput

    out << "Tour # 1" << endl;
    out << "     " << size << "x" << size << 
        " starting at " << "(" << srows << ", " << scols << ")" << endl;

    if (soln == false)  // no solution case
    {
        out << "     No solutions for this case" << endl;
        out << endl;
    }

    out << "    ";

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (count == size)
            {
                out << endl;
                out << "    ";
                count = 0;
            }
            out << setw(3) << storage[i+2][j+2];
            count++;
        }
    }
    out << endl << endl; // endl at the end
}



/** ***************************************************************************
  * @author Aryan Raval
  *
  * @par Description.
  * This function will use the 2D array of storage to print out the solution
  * of the knight problem to the file.
  *
  * @param[in,out] out - ostream to ouput on the screen.
  * @param[in]    size - size of the chess board.
  * @param[in] srows - starting row of the knight postiion.
  * @param[in] scols - starining column of the knight position.
  * @param[in] storage - a 2D array to hold the solution.
  * @param[in] soln - a bool value for solution and no solution.
  * @param[in] count2 - to keep count of the tour number.
  *
  *
  * @par Example
  * @verbatim
   touroutputf(fout,5,2,2,storage,soln,count2);
   touroutputf(fout,8,7,7,storage,soln,count2);
  
    @endverbatim
 *****************************************************************************/


void touroutputf(ofstream& out, int size, int srows,
    int scols, int** storage, bool soln,int count2)
{
    int i, j;
    int count = 0;

    out << "Tour # " << count2 << endl;
    out << "     " << size << "x" << size <<
        " starting at " << "(" << srows << ", " << scols << ")" << endl;

    if (soln == false)  // no solution case
    {
        out << "     No solutions for this case" << endl;
        out << endl;
        return;
    }

    out << "    ";

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (count == size)
            {
                out << endl;
                out << "    ";
                count = 0;
            }
            out << setw(3) << storage[i + 2][j + 2];
            count++;
        }
    }
    out << endl << endl;
}


/** ***************************************************************************
  * @author Aryan Raval
  *
  * @par Description.
  * This function would fill the 2D array of storage will 0s at the
  * postion of chessboard and -1 beyond the chessboard.
  *
  * @param[in]     size - the size of the chessboard.
  * @param[in,out] storage - a 2D array which is being iniatilised
  *
  * @par Example
  * @verbatim
   storagecreate(5,storage);  // will initialise the 5x5 array to 0s and 1s
   storagecreate(7,storage);  // will initialise the 7x7 array to 0s and 1s
  
    @endverbatim
 *****************************************************************************/


void storagecreate(int size, int **&storage)
{
    int nsize = size + 4, i, j;

    dynamic(nsize, storage); // dynamically allocates a board with boundaries

    for (i = 0; i < size; i++) // initialising the board to 0
    {
        for (j = 0; j < size; j++)
        {
            storage[i + 2][j + 2] = 0;
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < nsize; j++)
        {
            storage[i][j] = -1; //initialising first two rows 
        }
    }
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < nsize; i++)
        {
            storage[i][j] = -1; //initialising last two rows
        }
    }

    for (i = nsize - 1; i > nsize - 3; i--)
    {
        for (j = 0; j < nsize; j++)
        {
            storage[i][j] = -1; //initialising first two coloms
        }
    }
    for (j = nsize - 1; j > nsize - 3; j--)
    {
        for (i = 0; i < nsize; i++)
        {
            storage[i][j] = -1; //initialising last two coloms
        }
    }
}
