#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a, b;
vector<int> k;

void solve(void) {
    int n, q; cin >> n >> q;
    a.resize(n + 1); b.resize(q + 1); k.resize(q + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    sort(a.begin() + 1, a.end());
    
    for(int i = 1; i <= q; i++){
        cin >> b[i] >> k[i];
    }

    for(int i = 1; i <= q; i++){
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        int index = it - a.begin();
        
        if(index == 0 || index == n){
            cout << abs(b[i] - a[index]) << endl;
        }else{
            int dist_left = abs(b[i] - a[index - 1]);
            int dist_right = abs(b[i] - a[index]);
            
            if(k[i] % 2 == 1){
                cout << min(dist_left, dist_right) << endl;
            }else{
                cout << max(dist_left, dist_right) << endl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}