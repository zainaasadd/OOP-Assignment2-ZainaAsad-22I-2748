
#include <iostream>
using namespace std;


void ChangeLocation(char *arr, int b1, int b2) {
    if (b1 >= b2) return;
    char temp = arr[b1];
    arr[b1] = arr[b2];
    arr[b2] = temp;
    ChangeLocation(arr, b1 + 1, b2 - 1);
}

void PrintPattern(int n) {
    if (n <= 0) return;
    cout << n << " ";
    PrintPattern(n - 2);
}

int main() {
    cout << "Q1 by Zaina!\n\n";

    char arr[8] = {'C','O','M','P','U','T','E','R'};
    ChangeLocation(arr, 2, 6);
    cout << "After the ChangeLocation function: \n";
    for (char c : arr) cout << c << " ";
    cout << endl;

    int n = 4;
    cout << "\nPattern for n=4 is:\n";
    for (int i = n; i > 0; i--) {
        PrintPattern(i);
        cout << endl;
    }
}
