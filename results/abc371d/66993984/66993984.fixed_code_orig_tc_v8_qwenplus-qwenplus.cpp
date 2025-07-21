#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    
    vector<long long> x(n + 2), p(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        // Use prefix sum of p with x as key points
        x[i + 1] = x[i + 1]; // just to keep the sorted nature
        p[i] += p[i - 1];
    }

    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Find first index where x[i] >= L
        int left = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        // Find last index where x[i] <= R
        int right = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin() - 1;

        if (left > right)
            cout << 0 << '\n';
        else
            cout << p[right] - p[left - 1] << '\n';
    }

    return 0;
}