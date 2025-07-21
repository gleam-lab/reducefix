#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    int m = n - k;
    int ans = INT_MAX;
    for (int i = 0; i + m <= n; i++) {
        ans = min(ans, num[i + m - 1] - num[i]);
    }
    cout << ans << endl;
    return 0;
}