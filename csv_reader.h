#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>
#include <istream>

class CsvReader {
public:
    // delimiter по умолчанию запятая, можно указать другой, например ';'
    explicit CsvReader(char delimiter = ',');

    // прочитать одну строку CSV из входного потока
    // возвращает false, если достигнут конец файла или не удалось прочитать строку
    bool read_row(std::istream& in, std::vector<std::string>& row);

private:
    char delimiter_;

    void parse_line(const std::string& line, std::vector<std::string>& row);
};

#endif
