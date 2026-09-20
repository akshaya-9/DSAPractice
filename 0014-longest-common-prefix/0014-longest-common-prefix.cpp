class Solution {
class TrieNode{
    public:
    TrieNode* children[26];
    int childCount;
    bool leaf;
    TrieNode() {
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        leaf= false;
        childCount=0;
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* curr = root;
    for(char ch:word) {
        int idx = ch-'a';
        if(curr->children[idx]==NULL){
            curr->children[idx] = new TrieNode();
            curr->childCount++;
        }
        curr = curr->children[idx];
    }
    curr->leaf = true;
}

string walkTrie(TrieNode* root, string s) {
    TrieNode* curr = root;
    int i=0;

    while(curr->childCount==1 && !curr->leaf) {
        int idx = s[i]-'a';
        i++;
        curr = curr->children[idx];
    }
    return s.substr(0,i);
}
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode();

        for(string s:strs) {
            insert(root,s);
        }
        return walkTrie(root,strs[0]);
    }
};