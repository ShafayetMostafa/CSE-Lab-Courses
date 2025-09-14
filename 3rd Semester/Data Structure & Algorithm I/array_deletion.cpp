#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, pos;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100]; // fixed size for simplicity
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> pos;

    if(pos < 1 || pos > n) {
        cout << "Invalid position!" << endl;
    } else {
        // Shift elements to the left from pos
        for(int i=pos-1; i<n-1; i++) {
            arr[i] = arr[i+1];
        }
        n--; // reduce size

        cout << "Array after deletion: ";
        for(int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
