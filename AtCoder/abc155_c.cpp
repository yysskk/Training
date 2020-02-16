// SeeAlso: https://atcoder.jp/contests/abc155/tasks/abc155_c

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 200005
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
    ll n;
    map<string, int> m;
    cin >> n;
    rep(i, n) {
        string s;
        cin >> s;

        m[s]++;
    }

    set<string> ans;
    ll temp = 0;
    for(auto it =m.begin();it!=m.end();it++) {
        auto v = *it;
        if(temp<v.second) {
            ans.clear();
            temp = v.second;
            ans.insert(v.first);
        } else if (temp==v.second) {
            ans.insert(v.first);
        }
    }
    for(auto it =ans.begin();it!=ans.end();it++) {
        print(*it);
    }
    return 0;
}
