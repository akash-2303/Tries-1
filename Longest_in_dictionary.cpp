// Time Complexity: O(n *L) where n is the number of words in the dictionary and L is the average length of the word
// Space Complexity: O(n * L) where n is the number of words in the dictionary and L is the average length of the word
// Did this code successfully run on Leetcode : Yes

// Approach:
// 1. Create a Trie class with insert
// 2. In insert, iterate through the word and check if the children of the current node is null. If yes, create a new TrieNode.
// 3. In isBuildable, iterate through the word and check if the children of the current node is null. If yes, return false.
// 4. If the end of the word is not reached, return false.


struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool isBuildable(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
            if (!node->isEndOfWord) return false; // Check if previous prefix exists
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (string& word : words) {
            trie.insert(word);
        }

        string longest = "";
        for (string& word : words) {
            if (trie.isBuildable(word)) {
                if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};