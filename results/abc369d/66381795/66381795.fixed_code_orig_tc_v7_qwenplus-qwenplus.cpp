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
        // If we are at the last element, just add it once
        if (i == n - 1) {
            sum += data[i];
            i++;
            continue;
        }
        
        // Try to form a pair where second is larger or equal
        if (data[i+1] >= data[i]) {
            sum += data[i+1] * 2;
            i += 2;
        } else {
            // Otherwise, take single element and move one step
            sum += data[i];
            i++;
        }
    }

    cout << sum << endl;
    return 0;
}