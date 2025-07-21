#include <iostream>
#include <vector>
#include <algorithm>

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
    for (ll health : H) {
        T += (health + 2) / 3; // This rounds up the division by 3
    }
    cout << T << endl;
    return 0;
}