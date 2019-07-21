// SeeAlso: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 200000

typedef int _loop_int;
#define REP(i,n) for(ll i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

ll N;
ll A[MAX];
priority_queue<ll> pq;

int main() {

    cin >> N;

    ll temp = 0;
    REP(i, N) {
        cin >> A[i];
        pq.push(A[i]);        
    }

    REP(i, N) {
        ll top = pq.top();
        if(top == A[i]) {
            pq.pop();
            ll ans = pq.top();
            cout << ans << endl;
            pq.push(top);
        } else {
            cout << top << endl;
        } 
    }
    return 0;
}
