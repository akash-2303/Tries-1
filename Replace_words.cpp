// Time Complexity: O(n) where n is the length of the prefix
// Space Complexity: O(1)
// Did this code successfully run on Leetcode : Yes

// Approach:
// 1. for each word in the dictionary, insert it into the trie.
// 2. For each word in the sentence, get the shortest root of the word from the trie.
// 3. Return the result.

class TrieNode{
    public: 
        TrieNode* children[26];
        bool isEnd;
    
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    class Trie{
    private:
        TrieNode* root;
    
    public: 
        Trie(){
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
            node -> isEnd = true;
        }
        string getShortestRoot(string word){
            TrieNode* node = root;
            string rootWord; 
            for(char c : word) {
                int index = c - 'a';
                if(node -> children[index] == nullptr){
                    break;
                }
                rootWord += c;
                node = node -> children[index];
                if(node -> isEnd){
                    return rootWord;
                }
            }
            return word;
        }
    };
    class Solution {
    public:
        string replaceWords(vector<string>& dictionary, string sentence) {
            Trie trie; 
    
            for(string root : dictionary){
                trie.insert(root);
            }
    
            stringstream ss(sentence);
            string word, result;
    
            while(ss >> word){
                if(!result.empty()){
                    result += " ";
                }
                result += trie.getShortestRoot(word);
            }
            return result;
        }
    };