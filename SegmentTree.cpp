ll tree[4*N+5] ;
void build(ll s,ll e,ll i)
{
    if(s==e)
    {
        tree[i]=v[s] ;

    }
    else
    {
        ll m=(s+e)/2 ;
        build(s,m,2*i+1) ;
        build(m+1,e,2*i+2) ;
        tree[i]=max(tree[2*i+1],tree[2*i+2]) ;

    }
}
ll qu(ll s,ll e,ll i,ll l,ll p)
{
    if(l<=s&&e<=p)
        return tree[i] ;
    else if(l>e||p<s)
        return INT_MIN ;
    else
    {
        ll m=(s+e)/2 ;
        return max(qu(s,m,2*i+1,l,p),qu(m+1,e,2*i+2,l,p)) ;
    }
}
