#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;
int main() {
    int n, m;
    cin >> n;
    vector<int>a(n+1, 0), b(N+1, 0), c(N+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = c[i-1] + b[i];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l > n || r > n || l < 1) {
            cout << 0 << endl; // Out of bounds, return 0 or handle it as needed
            continue;
        }
        auto l_i = lower_bound(a.begin(), a.end(), l);
        auto r_j = upper_bound(a.begin(), a.end(), r);
        int i = l_i - a.begin();
        int j = r_j - a.begin();
        LL sum = c[j] - c[i-1];
        cout << sum << endl;
    }
    return 0;
}