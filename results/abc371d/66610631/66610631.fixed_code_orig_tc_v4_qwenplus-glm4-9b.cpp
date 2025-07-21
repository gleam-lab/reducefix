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
    for(int i=1;i<=n;i++){
        cin >> b[i];
        c[i]=b[i]+c[i-1];
    }
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin()+1,a.end(),l);
        auto r_i = upper_bound(a.begin()+1,a.end(),r);
        int left_bound = distance(a.begin(), l_i);
        int right_bound = distance(a.begin(), r_i);
        if(r_i == a.end() && l_i == a.begin() + 1) cout << c[n] << endl;
        else if(r_i == a.end()) cout << c[n] - c[left_bound - 1] << endl;
        else if(l_i == a.begin() + 1) cout << c[right_bound - 1] << endl;
        else cout << c[right_bound - 1] - c[left_bound - 1] << endl;
    }
    return 0;
}