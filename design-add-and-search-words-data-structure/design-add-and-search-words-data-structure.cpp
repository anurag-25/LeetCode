class Node {
public:
    char data;
    unordered_map <char, Node*> child;
    bool end;
    
    Node (char c) {
        data = c;
        end = false;
    }
    
};

class WordDictionary {
private:
    Node *root;
    int currSize;
public:
    WordDictionary() {
        root = new Node ('\0');
        currSize = 0;
    }
    
    void addWord(string word) {
        Node *temp = root;
        for (int i=0; i<word.length(); i++) {
            if (!temp->child.count(word[i])) temp->child[word[i]] = new Node(word[i]);
            temp = temp->child[word[i]];
        }
        temp->end = true;
    }
    bool search (string word, Node *temp, int idx) {
        for (int i=idx; i<word.length(); i++) {
            if (word[i]!='.') {
                if (!temp->child.count(word[i])) return false;
                temp = temp->child[word[i]];
            }
            else {
                for (int j=0; j<26; j++) {
                    if (temp->child.count('a'+j)) {
                        if (search(word, temp->child['a'+j], i+1)) return true;
                    } 
                }
                return false;
            }
        }
        return temp->end;
    }
    
    bool search(string word) {
        Node *temp = root;
        return search (word, temp, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */