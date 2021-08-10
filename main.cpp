#include <iostream>
#include <vector>
#include <set>

using namespace std;

template<class T, class E>
class Q {
public:
    T test(T t, E e) {
        return t + e;
    }
};

int add(int a, int b) {
    return a + b;
}

float add(float a, float b) {
    return a + b;
}

template<class T>
T zz(T a, T b) {
    return a + b;
}


namespace first_space {
    void func() {
        printf("first space func");
    }
}

namespace second_space {
    void func() {
        printf("second space func");
    }
}


//int main() {
//
////    first_space::func();
////    second_space::func();
////
////    int i = 1;
////    int&b = i;
////    int c = i;
////    printf("\ni is %d,&b is %d,c is %d",&i,&b,&c);
////    //i is -274684040,&b is -274684040,c is -274684052
//
//    set<int> list;
//    pair<set<int>::iterator, bool> a = list.insert(1);
//    cout << a.second << endl;
//    a = list.insert(1);
//    cout << a.second << endl;
//    a = list.insert(2);
//    cout << a.second << endl;
//    a = list.insert(2);
//    cout << a.second << endl;
//
//    return 0;
//}
