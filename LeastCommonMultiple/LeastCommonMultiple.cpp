#include <iostream>
using namespace std;

int main() {

    cout << "Least Common Multiple" << endl << endl;

    int i;
    int a;
    int b;

    while (1) {

        cout << " a = "; cin >> a; cout << endl;
        cout << " b = "; cin >> b; cout << endl;

        if (a > b) {

            for (i = b; i <= a * b; i = i + b) {
                if (i % a == 0 && i % b == 0) {
                    cout << "The number is = " << i << endl;
                    break;
                }
            }
        }
        else {
            for (i = a; i <= a * b; i = i + a) {
                if (i % a == 0 && i % b == 0) {
                    cout << "The number is = " << i << endl;
                    break;
                }
            }
        }

    }

    return 0;
}