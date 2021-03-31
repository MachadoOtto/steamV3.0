#include <iostream>

class A {
    private:
        int a = 1;
        B * b;
        C * c;
    public:
        void output() {
            std::cout << a << ") La clase A funciona" << std::endl;
        }
};

class B {
    private:
        A * a;
        int b = 2;
        C * c;
    public:
        void output() {
            std::cout << b << ") La clase B funciona" << std::endl;
        };
};

class C {
    private:
        A * a;
        B * b;
        int c = 3;
    public:
        void output() {
            std::cout << c << ") La clase C funciona" << std::endl;
        };
};

int main() {
    A claseA;
    B claseB;
    C claseC;
    claseA.output();
    claseB.output();
    claseC.output();
    return 0;
}
