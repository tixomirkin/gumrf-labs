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
    }

    T& operator[] (int index)
    {
        return arr[index];
    }

    void add(T arg) {
        T *n_arr = new T[n+1];
        for (int i=0; i<n; i++)
            n_arr[i] = arr[i];
        n_arr[n] = arg;
        n++;
        delete [] arr;
        arr = n_arr;
    }

    void del(int index) {
        n--;
        T *n_arr = new T[n];

        for (int i=0; i<index; i++)
            n_arr[i] = arr[i];
        for (int i=index; i<n; i++)
            n_arr[i] = arr[i+1];

        delete [] arr;
        arr = n_arr;
    }

    void print() {
        for (int i=0; i<n; i++)
            cout << arr[i] << "  ";
        cout << endl;
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

    double all_hours() {
        return hours() + lect + pract;
    }

    double hours() {
        if (control == 1)
            return 0.35 * studens;
        else
            return 0.5 * studens;
    }

    void input() {
        cin >> name >> semestr >> studens >> lect >> pract >> control;
    }

    void output() {
        cout << name << " " << semestr << " " << studens << " " << lect << " " << pract << " " << control << " " << hours()  << ";" << endl;
    }
};


class WorkTeacher: public Array<predmet> {
public:
    string last_name;
    string birthday;

    WorkTeacher(int _n, string _last_name, string _birthday) : Array(_n) {
        last_name = _last_name;
        birthday = _birthday;

        for (int i=0; i<n; i++)
            arr[i].input();
    }

    double sum_h() {
        double sum = 0;
        for (int i=0; i<n; i++)
            sum += arr[i].all_hours();
        return sum;
    }

    double stavka() {
        return sum_h() / 900;
    }


    void output() {
        stavka();
        cout << "WorkTeacher " << last_name << " date=" << birthday << " summa=" << sum_h() << " stavka=" << stavka() << endl;
        for (int i=0; i<n; i++) {
            arr[i].output();
        }
    }

};


int main()
{
    int n, mode, index, a;
    string last_name, birthday;

    cin >> n;

    Array<int> arr(n);

    for (int i=0; i<n; i++)
        cin >> arr[i];
    arr.print();

    cin >> last_name >> birthday >> n;

    WorkTeacher teacher(n, last_name, birthday);
    teacher.output();

    cin >> mode;
    while (mode != 0) {
        if (mode == 1) {
            cin >> index >> a;
            cout << "zamena mas["<<index<<"]="<< arr[index] << endl;
            arr[index] = a;
            arr.print();
        }
        else if (mode == 2) {
            cin >> index;
            teacher[index].input();
            teacher.output();
        }
        else if (mode == 3) {
            predmet t;
            t.input();
            teacher.add(t);
            teacher.output();
        }
        else if (mode == 4) {
            cin >> index;
            teacher.del(index);
            teacher.output();
        }

        cin >> mode;
    }
    return 0;
}


