#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N], b[N];
int prefix_sum[N];

// Function to check if candidate 'i' can win by getting 'add' extra votes
bool can_win(int idx, int add) {
    int target = a[idx] + add;

    // Copy original array and update candidate's score
    vector<int> temp(a, a + n);
    temp[idx] += add;

    // Sort the updated scores
    sort(temp.begin(), temp.end());

    // Count how many candidates have more votes than current candidate
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (temp[i] > target)
            ++cnt;
        else
            break;
    }

    return cnt < m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Early exit: If M == 0, everyone already wins
    if (m == 0) {
        for (int i = 0; i < n; ++i)
            cout << "0 ";
        return 0;
    }

    vector<int> res(n, -1);

    // Pre-sort the votes
    vector<int> sorted_votes(a, a + n);

    for (int i = 0; i < n; ++i) {
        int low = 0, high = k + 1;
        int answer = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Make a copy to avoid modifying original
            vector<int> curr = sorted_votes;
            curr[i] += mid;

            sort(curr.begin(), curr.end());
            int count = 0;

            // Check how many candidates have more votes than candidate i
            for (int j = n - 1; j >= 0; --j) {
                if (curr[j] > curr[i]) ++count;
                else if (curr[j] == curr[i]) continue;
                else break;
            }

            if (count < m) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer <= k)
            res[i] = answer;
        else
            res[i] = -1;
    }

    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}