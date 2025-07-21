#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    // We simulate the process in batches using binary search
    // to find the minimum T such that all enemies are reduced to 0 or less.

    // The maximum possible T is when every attack does only 1 damage.
    // So upper bound can be sum of all healths.
    ll low = 0, high = 2e18;

    while (low < high) {
        ll mid = (low + high) / 2;
        vector<ll> remaining = H;
        bool ok = true;

        // For each enemy, calculate how much damage it receives by time T=mid
        // Each enemy gets attacked every time until it dies.
        // Let's simulate from left to right

        ll attacks_at_current_time = 0;

        for (int i = 0; i < n; ++i) {
            ll h = H[i];

            // Total number of attacks we can do on this enemy before time `mid`
            // Since we attack enemies from left to right and cannot go back,
            // this enemy gets attacked at most `mid` times, but only after previous enemies are dead.

            // Let's simulate how many attacks this enemy actually receives
            // considering that we move forward only when previous enemy health <= 0

            // Number of attacks this enemy will receive: let’s say x
            // We want to find the minimal x such that:
            // total damage = number of non-multiples of 3 + 3 * number of multiples of 3

            // For x attacks:
            // number of turns that are multiples of 3 = x / 3
            // other turns = x - x / 3
            // total damage = (x - x/3) + 3*(x/3) = x + (2 * x/3)

            // damage = x + (x / 3)

            // Binary search over x to find minimal x such that damage >= h
            ll l = 0, r = mid;
            while (l < r) {
                ll m = (l + r) / 2;
                ll damage = m + (m / 3);
                if (damage >= h) r = m;
                else l = m + 1;
            }
            // l is the required number of attacks on this enemy
            attacks_at_current_time += l;

            if (attacks_at_current_time > mid) {
                ok = false;
                break;
            }
        }

        if (ok) high = mid;
        else low = mid + 1;
    }

    cout << low << "\n";
}