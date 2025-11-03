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
    unordered_map<int, int> modCount;
    
    // Initialize with 0 to handle subarrays starting from index 0
    modCount[0] = 1;
    
    // Count number of pairs with same remainder
    for(int i = 1; i <= n; i++){
        int rem = prefixsum[i];
        count += modCount[rem];
        modCount[rem]++;
    }
    
    cout << count << endl;
    return 0;
}