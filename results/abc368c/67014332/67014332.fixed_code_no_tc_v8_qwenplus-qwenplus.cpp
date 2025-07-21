#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    deque<ll> dq;
    for (ll i = 0; i < N; ++i) {
        ll h;
        cin >> h;
        dq.push_back(h);
    }

    ll time = 0;
    ll triple_attack_time = 0; // Counts how many times we've waited for a triple attack

    while (!dq.empty()) {
        time++;
        if (time % 3 == 0) {
            // Triple attack at this time step
            if (dq.front() <= 3) {
                dq.pop_front();
            } else {
                dq.front() -= 3;
            }
        } else {
            // Single attack
            if (dq.front() == 1) {
                dq.pop_front();
            } else {
                dq.front()--;
            }
        }

        // If there are more enemies and the current front enemy has <= 0 health, remove it
        while (!dq.empty() && dq.front() <= 0) {
            dq.pop_front();
        }
    }

    cout << time << "\n";
}