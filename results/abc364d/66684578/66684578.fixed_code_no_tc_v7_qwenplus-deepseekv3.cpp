#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    
    rep(_, Q) {
        int b, k;
        cin >> b >> k;
        
        int low = 0, high = 1e8;
        int answer = 0;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            auto left = lower_bound(a.begin(), a.end(), b - mid);
            auto right = upper_bound(a.begin(), a.end(), b + mid);
            int count = right - left;
            
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        vector<ll> distances;
        for (int num : a) {
            distances.push_back(abs((ll)num - b));
        }
        sort(distances.begin(), distances.end());
        
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}