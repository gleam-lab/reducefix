#include <bits/stdc++.h>
using namespace std;
#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) set<type>
class Sub {
public:
    
    int solve() {
        int N, M;
        scanf("%d %d", &N, &M);

        vector<vector<int>> grid(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            grid[a][b] = 1;
        }

        long long result = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (grid[i][j] == 0) { // Check if the cell is empty
                    bool canPlace = true;
                    // Check if the cell can be captured by any existing piece
                    canPlace &= grid[i + 2][j + 1] == 0;
                    canPlace &= grid[i + 1][j + 2] == 0;
                    canPlace &= grid[i - 1][j + 2] == 0;
                    canPlace &= grid[i - 2][j + 1] == 0;
                    canPlace &= grid[i - 2][j - 1] == 0;
                    canPlace &= grid[i - 1][j - 2] == 0;
                    canPlace &= grid[i + 1][j - 2] == 0;
                    canPlace &= grid[i + 2][j - 1] == 0;

                    if (canPlace) {
                        result++;
                    }
                }
            }
        }

        printf("%lld\n", result);

        return 0;
    }

private:
    // printé¢æ°
    void print() { cout << '\n'; }
    template<class T> void print(const T& v) { cout << v; print(); }
    template<class T> void print(const vector<T>& v) {
        for (const auto& x : v) print(x);
        print();
    }
    template<class T> void print(const vector<vector<T>>& v) {
        for (const auto& x : v) print(x);
        print();
    }
    template<class T,class...U> void print(const T&a, const U&...b) { cout << a; print(b...); }
    template<class T,class...U> void print(const vector<T>&a, const U&...b) { print(a); print(b...); }
    template<class T,class...U> void print(const vector<vector<T>>&a, const U&...b) { print(a); print(b...); }
    template<class T> void print(const vector<T>&v, const bool&m) { if (m) for (const auto&x:v) print(x); else for (const auto&x:v) print(x); }
    template<class T> void print(const vector<vector<T>>&v, const bool&m) { print(v,m); }

    // scanfé¢æ°
    template<class T> void scanf(T&v) { cin >> v; }
    template<class T> void scanf(vector<T>&v) { for (const auto&x:v) scanf(x); }
    template<class T> void scanf(vector<vector<T>>&v) { for (const auto&x:v) scanf(x); }
    template<class T,class...U> void scanf(T&a, U&...b) { scanf(a); scanf(b...); }
    template<class T,class...U> void scanf(vector<T>&a, U&...b) { scanf(a); scanf(b...); }
    template<class T,class...U> void scanf(vector<vector<T>>&a, U&...b) { scanf(a); scanf(b...); }

    // changeã®max,min
    template<class T> bool chmax(T&a, const T&b) { if (a < b) { a = b; return true; } else { return false; } }
    template<class T> bool chmin(T&a, const T&b) { if (a > b) { a = b; return true; } else { return false; } }
    // max,minã®åå¯¾å¿
    template<class T> T armax(vector<T>&v) { T M = -1; for (int i = 0; i < (int)v.size(); i++) { chmax(M, v[i]); }; return M; }
    template<class T> T armin(vector<T>&v) { T M = 1; for (int i = 0; i < (int)v.size(); i++) { chmin(M, v[i]); }; return M; }
    //sorté¢æ°
    template<class T> void sort_u(vector<T>&v) { sort(v.begin(), v.end()); }
    template<class T,class...U> void sort_u(vector<T>&a, vector<U>&...b) { sort_u(a); sort_u(b...); }
    template<class T> void sort_d(vector<T>&v) { sort(v.rbegin(), v.rend()); }
    template<class T,class...U> void sort_d(vector<T>&a, vector<U>&...b) { sort_u(a); sort_u(b...); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub *sub = new Sub();
    int back = sub->solve();
    delete sub;
    return back;
}