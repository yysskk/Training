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
template<class T> inline void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> inline void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const long long INF = 1LL<<60;

char henkan(ll t) {
    switch (t) {
    case 1:
        return 'a';
    case 2:
        return 'b';
    case 3:
        return 'c';
    case 4:
        return 'd';
    case 5:
        return 'e';
    case 6:
        return 'f';
    case 7:
        return 'g';
    case 8:
        return 'h';
    case 9:
        return 'i';
    case 10:
        return 'j';
    case 11:
        return 'k';
    case 12:
        return 'l';
    case 13:
        return 'm';
    case 14:
        return 'n';
    case 15:
        return 'o';
    case 16:
        return 'p';
    case 17:
        return 'q';
    case 18:
        return 'r';
    case 19:
        return 's';
    case 20:
        return 't';
    case 21:
        return 'u';
    case 22:
        return 'v';
    case 23:
        return 'w';
    case 24:
        return 'x';
    case 25:
        return 'y';
    case 0:
        return 'z';
    default:
        return 'a';
    }
    return 'a';
}

int main() {
    ll n; cin >> n;
    string s;


    while (n > 0) {
        ll memo = n % 26;
        if (memo == 0) {
            s += 'z';
            n = (n / 26) - 1;
        } else {
            s += (char) ((memo - 1) + 'a');
            n = n / 26;
        }
    }

    reverse(s.begin(), s.end());
    print(s);
    return 0;
}
