#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;

long long psum[200001], K;
int N, M;

bool can_win(node candidates[], long long votes, int i, int first_l, int second_l) {
    if (i >= first_l && i < second_l) {
        long long needed_votes = candidates[i].a + votes - candidates[candidates[i].idx].a;
        if (needed_votes <= K) return true;
        votes += needed_votes;
        K -= needed_votes;
    }
    return K < 0;
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    psum[0] = 0;
    node candidates[200001];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &candidates[i].a);
        candidates[i].idx = i;
    }
    sort(candidates, candidates + N, [](node a, node b) { return a.a < b.a; });
    for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + candidates[i - 1].a;
    K -= psum[N];

    long long votes_needed = 0;
    int first_l = N - M;
    int second_l = first_l + 1;
    if (second_l <= first_l) second_l = first_l + 1;
    vector<int> candidates_to_win;

    for (int i = N - 1; i >= 0; i--) {
        long long votes = can_win(candidates, 0, i, first_l, second_l);
        if (votes) {
            votes_needed = votes + candidates[i].a - candidates[candidates[i].idx].a;
            candidates_to_win.push_back(i);
        }
    }

    for (int i = 0; i < candidates_to_win.size(); i++) {
        if (i == 0) {
            printf("%lld", votes_needed + candidates[candidates[candidates_to_win[i]].idx].a - candidates[candidates_to_win[i]].a);
        } else {
            printf(" %lld", votes_needed + candidates[candidates[candidates_to_win[i]].idx].a - candidates[candidates_to_win[i]].a);
        }
    }

    if (candidates_to_win.size() < M) {
        for (int i = candidates_to_win.size(); i < M; i++) {
            printf(" -1");
        }
    }
    printf("\n");
}