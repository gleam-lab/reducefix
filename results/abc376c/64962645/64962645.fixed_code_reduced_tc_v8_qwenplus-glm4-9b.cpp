#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // Sort the sizes of toys and boxes in descending order
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    // Iterate through the sorted boxes sizes
    for (int i = 0; i < n - 1; i++) {
        // Check if the toy can be stored in the current box
        if (a[i] <= b[i]) {
            // If it can, check if it's the minimum box size that can store the toy
            // Since boxes are sorted in descending order, we need to check the next toy
            // If the next toy is larger, we need a new box, otherwise we can just use the current one
            if (i == n - 2 || a[i + 1] > b[i + 1]) {
                cout << a[i] << endl;
                return 0;
            }
        }
    }

    // If no suitable box size is found, output -1
    cout << -1 << endl;
    return 0;
}