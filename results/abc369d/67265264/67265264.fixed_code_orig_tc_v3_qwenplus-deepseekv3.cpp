#include <bits/stdc++.h>
using namespace std;
#define Youssef ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define asc(v) v.begin(), v.end()
#define desc(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll dp_odd = 0, dp_even = 0;
    for (int i = n - 1; i >= 0; --i) {
        ll new_odd = max(dp_even + v[i], dp_odd);
        ll new_even = max(dp_odd + 2 * v[i], dp_even);
        dp_odd = new_odd;
        dp_even = new_even;
    }
    cout << max(dp_odd, dp_even) << endl;
}

int main() {
    Youssef
    int q = 1;
    while (q--)
        solve();
    return 0;
}