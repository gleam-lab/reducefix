#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vi A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    rep(j, Q) {
        int b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        int l = pos - 1, r = pos;
        vl distances;
        while (distances.size() < (size_t)k && (l >= 0 || r < N)) {
            if (l >= 0 && r < N) {
                if (abs(A[l] - b) <= abs(A[r] - b)) {
                    distances.push_back(abs(A[l] - b));
                    l--;
                } else {
                    distances.push_back(abs(A[r] - b));
                    r++;
                }
            } else if (l >= 0) {
                distances.push_back(abs(A[l] - b));
                l--;
            } else if (r < N) {
                distances.push_back(abs(A[r] - b));
                r++;
            }
        }
        cout << distances[k - 1] << endl;
    }

    return 0;
}