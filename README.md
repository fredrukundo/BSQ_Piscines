# BSQ_Piscines

## Introduction

The BSQ project is a C program that finds the largest possible square in a grid-based map without encountering any obstacles. The map provided either as a file or through standard input, consists of a grid where each cell can be empty or contain an obstacle.  
The program scans the map, determines the largest square that can be drawn and visually marks it.

This project demonstrates key concepts such as dynamic programming, memory management file I/O and efficient algorithm design in C.

## Features

* <b>Flexible input:</b> The program can process map data from both files and standard input.
* <b>Dynamic Memory Allocation:</b> Efficiently handles large maps by dynamically allocating memory as needed.
* <b>Error Handling:</b> Comprehensive error handling ensures that invalid maps or input errors are gracefully reported.
* <b>Debugging Support:</b> Optional debugging output provides insights into the internal state of the algorithm, showing the dynamic programming matrix used to calculate the largest square
* <b>Efficient Computation:</b> Utilizes a dynamic programming approach to compute the largest square in O(n*m) time where n and m are the dimensions of the map.

## How it works

1. Map Parsing: The program begins by reading the map from a file or stdin. The first line of the map (legend) contains characters that represent empty spaces, obstacles, and the filler character.

2. Matrix Calculation: The program constructs a dynamic programming matrix, where each cell represents the size of the largest square that can end at that position without encountering an obstacle.

3. Square Identification: As it processes the matrix the program keeps track of the largest square found, recording its size and position.

4. Map Visualization: The largest square is then marked on the map using the filler character and the result is printed

5. Debugging Mode: If enabled the program also prints the dynamic programming matrix for debugging purposes.

## Compling

You can run the program by providing a map file as an argument:
```
git clone link
make
./bsq map.txt
```
Alternatively, you can provide the map via standard input:

```
cat map.txt | ./bsq

or

./bsq
9.ox
.........
...o.....
.....o...
.....o...
.........
...o.....
.........
o........
.........
```
## Map Format

The map must follow a specific format:

* The first line is the legend, containing:
   * Number of lines in the map
   * The character representing empty spaces
   * The character representing obstacles
   * The character used to fill the largest square.

- Example:

```
9.ox
.........
...o.....
.....o...
.....o...
.........
...o.....
.........
o........
.........
```
