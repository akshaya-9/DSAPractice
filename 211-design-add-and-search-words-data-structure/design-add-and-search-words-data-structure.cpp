class TrieNode {
   public:
    TrieNode* alphabets[26];
    bool flag=false;
    TrieNode() {
    for(int i=0;i<26;i++) {
        alphabets[i] =NULL;
    }
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
         root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch:word){
            int idx = ch-'a';
            if(node->alphabets[idx]==NULL) {
                node->alphabets[idx] = new TrieNode();
            }
            node = node->alphabets[idx];
        }
        node->flag= true;
    }

    bool dfs(string& word,int idx, TrieNode* node){
        if(idx==word.length()) return node->flag;

        if(word[idx]=='.') {
            for(int i=0;i<26;i++) {
                if(node->alphabets[i] && dfs(word,idx+1,node->alphabets[i])) 
                   return true;
            }
            return false;
        }
        int pos = word[idx]-'a';
        if(node->alphabets[pos]==NULL) {
            return false;
        }
        return dfs(word,idx+1,node->alphabets[pos]);
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */