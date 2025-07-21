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
#include <cmath>
#include <iomanip>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') return y == 'R' ? 1 : (y == 'S' ? -1 : 0);
    if (x == 'R') return y == 'S' ? 1 : (y == 'P' ? -1 : 0);
    if (x == 'S') return y == 'P' ? 1 : (y == 'R' ? -1 : 0);
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

    // Initialize variables
    int maxChain = 0;
    char current = 'X';
    char best = 'X';

    for (int i = 0; i < n; ++i) {
        // Update the current chain length if the current character can win against the best character
        if (cmp(s[i], best) == 1) {
            current = s[i];
        }

        // Update the best character if the current character is different and can win against the current character
        if (current != 'X' && cmp(current, best) == -1) {
            best = current;
        }

        // Increment the max chain length if the current character is the same as the best character
        if (current == best) {
            maxChain++;
        }
    }

    cout << maxChain << endl;

    return 0;
}