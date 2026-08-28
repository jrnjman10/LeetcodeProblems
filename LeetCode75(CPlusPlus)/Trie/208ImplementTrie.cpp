struct node{
    char x;
    vector<node>* childs;
    bool* isword;
};

class Trie {
    vector<node>* childs;
public:
    Trie() {
        new Trie*;
        this->childs = new vector<node>;
    }
    
    void insert(string word) {
        vector<node>* curr = this->childs;
        auto iter = curr->begin();
        int index = 0;
        while(iter != curr->end()){
            if(word[index] != iter->x){
                iter++;
            } else{
                index++;
                if(index >= word.size()){
                    break;
                }
                curr = iter->childs;
                iter = curr->begin();
            }
        }
        node* n;
        bool* k;
        for(auto i : word.substr(index)){
            n = new node;
            n->childs = new vector<node>;
            n->x = i;
            curr->push_back(*n);
            curr = n->childs;
            n->isword = new bool;
            k = n->isword;
        }
        *k = true;
    }
    
    bool search(string word) {
        vector<node>* curr = this->childs;
        auto iter = curr->begin();
        int index = 0;
        //cout << "hello";
        //cout << word << " " << word[index] << " " << iter->x << endl;
        while(iter != curr->end()){
            cout << word << " " << word[index] << " " << iter->x << endl;
            if(iter->x == word[index]){
                index++;
                if(index >= word.size() && iter->isword){
                    return true;
                }
                if(index >= word.size() && iter->isword){
                    return false;
                }
                curr = iter->childs;
                iter = curr->begin();
            } else {
                iter++;
            }
        }
        
        return false;
    }
    
    bool startsWith(string prefix) {
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */