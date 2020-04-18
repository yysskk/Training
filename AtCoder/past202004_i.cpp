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
    int n;
    cin >> n;
    ll counter = 1;
    rep(i, n) {
        counter *= 2;
    }

    vector<pair<ll, ll>> a;
    rep(i, counter) {
        ll t;
        cin >> t;
        ll index = i;
        a.push_back(make_pair(index, t));
    }

    ll ans[counter];
    ll tcounter = counter;
    for(int i=0;i<n;i++) {
        tcounter /= 2;
        rep(j, tcounter) {
            auto first = a[j];
            auto second = a[j+1];
            if (first.second > second.second) {
                a[j] = first;
                ans[second.first] = i+1;
            } else {
                a[j] = second;
                ans[first.first] = i+1;
            }
            a.erase(a.begin()+j+1);
        }
    } 
    ans[a[0].first] = n;

    rep(i, counter) {
        print(ans[i]);
    }
    return 0;
}
