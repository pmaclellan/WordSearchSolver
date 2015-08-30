/*
EECE 3326
Lab 3b
10/30/2014

Peter MacLellan
Ben Soper

This is tha main file for lab 3b.  It defines functions for searching through
a Grid object and matching its substrings to words in a Dictionary object.
It also defines a binary search algorithm for checking if words are in the
dictionary.  The main function just calls the TestSearch function which asks 
the user to enter an input file.
*/

#include "Dictionary.h"
#include "Grid.h"

using namespace std;

void findMatches(Dictionary&, Grid&);
void printMatches(string, vector<string>&);
string processDirection(Grid&, int, int, int);
void testSearch(Dictionary&);
int binarySearch(vector<string>&, int, int, string);

int main()
{
    Dictionary d("dictionary.txt");
    cout << "Completed reading dictionary\n";

    d.quicksort(0, d.getSize() - 1);

    //print the sorted dictionary
    for (int i = 0; i < d.getSize(); i++)
    {
        cout << d.getWord(i) << endl;
    }
    cout << "\n^^ Sorted Dictionary ^^\n\n";

    //run the word search with the given dictionary
    testSearch(d);

    system("Pause");
    return 0;
}

// finds all of the words in the grid that match words in the dictionary
void findMatches(Dictionary& d, Grid& g)
{
    string fullString;
    vector<string> words = d.getDict();

    for (int r = 0; r < g.getLetters().rows(); r++)
    {
        for (int c = 0; c < g.getLetters().cols(); c++)
        {
            for (int direction = 0; direction < 8; direction++)
            {
                fullString = processDirection(g, r, c, direction);
                printMatches(fullString, words);
            }

        }
    }
}

// helper function to print substrings that match words in
// the dictionary, given a longer string
void printMatches(string temp, vector<string>& words)
{
    for (int i = 5; i <= temp.size(); i++)
    {
        string word = temp.substr(0, i);
        int indexFound = binarySearch(words, 0, words.size(), word);
        if (indexFound >= 0)
        {
            cout << words.at(indexFound) << endl;
        }
    }
}

// helper function to retreive full length strings in a given direction
string processDirection(Grid& g, int startR, int startC, int dir)
{
    int r = startR;
    int c = startC;

    string temp;

    do // while the indices have not reached the starting value again
    {
        temp += g.getLetters()[r][c];
        // increment the column and row indices according to the direction
        //being scanned
        switch (dir)
        {
            /*
            5-6-7
            4---0
            3-2-1
            */
        case 0:
            c++;
            break;
        case 1:
            c++;
            r++;
            break;
        case 2:
            r++;
            break;
        case 3:
            c--;
            r++;
            break;
        case 4:
            c--;
            break;
        case 5:
            c--;
            r--;
            break;
        case 6:
            r--;
            break;
        case 7:
            c++;
            r--;
            break;
        } // end switch block

        // Deal with wrap-around for all directions
        if (c > g.getLetters().cols() - 1)
        {
            c = 0;
        }
        if (r > g.getLetters().rows() - 1)
        {
            r = 0;
        }

        if (c < 0)
        {
            c = g.getLetters().cols() - 1;
        }
        if (r < 0)
        {
            r = g.getLetters().rows() - 1;
        }
    } while (c != startC || r != startR);

    return temp;
}

// Reads in the word search file and findsall matching words in dictionary
void testSearch(Dictionary& d)
{
    string gridFile;

    cout << "Enter the file name for the grid to search:\n";
    cin >> gridFile;

    // "input15.txt"
    Grid g(gridFile);

    findMatches(d, g);
}

//recursively searches through the given dictionary to find the given key value
int binarySearch(vector<string>& words, int first, int last, string key)
{
    if (first > last)
    {
        return -1;
    }
    else
    {
        int mid = floor((last + first) / 2);
        if (mid < 0 || mid >= words.size())
        {
            return -1;
        }
        if (words.at(mid) == key)
        {
            return mid;
        }
        else if (key < words.at(mid))
        {
            return binarySearch(words, first, mid - 1, key);
        }
        else if (key > words.at(mid))
        {
            return binarySearch(words, mid + 1, last, key);
        }
    }
}
