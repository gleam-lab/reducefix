#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }

    // Instead of sorting in descending order, we need to find the smallest x
    // that can fit all toys into boxes.
    // We can use a two-pointer technique to find the minimum x.
    sort(vb.rbegin(), vb.rend()); // Sort the box sizes in descending order for easier iteration.

    int start = 0; // Start index for va
    int end = n - 1; // End index for va
    bool canFit = true;

    while (start <= end) {
        if (vb[start] >= va[start]) {
            start++;
        } else if (vb[start] >= va[end]) {
            end--;
        } else {
            canFit = false;
            break;
        }
    }

    if (canFit) {
        if (end < start) {
            cout << vb[start] << endl;
        } else {
            cout << vb[start] + 1 << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}