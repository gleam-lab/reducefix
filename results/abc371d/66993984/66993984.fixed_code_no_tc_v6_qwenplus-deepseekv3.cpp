#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed to long long to prevent overflow
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sum[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum[i]=sum[i-1]+p[i];
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        int c=lower_bound(x+1,x+n+1,L)-x;
        int d=upper_bound(x+1,x+n+1,R)-x;
        // Ensure c is within bounds and handle cases where no elements are in range
        if(c > n || x[c] > R || d <= 1 || x[d-1] < L) {
            cout << 0 << endl;
        } else {
            cout<<sum[d-1]-sum[c-1]<<endl;
        }
    }
    return 0;
}