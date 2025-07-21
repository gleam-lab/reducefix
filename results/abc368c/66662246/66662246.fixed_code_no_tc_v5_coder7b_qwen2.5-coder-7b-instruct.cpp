#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ans+=(a[i]+2)/3; // Directly calculating the number of turns needed for each enemy
    }
    cout << ans << endl;
}