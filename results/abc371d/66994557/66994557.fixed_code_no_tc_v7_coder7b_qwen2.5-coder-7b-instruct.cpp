#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed to long long to handle larger sums
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sort(x+1,x+n+1); // Sorting x array to use binary search effectively
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum[i] = sum[i-1] + p[i]; // Corrected index to match sorted x array
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        int l = lower_bound(x+1,x+n+1,L) - x; // Corrected index to match sorted x array
        int r = upper_bound(x+1,x+n+1,R) - x; // Corrected index to match sorted x array
        if(l <= n && r <= n){ // Added check to ensure indices are within bounds
            cout<<(sum[r] - sum[l-1])<<endl; // Corrected formula to calculate sum
        } else {
            cout<<"Invalid range"<<endl; // Handling invalid ranges
        }
    }
}