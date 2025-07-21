#include<bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> prefixsum(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefixsum[i + 1] = prefixsum[i] + nums[i];
    }
    long long count = 0;
    // Using a map to store prefix sums
    unordered_map<int, int> prefixMap;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            int idx = (prefixsum[i] + j) % n;
            count += prefixMap[idx];
        }
        prefixMap[prefixsum[i] % n]++;
    }
    cout << count << endl;
    return 0;
}