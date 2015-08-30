/*
EECE 3326
Lab 3b
10/30/2014

Peter MacLellan
Ben Soper

This header file defines the Dictionary class, which stores a dictionary of
words to be searched for in a grid of characters.  These words are read from
a file and stored in an arbitrarily long vector.  The file also defines
methods for getting a word from the dictionary as well as the size of the
dictionary.  Additionally, the file also declares implementations for selection
sort and quicksort.
*/

#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Dictionary
{
public:
    Dictionary(string fileName);
    string getWord(int index);
    int getSize();
    vector<string> getDict();
    void selectionSort(int first, int last);
    void quicksort(int first, int last);
    int partition(int lower, int upper);
    void swap(int indexA, int indexB);

private:
    vector<string> words;
};

// Constructor
// Takes a file name and reads all of the words from it into a vector
Dictionary::Dictionary(string filename)
{
    ifstream fin;
    fin.open(filename.c_str());
    string line;

    //handle case of bad file name
    if (!fin.good())
    {
        cout << "File not found, program will terminate.\n";
        system("Pause");
        exit(EXIT_FAILURE);
    }

    //read in list of words and push them back onto the vector
    while (!fin.eof())
    {
        getline(fin, line);
        words.push_back(line);
    }

    //close the input file
    fin.close();
}

//returns a pointer to the vector containing the dictionary of words
vector<string> Dictionary::getDict()
{
    return words;
}

// returns a single word from the dictionary
string Dictionary::getWord(int index)
{
    return words.at(index);
}

// returns the number of words in the dictionary
int Dictionary::getSize()
{
    return words.size();
}

//selection sort sorts the dictionary by finding the greatest value in a 
//sub-section of the vector and places it at the end
void Dictionary::selectionSort(int first, int last)
{
    string greatestString = "";

    for (int i = first; i < last; i++)
    {
        int min = i;
        for (int j = i+1; j < words.size(); j++)
        {
            if (words.at(j).compare(words.at(min)) < 0)
            {
                min = j;
            }
        }
        swap(i, min);
    }
}

void Dictionary::quicksort(int first, int last)
{
    if (first == last)
    {
        return;
    }
    else if (first < last) {
        int pivot = partition(first, last);
        quicksort(first, pivot - 1);
        quicksort(pivot + 1, last);
    }
}

//partition the dictionary so that all values less than the pivot are
//to the left and all values greater than the pivot are to the right.
int Dictionary::partition(int lower, int upper)
{
    while (true)
    {
        // Lower is the pivot, so any elements at the end of the array that are
        // greater than it are in the right place.
        while (lower < upper && words.at(lower) <= words.at(upper))
        {
            --upper;
        }

        // If lower and upper have met, the partition is finsished
        if (lower == upper) return lower;

        // Now we know that upper isn't in the right place,
        // so swap it into the right place and upper becomes the pivot.
        swap(lower, upper);
        lower++;

        while (lower < upper && words.at(lower) <= words.at(upper))
        {
            ++lower;
        }

        if (lower == upper) return upper;

        swap(lower, upper);
        upper--;
    }//end while
}

//helper function to swap two words in the dictionary
void Dictionary::swap(int indexA, int indexB)
{
    string temp = words.at(indexA);
    words.at(indexA) = words.at(indexB);
    words.at(indexB) = temp;
}