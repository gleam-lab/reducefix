#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) { // Calculate prefix sums
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    int count = 0;
    // Find possible (s, t) pairs
    for (int s = 1; s <= n; s++) {
        for (int t = s + 1; t <= n; t++) { // Ensure s < t to avoid counting the same pair twice
            int step = prefixSum[t] - prefixSum[s];
            if (step % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}