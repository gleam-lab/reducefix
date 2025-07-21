#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    b[0] = 1;
    for(int i=1; i<=n; i++)
    {
        d[i] = d[i-1] + a[i];
        sum = d[i] % m;
        b[sum]++;
    }
    // Calculate the sum of counts of d[i] modulo m that are greater than k
    for(int i=0; i<m; i++)
        if(b[i] > k)
            sum += b[i] - k;
    cout << sum << '\n';
    return 0;
}