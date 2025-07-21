#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Find the maximum votes any candidate currently has
    long long max_votes = *max_element(a.begin(), a.end());

    vector<long long> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        if(a[i] >= max_votes + 1) {
            ans[i] = 0;
        } else {
            ans[i] = max_votes + 1 - a[i];
        }
    }

    for(auto x : ans) {
        cout << x << " ";
    }
    return 0;
}