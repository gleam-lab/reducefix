#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canDefeat(const vector<ll>& H, ll T) {
    ll total_attacks = 0;
    for (ll h : H) {
        ll attacks_needed;
        if (T >= h) {
            attacks_needed = (h + 2) / 3;
        } else {
            ll remaining = h - T;
            attacks_needed = T + (remaining + 1) / 2;
        }
        if (attacks_needed > T) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll left = 0;
    ll right = *max_element(H.begin(), H.end()) * 3;
    ll answer = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (canDefeat(H, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}