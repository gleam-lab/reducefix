#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
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
        int l = 0, r = N - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] <= b) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        int left = r, right = r + 1;
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
        
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}