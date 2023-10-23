#include <iomanip>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Array {
public:
    static const int Size = 100;
    T array[Size];
    int current;

    Array() {
        current = 0;
        for (int i = 0; i < Size; i++)
            array[i] = 0;
    }

    Array(int n) {
        current = n;
        for (int i = 0; i < current; ++i)
            cin >> array[i];
    }

    Array(T* arr, int s) {
        current = s;
        for (int i = 0; i < current; i++)
            array[i] = arr[i];
        delete arr;
    }

    Array(int n, int j) {
        current = n;
        for (int i = 0; i < current; i++)
            array[i] = 0;
    }

    unsigned char operator [](int index) {
        if (index < current && index >= 0)
            return array[index];
        else return ' ';
    }

public:
    void chengeItem()
    {
        int i;
        T x;
        cin >> i >> x;
        array[i] = x;
    }

    void display(int index, int key) {
        switch (key) {
            case 1:
                cout << "Array" << index << " ";
                for (int i = 0; i < current; ++i)
                    cout << array[i] << " ";
                break;

            case 2:
                cout << "Array" << index;
                break;

            case 3:
                for (int i = 0; i < current; ++i)
                    cout << array[i] << " ";
                break;
        }
    }

    virtual Array sum(Array x) {
        T* arr = new T[current];
        for (int i = 0; i < current; i++)
            arr[i] = array[i] + x.array[i];
        return Array(arr, current);
    }
};

class Money : public Array <unsigned char>
{
public:
    string arrStr;

    Money(int i) {
        current = i + 1;
        cin >> array[current - 1] >> array[current - 2];
        array[current - 3] = '.';
        for (int j = current - 4; j >= 0; j--)
            cin >> array[j];
        toStr();
    }

    Money(int n, int j) {
        current = n;
        for (int i = current - 1; i >= 0; i--)
            array[i] = 0;
        toStr();
    }

    Money(string str) {
        int j = str.length() - 1;
        while (str[j] == '0') {
            str.pop_back();
            j--;
        }

        if (str[j] == '.') {
            str.push_back('0');
            str.push_back('0');
        }
        else if (str[j-1] =='.')
            str.push_back('0');

        int i = 0;
        while (str[i] != '.') {
            array[i] = str[i];
            i++;
        }

        for (int j = i; j < i + 3; j++)
            array[j] = str[j];
        current = i + 3;
        toStr();
    }


    Money operator + (Money x) {
        return Money(to_string(atof(arrStr.c_str()) + atof(x.arrStr.c_str())));
    }

    Money operator - (Money x) {
        double d = atof(arrStr.c_str()) - atof(x.arrStr.c_str());
        return Money(to_string(d));
    }

    Money operator * (double x) {
        return Money(to_string(atof(arrStr.c_str()) * x));
    }

    double operator / (Money x) {
        return (atof(arrStr.c_str()) / atof(x.arrStr.c_str()));
    }

    void chengeItem() {
        cin >> array[current - 1] >> array[current - 2];
        array[current - 3] = '.';
        for (int j = current - 4; j >= 0; j--)
            cin >> array[j];
        toStr();
    }

    void display(int index, int key) {
        switch (key) {
            case 1:
                cout << "Money" << index << " ";
                for (int i = 0; i < current; ++i)
                    cout << array[i];
                cout << "(u.e.)";
                break;

            case 2:
                cout << "Money" << index;
                break;

            case 3:
                for (int i = 0; i < current; ++i)
                    cout << array[i];
                cout << "(u.e.)";
                break;

            case 4:
                for (int i = 0; i < current; ++i)
                    cout << array[i];
                break;
        }
    }

private:
    void toStr() {
        arrStr = "";
        for (int i = 0; i < current; i++)
            arrStr += array[i];
    }
};

class Hex : public Array <unsigned char>
{
public:
    string arrStr;
public:
    Hex(int n) {
        current = n;
        for (int i = current - 1; i >= 0; i--)
            cin >> array[i];
        arrStr = "";
        toStr();
    }

    Hex(int n, int j) {
        current = n;
        for (int i = current - 1; i >= 0; i--)
            array[i] = 0;
        toStr();
    }

    Hex(string str) {
        current = str.length();
        for (int i = 0; i < current; i++)
            array[i] = str[i];
        toStr();
    }

    Hex operator + (Hex x) {
        unsigned long long num1, num2;
        ostringstream os;
        istringstream is1(arrStr), is2(x.arrStr);
        is1 >> hex >> num1;
        is2 >> hex >> num2;
        os << hex << num1 + num2;
        return Hex(os.str());
    }

