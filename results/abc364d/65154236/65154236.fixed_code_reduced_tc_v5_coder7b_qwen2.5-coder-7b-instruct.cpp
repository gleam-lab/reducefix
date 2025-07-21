#include <bits/stdc++.h>
using namespace std;

vector<int> a;

bool check(int mid, int x, int y){
    int cnt = upper_bound(a.begin(), a.end(), x + mid) - lower_bound(a.begin(), a.end(), x - mid);
    return cnt >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < q; i++){
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