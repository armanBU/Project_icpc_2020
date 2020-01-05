/*
    Sk arman Hossain
    University of Barisal

    Problem name : Lightoj 1412 - Visiting Islands
    Algorithm : BFS
 */

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
//ll big_mod(ll base,ll power,ll Mod){if(power==0){return 1;}else if(power%2==1){ll p1=base%Mod;ll p2=(big_mod(base,power-1,Mod))%Mod;return (p1*p2)%Mod;}else if(power%2==0){ll p1=(big_mod(base,power/2,Mod))%mod;return (p1*p1)%Mod;}}
class PAIR
{
public:
    ll first;
    ll second;
    ll third;
};
ll ans[100010];

vector<ll>nod[100010],v3;
ll label[100100]= {-1},mx_node,mx,cnt=0;
void bfs(ll node)
{
    //memset(label,-1,sizeof(label));
    v3.clear();
    v3.PB(node);
    queue<ll>q;
    q.push(node);
    cnt++;
    label[node]=0;
    while(!q.empty())
    {
        ll x;
        x=q.front();
        q.pop();
        ll siz=nod[x].size();
        for(ll i=0; i<siz; i++)
        {
            ll tmp=nod[x][i];
            if(label[tmp]==-1)
            {
                v3.PB(tmp);
                cnt++;
                label[tmp]=label[x]+1;
                if(label[tmp]>mx)
                {
                    mx=label[tmp];
                    mx_node=tmp;
                }
                q.push(tmp);
            }
        }
    }
}
void graph_input(ll edge)
{
    for(ll i=0; i<edge; i++)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        nod[a].push_back(b);
        nod[b].push_back(a);
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        //memset(ans,0,sizeof(ans));
        ll n,m;
        sf2(n,m);
        graph_input(m);
        for(ll i=0; i<=n; i++)
        {
            label[i]=-1;
            ans[i]=LONG_MAX;
        }
        ll mx_label=0,total_node=0;
        for(ll i=1; i<=n; i++)
        {
            if(label[i]==-1)
            {
                mx=0;
                bfs(i);
                ll len=v3.size();
                for(ll j=0; j<len; j++)
                {
                    label[v3[j]]=-1;
                }
                cnt=0,mx=0;
                //printf("%lld mx\n",mx_node);
                bfs(mx_node);
                mx_label=max(mx,mx_label);
                total_node=max(total_node,cnt);
                for(ll k=mx+2; k<=cnt; k+=1)
                {
                    mx+=2;
                    ans[k]=min(ans[k],mx);
                }
            }
        }
        //mx_node+=1;
        printf("Case %lld:\n",test);
        ll query;
        //printf("%lld %lld cn\n",total_node,mx_label);
        sf1(query);
        for(ll i=0; i<query; i++)
        {
            ll a;
            sf1(a);

            if(a>total_node)
            {
                printf("impossible\n");
            }
            else if(a<=mx_label+1)
            {
                printf("%lld\n",a-1);
            }
            else
            {
                printf("%lld\n",ans[a]);
            }
        }
        for(ll i=0;i<=n;i++){
            nod[i].clear();
        }

        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
