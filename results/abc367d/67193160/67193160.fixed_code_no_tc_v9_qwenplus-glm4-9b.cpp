#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    
    // Extend array a with itself to handle wrap-around
    for(int i = 1; i <= n; i++) 
        a[i+n] = a[i];
    
    // Initialize b array to keep track of occurrences of each prefix sum modulo m
    b[0] = 1;
    
    // Calculate prefix sums
    d[0] = 0;
    for(int i = 1; i <= 2*n; i++) {
        d[i] = d[i-1] + a[i];
    }
    
    // Calculate the number of pairs (x,y) such that x < y and x + y â¡ 0 (mod m)
    for(int i = 0; i <= 2*n; i++) {
        sum += b[d[i] % m];
        if(i < n) // Only increment when within the first n elements
            b[d[i] % m]++;
        if(i >= n) // Only decrement when past the first n elements
            b[d[i-n] % m]--;
    }
    
    cout << sum;
    return 0;
}