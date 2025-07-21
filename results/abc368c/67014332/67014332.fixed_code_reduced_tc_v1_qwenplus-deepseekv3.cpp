#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(ll T, vector<ll>& H) {
    ll total = 0;
    for (ll h : H) {
        ll attacks = (h + 1) / 2; // Initial guess, but need better calculation
        ll t3 = (T + 2) / 3;
        ll t1 = T - t3;
        if (3 * t3 + t1 < h) return false;
        // Calculate the exact number of t3 and t1 attacks needed
        ll req3 = max(0LL, (h - t1 + 2) / 3);
        if (req3 > t3) return false;
    }
    return true;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll left = 0;
    ll right = 3 * *max_element(H.begin(), H.end());
    ll ans = right;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll t3 = mid / 3;
        ll t1 = mid - t3;
        bool possible = true;
        for (ll h : H) {
            ll req3 = max(0LL, (h - t1 + 2) / 3);
            if (req3 > t3) {
                possible = false;
                break;
            }
        }
        if (possible) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}