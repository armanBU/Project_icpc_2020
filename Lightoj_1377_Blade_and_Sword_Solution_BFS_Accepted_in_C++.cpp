
/*
    Sk arman Hossain
    University of Barisal

    Problem name :Lightoj 1377 Blade and Sword
    Algorithm :BFS
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
vector<PR>Vp,Vd;
vector<ll>Vpl,Vdl;
string s[205];
ll n,m;
ll label[205][205],cntp,cntd;
void bfs(ll x,ll y,ll type)
{
    queue<PR>q;
    q.push({x,y});
    label[x][y]=0;
    while(!q.empty())
    {
        PR parent;
        parent=q.front();
        q.pop();
        for(ll i=0; i<4; i++)
        {
            ll childx=parent.ff+dx[i];
            ll childy=parent.ss+dy[i];
            if(type==1)
            {
                if(label[childx][childy]==-1&&childx>=0&&childx<n&&childy>=0&&childy<m&&s[childx][childy]!='#')
                {
                    label[childx][childy]=label[parent.ff][parent.ss]+1;
                    if(s[childx][childy]=='*'&&cntp<3)
                    {
                        cntp++;
                        Vp.PB({childx,childy});
                        Vpl.PB(label[childx][childy]);
                    }
                    if(s[childx][childy]!='*')
                        q.push({childx,childy});
                }
            }
            else
            {
                if(label[childx][childy]==-1&&childx>=0&&childx<n&&childy>=0&&childy<m&&s[childx][childy]!='#')
                {
                    label[childx][childy]=label[parent.ff][parent.ss]+1;
                    if(s[childx][childy]=='*'&&cntd<3)
                    {
                        cntd++;
                        Vd.PB({childx,childy});
                        Vdl.PB(label[childx][childy]);
                    }
                    if(s[childx][childy]!='*')
                        q.push({childx,childy});
                }

            }
        }
    }
}
int main()
{
    ///freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        Vp.clear();
        Vpl.clear();
        Vd.clear();
        Vdl.clear();
        cntp=0;
        cntd=0;
        ll xp,yp,xd,yd,cnt=0;
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            cin>>s[i];
            for(ll j=0; j<m; j++)
            {
                if(s[i][j]=='P')
                {
                    xp=i;
                    yp=j;
                }
                if(s[i][j]=='D')
                {
                    xd=i;
                    yd=j;
                }
                if(s[i][j]=='*')
                    cnt++;
                label[i][j]=-1;
            }
        }
        ll ans=LONG_MAX;
        bfs(xp,yp,1);
        if(label[xd][yd]!=-1)
        {
            ans=label[xd][yd];
        }
        cout<<"Case "<<test<<": ";
        if(Vp.size()==0||cnt<=1)
        {
            if(ans==LONG_MAX)
            {
                cout<<"impossible"<<endl;
            }
            else
            {
                cout<<ans<<endl;
            }
            continue;
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                label[i][j]=-1;
            }
        }
        bfs(xd,yd,0);
        ll tm=1;
        if(Vd.size())
        {
            if(Vd[0].ff==Vp[0].ff&&Vd[0].ss==Vp[0].ss)
            {
                ll ck=1;
                if(Vdl.size()>1){
                    if(Vdl[1]==Vdl[0])
                        ck=0;
                }
                if(Vpl.size()>1){
                    if(Vpl[1]==Vpl[0])
                        ck=0;
                }
                tm+=Vpl[0]+Vdl[0]+ck;
            }
            else
            {
                tm+=Vdl[0]+Vpl[0];
            }
            ans=min(ans,tm);
        }
        if(ans==LONG_MAX)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }

        // printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


