#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef struct {
    ll a;
    int idx;
} node;

vector<node> A;
vector<ll> psum;
ll K;
int N, M;

bool is_possible(ll x, int i) {
    ll total_votes = A[i].a + x;
    int idx = upper_bound(A.begin(), A.end(), node{total_votes, -1}, [](node a, node b) {
        return a.a < b.a;
    }) - A.begin();
    int l = N - M;
    if (idx <= l) {
        return false;
    }
    ll sum = psum[idx] - psum[l];
    ll required = (idx - l) * total_votes - sum;
    if (required <= K - x) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    A.resize(N);
    psum.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i].a);
        A[i].idx = i;
    }
    sort(A.begin(), A.end(), [](node a, node b) {
        return a.a < b.a;
    });
    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1].a;
    }
    K -= psum[N];
    vector<ll> res(N, -1);
    for (int i = 0; i < N; i++) {
        ll low = 0, high = K;
        ll ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (is_possible(mid, i)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans != -1) {
            res[A[i].idx] = ans;
        } else {
            res[A[i].idx] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%lld ", res[i]);
    }
    printf("\n");
    return 0;
}