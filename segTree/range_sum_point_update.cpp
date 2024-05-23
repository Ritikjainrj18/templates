
typedef long long ll;
// idx 1....4*siz
// l r 0....n-1


const ll N=2e5+10;
ll a[N];
ll stree[N*4];
ll build(int idx,int l,int r){
    if(l==r){
        stree[idx]=a[l];
    }else{
        stree[idx]= build(2*idx,l,(r+l)/2)+build(2*idx+1,(r+l)/2+1,r);
    }
    return stree[idx];
}

// li ri range on segtree 0....n-1
// lr rr range i want o based 
ll getsum(int idx,int li,int ri,int lr,int rr){
    if(lr>rr) return 0;
    if(li==lr&&ri==rr) return stree[idx];
    int m=(li+ri)/2;
    return getsum(idx*2  ,li,m,lr,min(rr,m))+
           getsum(idx*2+1,m+1,ri,max(lr,m+1),rr);
}

// k index
// val value
ll update(int idx,int l,int r,int k,ll val){
    if(k<l||k>r) return stree[idx];
    if(l==r) {
        stree[idx]=val;
    }
    else{
        stree[idx] =update(2*idx,l,(r+l)/2,k,val)+
        update(2*idx+1,(r+l)/2+1,r,k,val);
    }
    return stree[idx];
}
void solve(){
    ll n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n-1);
    while(q--){
        ll t,l,r;
        cin>>t;
        if(t==1){
            cin>>l>>r;
            l--;
            update(1,0,n-1,l,r);
        }else{
            cin>>l>>r;
            l--,r--;
            cout<<getsum(1,0,n-1,l,r)<<nl;
        }
    }
}