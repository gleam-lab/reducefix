#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    long long a;
    int idx;
} Node;

Node A[200000];
long long psum[200001], K;
int N, M;

// Function to check if a candidate can secure victory with 'k' additional votes
bool f(long long k, int i) {
    int idx = upper_bound(A + i, A + N, Node{A[i].a + k, -1}, [](Node a, Node b) { return a.a < b.a; }) - A;
    int l = N - M;
    if (i >= l) l--;
    if (idx <= l) return false;
    
    long long req = (idx - l) * (A[i].a + k + 1) - (psum[idx] - psum[l]);
    if (i > l) req -= k + 1;
    
    if (req <= K - k) return false;
    return true;
}

int main() {
    cin >> N >> M >> K;
    psum[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i].a;
        A[i].idx = i;
    }
    sort(A, A + N, [](Node a, Node b) { return a.a < b.a; });
    for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + A[i - 1].a;
    K -= psum[N];
    
    vector<long long> results(N, -1); // Initialize results with -1
    
    for (int i = 0; i < N; i++) {
        if (!f(K, i)) continue; // Skip if candidate cannot secure victory
        
        long long lo = 0, hi = K;
        while (hi - lo > 1) {
            long long mid = (lo + hi) >> 1;
            if (f(mid, i)) hi = mid;
            else lo = mid + 1;
        }
        
        if (hi > lo && f(hi - 1, i)) hi--;
        results[A[i].idx] = hi;
    }
    
    for (long long r : results) cout << r << " ";
    cout << endl;
    
    return 0;
}