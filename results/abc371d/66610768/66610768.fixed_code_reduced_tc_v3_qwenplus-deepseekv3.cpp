#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    vector<ll> c(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i-1] + b[i];
    }
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin()+1, a.end(), l);
        auto r_j = upper_bound(a.begin()+1, a.end(), r);
        int i = l_i - a.begin();
        int j = r_j - a.begin();
        ll sum = c[j-1] - c[i-1];
        cout << sum << endl;
    }
    return 0;
}