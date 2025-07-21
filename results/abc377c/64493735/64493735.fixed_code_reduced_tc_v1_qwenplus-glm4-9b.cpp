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

        s<p(int, int)> ans;
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            ans.insert({a, b});

            // Define a helper function to add valid capture positions to the set
            auto add_capture_positions = [&](int x, int y) {
                if (1 <= a + x && a + x <= N && 1 <= b + y && b + y <= N) {
                    ans.insert({a + x, b + y});
                }
            };

            // Add capture positions based on the given rules
            add_capture_positions(2, 1);
            add_capture_positions(1, 2);
            add_capture_positions(-1, 2);
            add_capture_positions(-2, 1);
            add_capture_positions(-2, -1);
            add_capture_positions(-1, -2);
            add_capture_positions(1, -2);
            add_capture_positions(2, -1);
        }

        // The total number of squares minus the number of squares with pieces or captured by other pieces
        int total_squares = N * N;
        int occupied_or_captured = ans.size();
        int result = total_squares - occupied_or_captured;

        print(result);

        return 0;
    }

private:
    void print() { cout << '\n'; }
    template <class T> void print(const T& v) { cout << v; print(); }
    template <class T> void print(const v<T>& v) { for (const auto& x : v) print(x); print(); }
    template <class T> void print(const m<T>& v) { for (const auto& x : v) print(x.first), print(x.second); print(); }
    template <class T> void print(const s<T>& v) { for (const auto& x : v) print(x); print(); }
    template <class T, class... U> void print(const T& a, const U&... b) { cout << a; print(b...); }
    template <class T, class... U> void print(const v<T>& a, const U&... b) { print(a); print(b...); }
    template <class T, class... U> void print(const v<v<T>>& a, const U&... b) { print(a); print(b...); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub* sub = new Sub();
    int back = sub->solve();
    delete sub;
    return back;
}