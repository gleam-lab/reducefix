#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
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
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    cout << min_diff << endl;

    return 0;
}