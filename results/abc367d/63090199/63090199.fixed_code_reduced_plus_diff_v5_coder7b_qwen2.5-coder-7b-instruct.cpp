#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums, prefixSum;

void preprocess() {
    prefixSum.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
}

bool isValid(int s, int t) {
    if (s == t) return false;
    int step = (s <= t) ? prefixSum[t] - prefixSum[s] : prefixSum[n] - prefixSum[s] + prefixSum[t];
    return step % m == 0;
}

int main() {
    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    preprocess();

    int count = 0;
    for (int s = 1; s <= n; ++s) {
        for (int t = 1; t <= n; ++t) {
            if (isValid(s, t)) {
                ++count;
            }
        }
    }

    cout << count << endl;
    return 0;
}