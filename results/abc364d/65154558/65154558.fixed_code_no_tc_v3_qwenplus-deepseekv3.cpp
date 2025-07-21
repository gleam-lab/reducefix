#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        // The k-th closest element is the k-th element in the sorted list of absolute differences
        // We can use binary search to find the smallest x such that there are at least k elements <= x
        
        // First, find the position where b would be inserted in the sorted array
        int pos = lower_bound(a.begin(), a.end(), b) - a.begin();
        
        // Now, the closest elements are around pos. We can use a two-pointer approach to find the k-th closest
        int left = pos - 1;
        int right = pos;
        vector<ll> distances;
        while (distances.size() < k && (left >= 0 || right < N)) {
            if (left >= 0 && right < N) {
                if (b - a[left] <= a[right] - b) {
                    distances.push_back(b - a[left]);
                    left--;
                } else {
                    distances.push_back(a[right] - b);
                    right++;
                }
            } else if (left >= 0) {
                distances.push_back(b - a[left]);
                left--;
            } else {
                distances.push_back(a[right] - b);
                right++;
            }
        }
        cout << distances[k - 1] << '\n';
    }
    return 0;
}