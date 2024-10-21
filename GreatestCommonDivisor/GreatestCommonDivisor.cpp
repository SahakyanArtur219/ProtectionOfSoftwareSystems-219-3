#include <iostream>
using namespace std;

void GCD(int a, int b){

    if (a < 1 || b < 1) {
        cout << "Please input correct numbers\n";
        return;
    }
    
    if (b > a) {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    for (int i = b; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            cout << "The number is = " << i << endl << endl;
            break;
        }
    }
}

int main() {

    cout << "Greatest Common Divisor" << endl << endl;

    int i;
    int a;
    int b;

    while (1) {

        cout << " a = "; cin >> a; cout << endl;
        cout << " b = "; cin >> b; cout << endl;
        GCD(a, b);


    }

    return 0;
}