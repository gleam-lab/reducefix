#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m, ans = 0;
    cin >> n >> m;
    vector<long long> a(n), prefix_sum(n + 1, 0);
    unordered_map<int, int> count;

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
        count[prefix_sum[i + 1]]++;
    }

    for (auto& [_, freq] : count) {
        ans += freq * (freq - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}