#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Candidate {
    ll a;
    int idx;
};

bool compareA(const Candidate &x, const Candidate &y) {
    return x.a < y.a;
}

bool compareIdx(const Candidate &x, const Candidate &y) {
    return x.idx < y.idx;
}

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<Candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }
    
    vector<Candidate> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), compareA);
    
    vector<ll> prefixSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedA[i].a;
    }
    
    ll remaining = K - prefixSum[N];
    
    vector<ll> res(N, -1);
    
    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll bestX = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVotes = sortedA[i].a + mid;
            
            int pos = upper_bound(sortedA.begin(), sortedA.end(), Candidate{newVotes, -1}, compareA) - sortedA.begin();
            int countGreater = N - pos;
            
            if (countGreater < M) {
                bestX = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (bestX != -1) {
            res[sortedA[i].idx] = bestX;
        } else {
            res[sortedA[i].idx] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}