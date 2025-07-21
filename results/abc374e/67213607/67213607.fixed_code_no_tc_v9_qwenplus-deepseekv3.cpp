#include<bits/stdc++.h>
using namespace std;
long long n,x,a[105],p[105],b[105],q[105],l,r,mid,ans,minn,sum;

long long compute_cost(long long mid, int i) {
    long long min_cost = LLONG_MAX;
    
    // Try all possible combinations of buying a[i] items
    long long max_j = min(mid / a[i] + 2, b[i]);
    for(long long j=0; j<=max_j; j++) {
        long long remaining = mid - j*a[i];
        if(remaining <= 0) {
            min_cost = min(min_cost, j*p[i]);
            continue;
        }
        long long k = (remaining + b[i] - 1) / b[i]; // ceiling division
        min_cost = min(min_cost, j*p[i] + k*q[i]);
    }
    
    // Try all possible combinations of buying b[i] items
    long long max_k = min(mid / b[i] + 2, a[i]);
    for(long long k=0; k<=max_k; k++) {
        long long remaining = mid - k*b[i];
        if(remaining <= 0) {
            min_cost = min(min_cost, k*q[i]);
            continue;
        }
        long long j = (remaining + a[i] - 1) / a[i]; // ceiling division
        min_cost = min(min_cost, k*q[i] + j*p[i]);
    }
    
    return min_cost;
}

int main() {
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>p[i]>>b[i]>>q[i];
    
    l=0, r=1e18; // Upper bound large enough for worst case
    ans = 0;
    while(l<=r) {
        mid = l + (r-l)/2;
        sum = 0;
        bool valid = true;
        
        for(int i=1;i<=n;i++) {
            long long cost = compute_cost(mid, i);
            sum += cost;
            if(sum > x) {
                valid = false;
                break;
            }
        }
        
        if(valid) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout<<ans;
    return 0;
}