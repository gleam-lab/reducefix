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

// Function to compare characters based on rock-paper-scissors rules
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
    if (x == 'X') return -100; // Special case for 'X'
}

// Function to determine the winning move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Initialize size array with 'X' at the end
    int siz[300009] = {0};
    siz[n] = 'X';
    
    char prev = 'A'; // Initial previous character
    int ans = 0; // Number of moves to break the pattern
    
    // First pass: count moves needed to break the pattern from left to right
    for (int i = 0; i < n; i++) {
        if (prev != win(s[i])) {
            ans++;
            prev = win(s[i]);
        } else {
            prev = s[i];
        }
    }
    
    // Reset previous character and initialize count for second pass
    prev = 'A';
    int sub = 0; // Number of moves to break the pattern from right to left
    
    // Second pass: count moves needed to break the pattern from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (prev != win(s[i])) {
            sub++;
            prev = win(s[i]);
        } else {
            prev = s[i];
        }
    }
    
    // Output the maximum of the two counts
    cout << max(ans, sub);
}