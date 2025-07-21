#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
vector<int> prefixSum;

void calculatePrefixSum() {
    prefixSum.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
}

int main() {
    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    calculatePrefixSum();

    int count = 0;
    for (int s = 0; s < n; ++s) {
        for (int t = s + 1; t < n; ++t) {
            int step = prefixSum[t + 1] - prefixSum[s];
            if (step % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}