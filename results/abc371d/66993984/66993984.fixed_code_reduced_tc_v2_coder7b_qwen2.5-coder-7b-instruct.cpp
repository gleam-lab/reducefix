#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int> x, p;
vector<long long> prefix_sum;

void preprocess() {
    prefix_sum.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i - 1];
    }
}

int main() {
    cin >> n;
    x.resize(n);
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    cin >> q;

    preprocess();

    while (q--) {
        int L, R;
        cin >> L >> R;
        auto it_L = lower_bound(begin(x), end(x), L);
        auto it_R = upper_bound(begin(x), end(x), R);
        int idx_L = distance(begin(x), it_L);
        int idx_R = distance(begin(x), it_R);

        // Adjust indices if they point to elements outside the valid range
        if (idx_L >= n || x[idx_L] < L) ++idx_L;
        if (idx_R > 0 && x[idx_R - 1] == R) --idx_R;

        if (idx_L <= idx_R) {
            long long result = prefix_sum[idx_R] - prefix_sum[idx_L - 1];
            cout << result << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}