#include<iostream>
#include<vector>

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
        ll remaining = H[i];
        // The number of full triple attacks (each triple attack deals 5 damage)
        ll full_cycles = remaining / 5;
        T += full_cycles * 3;
        remaining %= 5;
        if (remaining == 0) continue;
        // Now handle the remaining health with individual attacks
        while (remaining > 0) {
            T++;
            if (T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}