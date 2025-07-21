#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n-1; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll j = 0;
    for(ll i = 0; i < n-1; ++i)
    {
        while(j < n && a[j] <= b[i])
            ++j;
        if(j == n || a[j] > b[i]*2)
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << a[n-1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}