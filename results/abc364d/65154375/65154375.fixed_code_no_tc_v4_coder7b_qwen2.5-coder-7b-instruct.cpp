#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 100005;

vector<int> a[N];

void solve(void) {
    int n, q; cin >> n >> q;
    vector<pair<int,int>> coords(n);
    for(int i = 0; i < n; i++) {
        cin >> coords[i].first;
        a[coords[i].first].push_back(i);
    }
    
    for(int i = 0; i < n; i++) sort(a[coords[i].first].begin(), a[coords[i].first].end());
    
    for(int i = 0; i < q; i++){
        int x, k; cin >> x >> k;
        int ans = INF;
        for(auto& pos : a[x]) {
            ans = min(ans, abs(coords[pos].first - x));
            if(pos >= k-1) break;
        }
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}