#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i], a[i+n] = a[i];
    
    long long total = 0;
    d[0] = 0;
    b[0] = 1;
    
    for(int i=1;i<=2*n;i++) {
        d[i] = (d[i-1] + a[i]) % m;
        if(i > n) {
            b[d[i-n]]--;
        }
        total += b[d[i]];
        if(i < n) {
            b[d[i]]++;
        }
    }
    
    cout << total;
    return 0;
}