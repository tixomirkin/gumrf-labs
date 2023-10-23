#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


class Array {
public:
    virtual void Read() = 0;
    virtual void Obrabotka() = 0;
    virtual void Action() = 0;
    virtual void Display() = 0;
};

class OrArray : public Array {
public:
    int size2;
    OrArray() { size2 = 0; }
    vector<int> orarr1;
    vector<int> orarr2;

    void Read() override {
        cin >> size2;
        for (int i = 0; i < size2; ++i) {
            int temp;
            cin >> temp;
            orarr1.push_back(temp);
        }
        for (int i = 0; i < size2; ++i){
            int temp;
            cin >> temp;
            orarr2.push_back(temp);
        }
    }

    void Action() override {
        vector<int> new1 = orarr1, new2 = orarr2;
        sort(new1.begin(), new1.end());
        sort(new2.begin(), new2.end());

        vector<int> nums;
        for (auto i : new1)
            nums.push_back(i);
        for (auto i : new2)
            nums.push_back(i);

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        cout << "OrArray1+OrArray2 ";
        for (auto i: nums)
            cout << i << " ";
        cout << '\n';
    }

    void Obrabotka() override {
        cout << "obrabotka XortArray1 ";
        for (int i = 0; i < size2; ++i)
            cout << log(orarr1[i]) << " ";
        cout << endl;
        cout << "obrabotka XortArray2 ";
        for (int i = 0; i < size2; ++i)
            cout << log(orarr2[i]) << " ";
        cout << endl;
    }

    void Display() override {
        cout << "OrArray1 ";
        for (int i = 0; i < size2; ++i)
            cout << orarr1[i] << " ";
        cout << endl;
        cout << "OrArray2 ";
        for (int i = 0; i < size2; ++i)
            cout << orarr2[i] << " ";
        cout << endl;
    }
};

class AndArray : public Array {
public:
    int size1;
    AndArray() { size1 = 0; }
    vector<int> arr1;
    vector<int> arr2;

    void Read() override {
        cin >> size1;
        for (int i = 0; i < size1; ++i) {
            int temp;
            cin >> temp;
            arr1.push_back(temp);
        }

        for (int i = 0; i < size1; ++i) {
            int temp;
            cin >> temp;
            arr2.push_back(temp);
        }

    }

    void Obrabotka() override {
        cout << "obrabotka AndArray1 ";
        for (int i = 0; i < size1; ++i)
            cout << pow(arr1[i], 0.5) << " ";
        cout << endl;
        cout << "obrabotka AndArray2 ";
        for (int i = 0; i < size1; ++i)
            cout << pow(arr2[i], 0.5) << " ";
        cout << endl;
    }

    void Action() override {
        vector<int> new1 = arr1, new2 = arr2;
        sort(new1.begin(), new1.end());
        sort(new2.begin(), new2.end());

        vector<int> v(new1.size() + new2.size());
        vector<int>::iterator it, st;

        it = set_intersection(new1.begin(), new1.end(), new2.begin(), new2.end(), v.begin());

        cout << "AndArray1+AndArray2 ";
        for (st = v.begin(); st != it; ++st)
            cout << *st << " ";
        cout << '\n';
    }

    void Display() override {
        cout << "AndArray1 ";
        for (int i = 0; i < size1; ++i)
            cout << arr1[i] << " ";
        cout << endl;
        cout << "AndArray2 ";
        for (int i = 0; i < size1; ++i)
            cout << arr2[i] << " ";
        cout << endl;
    }
};

int main() {
    AndArray a;
    OrArray b;

    a.Read();
    b.Read();

    a.Display();
    a.Obrabotka();
    a.Action();
    b.Display();
    b.Obrabotka();
    b.Action();

    int n;
    cin >> n;
    while (n != 0) {
        if (n == 1) {
            vector<int> arr1;
            for (int i = 0; i < a.size1; ++i) {
                int temp;
                cin >> temp;
                arr1.push_back(temp);
            }
            a.arr1.clear();
            for (int i = 0; i < a.size1; ++i)
                a.arr1.push_back(arr1[i]);
            a.Display();
            a.Obrabotka();
            a.Action();
        }
        else if (n == 2) {
            vector<int> arr2;
            for (int i = 0; i < a.size1; ++i) {
                int temp;
                cin >> temp;
                arr2.push_back(temp);
            }
            a.arr2.clear();
            for (int i = 0; i < a.size1; ++i)
                a.arr2.push_back(arr2[i]);
            a.Display();
            a.Obrabotka();
            a.Action();
        }
        else if (n == 3) {
            vector<int> arr3;
            for (int i = 0; i < b.size2; ++i) {
                int temp;
                cin >> temp;
                arr3.push_back(temp);
            }
            b.orarr1.clear();
            for (int i = 0; i < b.size2; ++i)
                b.orarr1.push_back(arr3[i]);
            b.Display();
            b.Obrabotka();
            b.Action();
        }
        else if (n == 4) {
            vector<int> arr4;
            for (int i = 0; i < b.size2; ++i) {
                int temp;
                cin >> temp;
                arr4.push_back(temp);
            }
            b.orarr2.clear();
            for (int i = 0; i < b.size2; ++i)
                b.orarr2.push_back(arr4[i]);
            b.Display();
            b.Obrabotka();
            b.Action();
        }
        cin >> n;
    }
    return 0;
}