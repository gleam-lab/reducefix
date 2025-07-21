#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Candidate {
    ll a;
    int idx;
};

bool compareByA(const Candidate &x, const Candidate &y) {
    return x.a < y.a;
}

bool compareByIdx(const Candidate &x, const Candidate &y) {
    return x.idx < y.idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<Candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }
    
    sort(A.begin(), A.end(), compareByA);
    
    vector<ll> psum(N + 1);
    psum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        psum[i] = psum[i - 1] + A[i - 1].a;
    }
    
    ll remaining = K - psum[N];
    
    vector<ll> res(N, -1);
    
    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll best_x = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a = A[i].a + mid;
            
            int pos = upper_bound(A.begin(), A.end(), Candidate{new_a, -1}, compareByA) - A.begin();
            int higher = N - pos;
            
            if (higher < M) {
                best_x = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (best_x != -1) {
            res[A[i].idx] = best_x;
        } else {
            res[A[i].idx] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}