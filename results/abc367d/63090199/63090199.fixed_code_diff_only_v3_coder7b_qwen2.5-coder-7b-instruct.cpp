#include<bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) { // Calculate prefix sum
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int count = 0;
    // Find possible (s, t) pairs
    for (int s = 0; s <= n - 1; s++) {
        for (int t = s + 1; t <= n - 1; t++) {
            int step = prefixSum[t + 1] - prefixSum[s];
            if (step % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}