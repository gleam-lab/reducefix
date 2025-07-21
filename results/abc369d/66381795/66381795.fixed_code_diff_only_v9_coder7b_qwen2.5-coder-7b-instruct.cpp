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
    for (int i = 0; i < n - 1; i++) {
        if ((data[i + 1] * 2 > data[i] + data[i + 1]) && ((i + 1) % 2 == 0)) {
            sum += data[i + 1] * 2;
        } else if ((i + 1) % 2 == 0) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }

    // Add the last element as it is not considered in the loop
    sum += data[n - 1];

    cout << sum << endl;
    return 0;
}