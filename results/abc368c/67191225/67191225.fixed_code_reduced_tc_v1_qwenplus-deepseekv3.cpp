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
        ll cycles = h / 5;
        T += cycles * 3;
        h %= 5;
        if (h > 0) {
            if (T % 3 == 0) {
                if (h <= 3) {
                    T += 1;
                } else {
                    T += 3;
                }
            } else if (T % 3 == 1) {
                if (h <= 1) {
                    T += 1;
                } else if (h <= 3) {
                    T += 2;
                } else {
                    T += 3;
                }
            } else { // T % 3 == 2
                if (h <= 2) {
                    T += 1;
                } else if (h <= 4) {
                    T += 2;
                } else {
                    T += 3;
                }
            }
        }
    }
    cout << T << endl;
    return 0;
}