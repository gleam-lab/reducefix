#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_possible(const vector<ll>& H, ll T) {
    int n = H.size();
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) h[i] = H[i];

    // We'll simulate how many attacks are used per enemy
    ll attacks_used = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] <= 0) continue;
        ll remaining_attacks = T - attacks_used;
        if (remaining_attacks <= 0) return false;

        // Determine how many triple attacks can occur in remaining_attacks
        ll triple_turns = remaining_attacks / 3;
        ll single_turns = remaining_attacks - triple_turns;

        // Now distribute these attacks to minimize damage
        // Try to maximize triple attacks
        ll max_damage = triple_turns * 3 + single_turns * 1;
        if (h[i] > max_damage) return false;

        // Compute minimum number of attacks needed to eliminate h[i]
        // Use greedy method: as many triple attacks as possible
        ll needed_triple = (h[i] + 2) / 3;
        ll needed_single = max(0LL, h[i] - 3 * needed_triple);
        ll total_needed = needed_triple + needed_single;

        // Check if enough attacks remain
        if (total_needed > remaining_attacks) return false;

        attacks_used += total_needed;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> H(N);
    ll total_health = 0;
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        total_health += H[i];
    }

    ll low = 0;
    ll high = 3 * total_health; // Upper bound estimation

    while (low < high) {
        ll mid = (low + high) / 2;
        if (is_possible(H, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;
}