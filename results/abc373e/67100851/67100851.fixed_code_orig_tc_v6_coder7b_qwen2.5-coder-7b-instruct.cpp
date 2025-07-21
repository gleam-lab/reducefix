#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef struct {
    long long a;
    int idx;
} Node;

Node A[200000];
long long psum[200001], K;
int N, M;

bool f(long long k, int i) {
    int idx = upper_bound(A + i, A + N, Node{A[i].a + k, -1}, [](Node a, Node b) { return a.a < b.a; }) - A;
    int l = N - M;
    if (i >= l) l--;
    if (idx <= l) return false;
    long long req = (idx - l) * (A[i].a + k + 1) - (psum[idx] - psum[l]);
    if (i > l) req -= k + 1;
    return req <= K - k;
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

    vector<long long> results(N, -1);

    for (int i = 0; i < N; i++) {
        long long lo = 0, hi = K;
        while (hi - lo > 1) {
            long long mid = (lo + hi) / 2;
            if (f(mid, i)) hi = mid;
            else lo = mid;
        }
        if (hi > lo && f(hi, i)) hi--;
        results[i] = hi;
    }

    for (int i = 0; i < N; i++) cout << results[i] << " ";
    cout << endl;

    return 0;
}