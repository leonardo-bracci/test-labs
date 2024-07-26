
#include <stdio.h>
#include <stdlib.h>

// DEFINITIONS

// alphabet size
#define ALPHABET_SIZE 26

// maximum word length 
#define LENGTH 16

// Trie node structure
typedef struct trieNode {
    int isEndOfWord;
    struct trieNode *children[ALPHABET_SIZE];    
} trieNode;

// GLOBAL VARIABLES
trieNode rootOfTrie;

// FUNCTIONS DECLARATIONS

// Load dictionary into memory
void load_dictionary();

// Create a new node
trieNode generateTrieNode();

// Add word to trie
void addWordToTrie(char* word);


int main() {
    // Initialize the rootOfTrie node
    rootOfTrie.isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        *rootOfTrie.children[i] = generateTrieNode();
    }

    // Load dictionary into memory
    load_dictionary();
    printf("Dictionary loaded into memory");
}

// Load dictionary into memory
void load_dictionary() {
    FILE *dictionary = fopen("dictionary/dictionary_short.txt", "r+");
    if (dictionary == NULL) {
        printf("Error opening file\n");
        exit (1);
    }
    const char buffer[LENGTH + 2];
    int wordscount = 0;
    // Read dictionary until reach EOF (End Of File)
    while (fscanf(dictionary, "%s", buffer) == 1) {
        char word[LENGTH + 1];
        for (int i = 0; i < sizeof(buffer)/buffer[0]; i++){
            // eliminate apostrophes at the end of words
            while(buffer[i] > 'a' - 1 && buffer[i] < 'z' + 1){
                word[i] = buffer[i];
            }
        }
        // insert word into tree
        addWordToTrie(word);
        word[0] = '\n';
    }
    printf("Dictionary loaded.\n");
    fclose(dictionary);

}

// Generate a new trie node
trieNode generateTrieNode() {
    // declare a new node
    trieNode node;
    // set end of word flag to 0
    node.isEndOfWord = 0;
    // set all children to null, to mark dead ends
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node.children[i] = NULL;
    }
    return node;
}

// Add word to trie
void addWordToTrie(char* word) {
    // temporary node to keep track of the position
    trieNode tempNode = *rootOfTrie.children[word[0]];
    for (int i = 1; i < sizeof(word)/sizeof(word[0]); i++){
        int index = word[i] - 'a';
        if (tempNode.children[index] == NULL){
                *tempNode.children[index] = generateTrieNode();
            }
    }

}

// Function to insert a word into the trie
void insert(const char *word) {

    trieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index])
            current->children[index] = getNode();
        current = current->children[index];
        word++;
    }

    
    current->isEndOfWord = 1;
}
