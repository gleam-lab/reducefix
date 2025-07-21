#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }

    // Sort the toy sizes in descending order to try to fit the largest toy into the smallest available box
    sort(va.rbegin(), va.rend());

    // Initialize the result as the largest toy size
    int min_x = va[0];

    // Iterate through the existing boxes from smallest to largest
    for (int i = 0; i < n - 1; i++) {
        // If the current box can fit the largest toy, update the result and break
        if (vb[i] >= min_x) {
            min_x =vb[i];
            break;
        }
    }

    // If the result is still the largest toy size, that means no existing box can fit the largest toy
    // Therefore, x must be at least the size of the largest toy
    if (min_x == va[0]) {
        cout << va[0] << endl;
    } else {
        cout << min_x << endl;
    }

    return 0;
}