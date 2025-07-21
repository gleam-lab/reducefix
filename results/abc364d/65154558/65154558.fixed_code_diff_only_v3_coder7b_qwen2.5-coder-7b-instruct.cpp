#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;
vector<ll> A[MAXN], B(MAXN);

void solve() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        A[x].push_back(i);
    }
    
    for(int i = 0; i < q; ++i) {
        int x, k; cin >> x >> k;
        B[x].push_back(k);
    }

    for(int i = 0; i < MAXN; ++i) sort(A[i].begin(), A[i].end());
    
    for(int i = 0; i < q; ++i) {
        int x = B[i][0], k = B[i][1];
        if(A[x].size() < k) {
            cout << "Invalid query" << endl;
        } else {
            cout << abs(x - A[x][k - 1]) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}