#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll low = 0, high = 1e18;
    ll answer = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total = 0;
        bool possible = true;

        for (ll h : H) {
            ll damage = mid + 2 * (mid / 3);
            if (damage < h) {
                possible = false;
                break;
            }
        }

        if (possible) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}