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
    for (int i = 0; i < n - 1; ++i) {
        if (data[i] * 2 > data[i + 1] + data[i]) {
            // If current element doubled is greater than the next element plus itself, double it.
            sum += data[i] * 2;
            i++;  // Skip the next element as it's already included in the current addition.
        } else if (i % 2 == 0) {
            // If the index is even, double the current element.
            sum += data[i] * 2;
        } else {
            // If the index is odd, add the current element without doubling.
            sum += data[i];
        }
    }

    // Add the last element separately as it won't be handled in the loop.
    sum += data[n - 1];

    cout << sum << endl;
    return 0;
}