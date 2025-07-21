#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n), prefixsum(n + 1), count(1000000007, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    prefixsum[0] = 0;
    for (int i = 0; i < n; i++) {
        prefixsum[i + 1] = (prefixsum[i] + nums[i]) % m;
        count[prefixsum[i + 1]]++;
    }
    
    int total = n * (n + 1) / 2; // Calculate the total number of (s, t) pairs
    // Subtract invalid pairs (s, t) where s == t
    total -= n;
    // Subtract pairs (s, t) where prefixsum[t] - prefixsum[s] != 0 (which is always true)
    // Subtract pairs (s, t) where prefixsum[t] - prefixsum[s] % m != 0
    for (int i = 0; i < m; i++) {
        if (count[i] > 0) {
            total -= count[i];
        }
    }
    cout << total << endl;
    return 0;
}