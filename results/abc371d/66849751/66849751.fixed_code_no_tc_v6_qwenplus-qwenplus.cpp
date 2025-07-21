#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define reps(i,n) for (int i=0; i<=(n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b)?"Yes":"No") << endl
#define YES(b) cout << ((b)?"YES":"NO") << endl

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1), X(N);
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Create prefix sum of P
    // No need to map x_to_ptr as in the original code

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Binary search to find first index where X[i] >= L
        int left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (X[mid] >= L) right = mid;
            else left = mid + 1;
        }
        int l_idx = left;

        // Binary search to find first index where X[i] > R
        left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (X[mid] > R) right = mid;
            else left = mid + 1;
        }
        int r_idx = left;

        cout << P[r_idx] - P[l_idx] << endl;
    }

    return 0;
}