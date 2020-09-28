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
