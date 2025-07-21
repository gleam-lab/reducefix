#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> prefix_sum_count;
        prefix_sum_count[0]++;
        int current_sum = 0;
        for (int j = 0; j < n; ++j) {
            current_sum = (current_sum + arr[(i + j) % n]) % m;
            if (prefix_sum_count.find(current_sum) != prefix_sum_count.end()) {
                ans = (ans + prefix_sum_count[current_sum]) % MOD;
            }
            prefix_sum_count[current_sum]++;
        }
    }
    cout << ans << '\n';
    return 0;
}