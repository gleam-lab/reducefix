#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> dp_even, dp_odd;

    rep(i, n) {
        ll temp_even = dp_even.empty() ? 0 : dp_even.back();
        ll temp_odd = dp_odd.empty() ? 0 : dp_odd.back();
        dp_even.push_back(max(temp_odd + 2 * i, temp_even));
        dp_odd.push_back(max(temp_even + i, temp_odd));
    }

    cout << max(dp_even.back(), dp_odd.back()) << endl;
}