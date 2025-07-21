#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    ll tri = 1;

    for (ll i = 0; i < N; ++i) {
        ll h = H[i];
        // Calculate the number of full cycles (3 attacks)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h %= 5;

        // Handle the remaining attacks
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