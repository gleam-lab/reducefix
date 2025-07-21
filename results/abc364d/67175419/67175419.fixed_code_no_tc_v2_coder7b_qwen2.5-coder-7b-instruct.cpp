#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,k,a[N],b[N];
vector<int> v;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    for(int i = 1; i <= q; ++i) {
        cin >> b[i] >> k;
        auto it1 = lower_bound(v.begin(),v.end(),b[i]);
        auto it2 = upper_bound(v.begin(),v.end(),b[i]);
        if(it1 == v.end()) --it1;
        int left = it1 - v.begin() + 1, right = it2 - v.begin();
        if(k > right) cout << *it2 << '\n';
        else if(k < left) cout << *it1 << '\n';
        else {
            int idx = lower_bound(v.begin(),v.end(),b[i]) - v.begin();
            cout << v[idx+k-1] - b[i] << '\n';
        }
    }
    return 0;
}