#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 1LL << 60; // A large initial value
    for (int l = 0; l <= n - k; ++l) {
        int r = l + k;
        ans = min(ans, (long long)a[r - 1] - a[l]);
    }

    cout << ans << endl;
    return 0;
}