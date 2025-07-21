#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        
        int pos = lower_bound(a.begin(), a.end(), b) - a.begin();
        
        int left = pos - 1;
        int right = pos;
        vector<ll> distances;
        
        while (distances.size() < k && (left >= 0 || right < N)) {
            if (left >= 0 && right < N) {
                if (abs(a[left] - b) <= abs(a[right] - b)) {
                    distances.push_back(abs(a[left] - b));
                    left--;
                } else {
                    distances.push_back(abs(a[right] - b));
                    right++;
                }
            } else if (left >= 0) {
                distances.push_back(abs(a[left] - b));
                left--;
            } else {
                distances.push_back(abs(a[right] - b));
                right++;
            }
        }
        
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}