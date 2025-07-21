#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int n;
vector<ll> data;

int main() {
    cin >> n;
    data.resize(n);
    rep(i, n) {
        cin >> data[i];
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 1) {
            sum += data[i];
        } else {
            sum += min(data[i], data[i + 1]);
            i++; // Skip the next element as it's already considered
        }
    }

    cout << sum << endl;
    return 0;
}