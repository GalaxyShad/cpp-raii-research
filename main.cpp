#include "SquareMatrix.h"
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>

namespace class_creation_tests {
    static SquareMatrix static_matrix(3, "static_matrix");

    void stack_matrix() {
        std::cout << "\n" << __func__ << "\n";
        SquareMatrix stack_matrix(2, "stack_matrix");
    }

    void dynamic_matrix() {
        std::cout << "\n" << __func__ << "\n";
        auto dynamic_matrix = new SquareMatrix(2, "stack_matrix");
        delete dynamic_matrix;
    }

    void c_array() {
        std::cout << "\n" << __func__ << "\n";
        SquareMatrix matrix_c_arr[] = {
                SquareMatrix(1, "matrix_c_arr[0]"),
                SquareMatrix(2, "matrix_c_arr[1]"),
                SquareMatrix(3, "matrix_c_arr[2]"),
                SquareMatrix(4, "matrix_c_arr[3]"),
        };

        for (auto& matrix : matrix_c_arr) {
            matrix.print_to_stream(std::cout);
        }
    }

    void run_tests() {
        std::cout << "=== CLASS CREATION TESTS ===\n";

        stack_matrix();
        dynamic_matrix();
        c_array();

        std::cout << "=== CLASS CREATION TESTS END ===\n";
    }
}

namespace class_function_transfer_and_return_tests {
    SquareMatrix factory_create_2x2_matrix_value(bool use_std_move = false) {
        std::cout << "\n" << __func__ << "> called with use_std_move = " << use_std_move << "\n";

        SquareMatrix m2x2(2, use_std_move ? "factory_value_m2x2_moved" : "factory_value_m2x2");

        m2x2.set(0, 0, 1);
        m2x2.set(1, 1, 1);

        m2x2.print_to_stream(std::cout);

        return (use_std_move) ? std::move(m2x2) : m2x2;
    }

    SquareMatrix& factory_create_2x2_matrix_ref() {
        std::cout << "\n" << __func__ << "\n";

        SquareMatrix m2x2(2, "factory_reference_m2x2");

        m2x2.set(0, 0, 1);
        m2x2.set(1, 1, 1);

        m2x2.print_to_stream(std::cout);

        return m2x2;
    }

    void display_to_stdio_ref(SquareMatrix& m) {
        std::cout << "\n" << __func__ << "> called\n";
        m.print_to_stream(std::cout);
    }

    void display_to_stdio_value(SquareMatrix m) {
        std::cout << "\n" << __func__ << "> called\n";
        m.print_to_stream(std::cout);
    }

    void run_tests() {
        std::cout << "=== CLASS TRANSFER AND RETURN TESTS ===\n";

        std::cout << "\n-- Return tests --\n";
        SquareMatrix m2x2_value = factory_create_2x2_matrix_value();
        SquareMatrix m2x2_value_moved = factory_create_2x2_matrix_value(true);

        SquareMatrix* m2x2_value_ref = &factory_create_2x2_matrix_ref();
        m2x2_value_ref->print_to_stream(std::cout);

        std::cout << "\n-- Transfer tests --\n";
        display_to_stdio_value(m2x2_value);
        display_to_stdio_ref(m2x2_value);

        std::cout << "=== CLASS TRANSFER AND RETURN TESTS END ===\n";
    }
}

namespace class_collections_test {
    void vector(bool use_emplace) {
        std::cout << "\n" << __func__ << " with use_emplace = " << use_emplace << "\n";

        std::vector<SquareMatrix> matrix_vec(5);

        for (int i = 0; i < 5; i++) {
            if (use_emplace) {
                matrix_vec.emplace_back(i+1, "matrix_vec_emplace[" + std::to_string(i) + "]");
                continue;
            }

            matrix_vec.push_back(SquareMatrix(i+1, "matrix_vec[" + std::to_string(i) + "]"));
        }
    }

    void list(bool use_emplace) {
        std::cout << "\n" << __func__ << " with use_emplace = " << use_emplace << "\n";

        std::list<SquareMatrix> matrix_list;

        for (int i = 0; i < 5; i++) {
            if (use_emplace) {
                matrix_list.emplace_back(i+1, "matrix_vec_emplace[" + std::to_string(i) + "]");
                continue;
            }

            matrix_list.push_back(SquareMatrix(i+1, "matrix_vec[" + std::to_string(i) + "]"));
        }
    }

    void run_tests() {
        std::cout << "=== CLASS TRANSFER AND RETURN TESTS ===\n";

        vector(false);
        vector(true);

        list(false);
        list(true);

        std::cout << "=== CLASS TRANSFER AND RETURN TESTS END ===\n";
    }
}

int main() {

//    class_creation_tests::run_tests();
//    class_function_transfer_and_return_tests::run_tests();
//    class_collections_test::run_tests();

    return 0;
}
