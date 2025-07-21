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
    map<int, int> modCount;
    long long count = 0;

    // Count pairs (s, t) such that (t - s) % m == 0
    for (int t = 1; t <= n; t++) {
        for (int s = 1; s < t; s++) {
            int step = (t - s) % m;
            if (step < 0) step += m; // Ensure non-negative modulo result
            modCount[step]++;
        }
    }

    // Calculate valid pairs that satisfy the condition
    for (int k = 0; k < m; k++) {
        if (modCount[k] > 0) {
            count += modCount[k] * (modCount[k] - 1) / 2; // Combination of two from modCount[k]
        }
    }

    cout << count << endl;
    return 0;
}