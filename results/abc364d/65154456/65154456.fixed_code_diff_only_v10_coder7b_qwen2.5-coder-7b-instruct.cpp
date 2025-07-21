#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int INF = 0x3f3f3f3f;
const db eps = 1e-9;
const ll mod = 1e9 + 7;
const int N = 1e5 + 5;
int a[N];

bool check(int mid, int x, int y){
    return a[min(N - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for(int i = 1; i < n; i++){
        a[i] = a[i - 1] + A[i];
    }
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}