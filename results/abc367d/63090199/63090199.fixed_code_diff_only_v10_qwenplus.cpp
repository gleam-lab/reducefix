#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    // Build prefix sum array
    vector<int> prefixsum(n+1, 0);
    for(int i = 0; i < n; i++){
        prefixsum[i+1] = (prefixsum[i] + nums[i]) % m;
    }
    
    long long count = 0;
    // Use map to count frequency of each modulo value in prefix sums
    map<int, int> modCount;
    
    // Initialize with prefix[0] = 0
    modCount[0] = 1;
    
    // Traverse prefix sums and count valid subarrays
    for(int i = 1; i <= n; i++){
        int mod = prefixsum[i];
        // If this mod has been seen before, it means there are subarrays ending at i-1 that sum to multiple of m
        if(modCount.find(mod) != modCount.end()){
            count += modCount[mod];
        }
        modCount[mod]++;
    }
    
    cout << count << endl;
    return 0;
}