#include <iostream>
#include "set.h"

int aElements[] = {3, 4, 5, 6};
int bElements[] = {3, 6};
int cElements[] = {};
int dElements[] = {3};

int main() {
    int i;
    Set a(sizeof (aElements)/sizeof (int), aElements),
        b(sizeof (bElements)/sizeof (int), bElements),
        c(sizeof (cElements)/sizeof (int), cElements),
        d(sizeof (dElements)/sizeof (int), dElements);

    std::cout << "Try set operators and initial values of sets: " << std::endl;
    std::cout << "A set: " << a << std::endl;
    std::cout << "B set: " << b << std::endl;

    std::cout << "Create union and give a value (set + int):" << std::endl;
    a = a + 1;
    std::cout << "A set: " << a << std::endl;

    std::cout << "Complex union on B set = ((B+2)+7)+3" << std::endl;
    b = ((b+2)+7)+3;
    std::cout << "B set: " << b << std::endl;

    std::cout << "A set=int give a value with c = 13 instance" << std::endl;
    c = 13;
    std::cout << "C set - " << c << std::endl;

    std::cout << "Union operation (set + set) the B += A statement" << std::endl;
    std::cout << "B: " << b << std::endl;

    std::cout << "Form a common part with the D = C * A operation!" << std::endl;
    d = c * a;
    std::cout << "D:" << d << std::endl;

    if (d <= a) {
        std::cout << "D is part set of A." << std::endl;
    }

    std::cout << "Element relation check: 4 is in D ? " << std::endl;
    if (4 < d) {
        std::cout << "Yes, it is!" << std::endl;
    }

    return 0;
}
