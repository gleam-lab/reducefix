#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = n - k;
    int min_diff = INT_MAX;

    for (int l = 0; l <= k; ++l) {
        int r = n - 1 - (k - l);
        if (r < l) continue; // This handles cases where m <= 0, although constraints prevent it
        int current_min = *min_element(a.begin() + l, a.begin() + r + 1);
        int current_max = *max_element(a.begin() + l, a.begin() + r + 1);
        min_diff = min(min_diff, current_max - current_min);
    }

    cout << min_diff << endl;
    return 0;
}