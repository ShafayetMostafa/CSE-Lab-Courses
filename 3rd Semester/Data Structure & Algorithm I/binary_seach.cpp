#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, key;
    cout << "Enter number of elements (sorted): ";
    cin >> n;

    int arr[100];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Element found at position " << mid + 1 << endl;
            found = 1;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;  // search in right half
        }
        else {
            high = mid - 1; // search in left half
        }
    }

    if (found == 0) {
        cout << "Element not found!" << endl;
    }

    return 0;
}
