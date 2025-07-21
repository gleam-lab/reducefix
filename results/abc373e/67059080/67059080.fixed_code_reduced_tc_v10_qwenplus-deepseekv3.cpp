#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;
vector<ll> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    
    ll remainingVotes = K - prefix[N];
    
    vector<ll> result(N);
    for (int i = 0; i < N; ++i) {
        ll currentVotes = A[i];
        ll low = 0, high = remainingVotes;
        ll minX = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVotes = currentVotes + mid;
            
            // Find the first candidate in sortedA with votes > newVotes
            auto it = upper_bound(sortedA.begin(), sortedA.end(), newVotes);
            int cntGreater = sortedA.end() - it;
            
            if (cntGreater < M) {
                minX = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        result[i] = minX;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}