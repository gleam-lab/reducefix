#include <bits/stdc++.h>
using namespace std;

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
    int ans = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int left = i;
        int right = n - k + i - 1;
        ans = min(ans, num[right] - num[left]);
    }
    cout << ans << endl;
    return 0;
}