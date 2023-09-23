#include "thpe13.h"

/** ***************************************************************************
 * @file
 * @brief Contains function main and the execution of the program.w
 *****************************************************************************/


 /** **************************************************************************
  * @mainpage Program 3 - The Knight's Tour
  *
  * @section course_section Course Information
  *
  * @author Aryan Raval
  *
  * @par Professor:
  *         Roger Schrader
  *
  * @par Course:
  *         CSC215 - Programming techniques
  *
  * @par Location:
  *         McLaury - 306
  *
  * @date Due April 24, 2023
  *
  * @section program_section Program Information
  *
  * @details
  * 
  * The program either takes one or two arguements as input. If only one 
  * arguement is supplied then the program opens up a interface with 3 
  * different choices for the user. The user can either change the default 
  * size of the board(8) by choosing option 1 or change the default starting
  * row(7) and colum(7) by chossing option 2. Option 3 will use the values and 
  * find a solution in which a knight starts at the given row and colum,
  * and visits every square on a given size x size chess board onece.
  * Option 3 will also exit the program.
  * 
  * 
  * If a file is supplied as a second arguement with values caontianing 
  * size, rows and colums in that particular order. Then the program uses 
  * this values to create multiple solutions while naming them starting from
  * number 1. Each tour will show how a knight visits every square on a
  * given size x size chessboard from particular starting position. After all
  * the tours are solved the program will exit.
  * 
  * 
  * The program uses a recursive algorithm  and dynamic memory allocation
  * to find the solution to the knight probem. The soltuion is either printed 
  * out on screen or a file depending on the number of arguement supplied while
  * starting the program.
  *
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *      none - a straight compile and link with no external libraries.
  *
  * @par Usage:
    @verbatim
    thpe13.exe [tourfile]
    tourfile - name of a text file containing puzzles for the knight's tour
    @endverbatim
  *
  * @section todo_bugs_modification_section Todo, Bugs, and Modifications
  *
  * @bug To my best knowledge there are no bugs.
  *
  * @par Modifications and Development Timeline:
  * https://gitlab.cse.sdsmt.edu/101125506/csc215s23programs/-/commits/main?ref_type=heads
  *
  *****************************************************************************/


/** ***************************************************************************
   * @author Aryan Raval
   *
   * @par Description
   * The following is the function main that calls other functions to
   * execute the program.
   *
   * @param[in]    argc - the total number of arguements supplied.
   * @param[in]    argv - the array containing arguements supplied.
   *
   * @returns 0 if successful 
   *
   * @par Example
   * @verbatim
     thpe13.exe tourfile   // main supplied with two arguements
     thpe13.exe    // main supplied with only one arguement
     
     @endverbatim
 *****************************************************************************/


int main(int argc,char **argv)
{
    ifstream fin;

    bool keepGoing = true;
    int size = 8, srows = 7, scols = 7;

    if (argc != 2 && argc != 1)   // invalid arguements check
    {
        cout << "Usage: thpe13.exe [tourfile]" << endl;
        cout << "       tourfile - name of a text file containing "
             << "puzzles for the knight's tour" << endl;
        exit(0);
    }

    if (argc == 2)   // if a file is supplied as a arguement
    {
        fin.open(argv[1]);
        if (!fin.is_open())
        {
            cout << "Unable to open the file: " << argv[1] << endl;
            exit(0);
        }

        fileinput(fin);   //calls a function that takes input from file
    }

    else     // if no file is supplied as arguement
    {
        while (keepGoing)
        {
            printscrn(cout, size, srows, scols); // displays the menu
        }
    }
    return 0;
}
