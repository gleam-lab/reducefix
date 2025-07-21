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
        if (data[i + 1] * 2 > data[i] + data[i + 1]) {
            sum += data[i + 1] * 2;
            i++; // Skip the next element as it's already counted
        } else {
            sum += max(data[i], data[i + 1]);
        }
    }
    // Add the last element if it's not included yet
    if (n % 2 != 0) {
        sum += data[n - 1];
    }

    cout << sum << endl;
    return 0;
}