#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    // Prefix sum array for p
    vector<long long> prefix_p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_p[i] = prefix_p[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Find the first index where x[i] >= L
        int left = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        // Find the first index where x[i] > R
        int right = upper_bound(x.begin() + 1, x.end(), R) - x.begin();

        if (left < right) {
            cout << prefix_p[right - 1] - prefix_p[left - 1] << endl;
        } else {
            cout << 0 << endl; // No elements in range
        }
    }

    return 0;
}