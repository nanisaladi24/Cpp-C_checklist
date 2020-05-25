/*
Problem: Given a class A, we want to know how many objects in heap section of memory

Key solution aspects:
- create a constructor of class which increments a static variable to know number of objects
- create a operator overloading for 'new' operator, so that we know runtime creation of object calls the newly created operator
- extension of problem is implement delete operator overloading too
*/

#include <stdio.h>
#include <iostream>
#include <stdint.h>

using namespace std;

class A{
    public:
        static int objcnt;
        //static int objcnt=0; //Doesn't work. It should be const if we do this.

        static int ct;

        A(){
            objcnt++;
        }
        ~A(){
            objcnt--;
        }
        void* operator new(size_t sz){
            void* dummy;
            ct++;
            return dummy;// to get rid of warnings
        }
        void operator delete(void* tp){
            ct--;
            return;
        }
};

int A::objcnt = 0; //Must be initialized before using

int A::ct = 0; //Must be initialized before using

int main(){
    A a,b;
    A c,d,e;

    cout << "Prints with stack objects:" << endl;

    cout << A::objcnt << endl;
    cout << A::ct<< endl;

    A* f = new A;
    A* g = new A;

    cout << "Prints with stack objects and dynamic/heap objects:" << endl;

    cout << A::objcnt<< endl;

    //Dynamic obj prints
    cout << A::ct<< endl;

    delete f;

    cout << "Prints after deleting 1 dynamic/heap object:" << endl;

    cout << A::objcnt<< endl;
    cout << A::ct<< endl;

    return 0;
}
