#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        int idx = lower_bound(A.begin(), A.end(), b) - A.begin();
        int left = idx - 1;
        int right = idx;
        vector<ll> distances;
        while (distances.size() < k && (left >= 0 || right < N)) {
            if (left >= 0 && right < N) {
                if (abs(A[left] - b) <= abs(A[right] - b)) {
                    distances.push_back(abs(A[left] - b));
                    left--;
                } else {
                    distances.push_back(abs(A[right] - b));
                    right++;
                }
            } else if (left >= 0) {
                distances.push_back(abs(A[left] - b));
                left--;
            } else {
                distances.push_back(abs(A[right] - b));
                right++;
            }
        }
        cout << distances[k-1] << "\n";
    }
    
    return 0;
}