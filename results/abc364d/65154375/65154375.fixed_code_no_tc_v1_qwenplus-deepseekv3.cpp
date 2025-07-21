#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
        
        // Binary search to find the k-th closest element
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] < b) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        int pos = left;
        int l = pos - 1, r = pos;
        vector<ll> distances;
        while (distances.size() < k && (l >= 0 || r < N)) {
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
            } else {
                distances.push_back(abs(A[r] - b));
                r++;
            }
        }
        
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}