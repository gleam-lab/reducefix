#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;
node A[200001];
long long psum[200001];
int N, M, K;

bool canWin(int i, int votes_needed) {
    long long current_votes = A[i].a + votes_needed;
    int higher_votes_count = 0;
    
    // Count how many candidates have more votes than the current candidate
    for (int j = 0; j < N; ++j) {
        if (A[j].a > current_votes) {
            higher_votes_count++;
        }
    }

    // Candidate i needs to be in the top M positions
    return higher_votes_count < M;
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i].a);
        A[i].idx = i;
    }

    sort(A, A + N, [](node a, node b) { return a.a < b.a; });
    
    for (int i = 1; i <= N; ++i) {
        psum[i] = psum[i - 1] + A[i - 1].a;
    }
    
    K -= psum[N]; // Remaining votes to be distributed

    for (int i = 0; i < N; ++i) {
        if (canWin(i, 0)) {
            A[i].a = 0; // No additional votes needed
        } else {
            long long lo = 0, hi = K + A[i].a;
            while (lo < hi) {
                long long mid = lo + (hi - lo) / 2;
                if (canWin(i, mid - A[i].a)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            A[i].a = lo;
        }
    }

    sort(A, A + N, [](node a, node b) { return a.idx < b.idx; });

    for (int i = 0; i < N; ++i) {
        printf("%lld ", A[i].a);
    }
    printf("\n");
    return 0;
}