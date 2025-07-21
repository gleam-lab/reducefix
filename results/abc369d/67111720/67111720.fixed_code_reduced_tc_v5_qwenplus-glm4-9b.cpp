#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0; i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll dp_even = a[0];
    ll dp_odd = -a[0];

    for (int i = 1; i < n; ++i) {
        ll new_dp_even = max(dp_odd + 2 * a[i], dp_even);
        ll new_dp_odd = max(dp_even + a[i], dp_odd);
        dp_odd = new_dp_odd;
        dp_even = new_dp_even;
    }

    ll result = max(dp_even, dp_odd);
    cout << result << endl;
}