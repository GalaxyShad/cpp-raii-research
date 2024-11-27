//
// Created by Вадим Кадырин on 27.11.2024.
//

#ifndef CPP_RAII_RESEARCH_SQUAREMATRIX_H
#define CPP_RAII_RESEARCH_SQUAREMATRIX_H

#include <string>
#include <utility>

class SquareMatrix {
public:
    SquareMatrix();

    explicit SquareMatrix(int size, std::string name);

    SquareMatrix(SquareMatrix &other);

    SquareMatrix(SquareMatrix &&other) noexcept;

    ~SquareMatrix();

    void print_to_stream(std::basic_ostream<char> &stream);

    void set(int x, int y, int value);

    int get(int x, int y);


private:
    int size_{};
    std::string name_;
    int *value_list_ = nullptr;

    std::basic_ostream<char> &log();

    static void print_value_list_to_ostream(std::basic_ostream<char> &s, SquareMatrix &m);
};



#endif//CPP_RAII_RESEARCH_SQUAREMATRIX_H
