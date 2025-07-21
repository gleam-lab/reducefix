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
    
    // Initialize prefix sums array
    d[0] = 0;
    for(int i=1; i<=2*n; i++)
    {
        if(i > n)
            d[i] = d[i-1] + a[i-n]; // Add element from original array
        else
            d[i] = d[i-1]; // Carry forward the previous sum
    }
    
    // Initialize frequency array for prefix sums modulo m
    memset(b, 0, sizeof(b));
    b[0] = 2; // Two full arrays of elements have been considered
    
    // Use sliding window to find the number of valid prefix sums
    for(int i=1; i<=n; i++)
    {
        sum -= b[d[i] % m]; // Subtract the count of current window
        b[d[i] % m] += 2; // Add twice (for the two copies in the window)
        sum += b[d[i] % m]; // Add the count of new window
    }
    
    cout << sum;
    return 0;
}