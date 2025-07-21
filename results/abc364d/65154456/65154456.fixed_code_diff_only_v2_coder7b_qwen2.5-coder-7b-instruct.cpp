#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int a[N], pos[N];

bool check(int mid, int x, int y){
    int l = max(0, x - mid), r = min(N - 1, x + mid);
    return a[r] - (l ? a[l - 1] : 0) >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pos[x]++;
    }
    for(int i = 1; i < N; i++){
        pos[i] += pos[i - 1];
    }
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