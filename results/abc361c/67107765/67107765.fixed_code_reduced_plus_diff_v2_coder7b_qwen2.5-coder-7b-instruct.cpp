#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    // Sort the array
    sort(num.begin(), num.end());

    // Calculate the result
    int ans = INT_MAX;
    for(int i = 0; i <= n-k; ++i) {
        ans = min(ans, num[i+k-1] - num[i]);
    }

    cout << ans << endl;
    return 0;
}