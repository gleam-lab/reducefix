#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int m = n - k; // number of remaining elements
    long long min_diff = 1e18;

    for (int i = 0; i <= k; i++) {
        int j = i + m - 1;
        if (j < n) {
            min_diff = min(min_diff, (long long)(a[j] - a[i]));
        }
    }

    cout << min_diff << endl;
    return 0;
}