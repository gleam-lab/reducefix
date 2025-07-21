#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;
int N, K, T;
pii A[MAXN], B[MAXN];

void solve() {
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }
    for(int i = 1; i <= N; ++i) {
        cin >> B[i].first;
        B[i].second = i;
    }
    
    sort(A + 1, A + N + 1, greater<pii>());
    sort(B + 1, B + N + 1);
    
    long long maxA = A[K - 1].first;
    long long sumB = 0;
    for(int i = 1; i <= K; ++i) {
        sumB += B[i].first;
    }
    
    long long ans = maxA * sumB;
    
    for(int i = K; i < N; ++i) {
        sumB += B[i + 1].first - B[i - K + 1].first;
        ans = min(ans, maxA * sumB);
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}