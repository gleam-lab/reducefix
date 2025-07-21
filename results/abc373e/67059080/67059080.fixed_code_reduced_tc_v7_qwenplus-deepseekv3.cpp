#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
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
    
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    
    ll remaining = K - prefix[N];
    
    vector<ll> answer(N, -1);
    
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        int pos = upper_bound(sortedA.begin(), sortedA.end(), current) - sortedA.begin();
        if (pos >= N - M + 1) {
            answer[i] = 0;
            continue;
        }
        
        ll low = 0;
        ll high = remaining;
        ll best = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_current = current + mid;
            int new_pos = upper_bound(sortedA.begin(), sortedA.end(), new_current) - sortedA.begin();
            
            if (new_pos >= N - M + 1) {
                best = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                int count = N - new_pos;
                if (count < M) {
                    ll required = new_current + 1;
                    int start = new_pos;
                    int end = N - 1;
                    int cnt = end - start + 1;
                    if (cnt > 0) {
                        needed = required * cnt - (prefix[end + 1] - prefix[start]);
                    }
                }
                if (needed <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        answer[i] = best;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}