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

    ll T = 0;
    for (ll i = 0; i < N; ++i) {
        ll h = H[i];
        // Calculate the number of full triple attacks (3, 6, 9,...)
        // Each full triple attack occurs every 3 steps and deals 3 damage.
        // The pattern is: 1, 1, 3, 1, 1, 3, etc.
        // So, for every two 1-damage attacks and one 3-damage attack (total 5 damage per 3 steps).
        ll full_cycles = h / 5;
        h %= 5;
        T += full_cycles * 3;
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}