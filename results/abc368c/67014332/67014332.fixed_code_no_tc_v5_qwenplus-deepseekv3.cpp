#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(const vector<ll>& H, ll T) {
    ll remaining = 0;
    for (auto h : H) {
        ll needed = (h + 2) / 3; // Minimum attacks if all are triple attacks
        if (T < needed) return false;
        remaining += max(0LL, (3 * h - T + 3 - 1) / 3);
    }
    return remaining <= T;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; ++i) cin >> H[i];

    ll left = 0, right = 3 * 1e14; // Upper bound based on max H_i and N
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (isPossible(H, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}