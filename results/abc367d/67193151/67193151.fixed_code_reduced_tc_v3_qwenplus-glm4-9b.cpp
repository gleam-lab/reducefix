#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int mod(int x) {
    return x % m;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i], a[i + n] = a[i]; // Extend array 'a' by itself
    b[0] = 1;
    for(int i = 1; i < 2 * n + 1; i++) {
        if(i >= n) // Only decrement 'b' for the array's first half
            b[mod(d[i - n] % m)]--;
        d[i] = d[i - 1] + a[i];
        sum += b[mod(d[i] % m)];
        if(i < n) // Only increment 'b' for the array's first half
            b[mod(d[i] % m)]++;
    }
    cout << sum;
    return 0;
}