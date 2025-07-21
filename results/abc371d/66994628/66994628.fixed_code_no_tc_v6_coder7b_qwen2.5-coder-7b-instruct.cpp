#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed int to long long to handle larger sums
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum[i] = sum[i-1] + p[i]; // Corrected the index from 2000005 to 200005
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l = lower_bound(x+1,x+n+1,l) - x; // Corrected the array pointer
        r = upper_bound(x+1,x+n+1,r) - x; // Corrected the array pointer
        if(l <= r && r <= n){ // Added check to ensure indices are within bounds
            cout<<(sum[r] - sum[l-1])<<endl; // Fixed the indexing for the sum array
        } else {
            cout<<"Invalid range"<<endl; // Handle invalid range case
        }
    }
    return 0;
}