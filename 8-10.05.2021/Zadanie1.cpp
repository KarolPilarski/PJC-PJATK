#include <iostream>
#include <utility>  // swap (may be useful)
#include <string>

template <typename T>
class DLL {
    struct Node {
        T     data;
        Node* next;
        Node* prev;
    };
    Node* sent; // sentinel
public:
    DLL() : sent(new Node{T(),nullptr,nullptr}) {
        sent->next = sent->prev = sent;
    }

    bool empty() const{
        if(sent->next==sent&&sent->prev==sent) return true;
        else return false;
    }
    void push_front(const T& t) const{
        Node* tmp = sent->next;
        Node* push = new Node{t,tmp,sent};
        sent->next= push;
        tmp->prev=push;

    }
    void push_back(const T& t) const{
        Node* tmp = sent->prev;
        Node* push = new Node{t,sent,tmp};
        sent->prev= push;
        tmp->next=push;
    }
    void print_fwd(std::ostream& str = std::cout) const{
        Node* tmp=sent->next;
        while(tmp!=sent){
            str << tmp->data<<" ";
            tmp=tmp->next;
        }
        str<<std::endl;
    }
    void print_rev(std::ostream& str = std::cout) const{
        Node* tmp=sent->prev;
        while(tmp!=sent){
            str << tmp->data<<" ";
            tmp=tmp->prev;
        }
        str<<std::endl;
    }
    Node* find_first(const T& e) const{
        Node* tmp=sent->next;
        while(tmp!=sent){
            if(tmp->data==e) return tmp;
            tmp=tmp->next;
        }
        return nullptr;
    }
    Node* find_last(const T& e) const{
        Node* tmp=sent->prev;
        while(tmp!=sent){
            if(tmp->data==e) return tmp;
            tmp=tmp->prev;
        }
        return nullptr;
    }
    void insert_after(Node* a, const T& t) const{
        Node* tmp=sent->next;
        while(tmp!=a&&tmp!=sent){
            tmp=tmp->next;
        }
        if(tmp!=sent){
            Node* next=tmp->next;
            Node* insert = new Node{t,next,tmp};
            next->prev=insert;
            tmp->next=insert;
        }
    }
    void insert_before(Node* b, const T& t) const{
        Node* tmp=sent->prev;
        while(tmp!=b&&tmp!=sent){
            tmp=tmp->prev;
        }
        if(tmp!=sent){
            Node* prev=tmp->prev;
            Node* insert = new Node{t,tmp,prev};
            prev->next=insert;
            tmp->prev=insert;
        }
    }
    void delete_node(const Node* d) const{
        Node* tmp = sent->next;
        while(tmp!=sent){
            if(tmp==d){
                Node* prev = tmp->prev;
                Node* next = tmp->next;
                std::cout<<"DEL:"<<tmp->data<<std::endl;
                delete(tmp);
                prev->next=next;
                next->prev=prev;
            }
            tmp=tmp->next;
        }
    }
    void reverse() const{
        Node* tmp = sent->next;
        while(tmp!=sent){
            std::swap(tmp->prev,tmp->next);
            tmp=tmp->prev;
        }
        std::swap(sent->next,sent->prev);
    }
    void clear() const{
        while(!empty()){
            Node* tmp = sent->next->next;
            std::cout<<"DEL:"<<sent->next->data<<std::endl;
            delete(sent->next);
            tmp->prev=sent;
            sent->next=tmp;
        }
    }
    ~DLL(){
        while(!empty()){
            Node* tmp = sent->next->next;
            std::cout<<"DEL:"<<sent->next->data<<std::endl;
            delete(sent->next);
            tmp->prev=sent;
            sent->next=tmp;
        }
        delete(sent);
    }
};


int main () {
    using std::cout; using std::endl; using std::string;

    DLL<std::string>* listStr = new DLL<std::string>();
    listStr->push_back("X");
    listStr->push_back("E");
    listStr->push_front("C");
    listStr->push_front("X");
    listStr->push_front("A");
    cout << "List printed in both directions:" << endl;
    listStr->print_fwd();
    listStr->print_rev();

    listStr->delete_node(listStr->find_first("X"));
    listStr->delete_node(listStr->find_last("X"));
    cout << "\nList after deleting X's:" << endl;
    listStr->print_fwd();

    listStr->insert_after(listStr->find_first("A"),"B");
    listStr->insert_before(listStr->find_last("E"),"D");
    cout << "List after inserting B and D:" << endl;
    listStr->print_fwd();

    listStr->reverse();
    cout << "List after reversing:" << endl;
    listStr->print_fwd();

    std::cout << "Is list empty? " << std::boolalpha
              << listStr->empty() << std::endl;
    std::cout << "Clearing the listt" << std::endl;
    listStr->clear();

    std::cout << "Adding one element (Z)" << std::endl;
    listStr->push_front("Z");

    std::cout << "Deleting the list" << std::endl;
    delete listStr;
}

