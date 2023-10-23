#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Pair {
protected:
    int a;
    int b;

public:
    Pair() {};
    Pair(int _a, int _b) {
        a = _a;
        b = _b;
    };
    void input() {
        cin >> a >> b;
    };

    virtual void print(Pair p2) {
        printf("(%d,%d) ", a, b);
        printf("(%d,%d) ", p2.a, p2.b);
        printf("(%d,%d)\n", a+p2.a, b+p2.b);
    }

    void set_a(int n_a) {a = n_a;};
    void set_b(int n_b) {b = n_b;};
    void pr(int n) {a *= n; b *= n;};
};

class Money:public Pair {
public:
    Money() {};
    Money(int rub, int cop) {
        a = rub;
        b = cop;
    };
    virtual void print(Money m2, int prs) {
        this->out(); m2.out();
        Money res(a+m2.a, b+m2.b);
        res.out();

        int aa, bb;
        if (a >= m2.a) {
            if (a == m2.a && b >= m2.b) { aa = m2.a-a; bb = m2.b-b; }
            else { aa = a-m2.a; bb = b-m2.b; }
        }
        else { aa = m2.a-a; bb = m2.b-b; }

        Money res2(aa, bb);
        res2.out();

        //res = Money(a-m2.a, b-m2.b);

        //cout << fixed << setprecision(prs);
        cout << double (a + b / 100.0) / (m2.a + m2.b / 100.0) << endl;
    };
    void out(){
        a = a + b / 100;
        b = b % 100;

        if (b < 0) {
            a--;
            b = 100 + b;
        }

        printf("(%d RUB %d COP) ", a, b);
    };
};

int main() {

    Pair P1, P2;
    P1.input(); P2.input();
    Money M1, M2;
    M1.input(); M2.input();
    int mode;
    int arg;
    P1.print(P2);
    M1.print(M2, 5);

    cin >> mode;
    while (mode != 0) {
        cin >> arg;
        if (mode == 1) {P1.set_a(arg); P1.print(P2);}
        else if (mode == 2) {P1.set_b(arg); P1.print(P2);}
        else if (mode == 3) {P2.set_a(arg); P1.print(P2);}
        else if (mode == 4) {P2.set_b(arg); P1.print(P2);}
        else if (mode == 5) {P1.pr(arg); P1.print(P2);}
        else if (mode == 6) {P2.pr(arg); P1.print(P2);}
        else if (mode == 7) {M1.set_a(arg); M1.print(M2, 5);}
        else if (mode == 8) {M1.set_b(arg); M1.print(M2, 5);}
        else if (mode == 9) {M2.set_a(arg); M1.print(M2, 5);}
        else if (mode == 10) {M2.set_b(arg); M1.print(M2, 5);}
        else if (mode == 11) {M1.pr(arg); M1.print(M2, 5);}
        else if (mode == 12) {M2.pr(arg); M1.print(M2, 5);};

        cin >> mode;
    }

}