#ifndef ADS_INCLUDE_CONTAINERS_HPP_
#define ADS_INCLUDE_CONTAINERS_HPP_

#include "./include/lists/DBListNode.hpp"
#include <algorithm>
#include <iostream>

namespace ADS {
template <typename Type> class List {
  private:
    using Node = DBListNode<Type>;

    using value_type = Type;

    using reference_type = Type&;

    using const_reference = const Type&

    using size_type = std::size_type;

  public:
    List() { }

    List(size_type n) { }

    List(const std::initializer_list<value_type>& items) {
      std::for_each(items.begin(),items.end(),[](auto &t_element { 
          push_back(t_element);
      })); 
    }

    List(const List& l) { }

    List(List&& l) { }

    ~List() { }

    List& operator=(list&& l)  { }

  public:
    void clear() {
      while(root!=nullptr){  
        Node *tmp = root;
        root = root->next;
        delete tmp;
      }
    }

    void push_back(const_reference value) {
        Node *n_node = new Node(value);
        
        if(root == nullptr) { 
            n_node->prev = nullptr;
            root = n_node;
            return;
        } 

        Node *temp = root;
        while(temp->next!=nullptr) {
          temp = temp->next;
        }        

        temp->next = n_node;
        n_node->prev = temp;
    }

    void pop_back() {
        if(root == nullptr) { 
          return;
        }

        if(root->next == nullptr) { 
          delete root;
          root = nullptr;
          return;
        }

        Node *temp = root;
        while(temp->next!=nullptr) { 
          temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }

    void push_front(const_reference value) {
         Node *n_node = new Node(value);
        
        if(root == nullptr) { 
            n_node->prev = nullptr;
            root = n_node;
        } else { 
            n_node->prev = nullptr;
            n_node->next = root;
            root->prev = n_node;
            root = n_node;
        }
    }

    void pop_front() {
      if(root == nullptr) { 
          return;
      }

      if(root->next == nullptr) { 
        delete root;
        root = nullptr;
      } else { 
        root->next->prev = nullptr;
        root = root->next;
      }
    }

    void swap(List& other) {
      std::swap(root,other.root);
    }

    void merge(List& other) {
      Node *t_node = other.root;
      while(t_node!=nullptr) {
        push_back(t_node->value);
        t_node = t_node->next;
      } 
      other.clear();
    }

    void unique() {
      if(root == nullptr) {  
        return;
      }

      Node *curr = root;
      Node *temp = root->next;
      while(temp!=nullptr) { 
        if(temp->value == curr->value) { 
            curr->value = temp->next;
            if(curr->next!=nullptr) { 
              temp->next->prev = curr; 
            }
            delete temp;
            temp = curr->next;
        } else { 
            curr  = temp;
            temp = temp->next;
        }
      }
      
    }

    void sort() {
      if(root == nullptr) { 
        return;
      }

      Node *curr = root;
      while(curr->next!=nullptr) { 
        Node *temp = curr->prev;
        while(temp!=nullptr && temp->value > curr->value) { 
          temp->next->value = temp->next;
          temp = temp->prev;
        }

        if(temp == nullptr) { 
            root->value = curr->value;
        } else { 
          temp->next->value = curr->value;
          curr = curr->next;
        }
      }
    }

  private:
    Node* root;
};
} // namespace ADS

#endif