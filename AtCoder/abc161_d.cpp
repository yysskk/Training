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


bool rec(ll ans, int index) {
    if(index-1==to_string(ans).size()) return true;
    
    int keta = 1;
    rep(i, index) {
        keta *= 10;
    }
    int border1 = ans % keta;
    int border2 = (ans-border1) % (keta*10) / 10;
    debug(border1);
    debug(border2);
    if (abs(border1-border2)<=1) {
        return rec(ans, index+1);
    } else {
        return false;
    }
}

int main() {
    ll k;
    cin >> k;
    ll ans = 0;
    rep(i, k) {
        if(ans<10) {
            ans++;
            continue;
        }
        ans++;
        while(!rec(ans, 1)) {
            ans++; 
        }

        debug(ans);
    }
    print(ans);
    return 0;
}
