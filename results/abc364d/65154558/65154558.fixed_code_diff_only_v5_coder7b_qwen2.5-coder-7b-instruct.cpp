#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e8 + 5;
int a[MAXN], cnt[MAXN];

bool check(int mid, int x, int y){
    return a[min(MAXN - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    vector<int> positions(n);
    for(int i = 0; i < n; i++){
        cin >> positions[i];
    }
    sort(positions.begin(), positions.end());
    
    for(int i = 0; i < q; i++){
        int x, k; cin >> x >> k;
        int l = 0, r = 2e8;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid, x, k)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}