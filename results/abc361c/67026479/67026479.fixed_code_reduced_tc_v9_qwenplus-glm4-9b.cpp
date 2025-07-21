#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> prefix_sum(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1].first = prefix_sum[i].first + a[i];
        prefix_sum[i + 1].second = max(prefix_sum[i].second, a[i]);
    }

    int ans = INT_MAX;
    for (int i = k; i <= n; i++) {
        ans = min(ans, prefix_sum[i].first - (prefix_sum[i - k].second * i));
    }

    cout << ans << endl;
    return 0;
}