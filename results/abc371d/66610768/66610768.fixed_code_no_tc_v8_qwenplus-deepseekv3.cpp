#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n), c(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        c[i + 1] = c[i] + b[i];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_it = lower_bound(a.begin(), a.end(), l);
        auto r_it = upper_bound(a.begin(), a.end(), r);
        int i = l_it - a.begin();
        int j = r_it - a.begin();
        cout << c[j] - c[i] << endl;
    }
    return 0;
}