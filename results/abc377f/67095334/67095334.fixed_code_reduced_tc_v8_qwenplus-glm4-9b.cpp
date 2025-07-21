#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define inf 1e9+7

using namespace std;

int n, m;
vector<int> a, b, diamonds, antidiamonds;

bool is_covered(int x, int y) {
    if (find(a.begin(), a.end(), x) != a.end()) return true;
    if (find(b.begin(), b.end(), y) != b.end()) return true;
    if (find(diamonds.begin(), diamonds.end(), x + y) != diamonds.end()) return true;
    if (find(antidiamonds.begin(), antidiamonds.end(), x - y) != antidiamonds.end()) return true;
    return false;
}

int main() {
    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    diamonds.resize(m);
    antidiamonds.resize(m);
    
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        diamonds.push_back(x + y);
        antidiamonds.push_back(x - y);
    }
    
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!is_covered(i, j)) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}