#ifndef B
#define B

class claseA;
class claseC;

class claseB {
    private:
        claseA * a;
        int b = 2;
        claseC * c;
    public:
    	claseB();
    	~claseB();
        void output();
};

#endif
