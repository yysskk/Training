// SeeAlso: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000
#define NIL -1
#define MOD 1000000007

typedef int _loop_int;
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define debug(x) cout<<#x<<": "<<x<<endl
#define debig_vec(v) cout<<#v<<":";rep(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) rep(i, h) { rep(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

int main() {
    
    map<string, int> m;
    m.insert(make_pair("B9", -9));
    m.insert(make_pair("B8", -8));
    m.insert(make_pair("B7", -7));
    m.insert(make_pair("B6", -6));
    m.insert(make_pair("B5", -5));
    m.insert(make_pair("B4", -4));
    m.insert(make_pair("B3", -3));
    m.insert(make_pair("B2", -2));
    m.insert(make_pair("B1", -1));
    m.insert(make_pair("1F", 0));
    m.insert(make_pair("2F", 1));
    m.insert(make_pair("3F", 2));
    m.insert(make_pair("4F", 3));
    m.insert(make_pair("5F", 4));
    m.insert(make_pair("6F", 5));
    m.insert(make_pair("7F", 6));
    m.insert(make_pair("8F", 7));
    m.insert(make_pair("9F", 8));

    string s,t;
    cin >> s >> t;
    print(abs(m.at(t)-m.at(s)));
    return 0;
}
