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

ll culc(map<char, ll> mm) {
    ll ans = 0;
    for(auto it=mm.begin();it!=mm.end();it++) {
        auto valu = *it;
        ans += (valu.second*valu.second);
    }  
    return ans;
} 

void initialize(map<char, ll> mm) {
    mm.insert(make_pair('a', 0));
    mm.insert(make_pair('b', 0));
    mm.insert(make_pair('c', 0));
    mm.insert(make_pair('d', 0));
    mm.insert(make_pair('e', 0));
    mm.insert(make_pair('f', 0));
    mm.insert(make_pair('g', 0));
    mm.insert(make_pair('h', 0));
    mm.insert(make_pair('i', 0));
    mm.insert(make_pair('j', 0));
    mm.insert(make_pair('k', 0));
    mm.insert(make_pair('l', 0));
    mm.insert(make_pair('m', 0));
    mm.insert(make_pair('n', 0));
    mm.insert(make_pair('o', 0));
    mm.insert(make_pair('p', 0));
    mm.insert(make_pair('q', 0));
    mm.insert(make_pair('r', 0));
    mm.insert(make_pair('s', 0));
    mm.insert(make_pair('t', 0));
    mm.insert(make_pair('u', 0));
    mm.insert(make_pair('v', 0));
    mm.insert(make_pair('w', 0));
    mm.insert(make_pair('x', 0));
    mm.insert(make_pair('y', 0));
    mm.insert(make_pair('z', 0));
}

int main() {
    ll q;
    cin >> q;

    int t;
    vector<pair<char, ll>> s;
    ll scounter = 0;
    rep(i, q) {
        cin >> t;
        map<char, ll> mm;
        initialize(mm);

        if(t==1) {
            char c;
            ll x;
            cin >> c >> x;
            scounter += x;
            s.push_back(make_pair(c, x));
        } else if (t==2) {
            ll d;
            cin >> d;
            // d文字以下の場合はsはから文字列
            if (scounter<=d) {
                for(auto it=s.begin();it!=s.end();it++) {
                    auto v = *it;
                    mm[v.first] += v.second;
                }
                scounter = 0;
                s = {};
            } else {
                while(d>0) {
                    if(s[0].second <= d) {
                        d -= s[0].second;
                        mm[s[0].first] += s[0].second;
                        scounter -= s[0].second;
                        s.erase(s.begin());
                    } else {
                        mm[s[0].first] += d;
                        s[0].second -= d;
                        scounter -= d;
                        d=0;
                    }
                }
            }
            print(culc(mm));
        }
    }

    return 0;
}
