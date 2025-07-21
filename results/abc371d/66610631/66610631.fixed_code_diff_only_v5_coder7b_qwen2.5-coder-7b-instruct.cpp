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
    sort(a.begin()+1,a.begin()+n+1); // Sort array to use binary search
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
        if(r_i==a.end() && l_i!=a.begin()+1) cout << c[n] - c[l_i-a.begin()-1] << endl; // If r is out of bounds, calculate from start to just before l_i
        else if(l_i==a.begin()+1) cout << c[r_i-a.begin()-1] << endl; // If l is out of bounds, calculate up to r_i
        else cout << c[r_i-a.begin()-1] - c[l_i-a.begin()-1] << endl; // Calculate difference between r_i and l_i
    }
    return 0;
}