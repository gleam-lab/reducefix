#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    // Sort toys and boxes in descending order
    sort(va.begin(), va.end(), greater<long long>());
    sort(vb.begin(), vb.end(), greater<long long>());

    // Check if we can place all toys in existing boxes
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] > vb[i]) {
            // If not, find the smallest box that can hold the largest remaining toy
            long long min_box_size = va[i];
            bool found = false;
            for (int j = 0; j < n - 1; ++j) {
                if (min_box_size <= vb[j]) {
                    found = true;
                    break;
                }
                min_box_size += vb[j];
            }
            if (!found) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    // The largest toy that does not fit in any existing box
    cout << va[n - 1] << endl;
    return 0;
}