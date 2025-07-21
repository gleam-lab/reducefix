#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long ans = LLONG_MAX;
    for(int i = 0; i <= k; ++i) {
        ans = min(ans, arr[n-1-i] - arr[i]);
    }

    cout << ans << '\n';

    return 0;
}