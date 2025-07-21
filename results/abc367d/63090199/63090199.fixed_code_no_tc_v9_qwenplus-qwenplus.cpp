#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // Compute prefix sums modulo m
    vector<int> prefixSum(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefixSum[i+1] = (prefixSum[i] + nums[i]) % m;
    }

    // Count frequency of each remainder
    map<int, int> freq;
    for(int i = 0; i <= n; i++){
        freq[prefixSum[i]]++;
    }

    // For each remainder, count pairs: C(freq, 2)
    long long count = 0;
    for(auto &[rem, cnt] : freq){
        if(cnt > 1){
            count += 1LL * cnt * (cnt - 1);
        }
    }

    cout << count << endl;
    return 0;
}