#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6+7;
int n, m;
vector<int> a(N+1, 0), c(N+1, 0);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        c[i] = a[i] + c[i-1];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        auto r_j = upper_bound(a.begin() + 1, a.end(), r);
        int i = l_i - a.begin();
        int j = r_j - a.begin();
        if (r >= a[n]) {
            cout << c[n] - c[i - 1] << endl;
        } else {
            cout << c[j - 1] - c[i - 1] << endl;
        }
    }
    return 0;
}