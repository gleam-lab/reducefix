#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int a[N];

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[x + 100000000]++;
    }
    for(int i = 1; i < N; i++){
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= q; i++){
        int x, k; cin >> x >> k;
        int l = 0, r = 2e8;
        while(l < r){
            int mid = l + r >> 1;
            if(a[min(N - 1, x + mid + 1)] - a[max(0, x - mid)] >= k) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}