// SeeAlso: https://atcoder.jp/contests/abc155/tasks/abc155_d

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

ll casecounter(ll i) {
    return i * (i-1) / 2;
}
int main() {
    ll n, k;
    multiset<ll> b;
    multiset<ll, greater<ll>> a;
    multiset<ll, greater<ll>> abs_set;
    cin >> n >> k;


    ll a_counter = 0;
    ll b_counter = 0;

    rep(i, n) {
        ll t;
        cin >> t;
        if(t>0) {
            a.insert(t);
            a_counter++;
            abs_set.insert(t);
        } else {
            b.insert(t);
            b_counter++;
            abs_set.insert(abs(t));
        }
    }


    if(k <=(a_counter*b_counter)) {
        // 負の集合の場合
        multiset<ll> ans;
        for(auto it = a.begin();it!=a.end();it++) {
            for(auto it2 = b.begin();it2!=b.end();it2++) {
                ll v1 = *it;
                ll v2 = *it2;
                ans.insert((v1*v2));
            }
        }

        ll temp = 1;
        for(auto it = ans.begin();it!=ans.end();it++) {
            if(temp==k) {
                ll v = *it;
                print(v);
                break;
            }
            temp++;
        }
    } else {
        // 正の集合の場合
        ll counter = casecounter(n)-k+1;
        multiset<ll, greater<ll>> ans;
        ll temp = 0;
        for(auto it = a.begin();it!=a.end();it++) {
            for(auto it2 = a.begin();it2!=it;it2++) {
                if(it==it2) continue;
                temp++;
                ll v1 = *it;
                ll v2 = *it2;
                ll hoge = v1 * v2;
                ans.insert(hoge);
            }

            if(temp==counter) {
                break;
            }
        }

        temp = 0;
        for(auto it = b.begin();it!=b.end();it++) {
            for(auto it2 = b.begin();it2!=it;it2++) {
                if(it==it2) continue;
                temp++;
                ll v1 = *it;
                ll v2 = *it2;
                ll hoge = v1 * v2;
                ans.insert(hoge);
            }

            if(temp==counter) {
                break;
            }
        }

        temp = 0;
        for(auto it = ans.begin();it!=ans.end();it++) {
            temp++;
            if(temp==counter) {
                print(*it);
                break;
            }
        }
    }

    return 0;
}
