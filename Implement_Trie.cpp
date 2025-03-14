// Time complexity: 
// Insert: O(n) where n is the length of the word
// Search: O(n) where n is the length of the word
// StartsWith: O(n) where n is the length of the prefix
// Space complexity: O(n) where n is the length of the word
// Did this code successfully run on Leetcode : Yes

// Approach:
// 1. Create a TrieNode class with 26 children and a boolean variable to check if it is the end of the word.
// 2. Create a Trie class with insert
// 3. In insert, iterate through the word and check if the children of the current node is null. If yes, create a new TrieNode.
// 4. In search, iterate through the word and check if the children of the current node is null. If yes, return false.
// 5. In startsWith, iterate through the prefix and check if the children of the current node is null. If yes, return false.


class TrieNode{
    public: 
        TrieNode* children[26];
        bool endofWord;
    
        TrieNode() {
            endofWord = false;
            for (int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    class Trie {
    private: 
        TrieNode* root; 
    public:
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string word) {
            TrieNode* node = root; 
            for(char c : word){
                int index = c - 'a';
                if(node -> children[index] == nullptr){
                    node -> children[index] = new TrieNode();
                }
                node = node -> children[index];
            }
            node -> endofWord = true;
        }
        
        bool search(string word) {
            TrieNode* node = root;
            for(char c : word) {
                int index = c - 'a';
                if(node -> children[index] == nullptr){
                    return false;
                }
                node = node -> children[index];
            }
            return node -> endofWord;
        }
        
        bool startsWith(string prefix) {
            TrieNode* node = root; 
            for(char c : prefix) {
                int index = c - 'a';
                if(node -> children[index] == nullptr){
                    return false;
                }
                node = node -> children[index];
            }
            return true;
        }
    };