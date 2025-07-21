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
    rep(i, n - 1) { // Adjust loop to avoid out-of-bounds access
        if ((i + 1) % 2 == 0 && data[i] * 2 > data[i] + data[i + 1]) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }
    sum += data[n - 1]; // Add the last element as it's not processed in the loop

    cout << sum << endl;
    return 0;
}