#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    // Prefix sum with modular arithmetic
    vector<int> prefixSumMod(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefixSumMod[i + 1] = (prefixSumMod[i] + nums[i]) % m;
    }
    
    // Use a map to count occurrences of each remainder
    map<int, int> modCount;
    modCount[0] = 1; // Initialize with remainder 0
    
    long long count = 0;
    for(int i = 1; i <= n; i++){
        // For each prefix sum modulo m, find how many previous prefixes had the same remainder
        count += modCount[prefixSumMod[i]]++;
    }
    
    cout << count << endl;
    return 0;
}