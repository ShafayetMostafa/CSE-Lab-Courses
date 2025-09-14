#include <iostream>
using namespace std;

int main() {
    int n, pos, value;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100]; // fixed size for simplicity
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter position to insert (1 to " << n+1 << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;

    // Shift elements to the right from the position
    for(int i=n; i>=pos; i--) {
        arr[i] = arr[i-1];
    }

    // Insert the value
    arr[pos-1] = value;
    n++; // array size increases

    cout << "Array after insertion: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