    Hex operator - (Hex x) {
        unsigned long long num1, num2;
        ostringstream os;
        istringstream is1(arrStr), is2(x.arrStr);
        is1 >> hex >> num1;
        is2 >> hex >> num2;
        os << hex << ((num1 > num2) ? (num1 - num2) : (num2 - num1));
        return (num1 > num2) ? Hex(os.str()) : Hex('-' + os.str());
    }

    Hex operator * (Hex x) {
        unsigned long long num1, num2;
        ostringstream os;
        istringstream is1(arrStr), is2(x.arrStr);
        is1 >> hex >> num1;
        is2 >> hex >> num2;
        os << hex << num1 * num2;
        return Hex(os.str());
    }

    Hex operator / (Hex x) {
        long long num1, num2;
        ostringstream os;
        istringstream is1(arrStr), is2(x.arrStr);
        is1 >> hex >> num1;
        is2 >> hex >> num2;
        os << hex << num1 / num2;
        return Hex(os.str());
    }

    void chengeItem() {
        for (int i = current - 1; i >= 0; i--)
            cin >> array[i];
        toStr();
    }

    void display(int index, int key) {
        switch (key) {
            case 1:
                cout << "Hex" << index << " ";
                for (int i = 0; i < current; ++i)
                    cout << array[i];
                break;

            case 2:
                cout << "Hex" << index;
                break;

            case 3:
                for (int i = 0; i < current; ++i)
                    cout << array[i];
                break;
        }
    }

private:
    void toStr() {
        arrStr = "";
        for (int i = 0; i < current; i++)
            arrStr += array[i];
    }
};


void print_arr(Array<int> a1, Array<int> a2){
    a1.display(1, 1); a2.display(2, 1); cout << endl;
    Array<int> a3 = a1.sum(a2);
    a1.display(1, 2); cout << "+"; a2.display(2, 2); cout << " "; a3.display(0, 3); cout << endl;
}

void print_hex(Hex h1, Hex h2) {
    h1.display(1, 1); cout << " "; h2.display(2, 1); cout << endl;

    Hex h3 = h1 + h2;
    h1.display(1, 2); cout << "+"; h2.display(2, 2); cout << " "; h3.display(0, 3); cout << endl;

    h3 = h1 - h2;
    h1.display(1, 2); cout << "-"; h2.display(2, 2); cout << " "; h3.display(0, 3); cout << endl;

    h3 = h1 * h2;
    h1.display(1, 2); cout << "*"; h2.display(2, 2); cout << " "; h3.display(0, 3); cout << endl;

    h3 = h1 / h2;
    h1.display(1, 2); cout << "/"; h2.display(2, 2); cout << " "; h3.display(0, 3); cout << endl;
}

void print_money(Money m1, Money m2, double chislo) {
    m1.display(1, 1); cout << " "; m2.display(2, 1); cout << endl;

    Money m3 = m1 + m2;
    m1.display(1, 2); cout << "+"; m2.display(2, 2); cout << " "; m3.display(0, 3); cout << endl;

    m3 = m1 - m2;
    m1.display(1, 2); cout << "-"; m2.display(2, 2); cout << " "; m3.display(0, 3); cout << endl;

    m3 = m1 * chislo;
    m1.display(1, 2); cout << "*chislo "; m3.display(0, 3); cout << " ";
    m3 = m2 * chislo;
    m2.display(2, 2); cout << "*chislo "; m3.display(0, 3); cout << endl;

    double res = m1 / m2;
    m1.display(1, 2); cout << "/"; m2.display(2, 2); cout << " "; cout << res << endl;
}

int main()
{
    int sizeA, sizeM, sizeH, mode;
    double chislo, res;

    cin >> sizeA;

    Array<int> a1(sizeA);
    Array<int> a2(sizeA);

    print_arr(a1, a2);

    cin >> sizeH;

    Hex h1(sizeH);
    Hex h2(sizeH);

    print_hex(h1, h2);

    cin >> sizeM;

    Money m1(sizeM);
    Money m2(sizeM);

    cin >> chislo;

    print_money(m1, m2, chislo);

    cin >> mode;

    while (mode != 0) {

        if (mode == 1) {
            a1.chengeItem();
            print_arr(a1, a2);}
        else if (mode == 2) {
            a2.chengeItem();
            print_arr(a1, a2);}
        else if (mode == 3) {
            h1.chengeItem();
            print_hex(h1, h2);}
        else if (mode == 4) {
            h2.chengeItem();
            print_hex(h1, h2);}
        else if (mode == 5) {
            m1.chengeItem();
            print_money(m1, m2, chislo);}
        else if (mode == 6) {
            m2.chengeItem();
            print_money(m1, m2, chislo);}
        else if (mode == 7) {
            cin >> chislo;
            print_money(m1, m2, chislo);}

        cin >> mode;
    }

    return 0;
}

