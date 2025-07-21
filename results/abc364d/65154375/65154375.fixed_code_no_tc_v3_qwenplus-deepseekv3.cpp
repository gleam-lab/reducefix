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
        
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (a[mid] >= b) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        int pos = left;
        int l = pos - 1, r = pos;
        vector<ll> distances;
        for (int i = 0; i < k; ++i) {
            if (l >= 0 && r < N) {
                if (b - a[l] <= a[r] - b) {
                    distances.push_back(b - a[l]);
                    --l;
                } else {
                    distances.push_back(a[r] - b);
                    ++r;
                }
            } else if (l >= 0) {
                distances.push_back(b - a[l]);
                --l;
            } else if (r < N) {
                distances.push_back(a[r] - b);
                ++r;
            }
        }
        cout << distances[k - 1] << '\n';
    }
    return 0;
}