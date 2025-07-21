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
    for (ll h : H) {
        T += (h + 2) / 3; // This is equivalent to ceil(h / 3)
    }
    cout << T << endl;
}