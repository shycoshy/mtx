#include "mtx.h" 

int main()
{
    int a = 0;
    int b = 0;

    std::cin >> a;
    std::cin >> b;
    if (std::cin.fail()) { std::cerr << "input fail" << std::endl; return 1; }

    int** mtx = nullptr;
    try {
        mtx = makemtx(a, b);
    }
    catch (const std::bad_alloc & e) {
        std::cerr << "out of memory" << std::endl;
        return 2;
    }

    int err = fillmtx(mtx, a, b);
    if (err) {
        std::cerr << "input fail" << std::endl;
        return 1;
    }
    dspmtx(mtx, a, b);
    removemtx(mtx, a);
}