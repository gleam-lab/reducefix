#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < N; i++) {
        ll full_cycles = H[i] / 5;
        T += full_cycles * 3;
        ll remaining = H[i] % 5;

        if (remaining == 0) {
            continue;
        }

        ll mod = T % 3;
        if (mod == 0) {
            // Next attack is 3 damage
            if (remaining <= 3) {
                T += 1;
            } else {
                T += 2;
            }
        } else if (mod == 1) {
            // Next attack is 1 damage
            if (remaining == 1) {
                T += 1;
            } else if (remaining == 2) {
                T += 2;
            } else if (remaining == 3) {
                T += 3;
            } else { // remaining == 4
                T += 3;
            }
        } else { // mod == 2
            // Next attack is 1 damage, followed by 3 if needed
            if (remaining == 1) {
                T += 1;
            } else if (remaining == 2) {
                T += 2;
            } else if (remaining == 3) {
                T += 2;
            } else { // remaining == 4
                T += 3;
            }
        }
    }
    cout << T << endl;
    return 0;
}