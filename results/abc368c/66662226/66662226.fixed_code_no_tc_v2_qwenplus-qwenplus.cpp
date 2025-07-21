#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // We'll simulate the process from left to right
    // and handle each enemy's health one by one.

    for (int i = 0; i < n; ++i) {
        // Determine how many attacks of each type are needed
        // Each second attack at this position is a "3 damage" attack on T % 3 == 0

        // Let's find how many full triplets (1,1,3) we can do
        // Each triplet takes 3 turns and deals 5 damage total (1+1+3)

        ll h = H[i];
        if (h <= 0) continue;

        // Binary search to find minimum number of attacks needed
        // Let's perform binary search on answer T

        ll low = 0, high = 2e18;
        while (low < high) {
            ll mid = (low + high) / 2;
            // Calculate how much damage we can deal in mid attacks
            ll three_attacks = mid / 3;
            ll one_attacks = mid - three_attacks;
            ll damage = three_attacks * 3 + one_attacks * 1;
            if (damage >= h) high = mid;
            else low = mid + 1;
        }

        // low is the number of attacks needed starting from this enemy
        T = max(T, low);
        
        // Move to next enemies, but remember that time continues
        // No need to subtract damage explicitly because we're only tracking final T
    }

    cout << T << endl;

    return 0;
}