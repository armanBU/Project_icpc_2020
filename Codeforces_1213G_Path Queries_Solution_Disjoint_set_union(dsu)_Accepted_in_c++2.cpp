/*
    Sk arman Hossain
    University of Barisal

    Problem name :
    Algorithm :
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
bool cmp(PAIR t1,PAIR t2)
{
    if(t1.third!=t2.third)
        return (t1.third < t2.third);
    else
        return t1.third>t2.third;
}
ll rep[200010];
ll cnt_node[200010];
ll ans[200010];
ll sum=0;
void initial(ll n)
{
    for(int i=1; i<=n; i++)
    {
        rep[i]=i;
        cnt_node[i]=1;
    }
}
ll find_representative(ll node)
{
    if(rep[node]==node)
    {
        return node;
    }
    else
    {
        rep[node]=find_representative(rep[node]);
        return rep[node];
    }
}
void joint_node(ll nodex,ll nodey)
{
    ll u=find_representative(nodex);
    ll v=find_representative(nodey);
    if(u!=v)
    {
        rep[u]=v;
        sum+=(cnt_node[u]*cnt_node[v]);
        cnt_node[v]+=cnt_node[u];
    }
}
vector<PAIR>V;
int main()
{
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    // sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,ma=0;
        sf2(n,m);
        initial(n);
        for(ll i=0; i<n-1; i++)
        {
            ll a,b,c;
            sf3(a,b,c);
            V.PB({a,b,c});
        }
        sort(V.begin(),V.end(),cmp);
        for(ll i=0; i<n-1; i++)
        {
            //cout<<V[i].ff<<" "<<V[i].ss<<" "<<V[i].third<<endl;
            ll tm=V[i].third;
            joint_node(V[i].ff,V[i].ss);
            while(i<n-1){
                i++;
                if(i>=n-1)break;
                if(tm!=V[i].third){
                    i--;
                    break;
                }
                joint_node(V[i].ff,V[i].ss);
            }
            ma=max(tm,ma);
            ans[tm]=sum;
           // printf("%lld %lld test\n",tm,ans[tm]);
        }
        for(ll i=1;i<=m;i++){
            if(!ans[i])
                ans[i]=ans[i-1];
        }
        for(ll i=0;i<m;i++){
            ll a;
            sf1(a);
            if(a>=m){
                printf("%lld ",ans[m]);
            }
            else{
                printf("%lld ",ans[a]);
            }
        }
        nl;
        //printf("%lld\n");
        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


