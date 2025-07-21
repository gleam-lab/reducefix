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

    ll include = a[0];
    ll exclude = 0;
    ll new_include, new_exclude;

    for (int i = 1; i < n; i++) {
        new_include = exclude + a[i];
        new_exclude = max(include, exclude);
        include = new_include;
        exclude = new_exclude;
    }

    cout << max(include, exclude) << endl;
}