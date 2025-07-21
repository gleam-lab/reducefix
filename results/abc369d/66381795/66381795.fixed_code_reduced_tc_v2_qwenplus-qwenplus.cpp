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
        // If we're not at the end and it's beneficial to pair current with next
        if (i + 1 < n && data[i] + data[i+1] < 2 * max(data[i], data[i+1])) {
            sum += 2 * max(data[i], data[i+1]);
            i += 2; // Skip both elements
        } else {
            sum += data[i];
            i++; // Skip just the current element
        }
    }

    cout << sum << endl;
    return 0;
}