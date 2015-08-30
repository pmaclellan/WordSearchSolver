/*
EECE 3326
Lab 3b
10/30/2014

Peter MacLellan
Ben Soper

This header file defines the Grid class, which stores a two dimensional grid
of characters. The characters are read in from a file and then
stored in a matrix object.  The header file also contains the details for a
method which gets the entire matrix to be operated on.
*/

#include <fstream>
#include "d_matrix.h"

using namespace std;

class Grid
{
public:
    Grid(string fileName);
    matrix<char> getLetters();
private:
    matrix<char> letters;
};

// Conctructor
// Takes an input file name and creates a matrix of characters from it
Grid::Grid(string fileName)
{
    ifstream fin(fileName.c_str());
    // handle case where file name is invalid
    if (!fin.good())
    {
        cout << "File not found, program will terminate.\n";
        system("Pause");
        exit(EXIT_FAILURE);
    }

    int rows;
    int cols;

    // read in the number of rows and columns from the top of the grid file
    fin >> rows;
    fin >> cols;

    //resize the matrix to fit the entire grid
    letters.resize(rows, cols);

    // fill the matrix with letters
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fin >> letters[i][j];
        }
    }

    //close the input file
    fin.close();
}

// Returns the matrix of characters that represents a word search
matrix<char> Grid::getLetters()
{
    return letters;
}