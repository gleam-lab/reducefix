#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
vector<int> prefixSum;

void precomputePrefixSum() {
    prefixSum.push_back(0); // Initialize with 0
    for (int i = 0; i < n; ++i) {
        prefixSum.push_back(prefixSum.back() + nums[i]);
    }
}

int findValidPairs() {
    int count = 0;
    for (int s = 0; s < n; ++s) {
        for (int t = s + 1; t < n; ++t) {
            int step;
            if (s <= t) {
                step = prefixSum[t + 1] - prefixSum[s];
            } else {
                step = prefixSum[n] - prefixSum[s] + prefixSum[t + 1];
            }
            if (step % m == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    precomputePrefixSum();
    int result = findValidPairs();

    cout << result << endl;
    return 0;
}