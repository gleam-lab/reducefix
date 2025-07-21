#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> prefixsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixsum[i + 1] = prefixsum[i] + nums[i];
    }
    vector<int> count(m, 0);
    // Calculate the prefix sum differences
    for (int s = 1; s <= n; s++) {
        for (int t = 1; t <= n; t++) {
            if (s == t) continue;
            int step;
            if (s < t) {
                step = prefixsum[t] - prefixsum[s];
            } else {
                step = prefixsum[n] - prefixsum[s-1];
            }
            if (step % m == 0) {
                count[step % m]++;
            }
        }
    }
    // Adjust the counts for each multiple of m to avoid overcounting
    int multipleOfM = m;
    for (int i = 1; i <= n; i++) {
        multipleOfM += m;
        count[multipleOfM]--;
    }
    // The answer is the sum of all valid counts
    int answer = 0;
    for (int i = 0; i < m; i++) {
        answer += count[i];
    }
    cout << answer << endl;
    return 0;
}