#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin >> n >> m >> k; // Read k as well
    for(int i = 0; i < n; i++)
        cin >> a[i]; // Read the sequence only until n
    b[0] = 1;
    for(int i = 0; i < n; i++)
    {
        if(i >= k) // Only consider elements after the first k elements
            b[d[i-k] % m]--;
        d[i] = d[i-1] + a[i];
        sum += b[d[i] % m];
        if(i < k)
            b[d[i] % m]++;
    }
    cout << sum;
    return 0;
}