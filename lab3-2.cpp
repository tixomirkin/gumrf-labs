#include <iostream>
#include <string>
#include <iomanip>
#include <string>

using namespace std;

template<typename T>

class Array {
protected:
    T *arr;
    int n;

public:
    Array<T>(int _n)
    {
        n = _n;
        arr = new T[n];
        //for (int i=0; i<n; i++) arr[n] = 0;
    }

    T& operator[] (int index)
    {
        //if (index < 0 || index >= n) return -1.0;
        return arr[index];
    }

    void add(T arg) {
        n++;

    }


    ~Array(){
        delete [] arr;
    }
};

struct predmet {
    string name;
    int semestr;
    int studens;
    int lect;
    int pract;
    int control;
};


//class WorkTeacher: public Array<string> {
//
//};


int main()
{
    int n;
    cin >> n;
    Array<int> arr(n);

    arr[1] = 25;
    cout << arr[1] << arr[0];

    Array<predmet> arr2(2);
    arr2[1].name = "123";
    cout << arr2[1].name;
    return 0;
}

