#include <iostream>
using namespace std;


void LCM(int a,int b) {

    if (a < 1 || b < 1) {
        cout << "Please input correct numbers\n";
        return;
    }

    if (b > a) {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    for (int i = b; i <= a * b; i = i + b) {
        if (i % a == 0 && i % b == 0) {
            cout << "The number is = " << i << endl;
            break;
        }
    }
}



int main() {

    cout << "Least Common Multiple" << endl << endl;

    int i;
    int a;
    int b;

    while (1) {

        cout << " a = "; cin >> a; cout << endl;
        cout << " b = "; cin >> b; cout << endl;
        
        LCM(a, b);
    }

    return 0;
}