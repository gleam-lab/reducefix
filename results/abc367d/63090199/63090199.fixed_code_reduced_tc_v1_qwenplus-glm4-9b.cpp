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
    int count = 0;
    // Finding possible (s, t) pairs
    for(int s = 1; s <= n; s++){
        for(int t = s + 1; t <= n; t++){
            int step = prefixsum[t] - prefixsum[s];
            if(step % m == 0){
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}