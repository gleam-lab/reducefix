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
    int i = 0;
    while (i < n) {
        // If we are at the last element or it's better not to pair, take it as single
        if (i == n - 1 || 2 * data[i + 1] <= data[i]) {
            sum += data[i];
            i++;
        } else {
            // Otherwise, pair current and next
            sum += 2LL * data[i + 1];
            i += 2;
        }
    }

    cout << sum << endl;
    return 0;
}