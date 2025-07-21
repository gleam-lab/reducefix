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
    int min_diff = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int j = i + (n - k) - 1;
        if (j >= n) continue;
        min_diff = min(min_diff, num[j] - num[i]);
    }
    cout << min_diff << endl;
    return 0;
}