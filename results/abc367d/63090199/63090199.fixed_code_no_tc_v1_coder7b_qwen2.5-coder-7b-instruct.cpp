#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Calculate prefix sums
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    long long count = 0;
    
    // Iterate over all possible pairs (s, t)
    for (int s = 0; s < n; s++) {
        for (int t = s + 1; t < n; t++) {
            long long step;
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

    cout << count << endl;
    return 0;
}