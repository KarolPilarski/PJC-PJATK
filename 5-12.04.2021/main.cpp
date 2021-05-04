#include <iostream>
#include <vector>
#include <functional>

using namespace std;

//1
struct Point{
    double x;
    double y;
};
struct Rect{
    Point LG;
    Point PD;
};
vector<double> process(const Rect* rects, size_t sz, function<double(Rect)> f){
    vector<double>wynik;
    for(int i=0;i<sz;i++){
        wynik.push_back(f(rects[i]));
    }
    return wynik;
}

//2
enum Banks {PKO, BGZ, BRE, BPH};
struct Account{
    Banks bank;
    int balance;
};
struct Person{
    char name[20];
    Account account;
};
struct Couple{
    Person he;
    Person she;
};
const Couple* bestClient(const Couple* cpls, int size, Banks bank){
    int BestInx=-1;
    double Savings=-10000;
    for(int i=0;i<size;i++){
        if((cpls[i].he.account.bank==bank)||(cpls[i].she.account.bank==bank)){
            if((cpls[i].he.account.balance+cpls[i].she.account.balance)>Savings){
                Savings=cpls[i].he.account.balance+cpls[i].she.account.balance;
                BestInx=i;
            }
        }
    }
    if(BestInx==-1) return nullptr;
    else return cpls+BestInx;
}

//3
struct Node{
    int data;
    Node* next;
};

size_t size(const Node* head){
    int counter=1;
    if(head){
        Node* current=head->next;
        while(current){
            counter++;
            current=current->next;
        }
    }else return 0;
    return counter;
}

bool add(Node*& head, int data){
    bool Exists = false;
    Node* Current =head;

    for(int i=0;i<size(head);i++){
        if(Current->data==data) Exists=true;
        Current=Current->next;
    }

    if(!Exists){
        Node* node = new Node{data,head};
        head=node;
        return true;
    }else return false;

}

void clear(Node*& head){
    while(head){
        cout<<"Usuwanie: "<<head->data<<endl;
        Node* tmp=head->next;
        delete head;
        head=tmp;
    }
}
void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    //1
    Rect rects[]{
            {{3,2},{8,0}},
            {{4,6},{7,3}},
            {{5,5},{6,4}}
    };
    process(rects,3,[](Rect a)->double{return (a.LG.y-a.PD.y)*(a.PD.x-a.LG.x);});

    //2
    Couple cpls[] = {
            { {"Johny",{PKO,1200}},{"Mary", {BGZ, 1400}} },
            {{"Peter",{BGZ, 1400}},{"Suzy",{BRE,-1500}} },
            {{"Kevin",{PKO, 1600}},{"Katy",{BPH,1500}}},
            {{"Kenny",{BPH, 200}},{"Lucy",{BRE,-201}}}
    };

    const Couple* p = bestClient(cpls, 4, BRE);
    if (p) cout << p->he.name << " and " << p->she.name<< ": " << p->he.account.balance + p->she.account.balance << endl;
    else cout << "No such couple...\n";

    //3
    int tab[] = {1,4,1,3,5};
    Node*head = 0;
    for (size_t i = 0, e = 5;i != e; ++i){
        bool b = add(head,tab[i]);
        cout << tab[i] << (b ? "" : " NOT ")<< "added" << endl;
    }
    cout << "Size of the list: " << size(head) << endl;
    printList(head);
    clear(head);

    return 0;
}
