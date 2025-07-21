#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    vector<int> prefix_sum(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }
    
    int total_sum = prefix_sum[n];
    int count = 0;
    
    for(int s = 1; s <= n; s++){
        for(int t = 1; t <= n; t++){
            if(s == t) continue;
            int segment_sum;
            if(s < t){
                segment_sum = prefix_sum[t] - prefix_sum[s];
            } else {
                segment_sum = total_sum - (prefix_sum[s] - prefix_sum[t]);
            }
            if(segment_sum % m == 0){
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}