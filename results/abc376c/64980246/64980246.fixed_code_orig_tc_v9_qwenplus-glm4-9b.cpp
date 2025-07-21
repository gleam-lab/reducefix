#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int &tt : a) cin >> tt;
    for (int &tt : b) cin >> tt;

    // Sort the toy sizes in ascending order and box sizes in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables to track the current index and the minimum box size needed
    int i = 0, j = 0;
    int min_box_size = 0;

    // Iterate while there are toys and boxes left
    while (i < n && j < n - 1) {
        // If the current toy size is larger than the current box size, we need to buy a new box
        if (a[i] > b[j]) {
            if (min_box_size == 0) {
                // This is the first time we need a new box, so it should be the toy's size
                min_box_size = a[i];
            } else {
                // If the box size is not zero, we can't find a suitable box, so the answer is -1
                cout << -1 << endl;
                return 0;
            }
        } else {
            // Update j to find the smallest box that can fit the current toy
            j++;
            if (j == n - 1 && i < n - 1) {
                // If we've already checked all boxes and there are still toys, the answer is -1
                cout << -1 << endl;
                return 0;
            }
        }
        // Move to the next toy
        i++;
    }

    // If we have found a suitable box for each toy, print the minimum box size needed
    cout << min_box_size << endl;

    return 0;
}