#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
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
        priority_queue<ll> max_heap;
        
        while (i >= 0 && j < N) {
            if (b - A[i] <= A[j] - b) {
                max_heap.push(b - A[i]);
                i--;
            } else {
                max_heap.push(A[j] - b);
                j++;
            }
            if (max_heap.size() == k) break;
        }
        
        while (i >= 0 && max_heap.size() < k) {
            max_heap.push(b - A[i]);
            i--;
        }
        
        while (j < N && max_heap.size() < k) {
            max_heap.push(A[j] - b);
            j++;
        }
        
        cout << max_heap.top() << '\n';
    }
    
    return 0;
}