#include<bits/stdc++.h>
using namespace std;

bool check(int x, vector<int>& A, vector<int>& B) {
    multiset<int> s(B.begin(), B.end());
    for(int a : A) {
        auto it = s.upper_bound(a);
        if(it == s.end()) return false;
        s.erase(it);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    for(int &a : A) cin >> a;
    for(int &b : B) cin >> b;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int l = 0, r = 1e9;
    while(l <= r) {
        int m = (l + r) / 2;
        if(check(m, A, B)) r = m - 1;
        else l = m + 1;
    }

    if(r == 1e9) cout << "-1" << endl;
    else cout << r + 1 << endl;
    return 0;
}