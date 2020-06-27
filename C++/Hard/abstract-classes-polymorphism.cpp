#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

#include <deque>
class LRUCache : public Cache {
protected:
    map<int, Node *> mp; // map the key to the node in the linked list
    int cp;              // capacity
    Node *tail;          // double linked list tail pointer
    Node *head;          // double linked list head pointer
private:
    deque<int> order;
public:
    LRUCache(int cap) : cp{cap} {}
    void set(int, int) override; //set function
    int get(int) override;       // get function
};

void LRUCache::set(int k, int v)
{
    auto it = mp.find(k);
    if (it != mp.end()) {
        it->second->value = v;

        auto orderFound = find(order.begin(), order.end(), k);
        if (orderFound != order.end())
        {
            order.erase(orderFound);
            order.push_front(k);
        }
        else
        {
            // in map but not in cache...weird
        }
    }
    else
    {
        // not in the map, add to the map and the the deque
        if (mp.size() < cp)
        {
            mp[k] = new Node(k, v);
            order.push_front(k);
        }
        else
        {
            if (!order.empty())
            {
                auto del = order.back();
                order.pop_back();

                auto toDel = mp.find(del);
                if (toDel != mp.end())
                {
                    mp.erase(toDel);
                }

                mp[k] = new Node(k, v);
                order.push_front(k);
            }
        }
    }
}

int LRUCache::get(int k)
{
    auto it = mp.find(k);
    if (it != mp.end())
    {
        return it->second->value;
    }
    else
    {
        return -1;
    }
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
