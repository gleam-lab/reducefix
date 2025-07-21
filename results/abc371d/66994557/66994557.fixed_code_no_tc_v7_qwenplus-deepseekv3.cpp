#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed to long long to prevent overflow
int main(){
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
        int L,R;
        cin>>L>>R;
        int l=lower_bound(x+1,x+n+1,L)-x; // First element >= L
        int r=upper_bound(x+1,x+n+1,R)-x; // First element > R
        // The sum is from l to r-1 (inclusive)
        if(l > n || r-1 < 1 || l > r-1) { // No elements in range
            cout << 0 << endl;
        } else {
            cout << sum[r-1] - sum[l-1] << endl;
        }
    }
    return 0;
}