#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
map<int,int>sum;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum[i] = sum[i-1] + p[i];
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        int c = lower_bound(x+1, x+n+1, L) - x;  // lower_bound returns the first element greater than or equal to L
        int d = upper_bound(x+1, x+n+1, R) - x + 1;  // upper_bound returns the first element greater than R, so we add 1
        if (c > d) {
            cout << 0 << endl;  // Edge case where no elements are in the range
        } else {
            cout << sum[d-1] - sum[c-1] << endl;  // Adjust indices since sum array is 1-indexed
        }
    }
}