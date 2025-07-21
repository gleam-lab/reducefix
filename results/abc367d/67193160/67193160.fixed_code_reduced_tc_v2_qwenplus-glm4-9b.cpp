#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i], a[i+n] = a[i];  // Extend array to handle wrap-around
    b[0] = m;  // Frequency of modulo 0 is m
    for(int i = 1; i < n*2; i++)
    {
        if(i < n)
            b[d[i] % m]--;  // Decrement before sum calculation
        d[i] = d[i-1] + a[i];
        sum += b[d[i] % m];  // Use the frequency to calculate sum
        if(i >= n)
            b[d[i] % m]++;  // Increment after sum calculation
    }
    cout << sum;
    return 0;
}