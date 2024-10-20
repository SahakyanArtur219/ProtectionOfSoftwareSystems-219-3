#include <iostream>
using namespace std;

int main() {

    cout << "Greatest Common Divisor" << endl << endl;

    int i;
    int a;
    int b;

    while (1) {

        cout << " a = "; cin >> a; cout << endl;
        cout << " b = "; cin >> b; cout << endl;

        if (a > b) {

            for (i = b; i >= 1; i--) {
                if (a % i == 0 && b % i == 0) {
                    cout << "The number is = " << i << endl << endl;
                    break;
                }
            }
        }
        else {
            for (i = a; i >= 1; i--) {
                if (b % i == 0 && a % i == 0) {
                    cout << "The number is = " << i << endl << endl;
                    break;
                }
            }
        }

    }

    return 0;
}