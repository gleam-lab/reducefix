#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> nums;
vector<long long> prefixsum;

long long countValidPairs() {
    long long count = 0;
    for (int s = 1; s <= n; ++s) {
        for (int t = s + 1; t <= n; ++t) {
            long long step = prefixsum[t] - prefixsum[s - 1];
            if (step % m == 0) {
                count += n - t + 1;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nums.resize(n);
    prefixsum.resize(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        prefixsum[i + 1] = prefixsum[i] + nums[i];
    }

    long long result = countValidPairs();
    cout << result << endl;

    return 0;
}