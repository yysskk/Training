// SeeAlso: https://atcoder.jp/contests/abc121/tasks/abc121_c

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

int N, M;
ll A[MAX], B[MAX];

priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {

    cin >> N >> M;

    REP(i, N) {
        cin >> A[i] >> B[i];
        pq.push(make_pair(A[i], B[i]));
    }    

    ll sum = 0;
    ll ans = 0;
    while(M > sum) {
        pll ab = pq.top();
        pq.pop();
        ll temp;
        if ((sum + ab.second) > M) {
            temp = M - sum;
        } else {
            temp = ab.second;
        }

        ans += temp * ab.first;
        sum += temp;
    }

    cout << ans << endl;
    return 0;
}
