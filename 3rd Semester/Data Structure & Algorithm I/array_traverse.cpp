#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];   // input array
    }

    cout << "Traversing the array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";   // visiting each element
    }
    cout << endl;

    return 0;
}
