#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int x = -1;
    bool possible = true;
    
    // Check if all toys can be placed in existing boxes
    bool all_fit = true;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] > b[i]) {
            all_fit = false;
            break;
        }
    }
    if (all_fit) {
        x = a[0];
    } else {
        // Find the smallest x such that when added, all toys can be placed
        // The approach is to find the largest toy that cannot fit in any box
        // and set x to that toy's size.
        // Also, ensure that all other toys can fit in the remaining boxes.
        int cnt = 0;
        int last_unfit = -1;
        int i = 0, j = 0;
        while (i < n && j < n - 1) {
            if (a[i] <= b[j]) {
                ++i;
                ++j;
            } else {
                last_unfit = a[i];
                ++i;
            }
        }
        if (i < n) {
            last_unfit = a[i];
        }
        if (last_unfit != -1) {
            x = last_unfit;
            // Now check if with x, all toys can be placed
            vector<int> new_b = b;
            new_b.push_back(x);
            sort(new_b.begin(), new_b.end());
            bool ok = true;
            for (int k = 0; k < n; ++k) {
                if (a[k] > new_b[k]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                x = -1;
            }
        } else {
            x = -1;
        }
    }
    cout << x << endl;
    return 0;
}