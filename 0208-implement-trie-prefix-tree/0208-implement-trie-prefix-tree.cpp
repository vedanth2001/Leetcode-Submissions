struct Node{
    Node *links[26] = {};
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a']!=NULL;
    }

    void putKey(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node *get(char ch){
        return links[ch-'a']; 
    } 

    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag = true;
    }
};
class Trie {
public:
    Node *root;
    Trie() {
       root = new Node();
    }
    
    void insert(string word) {
        int n = word.length();
        Node *node = root;
        for(int i =0;i<n;i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        int n = word.size();
        Node *node = root;
        for(int i =0;i<n;i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* node = root;
        for(int i =0;i<n;i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */