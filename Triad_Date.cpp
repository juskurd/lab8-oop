#include <iostream>
#include <Windows.h>
using namespace std;

class Triad {
protected:
    int a, b, c;

public:
    Triad(int x = 0, int y = 0, int z = 0)
        : a(x), b(y), c(z) {
    }

    virtual void increase() {
        a++;
        b++;
        c++;
    }

    virtual void display() const {
        cout << "Òð³éêà: (" << a << ", " << b << ", " << c << ")";
    }

    virtual ~Triad() {}
};

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int daysInMonth(int m, int y) {
    if (m == 2) return isLeap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

class Date : public Triad {
public:
    Date(int d = 1, int m = 1, int y = 2000)
        : Triad(d, m, y) {
    }

    void addDays(int n) {
        a += n;

        while (a > daysInMonth(b, c)) {
            a -= daysInMonth(b, c);
            b++;
            if (b > 12) {
                b = 1;
                c++;
            }
        }
    }

    void increase() override {
        addDays(1);
    }

    void display() const override {
        cout << "Äàòà: ";
        if (a < 10) cout << "0";
        cout << a << ".";
        if (b < 10) cout << "0";
        cout << b << "." << c;
    }
};

Triad& processTriad(Triad& t) {
    t.increase();
    t.display();
    cout << endl;
    return t;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Triad t(1, 2, 3);
    Date d(15, 11, 2025);

    cout << "Ïî÷àòêîâà òð³éêà: ";
    t.display();
    cout << endl;

    cout << "Ï³ñëÿ increase(): ";
    t.increase();
    t.display();
    cout << endl << endl;

    cout << "Ïî÷àòêîâà äàòà: ";
    d.display();
    cout << endl;

    cout << "Ï³ñëÿ increase(): ";
    d.increase();
    d.display();
    cout << endl;

    cout << "Ï³ñëÿ addDays(365): ";
    d.addDays(365);
    d.display();
    cout << endl << endl;

    cout << "Äåìîíñòðàö³ÿ ïðèíöèïó ï³äñòàíîâêè:" << endl;
    processTriad(t);
    processTriad(d);

    return 0;
}

