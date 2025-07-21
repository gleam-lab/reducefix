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
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Initialize variables
    int wins = 0;
    char last_move = 'X'; // Initial value should not be R, P, or S
    
    // Iterate through each move in the game
    for (int i = 0; i < n; ++i) {
        char current_move = s[i];
        
        // Check if the current move beats the previous move
        if ((current_move == 'P' && last_move == 'R') ||
            (current_move == 'R' && last_move == 'S') ||
            (current_move == 'S' && last_move == 'P')) {
            ++wins;
        }
        
        // Update the last move to the current move
        last_move = current_move;
    }
    
    // Output the maximum number of games Takahashi could have won
    cout << wins << endl;
    
    return 0;
}