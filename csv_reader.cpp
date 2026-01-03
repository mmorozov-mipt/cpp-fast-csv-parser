#include "csv_reader.h"

#include <sstream>
#include <cctype>

CsvReader::CsvReader(char delimiter)
    : delimiter_(delimiter) {}

// простая обрезка пробелов по краям
static std::string trim(const std::string& s) {
    std::size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) {
        ++start;
    }
    std::size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) {
        --end;
    }
    return s.substr(start, end - start);
}

bool CsvReader::read_row(std::istream& in, std::vector<std::string>& row) {
    row.clear();
    std::string line;
    if (!std::getline(in, line)) {
        return false;
    }

    if (line.empty()) {
        // пустая строка - можно либо вернуть пустую, либо пропустить
        // здесь считаем это валидной строкой с нулем столбцов
        return true;
    }

    parse_line(line, row);
    return true;
}

void CsvReader::parse_line(const std::string& line, std::vector<std::string>& row) {
    row.clear();
    std::string current;
    bool in_quotes = false;

    for (char ch : line) {
        if (ch == '"') {
            in_quotes = !in_quotes;
            continue;
        }
        if (ch == delimiter_ && !in_quotes) {
            row.push_back(trim(current));
            current.clear();
        } else {
            current.push_back(ch);
        }
    }
    row.push_back(trim(current));
}
