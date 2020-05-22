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

ll n, k ,d;
vector<ll> a;
priority_queue<string, vector<string>, greater<string>> pq;

// i: 現在の位置
// counter: sの長さ
// s: 作成した文字列
void rec(ll i, ll counter, string s) {
    if(counter == k) {
        pq.push(s);
        return;
    }

    // 文字の長さを超えたら終了
    if (i >= n) {
        return;
    }
    
    s.push_back(' ');
    s.push_back(a[i] + '0');
    counter++;
    FOR(j, i+d, n) {
        rec(j, counter, s);
    }

    if(counter == k) {
        pq.push(s);
        return;
    }
    return;
}

int main() {
    cin >> n >> k >> d;
    rep(i, n) {
        ll t;
        cin >> t;
        a.push_back(t);
    }

    rep(i, n) {
        rec(i+d, 1, to_string(a[i]));
    }

    if (pq.empty()) {
        print(-1);
    } else {
        print(pq.top());
    }

    return 0;
}
