#include<bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> prefixsum(n+1, 0);
    for(int i = 0; i < n; i++){
        prefixsum[i+1] = prefixsum[i] + nums[i];
    }
    int count = 0;
    // å¯»æ¾å¯è½çæ(s, t)å¯¹
    for(int s = 1; s <= n; s++){
        for(int t = 1; t <= n + 1; t++){
            if(s == t) continue;
            int step = (t == n + 1) ? prefixsum[n] : prefixsum[t] - prefixsum[s];
            if(step % m == 0){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}