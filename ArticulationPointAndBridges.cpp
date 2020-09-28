/// Articulation points and bridges
vector<ll>v[N] ;
ll low[N],disc[N],visited[N] ;
vector<ll>articulation_points ;
vector<pll>bridges ;
ll tim ;
void dfs(ll i,ll p)
{
    disc[i]=tim++ ;
    low[i]=disc[i] ;
    ll child=0 ;
    ll cool_child=0 ;
    for(ll j:v[i])
    {
        if(j==p)
            continue ;


        if(visited[j]==0)
        {
        child++ ;
        visited[j]=1 ;
        dfs(j,i) ;
        if(disc[i]<=low[j])
        {
            cool_child++ ;/// if some child don't have a back-edge
           /// connecting a node in sub tree of j  and an ancestor of
           /// node i then it is a cool child

        }

        low[i]=min(low[i],low[j]) ;/// cascading not required
        }
        low[i]=min(low[i],disc[j]) ;/// just find out ancestor at least
                                    /// level can re reached using the nodes
                                    /// in subtree of i

    }
    ///Talk about articulation points

    if(p==-1)/// it is root
    {
       if(child>1)
       {
           articulation_points.pb(i) ;
       }
    }
    else
    {
        if(cool_child>0)
        {
            articulation_points.pb(i) ;
        }

    }

    ///Talk about bridges

    for(ll j:v[i])
    {
        if(j==p)
            continue ;

        //cout<<i<<" "<<j<<" "<<disc[i]<<" "<<low[j]<<endl ;

        if(disc[i]<low[j])
        {
            bridges.pb({min(i,j),max(i,j)}) ;
        }
    }
}
