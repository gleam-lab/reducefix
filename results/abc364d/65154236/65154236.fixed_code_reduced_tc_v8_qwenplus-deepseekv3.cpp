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
        ll b, k;
        cin >> b >> k;
        k--; // convert to 0-based index
        
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int pos = right; // last element <= b
        
        vector<ll> distances;
        int i = pos, j = pos + 1;
        for (int count = 0; count < N; ++count) {
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
            } else if (j < N) {
                distances.push_back(abs(A[j] - b));
                j++;
            }
        }
        
        cout << distances[k] << '\n';
    }
    
    return 0;
}