#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed to long long to prevent overflow
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum[i]=sum[i-1]+p[i];
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        // Find first x[i] >= l
        int left_pos = lower_bound(x+1, x+n+1, l) - x;
        // Find first x[i] > r
        int right_pos = upper_bound(x+1, x+n+1, r) - x;
        
        // The sum is from left_pos to right_pos-1
        if(left_pos > right_pos-1){
            cout << "0\n";
        } else {
            cout << sum[right_pos-1] - sum[left_pos-1] << "\n";
        }
    }
    return 0;
}