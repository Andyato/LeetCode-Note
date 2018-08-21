//############ Implement Trie (Prefix Tree) ##########//

/*
Implement a trie with insert(), search(), and startsWith() methods.
*/

#include<string>
using namespace std;

struct TrieNode
{
    bool is_word;
    vector<TrieNode*> children;

    TrieNode() : is_word(false), children(26, nullptr) {}
    ~TrieNode()
    {
        for (TrieNode* child : children)
            if (child) delete child;
    }
};

class Trie 
{
    private:
        TrieNode* root;

        TrieNode* find(const string& word)
        {
            TrieNode* p = root;
            for (const char c : word)
            {
                p = p->children[c-'a'];
                if(p==nullptr) break;
            }
            return p;
        }

    public:
        Trie() : root(new TrieNode()) {}
        ~Trie() { delete root }
        void insert(const string& word);
        bool search(const string& word);
        bool startsWith(const string& prefix);
};

void Trie::insert(const string& word)
{
    TrieNode* p = root;
    for(const char c : word)
    {
        if (!p->children[c-'a'])
            p->children[c-'a'] = new TrieNode();
        p = p->children[c-'a'];
    }
    p->is_word = true; //把结尾的child置为是单词
}

bool Trie::search(const string& word)
{
    TrieNode* p = find(word);
    return p && p->is_word;
}

bool startsWith(const string& prefix)
{
    return find(prefix) != nullptr;
}