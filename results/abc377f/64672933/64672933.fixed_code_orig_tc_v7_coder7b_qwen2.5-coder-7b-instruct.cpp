#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> g(M);
    vector<i64> A, B, C, D;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        A.push_back(a + b);
        B.push_back(a - b);
        C.push_back(a);
        D.push_back(b);
    }
    sort(begin(A), end(A)); A.erase(unique(begin(A), end(A)), end(A));
    sort(begin(B), end(B)); B.erase(unique(begin(B), end(B)), end(B));
    sort(begin(C), end(C)); C.erase(unique(begin(C), end(C)), end(C));
    sort(begin(D), end(D)); D.erase(unique(begin(D), end(D)), end(D));
    
    i64 ans = 0;
    for (auto line : B) {
        i64 L = max(1LL, min(line + 1, N));
        i64 R = min(line + N, N);
        ans += R - L + 1;
    }
    for (auto line : A) {
        i64 L = max(1LL, min(line - N + 1, N));
        i64 R = min(line, N);
        ans += R - L + 1;
    }

    map<i64, i64> checkx, checky;
    for (auto line : A) {
        for (auto line1 : B) {
            if ((line + line1) % 2 == 0) {
                i64 x = (line + line1) / 2;
                i64 y = line - x;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    checkx[x]++;
                }   
            }
            if ((line - line1) % 2 == 0) {
                i64 y = (line - line1) / 2;
                i64 x = line - y;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    checky[y]++;
                }
            }
        }
    }

    for (auto line : C) {
        ans += N;
        for (auto lineA : A) {
            i64 y = lineA - line;
            if (y >= 1 && y <= N) {
                ans -= 1;
            }
        }
        for (auto lineB : B) {
            i64 x = line + lineB;
            if (x >= 1 && x <= N) {
                ans -= 1;
            }
        }
        if (checkx.count(line)) {
            ans += checkx[line];
        }
    }

    for (auto line : D) {
        ans += N;
        for (auto lineA : A) {
            i64 x = lineA - line;
            if (x >= 1 && x <= N) {
                ans -= 1;
            }
        }
        for (auto lineB : B) {
            i64 y = line + lineB;
            if (y >= 1 && y <= N) {
                ans -= 1;
            }
        }
        ans += size(C);

        for (auto line1 : C) {
            i64 v = line + line1;
            auto p = lower_bound(begin(A), end(A), v) - begin(A);
            if (p < size(A) && A[p] == v) {
                ans += 1;
            }
        }

        for (auto line1 : C) {
            i64 v = line1 - line;
            auto p = lower_bound(begin(B), end(B), v) - begin(B);
            if (p < size(B) && B[p] == v) {
                ans += 1;
            }
        }

        if (checky.count(line)) {
            ans += checky[line];
        }
    }

    set<array<i64, 2>> SS;
    for (auto x : A) {
        for (auto y : B) {
            SS.insert({x, y});
        }
    }

    for (auto x : C) {
        for (auto y : D) {
            if (SS.count({x + y, x - y})) {
                ans -= 1;
            }
        }
    }

    cout << N * N - ans << "\n";

    return 0;
}