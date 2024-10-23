#include <iostream>
#include <cstdlib> 
#include <ctime> 



void fillArr(int arr[], int n) {
    int c = 0;
    int missedNumber = (std::rand() % (n+1))+1;
    for (int i = 1; i <= n+1; i++) {
        if (i == missedNumber) {
            c++;
            continue;
        }
        arr[i-1-c] = i;
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
}

int findMissNumber(int arr[], int m, int n) {

    if (arr[n] == n + 1) {
        return n + 2;
    }
    if (arr[0] == 2) {
        return 1;
    }

    int half = (m + n) / 2;
    if (n==(m+1)) {
        return m+2;
    }else if (arr[half] == (half+1)) {
       return findMissNumber(arr,half,n);
    }
    else {
        return findMissNumber(arr, m, half);
    }
    return 0;
}

int main() {
    int size;
    int arr[1000];

    while (true) {
        std::srand(std::time(0));

        std::cout << "Array size = ";
        std::cin >> size;

        fillArr(arr, size);
        printArr(arr, size);
        std::cout << "\n";
        std::cout << findMissNumber(arr, 0, size - 1)<<"\n";
    }
    return 0;
}
