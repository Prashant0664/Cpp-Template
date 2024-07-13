#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int cntEndWith = 0;
    int cntPrefix = 0;
    Node *links[26];
    bool flag = false;
    bool containskey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isend()
    {
        return flag;
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    void deletePrefix()
    {
        cntPrefix--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }
};
class Trie
{

private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containskey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        node->setEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containskey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containskey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containskey(word[i]))
            {
                node = node->get(word[i]);
                node->deletePrefix();
            }
            else
            {
                return;
            }
        }
        return node->deleteEnd();
    }
    bool check(string word)
    {
        bool fl = 1;
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containskey(word[i]))
            {
                node = node->get(word[i]);
                if (node->isend() == false)
                    return 0;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;
    for (auto &it : a)
    {
        trie.insert(it);
    }

    string longest = "";

    for (auto &it : a)
    {
        if (trie.check(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (
                it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }

    if (longest == "")
    {
        return "None";
    }
    return longest;
}

int distinctSubstring(string &word)
{
    //  Write your code here.
    int cnt = 0;
    Node *root = new Node();
    for (int i = 0; i < word.size(); i++)
    {
        Node *node = root;
        for (int j = i; j < word.size(); j++)
        {
            if (!node->containskey(word[j]))
            {
                cnt++;
                node->put(word[j], new Node());
            }
            node = node->get(word[j]);
        }
    }
    return cnt;
}
int main()
{
    return 0;
}