#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Initialize variables to keep track of the counts
    int count_1 = 0, count_2 = 0;
    bool flip_flop = false;

    for(int i = 0; i < n; ++i){
        if(i > 0 && s[i] != s[i-1]){
            flip_flop = !flip_flop;
        }
        if(flip_flop) ++count_1;
        else ++count_2;
    }

    cout << max(count_1, count_2) << endl;

    return 0;
}