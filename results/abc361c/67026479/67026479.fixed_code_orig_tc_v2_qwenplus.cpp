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

    int m = n - k; // size of the remaining sequence
    long long min_diff = 1e18;

    // We need to choose a contiguous segment of length m in the sorted array
    // because removing non-contiguous elements would only increase the range
    for (int i = 0; i + m - 1 < n; i++) {
        long long diff = a[i + m - 1] - a[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    cout << min_diff << endl;
    return 0;
}