#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, k;
int a[N], b[N];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n, greater<int>());
    int threshold = b[m - 1];
    int sum_above = 0;
    for (int i = 0; i < m - 1; ++i) {
        sum_above += b[i];
    }
    int remaining_votes = k - accumulate(a, a + n, 0LL);
    
    for (int i = 0; i < n; ++i) {
        if (a[i] >= threshold) {
            cout << "0 ";
        } else {
            int needed = threshold - a[i] + 1;
            if (remaining_votes >= needed) {
                int new_total = a[i] + needed;
                int new_threshold = new_total;
                int cnt = 0;
                for (int j = 0; j < n; ++j) {
                    if (j != i && a[j] > new_threshold) {
                        cnt++;
                    }
                }
                if (cnt < m) {
                    cout << needed << " ";
                } else {
                    cout << "-1 ";
                }
            } else {
                cout << "-1 ";
            }
        }
    }
    return 0;
}