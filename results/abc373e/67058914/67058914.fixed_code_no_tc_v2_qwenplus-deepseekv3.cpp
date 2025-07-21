#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
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
    
    ll totalVotes = prefix[N];
    ll remainingVotes = K - totalVotes;
    
    vector<ll> results(N);
    
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = remainingVotes + sortedA[N - 1] - current;
        ll answer = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newCurrent = current + mid;
            
            int idx = upper_bound(sortedA.begin(), sortedA.end(), newCurrent) - sortedA.begin();
            int countHigher = N - idx;
            
            if (countHigher < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        results[i] = answer;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << results[i] << ' ';
    }
    cout << endl;
    
    return 0;
}