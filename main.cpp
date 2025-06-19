#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "boy boy" << std::endl;
    long long a = 0;
    long long b = 1;
    
    long long c;
    long long d = 45;
    // por is gr8

    for (int i = 0; i < 25; i++){
        c = a+b;
        a = b;
        b = c;

        std::cout << c << std::endl;
    }
    std::cout << "Hello World!" << std::endl;    
    return 0;
}

