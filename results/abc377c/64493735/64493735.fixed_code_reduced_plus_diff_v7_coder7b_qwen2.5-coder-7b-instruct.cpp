#include <bits/stdc++.h>
using namespace std;
#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) set<type>
class Sub {
public:
    
int solve() {
    long long N, M;
    cin >> N >> M;

    s(p(long long, long long)) ans;
    for (long long i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        ans.emplace(a, b);

        long long a1 = a + 1;
        long long a2 = a + 2;
        long long as1 = a - 1;
        long long as2 = a - 2;
        long long b1 = b + 1;
        long long b2 = b + 2;
        long long bs1 = b - 1;
        long long bs2 = b - 2;

        if ((1 <= a2 && a2 <= N) && (1 <= b1 && b1 <= N)) {
            ans.emplace(a2, b1);
        }
        if ((1 <= a1 && a1 <= N) && (1 <= b2 && b2 <= N)) {
            ans.emplace(a1, b2);
        }
        if ((1 <= as1 && as1 <= N) && (1 <= b2 && b2 <= N)) {
            ans.emplace(as1, b2);
        }
        if ((1 <= as2 && as2 <= N) && (1 <= b1 && b1 <= N)) {
            ans.emplace(as2, b1);
        }
        if ((1 <= as2 && as2 <= N) && (1 <= bs1 && bs1 <= N)) {
            ans.emplace(as2, bs1);
        }
        if ((1 <= as1 && as1 <= N) && (1 <= bs2 && bs2 <= N)) {
            ans.emplace(as1, bs2);
        }
        if ((1 <= a1 && a2 <= N) && (1 <= bs2 && bs2 <= N)) {
            ans.emplace(a1, bs2);
        }
        if ((1 <= a2 && a2 <= N) && (1 <= bs1 && bs1 <= N)) {
            ans.emplace(a2, bs1);
        }
    }

    cout << static_cast<long long>(N)*N - ans.size() << endl;

    return 0;
}

private:
// print関数
void print(){cout<<'\n';}
template<class T>void print(const T&v){cout<<v;print();}
template<class T>void print(const vector<T>&v){for(const auto&x:v){cout<<x;if(&x!=&v.back()){cout<<' ';};};print();}
template<class T>void print(const vector<vector<T>>&v){print(v,m());