#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<int,2>> g(M);
    set<array<int,2>> ss;
    vector<int> A, B, C, D;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        ss.insert({a, b});
        A.push_back(a + b);
        B.push_back(a - b);
        C.push_back(a);
        D.push_back(b);
    }
    sort(begin(A), end(A)); A.erase(unique(begin(A), end(A)), end(A));
    sort(begin(B), end(B)); B.erase(unique(begin(B), end(B)), end(B));
    sort(begin(C), end(C)); C.erase(unique(begin(C), end(C)), end(C));
    sort(begin(D), end(D)); D.erase(unique(begin(D), end(D)), end(D));
    
    auto check = [&](int a, int b, int c, int d) -> int {
        i64 res = 0;
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                bool ok = true;
                if (a && x + y == A.back()) ok = false;
                if (b && x - y == B.back()) ok = false;
                if (c && x == C.back()) ok = false;
                if (d && y == D.back()) ok = false;
                res += ok;
            }
        }
        return res;
    };

    i64 ans = 0;
    ans += check(1, 0, 0, 0); // Only check vertical lines
    ans += check(0, 1, 0, 0); // Only check horizontal lines
    ans += check(1, 1, 0, 0); // Check diagonal lines x + y
    ans += check(1, -1, 0, 0); // Check diagonal lines x - y
    
    for(auto& [x, y]: ss){
        if(!((x+y==A.back()) || (x-y==B.back()) || (x==C.back()) || (y==D.back())))
            ans++;
    }

    cout << N * N + ans << "\n";

    return 0;
}