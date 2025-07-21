#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    
    vector<ll> res(N);
    ll remaining = K;
    
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        int pos = upper_bound(sortedA.begin(), sortedA.end(), a) - sortedA.begin();
        if (pos > N - M) {
            res[i] = 0;
            continue;
        }
        
        ll low = 0, high = remaining;
        ll minX = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a = a + mid;
            
            int new_pos = upper_bound(sortedA.begin(), sortedA.end(), new_a) - sortedA.begin();
            if (new_pos > N - M) {
                ll required = (new_pos - (N - M)) * new_a - (prefix[new_pos] - prefix[N - M]);
                if (i >= N - M) {
                    required -= (new_a - sortedA[i]);
                }
                if (required <= remaining - mid) {
                    minX = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        
        res[i] = minX;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
    
    return 0;
}