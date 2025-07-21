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
    int min_diff = INT_MAX;
    for (int i = 0; i + (n - k) - 1 < n; ++i) {
        min_diff = min(min_diff, num[i + (n - k) - 1] - num[i]);
    }
    cout << min_diff << endl;
    return 0;
}