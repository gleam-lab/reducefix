#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    queue<ll> triple_attacks; // Stores times where triple attack is available

    for (ll h : H) {
        // Determine how many attacks of each type are needed
        ll full_cycles = h / 5;
        ll remainder = h % 5;

        // Add three attacks per full cycle: two regular, one triple
        for (ll i = 0; i < full_cycles; ++i) {
            triple_attacks.push(T + 2);
            T += 3;
        }

        // Now handle the remainder
        while (remainder > 0) {
            if (!triple_attacks.empty() && triple_attacks.front() == T) {
                // Triple attack available
                remainder -= 3;
                triple_attacks.pop();
            } else {
                // Regular attack
                remainder -= 1;
            }
            T++;
        }
    }

    cout << T << endl;
}