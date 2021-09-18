#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int key;
    int value;
    node *next;
    node *prev;
};

node *createNode(int k, int v)
{
    node *temp = new node();
    temp->key = k;
    temp->value = v;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

class LRUCache
{
    unordered_map<int, node *> um;
    node *head;
    node *tail;
    int cap;
    public:
        LRUCache(int capacity)
        {
            head = NULL;
            tail = NULL;
            cap = capacity;
        }

        int get(int key)
        {
            if(um.find(key) == um.end())
                return -1;
            node *fv = um[key];
            if(head!=fv)
            {
                fv->prev->next = fv->next;
                fv->next->prev = fv->prev;
                fv->next = head;
                head->prev = fv;
                fv->prev = NULL;
                head = fv;
            }
            return head->value;
        }

        void put(int key,int value)
        {
            //case-1 when no element exists in LRU i.e head=null and tail=null
            if(!head && um.size()<cap)
            {
                node *newNode = createNode(key,value);
                um[key] = newNode;
                head = newNode;
                tail = head;
            }

            //case-2 when LRU is not full, and we have a new element, in that case just make it point to head
            else if(um.size()<cap && um.find(key)==um.end())
            {
                node *newNode = createNode(key,value);
                um[key] = newNode;
                newNode->next = head;
                head->prev = newNode;
                head=newNode;
            }

            //case-3 when LRU is not full and previously added element is updated which is head
            else if(um.size()<=cap && um.find(key)!=um.end() && um[key]==head)
            {
                head->value= value;
            }

            //case -4 when LRU is not full and previously added element is updated which is not head and tail
            else if(um.size()<=cap && um.find(key)!=um.end() && um[key]!=tail)
            {
                node *temp = um[key];
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = head;
                head->prev = temp;
                head = temp;
                head->value = value;
                temp->prev = NULL;
            }

            //case -5 when LRU is not full and previously added element is updated which is tail
            else if(um.size()<=cap && um.find(key)!=um.end() && um[key]==tail)
            {
                node *temp = um[key];
                tail = tail->prev;
                temp->prev->next = temp->next;
                temp->next = head;
                head->prev = temp;
                head = temp;node *todelete = tail;
                head->value = value;
                temp->prev = NULL;
            }

            //case-6 when LRU is full
            else if(um.size()==cap && um.find(key)==um.end())
            {
                node *todelete = tail;
                um.erase(tail->key);
                tail = tail->prev;                
                tail->next = NULL;
                delete(todelete);

                node *newNode = createNode(key, value);
                um[key] = newNode;
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                newNode->prev = NULL;
            }
            return;
        }
};


int main()
{
    LRUCache *obj = new LRUCache(3);
    obj->put(1, 2);
    cout << obj->get(1) << endl;
}