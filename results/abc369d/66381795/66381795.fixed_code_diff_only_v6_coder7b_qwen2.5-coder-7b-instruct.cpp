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
    rep(i, n - 1) { // Iterate up to n-1 to avoid out-of-bounds access
        if ((data[i + 1] * 2 > data[i] + data[i + 1]) && ((i + 1) % 2 == 0)) {
            sum += data[i + 1] * 2;
            i++; // Skip the next element as it's already counted
        } else if ((i + 1) % 2 == 0) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }

    // Add the last element if it exists
    if (n > 0) {
        sum += data[n - 1];
    }

    cout << sum << endl;
    return 0;
}