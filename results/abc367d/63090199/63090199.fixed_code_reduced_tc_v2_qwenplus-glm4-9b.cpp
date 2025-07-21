#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }
    int count = 0;
    // Use a map to store the frequency of remainders when divided by m
    map<int, int> remainder_count;
    for (int i = 0; i <= n; i++) {
        int rem = (i == 0) ? 0 : (prefix_sum[i] % m);
        remainder_count[rem]++;
    }
    // For each unique remainder, calculate the number of valid (s, t) pairs
    for (auto &pair : remainder_count) {
        int rem = pair.first;
        int count = pair.second;
        // When remainder is 0, the number of pairs is count * (count - 1) / 2
        // When remainder is not 0, the number of pairs is count * (count - 1) / 2 + count
        int pairs = (rem == 0) ? count * (count - 1) / 2 : count * (count - 1) / 2 + count;
        count += pairs;
    }
    cout << count << endl;
    return 0;
}