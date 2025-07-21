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
    
    // We'll use a map to count occurrences of each remainder
    map<int, int> remainder_count;
    long long current_sum = 0;
    long long result = 0;
    
    // Initialize with remainder 0 having one count (empty subarray)
    remainder_count[0] = 1;
    
    for(int i = 0; i < n; i++){
        current_sum += nums[i];
        int rem = ((current_sum % m) + m) % m;  // Handle negative remainders
        
        // Add the number of times this remainder has been seen before
        result += remainder_count[rem];
        
        // Increment the count of this remainder
        remainder_count[rem]++;
    }
    
    cout << result << endl;
    return 0;
}