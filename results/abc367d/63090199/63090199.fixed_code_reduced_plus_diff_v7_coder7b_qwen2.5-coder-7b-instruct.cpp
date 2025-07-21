#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    long long count = 0;
    for (int s = 1; s <= n; ++s) {
        for (int t = s + 1; t <= n; ++t) {
            int step = prefixSum[t] - prefixSum[s - 1];
            if (step % m == 0) {
                count += t - s;
            }
        }
    }

    cout << count << endl;
    return 0;
}