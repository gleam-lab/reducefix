#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

long long A[MAXN];
long long B[MAXN];
long long C[MAXN];

bool can_win(long long mid, int n, int m, int k) {
    long long sum = 0;
    vector<long long> votes(n);
    
    for (int i = 0; i < n; ++i) {
        votes[i] = A[i] + mid;
        sum += votes[i];
    }
    
    sort(votes.begin(), votes.end(), greater<long long>());
    
    for (int i = 0; i < m - 1; ++i) {
        sum -= votes[i];
    }
    
    return sum >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B, B + n, greater<long long>());

    for (int i = 0; i < n; ++i) {
        long long l = 0, r = k - A[i], ans = -1;
        
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (can_win(mid, n, m, k - A[i])) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        cout << ans << " ";
    }

    return 0;
}