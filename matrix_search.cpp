/**
Here in the .cpp you should define and implement the functions that are declared in the .h file.
It is not recommended to add extra functions on this assignment.
**/

#include "matrix_search.h"


// We're giving you this one the first time, and you should copy it into all future assignments.
// Change the information to your own email handle (S&T username)
void get_identity(string &my_id)
{
    my_id = "djtpfr";
}


char ** build_matrix(int rows, int cols)
{
    char** matrix = new char*[rows]; // creates an array for the matrix with rows

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols]; // adds second dimension to matrix for cols
    }
    return matrix;
}


void fill_matrix(int rows, int cols, char **matrix)
{
    string row_letters; // holds a string of the row's letters
    int line_length = cols * 2; // sets the length of the row

    cin.ignore();
    for (int i = 0; i < rows; i++)
    {
        getline(cin, row_letters); // gets the row from input
        for (int j = 0; j < line_length; j++)
        {
            if (j % 2 == 0)
            {
                matrix[i][j / 2] = row_letters[j]; // places letters in matrix
            } 
        }  
    } 
}


void print_matrix(int rows, int cols, char **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j != cols - 1) // if letter is not the last in the row, add a space
            {
                cout << matrix[i][j] << ' ';
            }
            else if (j == cols - 1) // if the letter is the last in the row, no space
            {
                cout << matrix[i][j];
            }
        }
        cout << endl;
    }
}


void delete_matrix(int rows, char **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i]; // clears out the cols portion of the matrix
    }
    delete[] matrix; // clears out the cols portion of the matrix
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
    const int no_negative = 0;
    int word_length; // the length of the word in numerical terms
    int count;
    bool letter;
    bool whole_word = false;

    word_length = word.length(); // determines the length of the word
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == word[0]) // checks for the first letter
            {
                count = 1; // restarts count at 1 before each if statement containing a do-while
                // searches diagonally down to the right
                if (i + count < rows && j + count < cols)
                {
                    letter = true;
                    do
                    {
                        if (word[count] != matrix[i + count][j + count]) // if the pattern does not continue, then the next letter is judged as false
                        {
                            letter = false;
                        }
                        else
                        {
                            letter = true;
                            if (count == word_length - 1)
                            {
                                sol[0] = i;
                                sol[1] = j;
                                sol[2] = i + count;
                                sol[3] = j + count;
                                whole_word = true;
                            }
                        }
                        count++;
                    } while ((i + count) < rows && (j + count) < cols && count != word_length && whole_word == false && letter == true);
                }

                count = 1;
                // searches straight to the right
                if (j + count < cols)
                {
                    letter = true;
                    do
                    {
                        if (word[count] != matrix[i][j + count]) // if the pattern does not continue, then the next letter is judged as false
                        {
                            letter = false;
                        }
                        else
                        {
                            letter = true;
                            if (count == word_length - 1)
                            {
                                sol[0] = i;
                                sol[1] = j;
                                sol[2] = i;
                                sol[3] = j + count;
                                whole_word = true;
                            }
                        }
                        count++;
                    } while ((j + count) < cols && count != word_length && whole_word == false && letter == true);
                }
                
                count = 1;
                // searches diagonally up to the right
                if (j + count < cols && i - count >= no_negative)
                {
                    letter = true;
                    do
                    {
                        if (word[count] != matrix[i - count][j + count]) // if the pattern does not continue, then the next letter is judged as false
                        {
                            letter = false;
                        }
                        else
                        {
                            letter = true;
                            if (count == word_length - 1)
                            {
                                sol[0] = i;
                                sol[1] = j;
                                sol[2] = i - count;
                                sol[3] = j + count;
                                whole_word = true;
                            }
                        }
                        count++;
                    } while ((j + count) < cols && (i - count) >= no_negative && count != word_length && whole_word == false && letter == true);
                }

                count = 1;
                // searches straight up
                if (i - count >= no_negative)
                {
                    letter = true;
                    do
                    {
                        if (word[count] != matrix[i - count][j]) // if the pattern does not continue, then the next letter is judged as false
                        {
                            letter = false;
                        }
                        else
                        {
                            letter = true;
                            if (count == word_length - 1)
                            {
                                sol[0] = i;
                                sol[1] = j;
                                sol[2] = i - count;
                                sol[3] = j;
                                whole_word = true;
                            }
                        }
                        count++;
                    } while ((i - count) >= no_negative && count != word_length && whole_word == false && letter == true);
                }

                count = 1;
                // searches diagonally up to the left
                if (i - count >= no_negative && j - count >= no_negative)
                {
                    letter = true;
                    do
                    {
                        if (word[count] != matrix[i - count][j - count]) // if the pattern does not continue, then the next letter is judged as false
                        {
                            letter = false;
                        }
                        else
                        {
                            letter = true;
                            if (count == word_length - 1)
                            {
                                sol[0] = i;
                                sol[1] = j;
                                sol[2] = i - count;
                                sol[3] = j - count;
                                whole_word = true;
                            }
                        }
                        count++;
                    } while ((i - count) >= no_negative && (j - count) >= no_negative && count != word_length && whole_word == false && letter == true);
                }

                count = 1;
                // searches straight to the left
                if (j - count >= no_negative)
                {
                    letter = true;
                    do
                    {
                        if (word[count] != matrix[i][j - count]) // if the pattern does not continue, then the next letter is judged as false
                        {
                            letter = false;
                        }
                        else
                        {
                            letter = true;
                            if (count == word_length - 1)
                            {
                                sol[0] = i;
                                sol[1] = j;
                                sol[2] = i;
                                sol[3] = j - count;
                                whole_word = true;
                            }
                        }
                        count++;
                    } while ((j - count) >= no_negative && count != word_length && whole_word == false && letter == true);
                }

                count = 1;
                // searches diagonally down to the left
                if (j - count >= no_negative && i + count < rows)
                {
                    letter = true;
                    do
                    {
                        if (word[count] != matrix[i + count][j - count]) // if the pattern does not continue, then the next letter is judged as false
                        {
                            letter = false;
                        }
                        else
                        {
                            letter = true;
                            if (count == word_length - 1)
                            {
                                sol[0] = i;
                                sol[1] = j;
                                sol[2] = i + count;
                                sol[3] = j - count;
                                whole_word = true;
                            }
                        }
                        count++;
                    } while ((i + count) < rows && (j - count) >= no_negative && count != word_length && whole_word == false && letter == true);
                }

                count = 1;
                // searches straight down
                if (i + count < rows)
                {
                    letter = true;
                    do
                    {
                        if (word[count] != matrix[i + count][j]) // if the pattern does not continue, then the next letter is judged as false
                        {
                            letter = false;
                        }
                        else
                        {
                            letter = true;
                            if (count == word_length - 1)
                            {
                                sol[0] = i;
                                sol[1] = j;
                                sol[2] = i + count;
                                sol[3] = j;
                                whole_word = true;
                            }
                        }
                        count++;
                    } while ((i + count) < rows && count != word_length && whole_word == false && letter == true);
                }    
            }
        }
    }
}