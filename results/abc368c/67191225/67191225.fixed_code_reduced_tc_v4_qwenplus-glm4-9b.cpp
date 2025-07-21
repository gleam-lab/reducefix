#include <iostream>
#include <vector>
#include <cmath>

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
    for (ll i = 0; i < N; i++) {
        while (H[i] > 0) {
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i]--;
            }
            T++;
            if (H[i] <= 0) {
                break;
            }
        }
    }
    cout << T << endl;
    return 0;
}