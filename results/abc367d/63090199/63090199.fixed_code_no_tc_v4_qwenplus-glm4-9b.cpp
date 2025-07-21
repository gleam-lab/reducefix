#include<bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<long long> prefixsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixsum[i + 1] = prefixsum[i] + nums[i];
    }
    int count = 0;

    // To handle large values caused by repeated additions, use a set to store remainders
    map<int, int> remainderCount;
    // To handle the case where t < s, use an array to store the prefix sums
    long long prefixSums[n + 1];

    for (int s = 1; s <= n; s++) {
        prefixSums[s] = prefixsum[s];
        for (int t = 1; t <= n; t++) {
            if (s == t) continue;
            long long step = prefixSums[t] - prefixSums[s];
            // Convert step to remainder modulo m
            int remainder = step % m;
            // If there is already a remainder with the same count, increment count
            if (remainderCount[remainder] > 0) {
                count += remainderCount[remainder];
            }
            // Increment the count of this remainder
            remainderCount[remainder]++;
        }
    }

    cout << count << endl;
    return 0;
}