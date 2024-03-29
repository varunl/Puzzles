//http://www.codechef.com/problems/INSOMA4

#include <stdio.h>
#include <string.h>
#include <cctype>
#include <map>
using namespace std;

// Create a Trie

struct trie_node {
  int count;
  map<int, trie_node*> children;
};


trie_node* CreateTrieNode() {
  trie_node* newnode = new trie_node;
  newnode->count = 1;
  int i;
  return newnode;
}

int CalculatePosition(char c) {
  if (isupper(c)) {
    return c - 'A';
  } else {
    return c - 'a' + 26;
  }
}

int InsertTrie(trie_node* trie, char word[], int index, int max, int flag) {
  // reached end of word
  if (word[index] == '\0') {
    return max;
  }
  int pos = CalculatePosition(word[index]);
  map<int, trie_node*>::iterator it;
  // Check if the node exists in the map
  it = trie->children.find(pos);
  if (it == trie->children.end()) {
    trie->children[pos] = CreateTrieNode();
    flag = 0;
  } else {
    (trie->children[pos]->count)++;
    if (trie->children[pos]->count >= 2) {
      max++;
    } else {
      flag = 0;
    }
  }
  return InsertTrie(trie->children[pos], word, ++index, max, flag);
}

int main() {
  trie_node* trie = CreateTrieNode();
  char input[100];
  int n;
  int max = 0;
  int global_max = 0;
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%s", input);
    max = InsertTrie(trie, input, 0, 0, 0);
    global_max = max > global_max? max: global_max;
  }
  printf("%d\n", global_max);
  return 0;
}
