#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        int low = 0, high = N - 1;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        int left = pos - 1, right = pos;
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < k; ++i) {
            if (left >= 0 && right < N) {
                if (abs(A[left] - b) <= abs(A[right] - b)) {
                    pq.push({abs(A[left] - b), A[left]});
                    --left;
                } else {
                    pq.push({abs(A[right] - b), A[right]});
                    ++right;
                }
            } else if (left >= 0) {
                pq.push({abs(A[left] - b), A[left]});
                --left;
            } else if (right < N) {
                pq.push({abs(A[right] - b), A[right]});
                ++right;
            }
        }
        
        cout << pq.top().first << '\n';
    }
    
    return 0;
}