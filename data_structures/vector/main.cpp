#include <iostream>

#include "vector.hpp"

struct test {
    test(int i, double d) : m_i{i}, m_d{d} {}

    friend std::ostream& operator<<(std::ostream& os, const test& t);

    int m_i;
    double m_d;
};

std::ostream& operator<<(std::ostream& os, const test& t) {
    os << t.m_i << ',' << t.m_d;
    return os;
}

int main() {
    ds::vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    for (auto& elem : v)
	std::cout << elem << ' ';

    std::cout << '\n';

    ds::vector<test> v2;

    test t{1, 1.2};

    v2.push_back(t);
    v2.push_back(std::move(t));
    v2.emplace_back(3, 3.4);

    for (auto& elem : v2)
	std::cout << elem << ' ';

    std::cout << '\n';

    return 0;
}
