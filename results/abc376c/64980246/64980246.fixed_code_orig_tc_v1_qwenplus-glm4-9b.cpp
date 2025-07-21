#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    // Since we need to find the minimum possible x, we should sort a in ascending order
    sort(a.begin(), a.end());

    // The smallest box size x must fit the largest existing box b_i and the smallest toy a[0]
    int x = max(a[0], *max_element(b.begin(), b.end()));

    // Check if x is already part of existing boxes b
    bool can_find = false;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] == x) {
            can_find = true;
            break;
        }
    }

    // If x is not part of existing boxes b, find the minimum x that can fit the smallest toy
    if (!can_find) {
        for (int i = 0; i < n - 1; i++) {
            if (b[i] > x && b[i] > a[0]) {
                // Find the next box size that can fit the smallest toy
                for (int j = i + 1; j < n - 1; ++j) {
                    if (b[j] > x) {
                        x = b[j];
                        break;
                    }
                }
                break;
            }
        }
    }

    // Output the result
    cout << (can_find || x == a[0] ? x : -1) << endl;

    return 0;
}