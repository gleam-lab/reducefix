#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Compute prefix sums
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    int count = 0;
    // Count pairs (s, t) such that (t - s) mod m == 0
    for (int s = 1; s <= n; s++) {
        for (int t = 1; t <= n; t++) {
            if (t < s) continue; // Ensure that s < t
            int step = (t - s) % m; // No need to calculate prefix sums difference here
            if (step == 0) {
                count++; // t - s is a multiple of m
            }
        }
    }

    cout << count << endl;
    return 0;
}