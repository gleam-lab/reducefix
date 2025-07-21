#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); // Speed up I/O operations
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;++i)
        cin>>x[i];

    vector<ll> p(n), ps(n+1); // Prefix sum array to store cumulative sums
    for(int i=0;i<n;++i){
        cin>>p[i];
        ps[i+1]=ps[i]+p[i]; // Calculate prefix sum
    }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;

        // Find first index greater than or equal to 'l' using binary search
        auto it_l = lower_bound(x.begin(), x.end(), l);
        
        // If no such element exists, set it_l to end of array
        if(it_l==x.end())
            it_l=x.end();

        // Find first index greater than 'r' using binary search
        auto it_r = upper_bound(x.begin(), x.end(), r);
        
        // If no such element exists, set it_r to start of array
        if(it_r==x.begin())
            it_r=x.begin();

        // Calculate result as difference between prefix sums
        ll res = ps[it_r-x.begin()] - ps[it_l-x.begin()];
        cout<<res<<'\n';
    }
    return 0;
}