#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    ll sum = 0;
    bool used = false;

    for (int i = 0; i < n; ++i) {
        if (used) {
            used = false;
            continue;
        }
        // If at last element or choose to not pair
        if (i == n - 1 || data[i] + data[i] >= data[i + 1]) {
            sum += data[i];
        } else {
            // Pair current and next
            sum += data[i + 1] * 2;
            used = true; // mark next as used
        }
    }

    cout << sum << endl;
    return 0;
}