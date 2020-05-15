/*Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.*/

/*------------------------------------------------------------------*/


// Code

class Trie {
    Trie *children[26];
    bool isEndofWord;
public:
    Trie(){
        isEndofWord=false;        
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
    
    void insert(string word) {
        Trie *p = this;
        for(char c:word){
            if(!(p->children[c-'a']))
                p->children[c-'a']=new Trie;
            p=p->children[c-'a'];
        }
        p->isEndofWord=true;
    }
    
    bool search(string word) {
        Trie *p = this;
        for(char c:word){
            p=p->children[c-'a'];
            if(!p)
                return false;
        }
        if(p->isEndofWord)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie *p = this;
        for(char c:prefix){
            p=p->children[c-'a'];
            if(!p)
                return false;
        }
        return true;
    }
};

/*
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */