#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed to long long to handle larger sums
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum[i] = sum[i-1] + p[i]; // Corrected array index to match loop variable
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        int l = lower_bound(x+1,x+n+1,L) - x; // Corrected array index to match loop variable
        int r = upper_bound(x+1,x+n+1,R) - x; // Corrected array index to match loop variable
        if(l <= r && r <= n){ // Added check to ensure indices are within bounds
            cout<<(sum[r]-sum[l-1])<<endl; // Fixed off-by-one error
        } else {
            cout<<"Invalid range"<<endl; // Handle invalid ranges
        }
    }
}