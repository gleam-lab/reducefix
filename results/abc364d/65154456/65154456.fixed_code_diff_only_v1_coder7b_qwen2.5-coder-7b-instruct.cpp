#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n, q;
ll a[N], b[N], c[N];

bool check(int mid, int x, int y){
    return a[min(n - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 1; i <= q; i++){
        cin >> b[i] >> c[i];
    }
    for(int i = 1; i <= q; i++){
        int l = 0, r = 1e9;
        while(l < r){
            int mid = (l + r) / 2;
            if(check(mid, lower_bound(a, a + n, b[i]) - a, c[i])) r = mid;
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