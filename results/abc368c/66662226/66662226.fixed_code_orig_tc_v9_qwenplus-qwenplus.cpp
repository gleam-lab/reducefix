#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to calculate the number of attacks needed for one enemy
ll compute_attacks(int health) {
    // Each cycle is 3 seconds:
    // - On T % 3 == 0 => damage 3
    // - Else => damage 1
    // So in 3 seconds, max damage is 5

    ll full_cycles = health / 5;
    ll time_used = full_cycles * 3;
    ll damage_done = full_cycles * 5;

    int remaining = health - damage_done;

    if (remaining <= 0) return time_used;

    time_used++;
    if (time_used % 3 == 0) remaining -= 3;
    else remaining--;

    if (remaining <= 0) return time_used;

    time_used++;
    if (time_used % 3 == 0) remaining -= 3;
    else remaining--;

    if (remaining <= 0) return time_used;

    time_used++;
    if (time_used % 3 == 0) remaining -= 3;
    else remaining--;

    return time_used;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll total_time = 0;

    // We process enemies from left to right
    for (int h : H) {
        total_time += compute_attacks(h);
    }

    cout << total_time << endl;

    return 0;
}