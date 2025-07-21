#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
int sum[200005]; // Corrected size to 200005 as we need an extra index for prefix sums
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum[i] = sum[i-1] + p[i]; // Corrected indexing for prefix sums
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l = lower_bound(x+1,x+n+1,l) - x; // Find the first element not less than l
        r = upper_bound(x+1,x+n+1,r) - x; // Find the first element greater than r
        if(l <= r){ // Check if the range is valid
            cout<<sum[r-1] - sum[l-1]<<endl;	
        } else {
            cout << "Invalid range" << endl; // Handle invalid range case
        }
    }
    return 0;
}