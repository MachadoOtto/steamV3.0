#ifndef A
#define A

class claseB;
class claseC;

class claseA {
    private:
        int a = 1;
        claseB * b;
        claseC * c;
    public:
    	claseA();
    	~claseA();
        void output();
};

#endif
