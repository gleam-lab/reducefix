#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    long long count = 0;
    for (int s = 0; s <= n; ++s) {
        for (int t = 0; t <= n; ++t) {
            if (s == t) continue;
            long long step = 0;
            if (s < t) {
                step = prefix_sum[t] - prefix_sum[s];
            } else {
                step = prefix_sum[n] - prefix_sum[s] + prefix_sum[t];
            }
            if (step % m == 0) {
                ++count;
            }
        }
    }

    cout << count << '\n';
    return 0;
}