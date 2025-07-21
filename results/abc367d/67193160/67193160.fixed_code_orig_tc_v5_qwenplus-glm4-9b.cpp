#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int i,j,x,y,z,t;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    b[0] = 1;
    for(i=1;i<n*2;i++) {
        if (i >= n) {
            b[d[i-n]%m]--;  // Check if i >= n
        }
        d[i] = d[i-1] + a[i % n];  // Use modulo n here to ensure correct index
        sum += b[d[i]%m];
        if (i < n) {  // only increment for the first n instances
            b[d[i]%m]++;
        }
        if (i >= n) {
            b[d[i-n]%m]++;
        }
    }
    cout<<sum;
    return 0;
}