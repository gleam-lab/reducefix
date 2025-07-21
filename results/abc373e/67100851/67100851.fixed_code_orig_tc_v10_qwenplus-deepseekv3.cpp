#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef struct {
    ll a;
    int idx;
} node;

bool compareA(const node &x, const node &y) {
    return x.a < y.a;
}

bool compareIdx(const node &x, const node &y) {
    return x.idx < y.idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<node> A(N);
    vector<ll> original(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        original[i] = A[i].a;
        A[i].idx = i;
    }

    if (M == N) {
        for (int i = 0; i < N; ++i) {
            cout << "0 ";
        }
        cout << "\n";
        return 0;
    }

    sort(A.begin(), A.end(), compareA);

    vector<ll> psum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        psum[i] = psum[i - 1] + A[i - 1].a;
    }

    ll remaining = K - psum[N];
    if (remaining < 0) {
        remaining = 0;
    }

    vector<ll> res(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i].a;
        int pos = upper_bound(A.begin(), A.end(), node{current, -1}, compareA) - A.begin();
        if (pos >= N - M + 1) {
            res[A[i].idx] = 0;
            continue;
        }

        ll low = 0, high = remaining;
        ll answer = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            int new_pos = upper_bound(A.begin(), A.end(), node{new_votes, -1}, compareA) - A.begin();
            if (new_pos >= N - M + 1) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        res[A[i].idx] = answer;
    }

    for (int i = 0; i < N; ++i) {
        if (res[i] == -1) {
            cout << "-1 ";
        } else {
            cout << res[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}