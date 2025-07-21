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
    ll add = 0; // This will track the additional attacks needed due to overlapping T increments

    for (int i = 0; i < N; i++) {
        H[i] -= add;
        if (H[i] <= 0) continue;

        ll a = H[i] / 3;
        ll rem = H[i] % 3;

        if (rem == 0) {
            T += a * 3;
            add += a;
        } else if (rem == 1) {
            T += a * 3 + 1;
            add += a;
        } else if (rem == 2) {
            if (a == 0) {
                T += 2;
                add += 1;
            } else {
                T += a * 3 + 2;
                add += a + 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}