#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 2e8 + 5;

vector<ll> a;

bool check(int mid, int x, int y){
    auto it = lower_bound(a.begin(), a.end(), x - mid);
    if(it == a.end()) return false;
    if(*it > x + mid) return false;
    int idx = it - a.begin();
    if(idx - 1 >= 0 && a[idx] - a[idx - 1] >= y) return true;
    if(idx + 1 < a.size() && a[idx + 1] - a[idx] >= y) return true;
    return false;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= q; i++){
        int x, y; cin >> x >> y;
        int l = 0, r = 2e8;
        while(r > l){
            int mid = l + r >> 1;
            if(check(mid, x, y)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}