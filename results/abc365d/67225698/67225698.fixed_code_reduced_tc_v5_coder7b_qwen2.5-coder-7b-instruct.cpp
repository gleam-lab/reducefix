#include <bits/stdc++.h>
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    // Initialize variables
    ll wins = 0;
    char last_move = '\0';
    bool can_win = true;
    
    for (char c : s)
    {
        if (last_move == '\0')
        {
            // First move, any move is fine
            last_move = c;
        }
        else if (c != last_move)
        {
            // If the current move is different from the previous one, we can win
            ++wins;
            last_move = c;
        }
        else
        {
            // If the current move is the same as the previous one, we cannot win
            can_win = false;
            break;
        }
    }
    
    // If we can't win at all, return 0
    if (!can_win)
    {
        cout << 0 << endl;
        return;
    }
    
    // Calculate the maximum number of wins
    cout << wins << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}