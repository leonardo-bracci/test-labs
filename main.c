#include <stdio.h>
#include "trie.h"

int main() {
    // Initialize trie
    trieNode* root = generateTrieNode();
    printf("Trie initialized\n");

    // Load dictionary into memory
    load_dictionary(root);
    printf("Dictionary loaded into memory\n");

    // Print trie
    char yesOrNo;
    printf("Do you want to print the trie? (y/n): ");
    fscanf(stdin, " %c", &yesOrNo);
    if (yesOrNo == 'y') {
        char word[LENGTH + 1];
        printTrie(root, word, 0);
        printf("Trie printed\n");
    }

    // Free trie
    freeTrie(root);
    printf("All memory of trie freed\n");

    return 0;
}
