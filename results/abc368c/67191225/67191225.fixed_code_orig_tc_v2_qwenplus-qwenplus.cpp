#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < N; ++i) {
        // Compute number of triple hits and single hits needed
        ll h = H[i];
        ll triple_hits = h / 5 * 3;
        ll rem = h % 5;

        T += triple_hits;
        if (rem > 0) {
            T += 1;
            if (T % 3 == 0 && rem >= 3) {
                // Triple hit already counted
            } else if (T % 3 == 1) {
                if (rem == 1) {
                    // nothing extra
                } else if (rem == 2) {
                    T += 1;
                } else {
                    T += 2;
                }
            } else if (T % 3 == 2) {
                if (rem <= 1) {
                    T += 1;
                } else {
                    T += 2;
                }
            } else {
                T += 1;
            }
        }
    }

    cout << T << endl;
}