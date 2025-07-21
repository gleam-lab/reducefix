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
//const ll mod = 998244353;
const int N = 2e8 + 5;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }
int f1[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
int f2[8][2] = { 2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1 };

int a[N];

bool check(int mid, int x, int y){
    return a[min(N - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    vector<int> A(n), B(q), K(q);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        A[i] += 100000000;
    }
    for(int i = 0; i < q; i++) {
        cin >> B[i] >> K[i];
        B[i] += 100000000;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i = 1; i < n; i++) {
        a[i] = a[i - 1] + (A[i] == A[i - 1]);
    }
    for(int i = 0; i < q; i++) {
        int left = 0, right = 2e8;
        while(left < right) {
            int mid = (left + right) / 2;
            if(check(mid, B[i], K[i])) right = mid;
            else left = mid + 1;
        }
        cout << left << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}