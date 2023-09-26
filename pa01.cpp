/**
Implement the main here to match input and output. 
**/

#include "matrix_search.h"

int main()
{
    int rows; // row amount
    int cols; // column amount
    int search_count; // how many word searches to actually search
    int coords[4]{-1, -1, -1, -1}; // holds the row/col values of the first and last letter respectively in the form: row, col, row, col
    string search_word; // the word to be searched
    char **matrix;

    cin >> search_count;
    for (int i = 0; i < search_count; i++)
    {
        cin >> rows >> cols; // takes in both rows and columns

        matrix = build_matrix(rows, cols); // builds and assigns the word search's matrix
        fill_matrix(rows, cols, matrix); // fills the matrix with the letters   
        cin >> search_word; // takes in the word
        matrix_search(coords, search_word, rows, cols, matrix); // searches the matrix
        if (coords[0] == -1) // output for if no pattern is found
        {
            cout << "Searching for \"" << search_word << "\" in matrix " << i << " yields:" << endl;
            cout << "The pattern was not found." << endl;
        }
        else // input for if the pattern is found
        {
            cout << "Searching for \"" << search_word << "\" in matrix " << i << " yields:" << endl;
            cout << "Start pos:(" << coords[0] << ", " << coords[1] << ") to End pos:(" << coords[2] << ", " << coords[3] << ")" << endl;
        }
        cout << endl;
        delete_matrix(rows, matrix); // deletes the word search matrix

        // resets the values of coords[] to 0
        coords[0] = -1;
        coords[1] = -1;
        coords[2] = -1;
        coords[3] = -1;
    }
    return 0;
}

