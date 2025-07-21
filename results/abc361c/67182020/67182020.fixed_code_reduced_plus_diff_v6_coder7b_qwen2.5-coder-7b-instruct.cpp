#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &a, int k) {
    sort(a.begin(), a.end());
    int n = a.size();
    long long ans = LLONG_MAX;
    for(int i = 0; i <= n-k; ++i) {
        ans = min(ans, a[i+k-1] - a[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << solve(a, k) << '\n';

    return 0;
}