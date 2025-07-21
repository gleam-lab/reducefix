#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

vector<ll> dist[MAXN];

void preprocess(vector<int>& A, vector<int>& B) {
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < B.size(); ++j) {
            dist[j].push_back(abs(A[i] - B[j]));
        }
        sort(dist[j].begin(), dist[j].end());
    }
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    vector<int> B(Q), K(Q);
    for(int i = 0; i < Q; ++i) cin >> B[i] >> K[i];

    preprocess(A, B);

    for(int i = 0; i < Q; ++i) {
        cout << dist[i][K[i] - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}