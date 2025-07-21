#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll time = 0;
    queue<int> q;

    // Initialize a queue to track enemies that need extra attacks after full cycles
    for (int i = 0; i < n; ++i) {
        ll full_cycles = H[i] / 5;
        time += full_cycles * 3;
        H[i] %= 5;

        while (H[i] > 0) {
            time++;
            if (time % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i]--;
            }
        }
    }

    cout << time << endl;
    return 0;
}