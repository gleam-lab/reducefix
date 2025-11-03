#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefixsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixsum[i + 1] = (prefixsum[i] + nums[i]) % m;
    }

    // Count frequency of each modulo value in prefix sums
    map<int, long long> modCount;
    for (int i = 0; i <= n; i++) {
        modCount[prefixsum[i]]++;
    }

    long long count = 0;
    // For each modulo group, number of pairs is C(k,2) = k*(k-1)/2
    for (auto& [modVal, freq] : modCount) {
        count += freq * (freq - 1) / 2;
    }

    cout << count << endl;
    return 0;
}