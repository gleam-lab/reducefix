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

    // Find the minimum size of box needed
    ll minBoxSize = a.back(); // Start with the largest toy size
    bool possible = true;

    for(ll i = 0; i < n-1 && possible; i++)
    {
        if(minBoxSize < b[i]) // If current box cannot hold the current biggest toy
        {
            possible = false; // It's impossible to place all toys
        }
        else
        {
            minBoxSize += a[i]; // Add the next toy size to the current box size
        }
    }

    if(possible) cout << minBoxSize << endl;
    else cout << "-1" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--)
    {
        solve();
    }

    return 0;
}