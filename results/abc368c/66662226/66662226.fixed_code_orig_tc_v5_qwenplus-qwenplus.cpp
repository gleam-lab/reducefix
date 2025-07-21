#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to simulate attacks on a single enemy
// Returns the number of steps required to reduce health to 0 or less
ll steps_to_defeat(ll h) {
    ll low = 0, high = 2 * h; // upper bound for binary search
    while (low < high) {
        ll mid = (low + high) / 2;
        // Calculate how many triple-damage attacks can be made in 'mid' steps
        ll triple_attacks = mid / 3;
        ll normal_attacks = mid - triple_attacks;
        ll damage = triple_attacks * 3 + normal_attacks * 1;
        if (damage >= h)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    // We will use a priority queue to always attack the leftmost enemy with positive health
    // Each element is {index, current_health}
    queue<pair<int, ll>> q;
    for (int i = 0; i < n; ++i) {
        if (H[i] > 0)
            q.push({i, H[i]});
    }

    ll T = 0;
    while (!q.empty()) {
        auto [idx, h] = q.front();
        q.pop();

        T++;
        if (T % 3 == 0) {
            h -= 3;
        } else {
            h -= 1;
        }

        if (h > 0) {
            q.push({idx, h});
        }
    }

    cout << T << endl;
    return 0;
}