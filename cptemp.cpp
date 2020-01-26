
///Power
ll  power(ll  i,ll  j)
{
    if(j==0)
    return 1 ;
    ll t=power(i,j/2)%maa ;
    if(j%2==0)
    return (t%maa*t%maa)%maa ;
    else
    return ((t%maa*t%maa)%maa*(i%maa)%maa)%maa ;
}

///Z
   ll z[N] ;
   z[0]=0 ;
   ll l=0,r=0 ;
   for(ll i=1;i<N;i++)
   {
       if(i>r)
       {
           l=i ;
           r=i ;
           while(r<N&&a[r]==a[r-l])
            r++ ;

           z[i]=r-l ;
           r-- ;
       }
       else
       {
           ll k=i-l ;
           if(z[k]<r-i+1)
            z[i]=z[k] ;
           else
           {
               l=i ;
               while(r<N&&a[r]==a[r-l])
                r++ ;

               z[i]=r-l ;
               r-- ;
           }
       }
   }

///Kmp
ll lps[N] ;
   ll i=1 ;
   ll len=0 ;
   lps[len]=0 ;
   while(i<N)
   {
       if(a[len]==a[i])
       {
           len++ ;
           lps[i]=len ;
           i++ ;
       }
       else
       {
           if(len!=0)
           {
               len=lps[len-1] ;
           }
           else
           {
               lps[i]=0 ;
               i++ ;
           }
       }
   }


///Dfs
void dfs(ll i,ll p)
{
    for(ll j:v[i])
    {
        if(j==p)
            continue ;
        dfs(j,i) ;
    }
}


///Bit
ll bit[N] ;
void up(ll i)
{
    while(i<N)
    {
        bit[i]++ ;
        i+=(i&(-i)) ;
    }
}
ll get(ll i)
{
    ll x=0 ;
    while(i>0)
    {
        x+=bit[i] ;
        i-=(i&(-i)) ;
    }
    return x ;
}

///Segment tree
ll tr[4*N+5] ;
void build(ll s,ll e,ll i)
{
    if(s==e)
    {
        tr[i]=v[s] ;

    }
    else
    {
        ll m=(s+e)/2 ;
        build(s,m,2*i+1) ;
        build(m+1,e,2*i+2) ;
        tr[i]=max(tr[2*i+1],tr[2*i+2]) ;

    }
}
ll qu(ll s,ll e,ll i,ll l,ll p)
{
    if(l<=s&&e<=p)
        return tr[i] ;
    else if(l>e||p<s)
        return INT_MIN ;
    else
    {
        ll m=(s+e)/2 ;
        return max(qu(s,m,2*i+1,l,p),qu(m+1,e,2*i+2,l,p)) ;
    }
}

///Merge_Sort_Tree
vector<ll>tree[5*N] ;
vector<ll>merge(vector<ll>&a,vector<ll>&b)
{
    vector<ll>lol ;
    ll n1=a.size() ;
    ll n2=b.size() ;
    ll i=0,j=0 ;
    while(i<n1&&j<n2)
    {
        if(a[i]<b[j])
        {
            lol.pb(a[i]) ;
            i++ ;
        }
        else
        {
            lol.pb(b[j]) ;
            j++ ;
        }
    }
    while(i<n1)
    {
      lol.pb(a[i]) ;
            i++ ;
    }
    while(j<n2)
    {
        lol.pb(b[j]) ;
        j++ ;
    }
    return lol ;
}
void build_tree( ll cur , ll l , ll r )
{
     if( l==r )
     {
            if(tree[cur].size()==0)
            tree[cur].push_back( vv[ l ] );
            else
                tree[cur][0]=vv[l] ;
            return ;
     }
     ll mid = l+(r-l)/2;
     build_tree(2*cur+1 , l , mid ); // Build left tree
     build_tree(2*cur+2 , mid+1 , r ); // Build right tree
     tree[cur] = merge( tree[2*cur+1] , tree[2*cur+2] ); //Merging the two sorted arrays
}
ll query( ll cur, ll l, ll r, ll x, ll y, ll k)
{
       if( r < x || l > y )
      {
               return 0; //out of range
      }
      if( x<=l && r<=y )
      {
              //Binary search over the current sorted vector to find elements smaller than K

              return upper_bound(tree[cur].begin(),tree[cur].end(),k)-tree[cur].begin();
      }
      ll mid=l+(r-l)/2;
     return query(2*cur+1,l,mid,x,y,k)+query(2*cur+2,mid+1,r,x,y,k);
}


///Lca
ll level[N],memo[N][31] ;
ll op=log2(n)+2 ;
void dfs(ll i,ll p)
{
    for(ll j:v[i])
    {
        if(j==p)
            continue ;

        else
        {

            level[j]=level[i]+1 ;
            memo[j][0]=i ;
            dfs(j,i) ;
        }
    }
}

   for(ll j=1;j<op;j++)
   {
       for(ll i=1;i<=n;i++)
       {
           if(memo[i][j-1]!=-1)
           {
               memo[i][j]=memo[memo[i][j-1]][j-1] ;
           }

       }
   }
ll LCA(ll i,ll j)
      {
          if(level[i]<level[j])
          swap(i,j) ;
          ll op=log2(n)+2 ;

          for(ll k=op;k>=0;k--)
          {
              if(level[i]-level[j]>=(1<<k))
              {
                  i=memo[i][k] ;

              }
          }
          if(i==j)
          return i  ;
          for(ll k=op;k>=0;k--)
          {
              if(memo[i][k]!=memo[j][k]&&memo[i][k]!=-1&&memo[j][k]!=-1)
              {
                  i=memo[i][k] ;
                  j=memo[j][k] ;
              }
          }
          return memo[i][0] ;
 }


 ///Trie
struct trie {
   trie* bit[2] ;
   ll cnt=0 ;
};
void insert(trie* root,ll x)
{
    for(ll i=30;i>=0;i--)
    {
        ll b=(x>>i)&1 ;
        if(root->bit[b]==NULL)
        {
            root->bit[b]=new trie() ;

        }
        root=root->bit[b] ;
        root->cnt++ ;
    }
}
void remove(trie* root,ll x)
{
     for(ll i=30;i>=0;i--)
    {
        ll b=(x>>i)&1 ;
        root=root->bit[b] ;
        root->cnt-- ;
    }
}
ll maxxor(trie* root,ll x)
{
    ll ans=0 ;
    for(ll i=30;i>=0;i--)
    {
        ll b=(x>>i)&1 ;
        if(root->bit[!b]&&root->bit[!b]->cnt>0)
        {
            ans+=(1LL<<i) ;
            root=root->bit[!b] ;
        }
        else
            root=root->bit[b] ;
    }
    return ans ;
}


///Matrix Multiplication
ll ans[2][2] ;
ans[0][0]=1 ;
ans[0][1]=0 ;
ans[1][0]=0 ;
ans[1][1]=1 ;
ll base[2][2] ;
void multiply(ll a[2][2],ll b[2][2])
{
    ll temp[2][2] ;
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            temp[i][j]=0 ;
            for(ll k=0;k<2;k++)
            {
                temp[i][j]+=(a[i][k]*b[k][j])%maa ;
                temp[i][j]%=maa ;
            }
        }
    }
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            ans[i][j]=temp[i][j]%maa ; ;
        }
    }
}
void power(ll j)
{
    if(j==0)
        return ;

    power(j/2) ;

    multiply(ans,ans) ;

    if(j%2==1)
    multiply(ans,base) ;
}







