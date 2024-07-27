#ifndef TRIE_H
#define TRIE_H

// DEFINITIONS

// Alphabet size, all letters
#define ALPHABET_SIZE 26
// Maximum word length
#define LENGTH 16

// Trie node structure
typedef struct trieNode {
    int isEndOfWord;
    struct trieNode *children[ALPHABET_SIZE];    
} trieNode;

// FUNCTIONS DECLARATIONS
// Generate trie node
trieNode* generateTrieNode();
// Load dictionary into memory
void load_dictionary(trieNode* root);
// Add word to trie
void addWordToTrie(trieNode* root, char* word);
// Print trie
void printTrie(trieNode* root, char* word, int level);
// Free trie
void freeTrie(trieNode* root);


#endif
