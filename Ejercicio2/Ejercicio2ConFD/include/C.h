#ifndef C
#define C

class claseA;
class claseB;

class claseC {
    private:
        claseA * a;
        claseB * b;
        int c = 3;
    public:
    	claseC();
    	~claseC();
        void output();
};

#endif
