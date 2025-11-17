#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node structure
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Create a new Trie node
struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Insert a key into the Trie
void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* curr = root;
    while (*key) {
        int index = *key - 'a';
        if (curr->children[index] == NULL)
            curr->children[index] = createNode();
        curr = curr->children[index];
        key++;
    }
    curr->isEndOfWord = true;
}

// Search a key in the Trie
bool search(struct TrieNode* root, const char* key) {
    struct TrieNode* curr = root;
    while (*key) {
        int index = *key - 'a';
        if (curr->children[index] == NULL)
            return false;
        curr = curr->children[index];
        key++;
    }
    return curr != NULL && curr->isEndOfWord;
}

// ================= MAIN =================
int main() {
    struct TrieNode* root = createNode();

    int n;
    printf("Enter number of words to insert: ");
    scanf("%d", &n);

    char word[100];
    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);
        insert(root, word);
    }

    int q;
    printf("\nEnter number of words to search: ");
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        printf("Enter word to search: ");
        scanf("%s", word);
        if (search(root, word))
            printf("'%s' found in Trie.\n", word);
        else
            printf("'%s' NOT found in Trie.\n", word);
    }

    return 0;
}
