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
    int count = 0;
    // Use a more efficient approach to avoid checking the same pairs multiple times
    for (int s = 1; s <= n; s++) {
        for (int t = s + 1; t <= n; t++) { // start t from s+1 to avoid duplicate pairs (s, t) and (t, s)
            if ((t - s) % m == 0) { // If the difference is divisible by m
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}