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
        // If we're not at the last element, check whether pairing is beneficial
        if (i + 1 < n && data[i] + data[i+1] < 2 * max(data[i], data[i+1])) {
            // Use the special rule for two consecutive elements
            sum += 2 * max(data[i], data[i+1]);
            i += 2; // Skip the next element since we've paired it
        } else {
            // Otherwise, just add the current element normally
            sum += data[i];
            i++;
        }
    }

    cout << sum << endl;
    return 0;
}