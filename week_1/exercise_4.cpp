#include <iostream>

using namespace std;

// usage of member access classifiers
class A {
    public:
        int a;
    protected:
        int b;
    private:
        int c;
};

int main() {
    A a;
    a.a = 1;
    //a.b = 2; // error: ‘int A::b’ is protected within this context
    //a.c = 3; // error: ‘int A::c’ is private within this context
    cout << "a.a = " << a.a << endl;
    return 0;
}
