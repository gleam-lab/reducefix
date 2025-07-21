#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll left = 0;
    ll right = 1e18;
    ll answer = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        vector<ll> temp = H;
        ll t = mid;
        bool possible = true;

        for (int i = 0; i < N; ++i) {
            ll normal_attacks = (t + 2) / 3;  // Number of attacks that are 1, 4, 7, etc.
            ll strong_attacks = t / 3;         // Number of attacks that are 3, 6, 9, etc.
            ll total_damage = normal_attacks + 3 * strong_attacks;
            if (total_damage < temp[i]) {
                possible = false;
                break;
            }
            // To find the minimal t for all enemies, we need to ensure each is covered
        }

        if (possible) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}