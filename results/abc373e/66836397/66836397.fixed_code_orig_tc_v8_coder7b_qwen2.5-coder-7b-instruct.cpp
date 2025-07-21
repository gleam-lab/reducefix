#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, K;
    cin >> n >> m >> K;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        K -= a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> ac(n + 1, 0);
    for (long long i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + a[i];
    }

    vector<long long> ans(n, -1);
    for (long long i = 0; i < n; ++i) {
        if (i >= m) {
            ans[i] = 0;
            continue;
        }

        long long needed = 0;
        for (long long j = i + 1; j < n; ++j) {
            long long gap = a[j] - a[i];
            needed += max(gap, 0LL);
        }

        if (needed <= K) {
            ans[i] = needed;
        }
    }

    for (long long i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}