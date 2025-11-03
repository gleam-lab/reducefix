#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    // Count frequency of each move in the string
    vector<int> count(3, 0); // R=0, P=1, S=2
    for (char c : S) {
        if (c == 'R') count[0]++;
        else if (c == 'P') count[1]++;
        else if (c == 'S') count[2]++;
    }

    // Calculate maximum possible wins
    // To beat R: use P
    // To beat P: use S  
    // To beat S: use R
    long long total_wins = 0;
    total_wins += min(count[0], count[1]); // P beats R
    total_wins += min(count[1], count[2]); // S beats P
    total_wins += min(count[2], count[0]); // R beats S

    cout << total_wins << endl;

    return 0;
}