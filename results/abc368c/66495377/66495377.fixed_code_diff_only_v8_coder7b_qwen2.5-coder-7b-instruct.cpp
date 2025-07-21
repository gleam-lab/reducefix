#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll t, ll h) {
    ll cnt = 0;
    // Directly calculate the number of attacks based on the health and time modulo 3
    if (t % 3 == 0) {
        cnt = (h + 2) / 3; // For multiples of 3, each attack reduces health by 3
    } else {
        cnt = (h + 1) / 2; // Otherwise, each attack reduces health by 1
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t += num_attack(t, h); // Update the total time after each attack calculation
    }

    cout << t << endl;
}