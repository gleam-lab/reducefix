#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        unordered_map<int, int> prefix_count;
        prefix_count[0]++;
        for (int j = 0; j < n; ++j) {
            sum = (sum + arr[(i + j) % n]) % m;
            ans = (ans + prefix_count[(sum * m + m - (arr[(i + j) % n] % m)) % m]) % MOD;
            prefix_count[sum]++;
        }
    }

    cout << ans << '\n';
    return 0;
}