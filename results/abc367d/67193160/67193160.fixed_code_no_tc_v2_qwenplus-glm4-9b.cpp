#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int i, x, y, z, t;
    cin>>n>>m;

    for(i = 1; i <= n; i++)
        cin>>a[i];
    
    // Extend the array to handle wraparound by concatenating itself
    for(i = 1; i <= n; i++)
        a[i+n] = a[i];

    // Initialize count arrays
    memset(b, 0, sizeof(b));

    // Calculate prefix sums for b to keep track of count of each mod value
    b[0] = 1;
    for(i = 1; i <= 2*n; i++)
    {
        // Use the prefix sum array to keep track of counts
        d[i] = d[i-1] + a[i];
        sum += b[d[i] % m];
        if(i < n) // Only increment for the first n elements
            b[d[i] % m]++;
    }

    cout << sum;
    return 0;
}