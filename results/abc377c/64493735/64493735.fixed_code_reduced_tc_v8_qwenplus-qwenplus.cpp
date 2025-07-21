#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) unordered_set<type, boost::hash<type> > 

class Sub {
public:
    int solve() {
        ll N, M;
        scanf(N, M);

        // Use a hash-based set for faster lookups
        auto hasher = [](const pll& p) { return (p.first * 100000007LL) ^ p.second; };
        unordered_set<pll, decltype(hasher)> attacked(1024, hasher);

        for (ll i = 0; i < M; ++i) {
            ll a, b;
            scanf(a, b);
            
            // Add current piece position to attacked set (it's not empty anyway)
            attacked.insert({a, b});

            // Define all 8 possible attack positions
            const array<array<ll, 2>, 8> deltas = {{
                {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
            }};

            for (const auto& delta : deltas) {
                ll new_a = a + delta[0];
                ll new_b = b + delta[1];
                
                if (1 <= new_a && new_a <= N && 1 <= new_b && new_b <= N) {
                    attacked.insert({new_a, new_b});
                }
            }
        }

        // Total squares that are either occupied or under attack
        ll forbidden = attacked.size();
        
        // Total squares is N*N, so available squares = total - forbidden
        cout << (N * N - forbidden) << endl;

        return 0;
    }

private:
    // Simplified I/O functions for competitive programming
    void print() { cout << '\n'; }
    
    template<class T>
    void print(const T& v) { cout << v; print(); }
    
    template<class T>
    void print(const vector<T>& v) {
        for (const auto& x : v) {
            cout << x << ' ';
        }
        print();
    }

    template<class T, class... U>
    void scanf(T& a, U&... b) { cin >> a; scanf(b...); }

    template<class T>
    void scanf(vector<T>& v) { for (auto& x : v) cin >> x; }

    template<class T>
    void scanf(T& v) { cin >> v; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Sub sub;
    return sub.solve();
}