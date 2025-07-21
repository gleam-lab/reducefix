#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int N, Q;
ll A[MAXN], B[MAXN], K[MAXN];
vector<ll> dist[MAXN];

void preprocess() {
    sort(A + 1, A + N + 1);
    for(int i = 1; i <= Q; i++) {
        dist[i].resize(N + 1);
        for(int j = 1; j <= N; j++) {
            dist[i][j] = abs(B[i] - A[j]);
        }
        sort(dist[i].begin(), dist[i].end());
    }
}

void solve() {
    preprocess();
    for(int i = 1; i <= Q; i++) {
        cout << dist[i][K[i]] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= Q; i++) {
        cin >> B[i] >> K[i];
    }
    solve();
    return 0;
}