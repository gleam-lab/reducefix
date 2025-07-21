#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        --k; // convert to 0-based index
        
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int l = right;
        int r = right + 1;
        vector<ll> distances;
        while (distances.size() < N && (l >= 0 || r < N)) {
            if (l >= 0 && r < N) {
                if (b - A[l] <= A[r] - b) {
                    distances.push_back(b - A[l]);
                    --l;
                } else {
                    distances.push_back(A[r] - b);
                    ++r;
                }
            } else if (l >= 0) {
                distances.push_back(b - A[l]);
                --l;
            } else {
                distances.push_back(A[r] - b);
                ++r;
            }
        }
        cout << distances[k] << '\n';
    }
    
    return 0;
}