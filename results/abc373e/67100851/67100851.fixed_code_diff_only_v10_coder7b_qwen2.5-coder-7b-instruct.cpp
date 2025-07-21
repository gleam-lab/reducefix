#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int m, long long k, int i, long long x) {
    int n = candidates.size();
    int numWinners = n - m;
    long long sumVotes = 0;
    int countLessThanMe = 0;

    for (const auto& c : candidates) {
        if (c.index == i) {
            sumVotes += c.votes + x;
        } else {
            sumVotes += c.votes;
            if (c.votes + x > c.votes) {
                countLessThanMe++;
            }
        }
    }

    if (countLessThanMe <= numWinners) {
        return true;
    }

    return false;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });

    vector<long long> results(n, -1);

    for (int i = 0; i < n; ++i) {
        if (candidates[i].votes >= k) {
            continue;
        }

        int left = 0, right = k - candidates[i].votes;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canWin(candidates, m, k, i, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (canWin(candidates, m, k, i, left)) {
            results[candidates[i].index] = left;
        }
    }

    for (long long result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}