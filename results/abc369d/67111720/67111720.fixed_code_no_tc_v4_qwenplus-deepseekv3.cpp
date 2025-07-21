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

    ll incl = a[0];  // max sum including the previous element
    ll excl = 0;      // max sum excluding the previous element

    for (int i = 1; i < n; i++) {
        ll new_excl = max(incl, excl);
        incl = excl + a[i];
        excl = new_excl;
    }

    cout << max(incl, excl) << endl;
}