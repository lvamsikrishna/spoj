// http://www.spoj.com/problems/ADAINDEX/

#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int prefixCount;
};

struct TrieNode *getNode(void) {
    struct TrieNode *node = new TrieNode;
    node->isEndOfWord = false;
    node->prefixCount=0;
    for(int i=0;i<ALPHABET_SIZE;i++){
        node->children[i] = NULL;
    }
    return node;
}

struct TrieNode *getNode(void);


void insertNode(struct TrieNode *root, string key){
    for(int i=0;i<key.length();i++){
        int index = key[i] - 'a';
        if(!root->children[index]){
            root->children[index] = getNode();
        }
        root = root->children[index];
        root->prefixCount++;
    }
    root->isEndOfWord = true;
}

int searchKey(struct TrieNode *root, string key){
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] - 'a';
        if(!root->children[index]){
            return 0;
        }
        root = root->children[index];
    }
    return root->prefixCount;
}

int main() {
    int N,Q;
    cin>>N>>Q;
    struct TrieNode *root = getNode();
    for(int i=0;i<N;i++){
        string in;
        cin>>in;
        insertNode(root,in);
    }

    for(int i=0;i<Q;i++){
        string in;
        cin>>in;
        int count = searchKey(root,in);
        cout<<count<<endl;
    }

    return 0;
}
