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
    b[0]=1; // Initialize the base case for modulo counts
    for(i=1;i<=n*2;i++) {
        d[i] = (i > n) ? d[i-1] + a[i-n] : d[i-1] + a[i-1]; // Correct prefix sum calculation
        sum += b[d[i]%m]; // Add the current count of modulo results
        b[d[i]%m]++; // Increment the count of the current modulo result
    }
    cout<<sum;
    return 0;
}