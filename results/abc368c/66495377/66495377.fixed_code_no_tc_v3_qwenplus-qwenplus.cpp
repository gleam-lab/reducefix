#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// This function computes how many attacks are needed to reduce health h to <= 0,
// assuming the current time is t (which affects whether attacks are triple damage).
ll num_attack(ll t, ll h) {
    // We binary search the number of attacks needed
    ll low = 0;
    ll high = 2 * h; // upper bound on number of attacks needed

    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = 0;
        ll cnt3 = mid - mid / 3; // Number of times attack is NOT multiple of 3 -> normal attacks
        ll cnt1 = mid / 3;       // Triple damage attacks

        damage = cnt3 + cnt1 * 3;

        if (damage >= h)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll attacks_needed = num_attack(t, H[i]);
        t += attacks_needed;
    }

    cout << t << endl;
}