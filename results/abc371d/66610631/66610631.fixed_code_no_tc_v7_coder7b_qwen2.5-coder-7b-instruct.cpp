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
    sort(a.begin()+1,a.end()); // Sort array 'a' to use binary search effectively
    for(int i=1;i<=n;i++){
        cin >> b[i];
        c[i]=b[i]+c[i-1];
    }
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin()+1,a.end(),l); // Find first element not less than 'l'
        auto r_i = upper_bound(a.begin()+1,a.end(),r); // Find first element greater than 'r'
        if(r_i == a.end() && l_i == a.begin()+1) cout << c[n] << endl; // If range is from start to end
        else if(r_i == a.end()) cout << c[n]-c[l_i-a.begin()] << endl; // If range ends at the end of the array
        else if(l_i == a.begin()+1) cout << c[r_i-a.begin()-1] << endl; // If range starts from the beginning of the array
        else cout << c[r_i-a.begin()-1]-c[l_i-a.begin()] << endl; // For any other range
    }
    return 0;
}