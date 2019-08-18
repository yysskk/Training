// SeeAlso: https://atcoder.jp/contests/abc138/tasks/abc138_e

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

string s, t;
int main() {
    cin >> s;
    cin >> t;

    bool flag = true;
    for(ll i=0;i<t.size();i++){
        if (s.find(t[i]) == -1) {
            flag = false;
            break;
        }
    }   
    if (!flag) {
        print("-1");
        return 0;
    }
    ll ans = 0;
    string temp = s;
    for(ll i=0;i<t.size();i++){       
        DEBUG(temp);
        DEBUG(t[i]); 
        ll length = temp.find(t[i]);
        if(length==-1) {
            temp += s;
            length = temp.find(t[i]);
        }
        temp.erase(temp.begin(), temp.begin()+length+1);
        ans += (length+1);        
    }

    ll length = temp.find(t[t.size()]);
    
    print(ans);
    return 0;
}
