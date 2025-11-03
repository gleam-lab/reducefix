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
    
    // Use frequency map to count pairs with same remainder
    map<int, int> freq;
    for(int i = 0; i <= n; i++){
        int rem = prefixsum[i] % m;
        count += freq[rem];
        freq[rem]++;
    }
    
    cout << count << endl;
    return 0;
}