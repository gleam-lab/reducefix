#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    // Calculate prefix sum
    vector<int> prefixsum(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefixsum[i + 1] = (prefixsum[i] + nums[i]) % m;
    }
    
    long long count = 0;
    // Use frequency array to count occurrences of each remainder
    vector<int> freq(m, 0);
    
    // For each starting position s, we want to find valid ending positions t
    for(int s = 0; s < n; s++){
        for(int len = 1; len <= n - 1; len++){ // length of segment (1 to n-1 since s != t)
            int t = (s + len) % n;
            int sum;
            
            if(s <= t){
                sum = prefixsum[t + 1] - prefixsum[s];
            } else {
                sum = prefixsum[t + 1] + (prefixsum[n] - prefixsum[s]);
            }
            
            sum %= m;
            if(sum == 0){
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}