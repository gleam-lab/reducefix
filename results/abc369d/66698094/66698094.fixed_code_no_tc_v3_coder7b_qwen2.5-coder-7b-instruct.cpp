#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int MOD = 1e9 + 7, N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    // Initialize DP arrays
    vector<ll> dp_let(n + 1, 0); // Maximum experience if we let the previous monster go
    vector<ll> dp_defeat(n + 1, 0); // Maximum experience if we defeat the previous monster
    
    for (int i = 0; i < n; ++i)
    {
        dp_let[i + 1] = max(dp_let[i + 1], dp_defeat[i]); // Option to let the current monster go
        dp_defeat[i + 1] = max(dp_defeat[i + 1], dp_let[i] + v[i]); // Option to defeat the current monster
        
        // For even-indexed monsters, add extra experience points
        if ((i + 1) % 2 == 0)
        {
            dp_defeat[i + 1] += v[i];
        }
    }
    
    cout << max(dp_let[n], dp_defeat[n]) << '\n';
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}