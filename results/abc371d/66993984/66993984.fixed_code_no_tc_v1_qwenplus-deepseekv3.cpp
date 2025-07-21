#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005];  // Use long long to prevent overflow

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
        if (L > R) {
            cout << 0 << endl;  // Invalid range, sum is 0
            continue;
        }
        int c=lower_bound(x+1,x+n+1,L)-x;
        int d=upper_bound(x+1,x+n+1,R)-x;
        if (c > n || d == 1) {  // No elements in [L, R]
            cout << 0 << endl;
        } else {
            cout << sum[d-1]-sum[c-1] << endl;
        }
    }
    return 0;
}