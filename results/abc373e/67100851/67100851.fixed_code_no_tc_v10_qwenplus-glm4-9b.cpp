#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;

int N, M, K;
vector<node> A;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

bool check(long long x) {
    long long sum = 0, extra_votes = K - (N * x);
    while (!pq.empty()) {
        auto [val, idx] = pq.top();
        pq.pop();
        long long votes_needed = max(0LL, M - 1 - val);
        sum += votes_needed;
        if (sum > extra_votes) return false;
    }
    return true;
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    long long sum_votes = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i].a);
        sum_votes += A[i].a;
        pq.push({A[i].a, i});
    }

    if (sum_votes < M) {
        // If the sum of votes already obtained by all candidates is less than M, no one can win.
        for (int i = 0; i < N; ++i) {
            cout << -1 << " ";
        }
        cout << endl;
        return 0;
    }

    // Binary search for the minimum x that guarantees victory for each candidate
    long long lo = 0, hi = K / N;
    while (lo < hi) {
        long long mid = (lo + hi + 1) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    
    // After binary search, lo should be the minimum votes needed to guarantee victory
    for (int i = 0; i < N; ++i) {
        long long votes_needed = max(0LL, M - 1 - A[i].a);
        votes_needed = max(0LL, votes_needed - ((lo > A[i].a) ? lo - A[i].a : 0));
        cout << votes_needed << " ";
    }
    cout << endl;

    return 0;
}