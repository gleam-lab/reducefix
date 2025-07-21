#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    ll T = 0;
    for (int i = 0; i < N; ++i) {
        ll h = H[i];
        ll groups = h / 5;
        ll rem = h % 5;
        T += 3 * groups;
        if (rem > 0) {
            if (T % 3 == 0) {
                if (rem <= 3) {
                    T += 1;
                } else {
                    T += 2;
                }
            } else if (T % 3 == 1) {
                if (rem == 1) {
                    T += 1;
                } else if (rem == 2) {
                    T += 2;
                } else if (rem == 3) {
                    T += 2;
                } else if (rem == 4) {
                    T += 3;
                }
            } else if (T % 3 == 2) {
                if (rem == 1) {
                    T += 1;
                } else if (rem == 2) {
                    T += 1;
                } else if (rem == 3) {
                    T += 2;
                } else if (rem == 4) {
                    T += 2;
                }
            }
        }
    }
    cout << T << endl;
    return 0;
}