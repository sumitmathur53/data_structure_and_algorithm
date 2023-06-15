#include<iostream>
using namespace std;
#include<string>


class TrieNode{
    public:

    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data){  // constructor
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){     // initialise with NULL
            children[i] = NULL; 
        }
        isTerminal = false;
    }

};

class Trie{
    TrieNode *root;

    public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root,string word){
        // base case

        if(word.size()==0){
            root->isTerminal = true;  // make terminal
            return;
        }

        // small calculation
        int index = word[0] - 'a';  

        TrieNode *child;

        if(root->children[index] != NULL){

            child = root->children[index];

        }else{
            child = new TrieNode(word[0]);

            root->children[index] = child;
        }

        // recursive call

        insertWord(child ,word.substr(1));
    }
    
    
    void insertWord(string word){
        insertWord(root,word);
    }

    bool search(TrieNode *root,string word) {
        // Write your code here

        if(root->children[word[0]-'a']==NULL)
            return false;

        if(word.size()==1)
        {
            return root->children[word[0]-'a']->isTerminal;
        }

        return search(root->children[word[0]-'a'],word.substr(1)); 
    }
    bool search(string word){
        return search(root,word);
    }

    
    void removeWord(TrieNode *root, string word){
        // base case

        if(word.size()==0){
            root-> isTerminal = false;
            return;
        }

        // small calculation

        TrieNode *child;

        int index = word[0] -'a';
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // word not found
            return;
        }
    }

    void removeWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = false;
			return;
		}

		// Small calculation
		TrieNode *child;
		int index =  word[0] - 'a';
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			// Word not found
			return;
		}

		removeWord(child, word.substr(1));

		// Remove child Node if it is useless
		if(child -> isTerminal == false) {
			for(int i = 0; i < 26; i++) {
				if(child -> children[i] != NULL) {
					return;
				}
			}
			delete child;
			root -> children[index] = NULL;
		}
	}
    void removeWord(string word) {
		removeWord(root, word);
	}
};


