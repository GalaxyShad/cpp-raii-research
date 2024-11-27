#include "SquareMatrix.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

SquareMatrix::SquareMatrix() : name_("[no name]") {
    size_ = 1;
    value_list_ = new int[size_]{0};
    value_list_[0] = 1;

    log() << "[Default Constructor] New no_name matrix (1) instance with 1 element created\n";
}

SquareMatrix::SquareMatrix(int size, std::string name) : name_(std::move(name)) {
    size_ = size;
    value_list_ = new int[size_ * size_]{0};

    log() << "[Constructor with param] New matrix instance with size = " << size << "x" << size << " created\n";
}

SquareMatrix::SquareMatrix(SquareMatrix &other) {
    if (other.value_list_ == nullptr) {
        size_ = other.size_;
        value_list_ = nullptr;

        log() << "[Copy constructor] " << "nullptr matrix (o_O) with id = " << &other << " was copied to this instance id = " << this << "\n";

        return;
    }

    delete[] value_list_;

    auto squared_size = other.size_ * other.size_;

    size_ = other.size_;
    value_list_ = new int[squared_size];

    std::copy(other.value_list_, other.value_list_ + squared_size, value_list_);

    auto &so = log() << "[Copy constructor] matrix copied... \n";
    so << "from ";
    print_value_list_to_ostream(so, other);
    so << "to ME ";
    print_value_list_to_ostream(so, *this);
    so << "\n";
}

SquareMatrix::SquareMatrix(SquareMatrix &&other) noexcept {
    auto previous = other.value_list_;

    size_ = std::exchange(other.size_, 0);
    value_list_ = other.value_list_;
    name_ = std::move(other.name_);

    other.value_list_ = nullptr;

    log() << "[Move constructor] matrix data moved from " << &other << " to " << this << ". values ptr changed from " << previous << " to " << value_list_ << "\n";
}

SquareMatrix::~SquareMatrix() {
    delete[] value_list_;
    value_list_ = nullptr;

    log() << "[Destructor] matrix instance destroyed \n";
}

// methods

void SquareMatrix::print_to_stream(std::basic_ostream<char> &stream) {
    print_value_list_to_ostream(stream, *this);
}

void SquareMatrix::set(int x, int y, int value) {
    value_list_[y * size_ + x] = value;
    log() << "[method set] [m(x, y) = value] m(" << x << "," << y << ") set to = " << value << "\n";
}

int SquareMatrix::get(int x, int y) {
    return value_list_[y * size_ + x];
}

// ====== PRIVATE ========= //

std::basic_ostream<char> &SquareMatrix::log() {
    return std::cout << "[SquareMatrix] instance_id=" << this
                     << "; name=" << name_
                     << "; sizeof(instance)=" << sizeof(*this)
                     << "; size=" << size_
                     << "; values ptr=" << value_list_
                     << " | ";
}

void SquareMatrix::print_value_list_to_ostream(std::basic_ostream<char> &s, SquareMatrix &m) {
    s << "id = " << &m
      << "; name = " << m.name_
      << "; size = " << m.size_ << "x" << m.size_
      << "\n";

    for (int y = 0; y < m.size_; y++) {
        for (int x = 0; x < m.size_; x++) {
            s << m.value_list_[y * m.size_ + x] << " ";
        }

        s << std::endl;
    }
}
