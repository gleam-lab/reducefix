#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[2*N],b[N],d[2*N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    memset(b, 0, sizeof(b));
    b[0] = 1;
    d[0] = 0;
    
    for(int i=1; i<2*n; i++) {
        d[i] = d[i-1] + a[i];
        
        if(i >= n) {
            b[d[i-n] % m]--;
        }
        
        sum += b[d[i] % m];
        
        if(i < n) {
            b[d[i] % m]++;
        }
    }
    
    cout << sum;
    return 0;
}