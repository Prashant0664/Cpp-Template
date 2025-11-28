#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *list[26];
    bool flag = 0;
    bool containskey(char ch)
    {
        if (list[ch - 'a'])
        {
            return 1;
        }
        return 0;
    }
    void put(char ch, Node *node)
    {
        list[ch - 'a'] = node;
    }
    Node *getnext(char ch)
    {
        return list[ch - 'a'];
    }
    void setend()
    {
        flag = 1;
    }
};

class Trie
{
    Node *head;

public:
    Trie()
    {
        head = new Node();
    }

    void insert(string s)
    {
        int len = s.length();
        Node *temp = head;
        for (int i = 0; i < len; i++)
        {
            char ch = s[i];
            if (!temp->containskey(ch))
            {
                temp->put(ch, new Node());
            }
            temp = temp->getnext(ch);
        }
        temp->setend();
    }
    bool check(string s)
    {
        int len = s.length();
        Node *temp = head;
        for (int i = 0; i < len; i++)
        {
            char ch = s[i];
            if (!temp->containskey(ch))
            {
                return 0;
            }
            temp = temp->getnext(ch);
        }
        return (temp->flag) ? 1 : 0;
    }
    
    bool startswith(string s){
        int len = s.length();
        Node *temp = head;
        for (int i = 0; i < len; i++)
        {
            char ch = s[i];
            if (!temp->containskey(ch))
            {
                return 0;
            }
            temp = temp->getnext(ch);
        }
        return 1;
    }

};

int main()
{
    return 0;
}