#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + nums[i]) % m;
    }

    long long total_sum = prefix[n];
    long long count = 0;
    unordered_map<int, int> freq;

    for (int i = 1; i <= n; i++) {
        int target = (prefix[i] - total_sum) % m;
        if (target < 0) target += m;
        count += freq[target];
        freq[prefix[i] % m]++;
    }

    cout << count << endl;
    return 0;
}