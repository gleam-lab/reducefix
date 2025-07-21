#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
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

    ll prev_include = a[0];
    ll prev_exclude = 0;

    for (int i = 1; i < n; i++) {
        ll curr_include = prev_exclude + a[i];
        ll curr_exclude = max(prev_include, prev_exclude);

        prev_include = curr_include;
        prev_exclude = curr_exclude;
    }

    cout << max(prev_include, prev_exclude) << endl;
}