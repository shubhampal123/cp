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
