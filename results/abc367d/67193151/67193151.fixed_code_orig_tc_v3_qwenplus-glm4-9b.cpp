#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int i,j,x,y,z,t;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i];
    
    // Use a map to track the frequencies of modulo values of d
    map<int, int> freq;

    // Initialize the first element
    freq[d[0] = d[0]] = 1;  // d[0] is 0
    sum += b[d[0] % m];     // d[0] % m is 0

    for(i=1; i<n*2; i++)
    {
        // Calculate d[i] based on previous d[i-1] + a[i]
        d[i] = d[i-1] + a[i];
        
        // Update the frequency of (d[i] % m) in the map
        freq[d[i] % m]++;
        sum += b[d[i] % m];

        // If i < m, increment the frequency of the previous modulo value
        if(i < m)
        {
            freq[(d[i-1] % m)]--;
            sum -= b[(d[i-1] % m)];
        }
    }

    cout << sum;
    return 0;
}