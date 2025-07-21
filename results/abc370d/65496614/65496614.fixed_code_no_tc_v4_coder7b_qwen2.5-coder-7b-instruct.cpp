#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n) ; ++i)
#define rep1(i,n) for(int i = 1; i < (int)(n) ; ++i)
#define rrep(i,n) for(int i = (int)n-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (int)n-1; i >= 1 ; --i)

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

using vs = vector<string>;

string filename = __FILE__;

//===============================================
//デバッグ用出力関数===============================
//===============================================

// コンテナ型かどうかの判定（begin/endがあるかで判定）
//is_containerはstd::false_typeを継承。::valueを通じてfalseを返す。
//デフォルトではコンテナ型なしと判定。
template<typename T, typename = void>
struct is_container : std::false_type {};


template<typename T>
struct is_container<
    T,
    //ヘルパー型。中のすべてのdecltypeが有効ならvoid型になる。
    //無効であればテンプレートの特殊化自体が除外(SFINAE発動)
    std::void_t<
        //右辺値を生成せずにメンバ関数を持っているか判定
        //decltype: 中の式の型を取得する
        //declval:  実体を生成せずに使う
        decltype(std::declval<T>().begin()),
        decltype(std::declval<T>().end())
    >
> : std::true_type {};



template<typename T>
void dbg(const T &i, bool linebreak = true){
    if(filename == "Main.cpp") return;

    cout << i;
    if(linebreak) cout << "\n";
    else cout << " ";
    return;
}

// double型専用処理（std::enable_ifを使う)
// enable_ifは中身がtrueの場合、voidを返す
// 中身がfalseの場合、enable_ifは無効化され、このテンプレート関数は選ばれない。
template<typename T>
typename std::enable_if<std::is_same<T, double>::value>::type
dbg(const T &i, bool linebreak = true){
    if(filename == "Main.cpp") return;

    printf("%.10lf", i);
    if(linebreak) cout << "\n";
    else cout << " ";
    return;
}

// string専用処理
template<typename T>
typename std::enable_if<std::is_same<T, string>::value>::type
dbg(const T &i, bool linebreak = true){
    if(filename == "Main.cpp") return;

    cout << i;
    if(linebreak) cout << "\n";
    else cout << " ";
    return;
}



template<typename T>
void dbg(const vector<T> &vec, bool linebreak = true){
    if(filename == "Main.cpp") return;

    for(const auto &val: vec) dbg(val, is_container<T>::value);
    cout << endl;
    return;
}




int main()
{
    int h, w, q;
    cin >> h >> w >> q;

    vvb coo(h+2, vb(w+2, true));
    vector<vector<pair<int,int>>> row(h+2);
    vector<vector<pair<int,int>>> col(w+2);

    int r, c;

    auto erase = [&](int i, int j){
        if(!coo[i][j]) return;
        coo[i][j] = false;
        for(auto [ri, ci]: row[i]) col[ci].erase({ri, ci});
        for(auto [ri, ci]: col[j]) row[ri].erase({ri, ci});
    };

    auto bin = [&](){
        {
            auto &st = row[r];
            auto it = lower_bound(st.begin(), st.end(), make_pair(-1, c));
            if(it != st.begin()) erase(prev(it)->first, prev(it)->second);
            if(next(it) != st.end()) erase(next(it)->first, next(it)->second);
        }

        {
            auto &st = col[c];
            auto it = lower_bound(st.begin(), st.end(), make_pair(-1, r));
            if(it != st.begin()) erase(prev(it)->first, prev(it)->second);
            if(next(it) != st.end()) erase(next(it)->first, next(it)->second);
        }
    };

    while(q--){
        cin >> r >> c;
        if(coo[r][c]){
            erase(r,c);
            continue;
        }
        bin();
    }

    int ans = 0;
    rep(i,h)rep(j,w) if(coo[i+1][j+1]) ans++;

    cout << ans << endl;
    return 0;
}