#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> counts(3, 0); // Counts of 'P', 'R', 'S'
    for (char c : S) {
        counts[c - 'P']++;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        char c = S[i];
        if (c == 'P') {
            ans += min(counts[1], counts[2]);
            counts[0]--;
            counts[1] = max(0, counts[1] - 1);
            counts[2] = max(0, counts[2] - 1);
        } else if (c == 'R') {
            ans += min(counts[0], counts[2]);
            counts[1]--;
            counts[0] = max(0, counts[0] - 1);
            counts[2] = max(0, counts[2] - 1);
        } else if (c == 'S') {
            ans += min(counts[0], counts[1]);
            counts[2]--;
            counts[0] = max(0, counts[0] - 1);
            counts[1] = max(0, counts[1] - 1);
        }
    }

    cout << ans << endl;
    return 0;
}