#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    unordered_map<char, int> count;
    int ans = 0;
    
    for (char c : s) {
        ans = max(ans, count[c]);
        count[c]++;
    }
    
    cout << n - ans;
    return 0;
}