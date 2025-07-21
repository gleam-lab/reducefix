#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool checkVictory(int i, int m, vector<int>& a, int x, int totalVotes) {
    int currentVotes = a[i] + x;
    int numWinners = 0;
    for (int vote : a) {
        if (vote > currentVotes) {
            numWinners++;
        }
    }
    return numWinners < m;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> c(n);
    int totalVotes = accumulate(a.begin(), a.end(), 0);
    int remainingVotes = k - totalVotes;

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        if (checkVictory(i, m, a, 0, totalVotes)) {
            c[i] = 0;
        } else {
            int left = 0, right = remainingVotes;
            while (left < right) {
                int mid = (left + right) / 2;
                if (checkVictory(i, m, a, mid, totalVotes)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            c[i] = left;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}