#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2); // x[1..n]
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    vector<long long> p(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Prefix sum of p
    vector<long long> prefix_sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Binary search to find the first index where x[i] >= L
        int left = 1, right = n;
        int c = n + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] >= L) {
                c = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Binary search to find the last index where x[i] <= R
        left = 1, right = n;
        int d = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] <= R) {
                d = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (c > d) {
            cout << 0 << "\n";
        } else {
            cout << (prefix_sum[d] - prefix_sum[c - 1]) << "\n";
        }
    }

    return 0;
}