#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int min_diff = INT_MAX;
    for (int i = 0; i <= n - k; ++i) {
        int diff = a[i + k - 1] - a[i];
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}