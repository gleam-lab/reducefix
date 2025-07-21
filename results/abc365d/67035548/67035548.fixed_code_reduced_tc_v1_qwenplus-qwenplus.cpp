#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 0;
        if (y == 'R') return 1;
        if (y == 'S') return -1;
    }
    if (x == 'R') {
        if (y == 'P') return -1;
        if (y == 'R') return 0;
        if (y == 'S') return 1;
    }
    if (x == 'S') {
        if (y == 'P') return 1;
        if (y == 'R') return -1;
        if (y == 'S') return 0;
    }
    return 0;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return x;
}

int solve(const string& s) {
    int n = s.size();
    vector<int> forward(n), backward(n);
    
    // Forward pass
    int count = 0;
    char last_move = 'X'; // no move taken yet
    for (int i = 0; i < n; ++i) {
        if (last_move != win(s[i])) {
            count++;
            last_move = win(s[i]);
        } else {
            last_move = s[i];
        }
        forward[i] = count;
    }

    // Backward pass
    count = 0;
    last_move = 'X';
    for (int i = n-1; i >= 0; --i) {
        if (last_move != win(s[i])) {
            count++;
            last_move = win(s[i]);
        } else {
            last_move = s[i];
        }
        backward[i] = count;
    }

    int max_wins = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            max_wins = max(forward[n-1], backward[0]);
        } else {
            max_wins = max(max_wins, forward[i-1] + backward[i]);
        }
    }

    return max_wins;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(s) << endl;
    return 0;
}