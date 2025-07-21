#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed to long long to prevent overflow
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        int l_query, r_query;
        cin>>l_query>>r_query;
        // Find first x[i] >= l_query
        int l = lower_bound(x+1, x+n+1, l_query) - x;
        // Find first x[i] > r_query, then subtract 1 to get last x[i] <= r_query
        int r = upper_bound(x+1, x+n+1, r_query) - x - 1;
        
        if(l > r){
            cout << "0\n"; // No elements in range
        } else {
            cout << sum[r] - sum[l-1] << "\n";
        }
    }
    return 0;
}