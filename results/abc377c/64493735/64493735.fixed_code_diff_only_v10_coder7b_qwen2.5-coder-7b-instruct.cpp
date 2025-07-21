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
    cin >> N >> M;

    s(p(int, int)) ans;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ans.emplace(a, b);

        int a1 = a + 1;
        int a2 = a + 2;
        int as1 = a - 1;
        int as2 = a - 2;
        int b1 = b + 1;
        int b2 = b + 2;
        int bs1 = b - 1;
        int bs2 = b - 2;

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
        if ((1 <= a1 && a1 <= N) && (1 <= bs2 && bs2 <= N)) {
            ans.emplace(a1, bs2);
        }
        if ((1 <= a2 && a2 <= N) && (1 <= bs1 && bs1 <= N)) {
            ans.emplace(a2, bs1);
        }
    }

    cout << static_cast<long long>(N) * N - ans.size() << endl;

    return 0;
};

private:
// print関数
void print(){cout<<'\n';}
template<class T>void print(const T&v){cout<<v;print();}
template<class T>void print(const vector<T>&v){for(const auto&x:v){cout<<x;if(&x!=&v.back()){cout<<' ';};};print();}
template<class T>void print(const vector<vector<T>>&v){for(const auto&x:v)print(x);}
template<class T,class...U>void print(const T&a,const U&...b){cout<<a;print(b...);};
template<class T,class...U>void print(const vector<T>&a,const U&...b){print(a);print(b...);}
template<class T,class...U>void print(const vector<vector<T>>&a,const U&...b){print(a);print(b...);}
// scanf関数
template<class T>void scanf(T&v){cin>>v;}
template<class T>void scanf(vector<T>&v){for(const auto&x:v)scanf(x);}
template<class T>void scanf(vector<vector<T>>&v){for(const auto&x:v)scanf(x);}
template<class T,class...U>void scanf(T&a,U&...b){scanf(a);scanf(b...);}
template<class T,class...U>void scanf(vector<T>&a,U&...b){scanf(a);scanf(b...);}
template<class T,class...U>void scanf(vector<vector<T>>&a,U&...b){scanf(a);scanf(b...);}
// changeのmax,min
template<class T>bool chmax(T&a,const T&b){if(a<b){a=b;return true;}else{return false;}}
template<class T>bool chmin(T&a,const T&b){if(a>b){a=b;return true;}else{return false;}}
// max,minの配列対応
template<class T>T armax(vector<T>&v){T M=-1;for(int i=0;i<(int)v.size();i++){chmax(M,v[i]);};return M;}
template<class T>T armin(vector<T>&v){T M=1;for(int i=0;i<(int)v.size();i++){chmin(M,v[i]);};return M;}
//sort関数
template<class T>void sort_u(vector<T>&v){sort(v.begin(),v.end());}
template<class T,class...U>void sort_u(vector<T>&a,vector<U>&...b){sort_u(a);sort_u(b...);}
template<class T>void sort_d(vector<T>&v){sort(v.rbegin(),v.rend());}
template<class T,class...U>void sort_d(vector<T>&a,vector<U>&...b){sort_u(a);sort_u(b...);}
// 競プロ出力
string YesPrintBollSetting="Yes",NoPrintBollSetting="No";
void print_set(const string&Y,const string&N){YesPrintBollSetting=Y,NoPrintBollSetting=N;}
void print(const bool&v){v?print(YesPrintBollSetting):print(NoPrintBollSetting);}

template<class T>bool isPrime(const T&N){for(T i=2;i*i<=N;i++){if(N%i==0)return false;};return true;}
template<class T>vector<T> enumDivisor(const T&N){vector<T>M;for(T i=1;i*i<=N;i++){if(N%i!=0){continue;};M.push_back(i);if(i!=N/i){M.push_back(N/i);};};return M;}
template<class T>vector<pair<T,T>> primeFactorize(const T&v){T N=v;vector<pair<T,T>>R;for(T i=2;i*i<=N;i++){if(N%i!=0)continue;T e=0;while(N%i==0){e++;N/=i;};R.push_back({i,e});};if(N!=1)R.push_back({N,1});return R;}
template<class T>vector<T> changeDimensional(const vector<pair<T,T>>&v){vector<T>R;for(const auto&x:v){for(auto i=0;i<x.second;i++){R.push_back(x.first);};};return R;}
template<class T>T gcd(const T&a,const T&b){T A=a,B=b;while(1<=A&&1<=B){if(A<B){B%=A;}else{A%=B;};};if(1<=A){return A;}else{return B;};}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub *sub = new Sub();
    int back = sub->solve();
    delete sub;
    return back;
}