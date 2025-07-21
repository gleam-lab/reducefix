#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
long long a[N * 2];
map<int, int> cnt;
long long sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    // Prefix sum array
    long long prefix = 0;
    cnt[0] = 1;  // To count subarrays starting from index 0

    for (int i = 1; i < 2 * n; ++i) {
        prefix += a[i];
        int mod = ((prefix % m) + m) % m;  // Handle negative mods if any
        sum += cnt[mod];
        if (i < n) {
            cnt[mod]++;
        }
    }

    cout << sum << endl;
    return 0;
}