#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 100005;
int a[N], cnt[N];

bool check(int mid, int x, int y){
    return a[min(N - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i < N; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = 1; i <= q; i++){
        int x, y; cin >> x >> y;
        int l = 0, r = 2e8;
        while(r > l){
            int mid = l + r >> 1;
            if(cnt[min(N - 1, x + mid)] - cnt[max(0, x - mid - 1)] >= y) r = mid;
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