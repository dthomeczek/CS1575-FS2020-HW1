# Homework #1

This was the first coding assignment for the Fall 2020 CS1575 (Data Structures) course. The purpose of this code was designed around dynamically allocated two-dimensional arrays.

# Information From Assignment README

Finding patterns in data, like text files, or arrays of pixel values, is the basis of many more advanced methods, for example, image recognition in AI, or text processing. This week, you will write a program to input and store a 2D matrix of data of user-defined size, and then find a segment of data in that matrix that matches a search key, regardless of its orientation or direction.
- If there is no matching, still report that the pattern was not found.

* Input is all via C++ std::cin at the command prompt. Even though sample_input.txt is a file, input is not via fstream or file input; we re-direct via **standard input**: https://en.wikipedia.org/wiki/Standard_streams.
* The general form of input is here:
```
    <number of cases>

    <number of rows> <number of columns>
    <data set>
    <intended word to search>

    <number of rows> <number of columns>
    <data set>
    <intended word to search>
```

Input and output are handled as follows:
```
$ executable_name <my_input.txt >my_output.txt
```
will take input from the input file and will output to the output file.
