#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
map<int, int> sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Find the first position greater than or equal to L
        auto it_c = lower_bound(x + 1, x + n + 1, L);
        int c = it_c - x;

        // Find the first position strictly greater than R
        auto it_d = upper_bound(x + 1, x + n + 1, R);
        int d = it_d - x;

        // Adjust indices to match the problem's requirement
        if (it_c != x + 1 && (*it_c == L)) --c;
        if (it_d != x + 1 && (*it_d > R)) --d;

        cout << sum[d - 1] - sum[max(0, c - 1)] << endl;
    }

    return 0;
}