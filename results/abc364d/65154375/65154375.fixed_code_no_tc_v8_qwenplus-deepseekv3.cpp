#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
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
        
        int pivot = right;
        vector<ll> distances;
        int i = pivot, j = pivot + 1;
        while (distances.size() < N) {
            if (i >= 0 && (j >= N || abs(A[i] - b) <= abs(A[j] - b))) {
                distances.push_back(abs(A[i] - b));
                i--;
            } else {
                distances.push_back(abs(A[j] - b));
                j++;
            }
        }
        
        cout << distances[k - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}