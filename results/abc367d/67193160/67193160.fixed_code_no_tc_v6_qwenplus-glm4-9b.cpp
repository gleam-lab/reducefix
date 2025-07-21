#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin >> n >> m;
    
    // Read array a and extend it to a[0] to a[2*n] for circular behavior
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    // Initialize frequency array b
    for(int i = 0; i < m; i++) {
        b[i] = 0;
    }
    
    // Calculate the prefix sum array d
    for(int i = 1; i <= 2 * n; i++) {
        d[i] = d[i - 1] + a[i];
    }
    
    // Calculate the sum of b[d[i] % m] for i from 1 to n
    for(int i = 1; i <= n; i++) {
        sum += b[d[i] % m];
    }
    
    cout << sum;
    return 0;
}