#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_possible(ll T, const vector<ll>& H) {
    ll total_attacks = 0;
    for (ll h : H) {
        ll x = (2 * h + 2) / 3; // Initial estimate for x + 2*(x/3) >= h
        ll low = 0, high = x;
        ll best_x = x;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (mid + 2 * (mid / 3) >= h) {
                best_x = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        total_attacks += best_x;
        if (total_attacks > T) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll left = 0;
    ll right = 1e18; // Upper bound for binary search
    ll answer = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (is_possible(mid, H)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}