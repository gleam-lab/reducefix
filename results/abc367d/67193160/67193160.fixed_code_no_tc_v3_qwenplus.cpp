#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,sum,a[N];
long long ans;
map<int,int> cnt;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    // Calculate prefix sums modulo m
    vector<int> prefix(n+1, 0);
    for(int i=1;i<=n;i++)
        prefix[i] = (prefix[i-1] + a[i]) % m;
    
    // Count frequency of each remainder
    cnt[0] = 1; // Empty prefix has sum 0
    for(int i=1;i<=n;i++)
    {
        // For each position, add number of previous prefixes with same remainder
        // This means the subarray between those positions has sum divisible by m
        ans += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    
    cout<<ans;
    return 0;
}