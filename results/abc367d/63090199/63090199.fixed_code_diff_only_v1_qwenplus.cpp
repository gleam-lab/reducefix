#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Build prefix sum array
    vector<int> prefixsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixsum[i + 1] = (prefixsum[i] + nums[i]) % m;
    }

    long long count = 0;
    unordered_map<int, int> modCount;
    
    // Count frequency of each modulo value in prefix sums
    for (int i = 0; i <= n; i++) {
        int mod = prefixsum[i] % m;
        modCount[mod]++;
    }

    // For each modulo group with frequency f, number of pairs is C(f,2) = f*(f-1)/2
    for (auto& pair : modCount) {
        long long freq = pair.second;
        count += freq * (freq - 1) / 2;
    }

    cout << count << endl;
    return 0;
}