#include <bits/stdc++.h>
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    // Initialize variables to keep track of the count of consecutive same moves and the answer
    ll cnt = 1;
    ll ans = 0;
    
    // Iterate through the moves to count consecutive same moves
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
        {
            ++cnt;
        }
        else
        {
            // Calculate the maximum wins for the current segment of consecutive moves
            ans += (cnt + 1) / 2;
            cnt = 1;
        }
    }
    
    // Add the maximum wins for the last segment of consecutive moves
    ans += (cnt + 1) / 2;
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}