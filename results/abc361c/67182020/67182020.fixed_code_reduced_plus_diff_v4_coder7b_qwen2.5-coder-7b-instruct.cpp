#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if(k % 2 == 0) {
        long long ans = INT_MAX;
        for(int i = 0; i <= n-k; ++i) {
            ans = min(ans, a[i+k-1] - a[i]);
        }
        cout << ans << '\n';
    } else {
        long long ans = INT_MAX;
        for(int i = 0; i <= n-k; ++i) {
            ans = min(ans, max(a[i+k-1] - a[i], a[i+k] - a[i+1]));
        }
        cout << ans << '\n';
    }

    return 0;
}