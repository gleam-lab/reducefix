#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,m,k,sum,cnt,a[N],b[N],c[N];

// Function to check if a candidate can win with x additional votes
bool check(ll x, ll y){
    // Find the position where the sum of votes including x exceeds the current vote count plus one
    ll z = lower_bound(b+1, b+1+n, x+y+1) - b - 1;
    
    // Check if the number of candidates that could beat this candidate is less than m
    if(z < n - m)
        return false;
    
    // Calculate the potential votes left after giving x votes to the candidate
    ll remaining_votes = k - y;
    
    // Calculate the votes needed to ensure victory
    ll required_votes = (x + y + 1) * (z - n + m) - (c[z] - c[n-m-1] - max(x, b[n-m]));
    
    // Return true if enough votes are left to cover the required votes
    return remaining_votes >= required_votes;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i,j,x,y,z,t;
    cin >> n >> m >> k;
    for(i=1; i<=n; i++){
        cin >> a[i];
        k -= a[i]; // Decrease total votes by the initial votes for candidate i
        b[i] = a[i];
    }
    sort(b+1, b+n+1); // Sort the array of initial votes
    for(i=1; i<=n; i++)
        c[i] = c[i-1] + b[i]; // Cumulative sum of votes
    
    for(i=1; i<=n; i++){
        int l=0, r=k+1;
        while(l<r){
            int mid=(l+r)/2;
            if(check(a[i],mid)) // Check if candidate i can win with mid additional votes
                r=mid;
            else
                l=mid+1;
        }
        if(l <= k) // If l is within the total remaining votes, print l
            cout << l << " ";
        else
            cout << "-1 "; // Otherwise, print -1
    }
    return 0;
}