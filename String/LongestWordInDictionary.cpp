//########## Longest Word in Dictionary #########//
        /*  related: leetcode-208   */
/*
Given a list of strings words representing an English Dictionary,
find the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, 
return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
*/

#include <string>
#include <vector>
using namespace std;

//using Trie
class Solution1 //runtime:32 ms(<87.32%)
{
  private:
    class Trie
    {
      private:
        struct TrieNode
        {
            bool is_word;
            vector<TrieNode *> children;

            TrieNode() : is_word(false), children(26, nullptr) {}
            ~TrieNode()
            {
                for (TrieNode *child : children)
                    delete child;
            }
        };
        TrieNode *root;

      public:
        Trie() : root(new TrieNode()) {}
        ~Trie() { delete root; }
        void insert(const string &word)
        {
            TrieNode *p = root;
            for (const char c : word)
            {
                if (!p->children[c - 'a'])
                    p->children[c - 'a'] = new TrieNode();
                p = p->children[c - 'a'];
            }
            p->is_word = true;
        }

        bool hasAllPrefixes(const string &word)
        {
            TrieNode *p = root;
            for (const char c : word)
            {
                if (!p->children[c - 'a']) return false;
                p = p->children[c - 'a'];
                if (!p->is_word) return false;
            }
            return true;
        }
    };

  public:
    string longestWord(vector<string> &words)
    {
        Trie dict;
        for (const string &word : words)
            dict.insert(word);

        string best;
        for (const string &word : words)
        {
            if (word.length() < best.length() || (word.length() == best.length() && word > best))
                continue;
            if (dict.hasAllPrefixes(word))
                best = word;
        }
        return best;
    }
};

// brute force
class Solution2   //runtime 24ms(<98.39%)
{
public:
    string longestWord(vector<string> &words)
    {
        string best;
        unordered_set<string> dict(words.begin(), words.end());

        for (const string& word : words)
        {
            if (word.length() < best.length() || (word.length() == best.length() && word > best))
                continue;

            string prefix;  //exampel: apple's prefix : appl
            bool prefix_in = true;
            for( int i = 0; i < word.length() - 1 && prefix_in; ++i)
            {
                prefix += word[i];
                if(!dict.count(prefix)) prefix_in = false;
            }
            if(prefix_in) best = word;
        }
        return best;
    }
};