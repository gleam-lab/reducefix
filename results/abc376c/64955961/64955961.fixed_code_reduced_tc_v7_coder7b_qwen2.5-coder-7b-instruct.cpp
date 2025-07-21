#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll x = 0, j = n-2;
    for(ll i = n-1; i >= 0 && j >= 0; --i)
    {
        if(a[i] > b[j]) 
        {
            ++x;
            j -= x;
        }
    }

    if(j >= 0 || (x == 1 && a[0] <= b[n-2])) cout << -1 << endl;
    else cout << a[x] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}