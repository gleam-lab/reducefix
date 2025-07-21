#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;
node A[200001];
int N, M, K;
long long psum[200001];

bool f(long long x) {
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        if (i >= M) sum += A[i].a + x;
        if (A[i].a + x < psum[i + 1 - M]) return false;
    }
    long long needed = sum - psum[M - 1];
    return needed <= K;
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    psum[0] = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i].a);
        A[i].idx = i;
    }
    sort(A, A + N, [](node a, node b) { return a.a < b.a; });
    for (int i = 1; i <= N; ++i) psum[i] = psum[i - 1] + A[i - 1].a;

    for (int i = 0; i < N; ++i) {
        long long lo = 0, hi = K;
        if (i < M) hi = psum[i + M] - psum[i];
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            if (f(mid)) hi = mid;
            else lo = mid;
        }
        if (f(lo)) A[i].a = lo;
        else A[i].a = -1;
    }

    sort(A, A + N, [](node a, node b) { return a.idx < b.idx; });
    for (int i = 0; i < N; ++i) printf("%lld ", A[i].a);
    printf("\n");
}