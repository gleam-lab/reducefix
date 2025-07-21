#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    long long count = 0;
    for (int s = 0; s <= n; ++s) {
        for (int t = 0; t <= n; ++t) {
            if (s == t) continue;
            int step = 0;
            if (s < t) {
                step = prefixSum[t] - prefixSum[s];
            } else {
                step = prefixSum[n] - prefixSum[s] + prefixSum[t];
            }
            if (step % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}