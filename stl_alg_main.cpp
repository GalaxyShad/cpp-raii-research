#include <algorithm>
#include <format>
#include <iostream>
#include <random>
#include <ranges>
#include <tuple>
#include <vector>

#include "SquareMatrix.h"

auto irandom(int from, int to) -> int {
    std::random_device r;

    std::default_random_engine e1(r());

    std::uniform_int_distribution<int> uniform_dist(from, to);

    return uniform_dist(e1);
}

auto make_randomized_matrix() -> SquareMatrix {
    auto radius = irandom(2, 6);

    SquareMatrix m(radius, "m");

    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            m.set(i, j, irandom(5, 1024));
        }
    }

    return std::move(m);
}

/////////////////////////////////////////////////////////////////////

constexpr std::pair<int, int> VECTOR_SIZE_RANDOM_RANGE(500, 1'000);
constexpr std::pair<int, int> TAKE_MINMAX_RANDOM_RANGE(20, 50);
constexpr int FROM_V1_TAKE_LAST = 200;

//constexpr std::pair<int, int> VECTOR_SIZE_RANDOM_RANGE(40, 50);
//constexpr std::pair<int, int> TAKE_MINMAX_RANDOM_RANGE(5, 10);
//constexpr int FROM_V1_TAKE_LAST = 20;

/////////////////////////////////////////////////////////////////////

auto print_matrixes_first_el(const std::vector<SquareMatrix> &m, const std::string &name) {
    std::cout << "[" << name << "]: ";

    for (auto &x: m) {
        std::cout << x.get(0, 0) << " ";
    }

    std::cout << "\n";
}

auto main() -> int {
    constexpr int FROM = VECTOR_SIZE_RANDOM_RANGE.first;
    constexpr int TO = VECTOR_SIZE_RANDOM_RANGE.second;

    constexpr int TAKE_MINMAX_FROM = TAKE_MINMAX_RANDOM_RANGE.first;
    constexpr int TAKE_MINMAX_TO = TAKE_MINMAX_RANDOM_RANGE.second;

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n1. Создать вектор v1 размером от 500 до 1000 элементов, число элементов не известно до запуска программы. "
                 "Элементами вектора являются экземпляры класса из Л.Р. №2 имеющие произвольные(случайные) значения. "
                 "В случае необходимости этот класс должен быть доработан для возможности решать поставленные в этой ЛР задачи.\n";
    auto vector_size = irandom(FROM, TO);
    std::vector<SquareMatrix> v1;
    v1.reserve(vector_size);
    std::ranges::generate_n(std::back_inserter(v1), vector_size, make_randomized_matrix);
    print_matrixes_first_el(v1, "v1");
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n2. Создать вектор v2, поместив в него последние 200 элементов вектора v1. "
                 "Рассмотрите решение для произвольных b и e, которые задают позиции первого и последнего копируемых элементов.\n";
    auto b = vector_size - FROM_V1_TAKE_LAST;
    auto e = vector_size;
    std::vector<SquareMatrix> v2(v1.begin() + b, v1.begin() + e);
    print_matrixes_first_el(v2, "v2");
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    auto greater_comp = [](SquareMatrix &a, SquareMatrix &b) { return a.get(0, 0) > b.get(0, 0); };
    auto less_comp = [](SquareMatrix &a, SquareMatrix &b) { return a.get(0, 0) < b.get(0, 0); };

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n3. Сформировать список list1, поместив в него первые n (от 20 до 50) наибольших элементов вектора v1 (указанные элементы должны быть отсортированы до помещения их в список).\n";
    std::vector<SquareMatrix> list1(irandom(TAKE_MINMAX_FROM, TAKE_MINMAX_TO));
    std::ranges::partial_sort_copy(v1, list1, greater_comp);
    print_matrixes_first_el(list1, "list1");
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n4. Сформировать список list2, поместив в него последние n (от 20 до 50) наименьших элементов вектора v2, порядок элементов не важен.\n";
    std::vector<SquareMatrix> list2(irandom(TAKE_MINMAX_FROM, TAKE_MINMAX_TO));
    std::ranges::partial_sort_copy(v2, list2, less_comp);
    print_matrixes_first_el(list2, "list2");
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n5. Удалить из векторов v1 и v2 перемещенные элементы. Скорректируйте размеры векторов после удаления из них элементов.\n";

    auto vec_remove_el_from_vec = [](std::vector<SquareMatrix> &src, const std::string &name, std::vector<SquareMatrix> &other, bool less) {
        auto m = [&other, less](auto &x) {
            return std::ranges::binary_search(other, x, [less](auto &a, auto &b) { return (less) ? (a.get(0, 0) < b.get(0, 0)) : (a.get(0, 0) > b.get(0, 0)); });
        };

        const auto [first, last] = std::ranges::remove_if(src, m);
        src.erase(first, last);
        src.reserve(src.size());

        print_matrixes_first_el(src, name);
    };

    vec_remove_el_from_vec(v1, "v1", list1, false);
    vec_remove_el_from_vec(v2, "v2", list2, true);
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n6. Для списка list1 найти элемент со средним значением. Перегруппировать элементы списка так, чтобы в начале оказались все элементы, большие среднего значения.\n";
    std::ranges::rotate(list1, list1.begin() + list1.size() / 2);
    print_matrixes_first_el(list1, "list1");
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n7. Удалите из списка list2 все нечётные элементы (или используйте другой критерий, который однозначно делит экземпляры вашего класса на два непересекающихся множества).\n";
    const auto [f, l] = std::ranges::remove_if(list2, [](auto &x) { return x.get(0, 0) % 2 != 0; });
    list2.erase(f, l);
    print_matrixes_first_el(list2, "list2");
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n8. Создайте вектор v3 из элементов, которые присутствуют и в векторе v1 и в векторе v2.\n";

    std::vector<SquareMatrix> v3;
    v3.resize(v1.size() + v2.size());

    std::ranges::sort(v1, less_comp);
    std::ranges::sort(v2, less_comp);
    auto end_it = std::ranges::set_union(v1, v2, v3.begin(), less_comp).out;
    v3.erase(end_it, v3.end());
    print_matrixes_first_el(v3, "v3");
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n9. Для списков list1 и list2 из списка с большим числом элементов удалите первые n так, чтобы оба списка имели бы одинаковый размер. "
                 "Сформируйте из них список list3, который будет хранить пары <первый элемент списка list1, первый элемент списка list2>, <второй элемент списка list1, второй элемент списка list2> и т. д.\n";

    //    if (list1.size() > list2.size()) {
    //        list1.resize(list1.size() - list2.size());
    //    } else {
    //        list2.resize(list2.size() - list1.size());
    //    }

    auto list3 = std::views::zip(list1, list2) | std::ranges::to<std::vector>();
    for (auto &i: list3) {
        std::cout << std::format("<{}, {}>, ", i.first.get(0, 0), i.second.get(0, 0));
    }
    std::cout << "\n";
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
    std::cout << "\n10. Решите предыдущую задачу для векторов v1 и v2 без предварительного приведения векторов к одному размеру. "
                 "Пар с пустыми значениями быть не должно.\n";

    auto zip_v1_v2 = std::views::zip(v1, v2) | std::ranges::to<std::vector>();
    for (auto &i: zip_v1_v2) {
        std::cout << std::format("<{}, {}>, ", i.first.get(0, 0), i.second.get(0, 0));
    }
    std::cout << "\n";
    /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

    return 0;
}