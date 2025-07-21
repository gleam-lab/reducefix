#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s(n, ' ');
    cin >> s;

    vector<int> count(3);
    for(char c : s) {
        count[c - 'P']++;
    }

    int res = min(count[0], min(count[1], count[2]));
    if(res == count[0]) {
        cout << count[1] + count[2] - res << endl;
    } else if(res == count[1]) {
        cout << count[0] + count[2] - res << endl;
    } else {
        cout << count[0] + count[1] - res << endl;
    }
    return 0;
}