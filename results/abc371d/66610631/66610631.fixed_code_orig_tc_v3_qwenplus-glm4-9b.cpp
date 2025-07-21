#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i] + c[i - 1];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        auto r_i = upper_bound(a.begin() + 1, a.end(), r);
        
        if (l_i == a.begin() + 1) {
            if (r_i == a.begin() + 1) {
                cout << c[n] << endl; // Both l and r are the first elements
            } else {
                cout << c[n - 1] - c[n] << endl; // r is beyond the last element
            }
        } else if (r_i == a.begin() + n) {
            cout << c[n] - c[l_i - a.begin() - 1] << endl; // r is the last element
        } else {
            cout << c[r_i - a.begin() - 1] - c[l_i - a.begin() - 1] << endl; // Range between l and r
        }
    }
    return 0;
}