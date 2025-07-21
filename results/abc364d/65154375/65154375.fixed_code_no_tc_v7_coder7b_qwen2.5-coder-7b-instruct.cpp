#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N], b[N], c[N];
vector<int> v;

bool check(int mid, int x, int y){
    return c[min(N - 1, x + mid)] - c[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[x] ++;
    }
    for(int i = 1; i <= 1e8; i++){
        c[i] = c[i - 1] + a[i];
    }
    for(int i = 1; i <= q; i++){
        int x, y; cin >> x >> y;
        int l = 0, r = 1e8;
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