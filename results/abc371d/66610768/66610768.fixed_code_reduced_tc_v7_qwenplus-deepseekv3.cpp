#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    vector<ll> c(n+1, 0); // Using long long to prevent overflow

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

        if(r >= a[n]) {
            cout << c[n] - c[i-1] << '\n';
        } else {
            cout << c[j-1] - c[i-1] << '\n';
        }
    }
    return 0;
}