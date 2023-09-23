
/** ***************************************************************************
 * @file
 * @brief contains functions prototypes and header files.
 *****************************************************************************/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

#ifndef __thpe13__H__
#define __thpe13__H__

void printscrn(ostream& out, int &size, int& srows, int& scols);

void fileinput(ifstream& fin);

bool knightrecursive(int**& storage, int size, int nrows,
    int ncols, int number);

void storagecreate(int size, int **&storage);

void touroutputs(ostream& out, int size, int srows,
    int scols, int** storage, bool soln);

void touroutputf(ofstream& out, int size, int srows,
    int scols, int** storage, bool soln, int count2);

void dynamic(int size, int**& storage);

void freeup(int size, int**& storage);


#endif
