#include <iostream>
#include <vector>
#include <algorithm>

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
        ll health = H[i];
        while (health > 0) {
            if (T % 3 == 0) {
                health -= 3;
            } else {
                health -= 1;
            }
            T++;
        }
    }
    cout << T << endl;
    return 0;
}