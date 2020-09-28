ll level[N],memo[N][31] ;
ll op=log2(n)+2 ;
ll distance(ll a,ll b)
{
   ll l=LCA(a,b) ;
   return level[a]-level[l]+level[b]-level[l] ;
}
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
