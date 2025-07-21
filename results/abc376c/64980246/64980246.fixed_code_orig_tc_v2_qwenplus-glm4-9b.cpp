#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    // Sort the toys and boxes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int min_x = -1;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            // Find the smallest box that can fit the current toy, considering the list of boxes
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            // If the iterator points to the start of the list, then the current box size is the smallest possible
            if (it == b.begin()) {
                min_x = *b.begin();
            }
        } else {
            // For the largest toy, it can fit in the largest existing box or the box we plan to buy
            min_x = max(min_x, a[i]);
        }
    }

    cout << (min_x == -1 ? -1 : min_x) << endl;
    return 0;
}