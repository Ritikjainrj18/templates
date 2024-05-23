// 0....n-1 elements
class DSU{
    int n,component;
    vector<int>par,siz;
    DSU(int n){
        this->n=n;
        for(int i=0;i<n;i++){
              par.push_back(i);
              siz.push_back(1);
        }
    }
    int getPar(int x){
        if(par[x]==x) return x;
        return par[x]=getPar(x);
    }
    void merge(int a,int b){
        a=getPar(a);
        b=getPar(b);
        if(a==b) return;
        if(siz[a]<siz[b]){
            swap(a,b);
        }
        par[b]=a;
        siz[a]+=siz[b];
    }
};