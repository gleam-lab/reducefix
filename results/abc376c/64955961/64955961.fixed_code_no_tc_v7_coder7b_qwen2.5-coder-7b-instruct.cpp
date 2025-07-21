#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n - 1; ++i)
        cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = -1;
    bool possible = true;
    for(ll i = 0; i < n - 1; ++i)
    {
        if(a[n - i - 1] > b[n - i - 2])
        {
            possible = false;
            break;
        }
    }

    if(possible && a[0] <= b[n - 2]) 
        ans = max(ans, b[n - 2]);
    if(possible && a[1] <= b[n - 2]) 
        ans = max(ans, b[n - 2]);

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}