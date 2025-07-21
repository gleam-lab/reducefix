#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;

node A[200000];
long long psum[200001];
long long K;
int N, M;

bool is_possible(long long X, int i) {
    long long new_vote = A[i].a + X;
    int pos = upper_bound(A, A + N, new_vote, [](long long val, const node& b) {
        return val < b.a;
    }) - A;
    
    int count_above = N - pos;
    if (count_above < M) {
        return true;
    }
    
    long long required = 0;
    int start_pos = pos;
    int end_pos = pos + (count_above - (M - 1)) - 1;
    if (end_pos >= N) {
        end_pos = N - 1;
    }
    required = (A[end_pos].a - new_vote) * (end_pos - start_pos + 1);
    required += psum[pos] - psum[start_pos];
    
    long long remaining_votes = K - (psum[N] + X);
    if (required <= remaining_votes) {
        return true;
    } else {
        return false;
    }
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i].a);
        A[i].idx = i;
    }
    sort(A, A + N, [](const node& a, const node& b) {
        return a.a < b.a;
    });
    
    psum[0] = 0;
    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1].a;
    }
    
    long long total_used = psum[N];
    long long remaining = K - total_used;
    
    for (int i = 0; i < N; i++) {
        long long lo = 0, hi = remaining;
        long long min_X = -1;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (is_possible(mid, i)) {
                min_X = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        A[i].a = min_X;
    }
    
    sort(A, A + N, [](const node& a, const node& b) {
        return a.idx < b.idx;
    });
    
    for (int i = 0; i < N; i++) {
        printf("%lld ", A[i].a);
    }
    printf("\n");
    
    return 0;
}