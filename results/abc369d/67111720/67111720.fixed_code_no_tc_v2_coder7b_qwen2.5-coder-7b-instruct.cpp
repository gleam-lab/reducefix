#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // Initialize variables to store the maximum experience points if the last action was to defeat or let go of the monster
    ll dp_defeat = 0, dp_let_go = -1;

    rep(i,n)
    {
        // Temporary variable to store the current value of dp_let_go
        ll temp = dp_let_go;
        
        // Update dp_let_go to be the maximum between the current dp_let_go and the experience gained by defeating the current monster
        dp_let_go = max(dp_defeat + a[i], dp_let_go);
        
        // Update dp_defeat to be the maximum between the previous dp_let_go value and the experience gained by defeating the current monster plus its strength if it's an even-indexed monster
        dp_defeat = max(temp + (i % 2 == 0 ? a[i] * 2 : a[i]), dp_defeat);
    }

    // Output the maximum of the two possible final states: defeating the last monster or letting it go
    cout << max(dp_defeat, dp_let_go) << endl;
}