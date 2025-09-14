#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Insertion Sort using for loop
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j;
        for(j=i-1; j>=0 && arr[j] > key; j--) {
            arr[j+1] = arr[j];  // shift elements
        }
        arr[j+1] = key;  // place key
    }

    cout << "Sorted array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
