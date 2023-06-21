
#include <iostream>
#include "doctest.h"
#include "pascal.h"
//#include "doctest.h"

void pascal(int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << combination(i, j) << ' ';
        }
        std::cout << '\n';
    }
}
int find_factorial(int i){
    if(i == 0 or i == 1){return 1;}
    return i*find_factorial(i-1);
}

int combination(int n, int k){
   // std::cout << find_factorial(n) / (find_factorial(n-k) * find_factorial(k));
    return find_factorial(n) / (find_factorial(n-k) * find_factorial(k));
}

