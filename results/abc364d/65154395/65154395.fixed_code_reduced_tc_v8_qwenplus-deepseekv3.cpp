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
        ll b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int lower = right;
        int upper = left;
        vector<ll> distances;
        int i = lower, j = upper;
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
        
        cout << distances[k - 1] << endl;
    }
    return 0;
}