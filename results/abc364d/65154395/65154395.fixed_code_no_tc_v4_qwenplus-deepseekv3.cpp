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
        
        int low = 0, high = N - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] <= b) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        int left = high;
        int right = low;
        vector<ll> distances;
        int count = 0;
        while (count < k && (left >= 0 || right < N)) {
            ll left_dist = left >= 0 ? b - A[left] : LLONG_MAX;
            ll right_dist = right < N ? A[right] - b : LLONG_MAX;
            if (left_dist <= right_dist) {
                distances.push_back(left_dist);
                left--;
            } else {
                distances.push_back(right_dist);
                right++;
            }
            count++;
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }
    return 0;
}