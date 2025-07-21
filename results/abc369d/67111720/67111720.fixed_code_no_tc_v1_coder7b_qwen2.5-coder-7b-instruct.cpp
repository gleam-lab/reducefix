#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // Initialize dp arrays for even and odd indexed monsters
    vector<ll> dp_even(n, 0);
    vector<ll> dp_odd(n, 0);

    // Base case for the first monster
    dp_even[0] = 0; // Letting the first monster go
    dp_odd[0] = a[0]; // Defeating the first monster

    // Fill the dp arrays
    for(int i = 1; i < n; ++i){
        if(i % 2 == 0){ // Current monster index is even
            dp_even[i] = max(dp_even[i-1], dp_odd[i-1]); // Either let the previous one go or defeat it
            dp_odd[i] = dp_even[i-1] + 2 * a[i]; // Defeat the current monster and add bonus for being at an even position
        } else { // Current monster index is odd
            dp_even[i] = dp_even[i-1] + a[i]; // Defeat the current monster and add bonus for being at an even position
            dp_odd[i] = max(dp_even[i-1], dp_odd[i-1]); // Either let the previous one go or defeat it
        }
    }

    // Output the maximum experience points
    cout << max(dp_even[n-1], dp_odd[n-1]) << endl;
}