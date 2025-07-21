#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
int sum[200005]; // Change the size of sum array to match x array size

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]; // Read the elements into x array
    }
    sort(x+1, x+n+1); // Sort the x array
    for(int i=1;i<=n;i++){
        cin>>p[i]; // Read the prefix sums into p array
        sum[i]=sum[i-1]+p[i]; // Calculate prefix sum
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R; // Read the query range L and R
        // Use binary search to find the indices of L and R in sorted x array
        auto itL = lower_bound(x+1, x+n+1, L); // Find index of L in sorted x array
        auto itR = upper_bound(x+1, x+n+1, R); // Find index of R in sorted x array (excluding R)
        // Calculate the sum using prefix sum array and output it
        cout<<sum[itR-x]-sum[itL-x-1]<<endl; // Output the sum of elements in range L to R (inclusive) using prefix sum array
    }
}