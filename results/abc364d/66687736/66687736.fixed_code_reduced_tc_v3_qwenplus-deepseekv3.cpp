#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    rep(_, Q) {
        ll b, k;
        cin >> b >> k;
        
        int left = lower_bound(A.begin(), A.end(), b) - A.begin();
        int right = left;
        vector<ll> distances;
        
        int i = left - 1, j = left;
        while (distances.size() < k && (i >= 0 || j < N)) {
            if (i >= 0 && j < N) {
                if (abs(A[i] - b) <= abs(A[j] - b)) {
                    distances.push_back(abs(A[i] - b));
                    i--;
                } else {
                    distances.push_back(abs(A[j] - b));
                    j++;
                }
            } else if (i >= 0) {
                distances.push_back(abs(A[i] - b));
                i--;
            } else {
                distances.push_back(abs(A[j] - b));
                j++;
            }
        }
        
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}