#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    
    // Initialize the frequency array for modulo m
    for(int i = 0; i < m; i++)
        b[i] = 0;
    
    // Calculate the prefix sums of a with modulo m
    for(int i = 1; i <= n; i++)
        d[i] = (d[i-1] + a[i]) % m;
    
    // Calculate the sum using the prefix sums
    for(int i = 1; i <= n; i++)
    {
        // Increment the count of the prefix sum modulo m
        b[d[i]]++;
        
        // Add the count of the current modulo to sum
        sum += b[d[i]];
        
        // Decrement the count of the previous prefix sum modulo m
        if (i > 1)
            b[d[i-1]]--;
    }
    
    cout << sum;
    return 0;
}