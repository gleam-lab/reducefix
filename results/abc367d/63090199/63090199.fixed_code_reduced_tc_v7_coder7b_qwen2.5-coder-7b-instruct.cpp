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
    for (int i = 0; i < n; i++) { // Calculate prefix sums
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int count = 0;
    unordered_map<int, int> remainderCount;
    remainderCount[0] = 1; // Base case for empty subarray

    for (int i = 1; i <= n; i++) {
        int currentRemainder = prefixSum[i] % m;
        int targetRemainder = (currentRemainder * m / n) % m; // Target remainder for valid subarray

        if (remainderCount.find(targetRemainder) != remainderCount.end()) {
            count += remainderCount[targetRemainder];
        }

        remainderCount[currentRemainder]++;
    }

    cout << count << endl;
    return 0;
}