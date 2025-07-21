#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e6+7;
int main() {
    int n, m;
    cin >> n;
    vector<int>a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i] + (i > 1 ? c[i-1] : 0);
    }
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin(), a.end(), l);
        auto r_j = upper_bound(a.begin(), a.end(), r);
        int i = distance(a.begin(), l_i);
        int j = distance(a.begin(), r_j);
        if(r >= a[n] || r == a[n-1]) {
            cout << c[n] << endl;
        } else {
            cout << c[j-1] - c[i-1] << endl;
        }
    }
    return 0;
}