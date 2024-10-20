#include "mtx.h"

void removemtx(int** mtx, int a) {
    for (int i = 0; i < a; i++) {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int** makemtx(int a, int b) {
    int** mtx = new int* [a];
    int created = 0;
    try {
        for (; created < a; ++created) {
            mtx[created] = new int[b];
        }
    }
    catch (const std::bad_alloc& e) {
        removemtx(mtx, created);
        throw;
    }
    return mtx;
}

int fillmtx(int** mtx, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int e = 0; e < b; e++) {

            std::cin >> mtx[i][e];
            if (std::cin.fail()) { return 1; }
        }
    }
    return 0;
}

void dspmtx(int** mtx, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int e = 0; e < b - 1; e++) {
            std::cout << mtx[i][e] << ' ';
        }
        std::cout << mtx[i][b - 1] << '\n';
    }
    std::cout << '\n';
}