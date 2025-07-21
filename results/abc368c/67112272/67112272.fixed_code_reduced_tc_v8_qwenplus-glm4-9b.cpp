#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    ll ans = 0;
    vector<ll> h(n);
    rep(i, n)
    {
        cin >> h[i];
        // To ensure we only increment the total time T when necessary
        while (h[i] > 0) {
            if (h[i] >= 3) {
                h[i] -= 3;
                ans += 3;
            } else {
                h[i] -= 1;
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}