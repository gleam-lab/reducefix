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
#include<cmath>
#include<iomanip>
using namespace std;

int cmp(char x, char y) {
    if(x == 'P') {
        if(y == 'P') return 0;
        if(y == 'R') return 1;
        if(y == 'S') return -1;
    }
    if(x == 'R') {
        if(y == 'P') return -1;
        if(y == 'R') return 0;
        if(y == 'S') return 1;
    }
    if(x == 'S') {
        if(y == 'P') return 1;
        if(y == 'R') return -1;
        if(y == 'S') return 0;
    }
    if(x == 'X') return -100;
}

char win(char x) {
    if(x == 'R') return 'P';
    if(x == 'S') return 'R';
    if(x == 'P') return 'S'; 
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> siz(n);
    char rsp[n];
    int pos = 0;
    int c = 1;
    siz[n-1] = 'X';
    char prev = 'A';
    int ans = 0;
    
    for(int i = n-2; i >= 0; --i) {
        if(prev != win(s[i+1])) {
            ans++;
            prev = win(s[i+1]);
        } else {
            prev = s[i+1];
        }
    }

    cout << ans + 1 << endl; // Add 1 because we need to count the first move as well
}