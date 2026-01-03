#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "csv_reader.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: fast_csv_demo <path_to_csv>\n";
        return 1;
    }

    const char* path = argv[1];

    // большой буфер для ускорения ввода
    std::ifstream file(path, std::ios::in);
    if (!file) {
        std::cerr << "Failed to open file: " << path << "\n";
        return 1;
    }

    // можно задать буфер вручную
    static const std::size_t BUFFER_SIZE = 1 << 20; // 1 MB
    static char buffer[BUFFER_SIZE];
    file.rdbuf()->pubsetbuf(buffer, BUFFER_SIZE);

    CsvReader reader(',');
    std::vector<std::string> row;

    std::size_t row_count = 0;
    std::size_t first_row_columns = 0;
    bool first_row_seen = false;

    auto start = std::chrono::high_resolution_clock::now();

    while (true) {
        bool ok = reader.read_row(file, row);
        if (!ok) {
            break;
        }
        if (!first_row_seen) {
            first_row_columns = row.size();
            first_row_seen = true;
        }
        ++row_count;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "File: " << path << "\n";
    std::cout << "Rows read: " << row_count << "\n";
    std::cout << "Columns in first row: " << first_row_columns << "\n";
    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";

    return 0;
}
