class TrieNode {
public:
    // Initialize your data structure here.
    bool isWord;
    TrieNode* children[26];
    
    TrieNode() {
        isWord = false;
        memset(children, 0, sizeof(children));
    }
    
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        int i = 0, w = word.length(), ch, j;
        for (; i < w; ++i) {
            ch = word[i] - 'a';
            if (node->children[ch] == NULL) node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isWord = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return findFrom(root, word.c_str());
    }
    
private:
    TrieNode* root;
    
    bool findFrom(TrieNode* root, const char* word) {
        TrieNode* node = root;
        int i = 0, j;
        for (;node != NULL; ++i) {
            if (word[i] == '\0') break;
            else if (word[i] == '.'){
                TrieNode* tmp = node;
                for (j = 0; j < 26; ++j) {
                    node = tmp->children[j];
                    if (findFrom(node, word + i + 1)) return true;
                }
                return false;
            }
            else node = node->children[word[i] - 'a'];
        }
        return node == NULL ? false : node->isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");