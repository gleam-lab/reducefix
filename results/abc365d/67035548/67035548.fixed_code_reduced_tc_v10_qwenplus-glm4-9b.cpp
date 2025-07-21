#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // pow, sqrt, ceil, floor, log, log10
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') return y == 'R' ? -1 : (y == 'S' ? 1 : 0);
    if (x == 'R') return y == 'P' ? 1 : (y == 'S' ? -1 : 0);
    if (x == 'S') return y == 'P' ? -1 : (y == 'R' ? 1 : 0);
    return -100;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> wins;
    vector<int> losses;

    for (int i = 0; i < n; ++i) {
        int currentCmp = cmp(s[i], 'P');
        int nextCmp = i < n - 1 ? cmp(s[i + 1], 'P') : 0;

        if (currentCmp > nextCmp) {
            wins.push_back(i);
        } else if (currentCmp < nextCmp) {
            losses.push_back(i);
        }
    }

    int ans = max(int(wins.size()), int(losses.size()));
    cout << ans;
    return 0;
}