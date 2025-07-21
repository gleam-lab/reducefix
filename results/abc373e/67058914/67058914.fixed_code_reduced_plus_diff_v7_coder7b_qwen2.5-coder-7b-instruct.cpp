#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
    ll val;
    int idx;
};

bool canWin(const vector<int>& votes, int i, int addVotes) {
    int cnt = 0;
    for (int j = 0; j < N; ++j) {
        if (j == i) {
            cnt += votes[j] + addVotes;
        } else {
            cnt += votes[j];
        }
        if (cnt > votes[i]) {
            break;
        }
    }
    return cnt > votes[i] && cnt - votes[i] >= M - 1;
}

int main() {
    cin >> N >> M >> K;

    vector<int> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    vector<int> result(N, -1);
    
    for (int i = 0; i < N; ++i) {
        if (votes[i] >= K) {
            result[i] = 0;
            continue;
        }

        int low = 0, high = K - votes[i];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canWin(votes, i, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        result[i] = low;
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}