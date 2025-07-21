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
        ll b;
        int k;
        cin >> b >> k;
        int left = lower_bound(A.begin(), A.end(), b) - A.begin();
        int right = left;
        priority_queue<ll> max_heap;
        
        int count = 0;
        while (count < k && (left >= 0 || right < N)) {
            if (left >= 0 && right < N) {
                ll dist_left = abs(A[left] - b);
                ll dist_right = abs(A[right] - b);
                if (dist_left <= dist_right) {
                    max_heap.push(dist_left);
                    left--;
                } else {
                    max_heap.push(dist_right);
                    right++;
                }
            } else if (left >= 0) {
                ll dist_left = abs(A[left] - b);
                max_heap.push(dist_left);
                left--;
            } else {
                ll dist_right = abs(A[right] - b);
                max_heap.push(dist_right);
                right++;
            }
            count++;
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }
        cout << max_heap.top() << '\n';
    }

    return 0;
}