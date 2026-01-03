# cpp-fast-csv-parser

High speed streaming CSV parser written in modern C++ for working with large files without loading them fully into memory.

This project demonstrates:
- efficient line by line processing of CSV files
- simple parser that handles configurable delimiter
- skipping empty lines and trimming spaces
- basic benchmark of read speed
- clean and minimal API suitable for data engineering tasks

Contents:
- csv_reader.h - CsvReader class declaration
- csv_reader.cpp - implementation of the CSV reader
- main.cpp - example program that uses CsvReader to scan a file and measure performance

## Features

- streaming read, no full file load
- configurable delimiter (comma by default)
- optional header processing
- robust handling of empty lines
- statistics: number of rows, number of columns in first row, time to read file

## Build (macOS / Linux)

Use any modern C++ compiler with C++17 support.

Example command:

g++ -std=c++17 -O2 main.cpp csv_reader.cpp -o fast_csv_demo

## Run

Run the program with path to CSV file as argument:

./fast_csv_demo path/to/file.csv

The program will print:
- number of rows read
- number of columns in the first row
- total read time in seconds

## Example use case

- fast pre scan of a large CSV dataset
- checking file structure before loading into Python or a database
- measuring throughput of disk and parsing logic for data pipelines

## Disclaimer

This project is intended for educational and portfolio purposes only.
The author is not responsible for any misuse of the code.
