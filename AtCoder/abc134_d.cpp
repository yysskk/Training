// SeeAlso: https://atcoder.jp/contests/abc131/tasks/abc131_d
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
#define MAX 200000
 
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
 
ll N;
ll A[MAX], B[MAX];
 
int main() {
    cin >> N;
    REP(i, N) {
        cin >> A[i] >> B[i];
    }    
 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
 
    REP(i, N) {
        pq.push(make_pair(B[i], A[i]));
    }
    bool flag = true;
    ll t = 0;
    REP(i, N) {
        auto a = pq.top().second;
        auto b = pq.top().first;
        pq.pop();
        t += a;
        if (t > b) {
            flag = false;
            break;
        }  
    }
 
    string S;
    
    if (flag) {
        S = "Yes";
    } else {
        S = "No";
    }
 
    cout << S << endl;
    return 0;
}
