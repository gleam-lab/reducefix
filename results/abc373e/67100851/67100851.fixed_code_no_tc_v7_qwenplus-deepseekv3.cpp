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
vector<ll> sorted_A;
vector<ll> prefix_sum;
ll K;
int N, M;

bool is_possible(ll X, int i) {
    ll new_votes = sorted_A[i] + X;
    int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes) - sorted_A.begin();
    int candidates_above = N - pos;
    if (candidates_above < M) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    A.resize(N);
    sorted_A.resize(N);
    prefix_sum.resize(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
        sorted_A[i] = A[i].a;
    }

    sort(sorted_A.begin(), sorted_A.end());
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    ll remaining_votes = K;
    for (int i = 0; i < N; ++i) {
        remaining_votes -= A[i].a;
    }

    vector<ll> result(N, -1);
    for (int i = 0; i < N; ++i) {
        ll original = A[i].a;
        ll low = 0, high = remaining_votes;
        ll min_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = original + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes) - sorted_A.begin();
            int candidates_above = N - pos;
            if (candidates_above < M) {
                min_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        result[A[i].idx] = min_X;
    }

    for (int i = 0; i < N; ++i) {
        if (result[i] != -1) {
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), A[i].a) - sorted_A.begin();
            int candidates_above = N - pos;
            if (candidates_above < M) {
                result[i] = 0;
            }
        }
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}