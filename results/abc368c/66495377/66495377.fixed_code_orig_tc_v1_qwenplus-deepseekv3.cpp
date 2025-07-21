#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_min_attacks(const vector<ll>& H) {
    ll low = 1, high = 3 * *max_element(H.begin(), H.end());
    ll answer = high;

    auto can_defeat = [&](ll T) {
        ll total_attacks = 0;
        for (ll h : H) {
            ll attacks_needed = (h + 2) / 3;  // ceil(h / 3)
            ll min_T = h;
            // The actual formula for damage at T is T + 2 * (T / 3)
            // So for each h, we need T + 2*(T/3) >= h
            // Let's find the minimal T such that T + 2*(T/3) >= h
            ll left = 1, right = 3 * h, best_T = 3 * h;
            while (left <= right) {
                ll mid = (left + right) / 2;
                ll damage = mid + 2 * (mid / 3);
                if (damage >= h) {
                    best_T = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            total_attacks = max(total_attacks, best_T);
        }
        return total_attacks <= T;
    };

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (can_defeat(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    cout << calculate_min_attacks(H) << '\n';

    return 0;
}