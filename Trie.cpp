class Node{
    public:
    Node *next[26];
    bool end;
    Node(){
        end = false;
        for(int i=0;i<26;i++) next[i] = NULL;
    }
};

class Tries{
public:
Node *trie;

Tries(){
    trie = new Node();
}

void insert(string &s){
    Node *it = trie;
    for(auto c : s){
        if(it->next[c - 'a'] == NULL)
            it->next[c - 'a'] = new Node();
        it = it->next[c - 'a'];
    }
    it->end = true;
}

void find(string &s){
    Node *it = trie;
    for(auto c : s){
        if(!it->next[c - 'a']){
            cout<<"No suggestions"<<endl;
            insert(s);
            return;
        }
        it = it->next[c - 'a'];
    }
    cout<<"FOUND"<<endl;
}
};

void solve() {
Tries* t = new Tries();
} 
