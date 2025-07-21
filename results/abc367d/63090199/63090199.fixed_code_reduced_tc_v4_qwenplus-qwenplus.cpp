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
    
    // To count (i,j) such that sum from i to j-1 is divisible by m
    // We use prefix sums modulo m
    vector<int> prefix_mod(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix_mod[i + 1] = (prefix_mod[i] + nums[i]) % m;
    }
    
    // Use a map to count occurrences of each modulo value
    map<int, int> mod_count;
    long long count = 0;
    
    for(int i = 0; i <= n; i++){
        int mod_val = prefix_mod[i];
        count += mod_count[mod_val];  // Count pairs with same mod value
        mod_count[mod_val]++;
    }
    
    cout << count << endl;
    return 0;
}