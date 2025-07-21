#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    ll sum = 0;
    int i = 0;
    while (i < n) {
        if (i + 1 < n && data[i+1] > data[i]) {
            // Use pair: take both and add max of the two
            sum += data[i] + data[i+1];
            i += 2;
        } else {
            // Take single value
            sum += data[i];
            i++;
        }
    }

    cout << sum << endl;
    return 0;
}