#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) { // Calculate prefix sum
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    int count = 0;
    // Find possible (s, t) pairs
    for (int s = 0; s < n; s++) {
        for (int t = s + 1; t < n; t++) {
            int step = prefix_sum[t + 1] - prefix_sum[s];
            if (step % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}