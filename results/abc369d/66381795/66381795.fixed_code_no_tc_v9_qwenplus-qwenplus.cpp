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

    rep(i, n) {
        if (used) {
            used = false;
            continue;
        }
        // Try to pair data[i] with data[i+1] if it's better
        if (i + 1 < n && data[i+1] > (data[i] + data[i+1]) / 2) {
            sum += 2 * data[i+1];
            used = true; // Mark next element as used
        } else {
            sum += data[i];
        }
    }

    cout << sum << endl;
    return 0;
}