#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for(ll i = 0; i < n-1; ++i)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll j = n-2;
    for(ll i = n-1; i >= 0 && j >= 0; --i)
    {
        if(a[i] <= b[j]) 
        {
            --j;
        }
    }

    if(j == -1) 
    {
        cout << a.back() << endl;
    } 
    else 
    {
        cout << -1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}