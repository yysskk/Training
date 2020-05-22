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
    string s;
    cin >> s;

    set<string> st;

    rep(i, s.size()) {
        int ssize = s.size();
        int limit = min((ssize-i), 3);
        for(int j=1;j<=limit;j++) {
            st.insert(s.substr(i, j));
        }
    }

    set<string> newst;
    for(auto it = st.begin(); it!=st.end();it++) {
        string v = *it;
        int dotcounter = 0;
        set<string> temp;
        while(dotcounter!=v.size()) {
            if(dotcounter==0) {
                rep(i, v.size()) {
                    string t = v;
                    t[i] = '.';
                    newst.insert(t);
                    temp.insert(t);
                }
            } else {
                set<string> ttemp;
                for(auto ite=temp.begin();ite!=temp.end();ite++) {
                    string valu = *ite;
                    int valusize = valu.size();
                    rep(i, valusize) {
                        string t = valu;
                        if (t[i] == '.') continue;
                        t[i] = '.';
                        newst.insert(t);
                        ttemp.insert(t);
                    }
                }
                temp = ttemp;
            }
            dotcounter++;
        }
    }

    print(st.size() + newst.size());
    return 0;
}
