#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;
int main() {
    int n,m;
    cin >> n;
    vector<int>a(n+1,0),b(n+1,0),c(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1, a.end()); // Sort array to use binary search effectively
    for(int i=1;i<=n;i++){
        cin >> b[i];
        c[i]=b[i]+c[i-1];
    }
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin()+1,a.end(),l); // Find first element not less than l
        auto r_i = upper_bound(a.begin()+1,a.end(),r); // Find first element greater than r
        if(r_i == a.end() && l_i != a.begin()+1) cout << c[n] - c[l_i-a.begin()-1] << endl; // If r is beyond the last element and l is within bounds
        else if(r_i == a.end()) cout << c[n] << endl; // If r is beyond the last element
        else if(l_i == a.begin()+1) cout << c[r_i-a.begin()-1] << endl; // If l is before the first element
        else cout << c[r_i-a.begin()-1] - c[l_i-a.begin()] << endl; // If both l and r are within valid bounds
    }
    return 0;
}