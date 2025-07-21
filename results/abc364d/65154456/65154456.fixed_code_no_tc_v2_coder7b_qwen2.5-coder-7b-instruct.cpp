#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a;

bool check(int mid, int x, int y){
    auto it = lower_bound(a.begin(), a.end(), x - mid);
    if(it == a.end()) return false;
    int idx = it - a.begin();
    if(idx + y >= a.size()) return false;
    return a[idx + y] - a[idx] >= x + mid;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < a.size(); i++){
        a[i] += a[i - 1];
    }
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        int l = 0, r = 1e9;
        while(r > l){
            int mid = l + r >> 1;
            if(check(mid, x, y)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}