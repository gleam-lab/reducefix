#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    ll ans = 0;
    rep(i, n)
    {
        cin >> h[i];
        // Calculate the number of full attacks that can be made
        ll full_attacks = h[i] / 3;
        ans += full_attacks;
        // Subtract the health after full attacks
        h[i] -= full_attacks * 3;
        // Handle remaining health
        while (h[i] > 0)
        {
            ans++;
            h[i]--;
        }
    }
    cout << ans << endl;
}