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
        
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int i = right;
        int j = i + 1;
        vector<ll> distances;
        while (distances.size() < k && (i >= 0 || j < N)) {
            if (i >= 0 && j < N) {
                if (b - A[i] <= A[j] - b) {
                    distances.push_back(b - A[i]);
                    i--;
                } else {
                    distances.push_back(A[j] - b);
                    j++;
                }
            } else if (i >= 0) {
                distances.push_back(b - A[i]);
                i--;
            } else {
                distances.push_back(A[j] - b);
                j++;
            }
        }
        
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}