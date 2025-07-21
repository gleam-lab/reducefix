#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<int> x(n + 2), p(n + 2);  // +2 to avoid off-by-one issues
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    x[0] = -1e9;           // ensure lower_bound works correctly
    x[n+1] = 2e9;         // ensure upper_bound works correctly

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // Prefix sum of p
    vector<int> sum(n + 2, 0);
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        // Find first index where x >= l
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, l) - x.begin();

        // Find first index where x > r
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, r) - x.begin();

        // All elements from left to right-1 are in range [l, r]
        if (left < right) {
            cout << sum[right - 1] - sum[left - 1] << endl;
        } else {
            cout << 0 << endl; // No elements in range
        }
    }

    return 0;
}