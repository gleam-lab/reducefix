#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> prefix(n+1, 0);
    for(int i = 0; i < n; i++){
        prefix[i+1] = (prefix[i] + nums[i]) % m;
    }
    
    int total_sum = prefix[n];
    long long count = 0;
    unordered_map<int, int> freq;
    
    for(int i = 1; i <= n; i++){
        int target = prefix[i];
        count += freq[target];
        freq[prefix[i]]++;
    }
    
    // For circular cases, we need to consider wrap-around sums
    // This requires additional handling but might not be needed if the problem
    // is about non-circular subarrays (clarification needed)
    // The original problem seems to want circular sums
    
    // Alternative approach for circular case
    count = 0;
    for(int s = 0; s < n; s++){
        for(int t = 0; t < n; t++){
            if(s == t) continue;
            int sum;
            if(s < t){
                sum = prefix[t+1] - prefix[s+1];
            } else {
                sum = prefix[n] - prefix[s+1] + prefix[t+1];
            }
            if(sum % m == 0){
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}