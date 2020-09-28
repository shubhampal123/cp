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
