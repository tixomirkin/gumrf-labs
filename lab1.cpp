#include<iostream>
#include<string>

using namespace std;

struct Node{
    string word;
    string pages;
    Node* next;

    Node(){
        cin >> word;
        getline(cin, pages);
        next = nullptr;
    }

    Node(string _word, string _page){
        word = _word;
        pages = _page;
        next = nullptr;
    }

    void print(){
        cout << word << pages << endl;
    }
};

class List{
    Node* first;
    Node* last;
public:
    List(){
        first = nullptr;
        last = nullptr;
    }

    bool is_empty(){
        if (first == nullptr){
            return true;}
        return false;
    }

    void add(string word, string pages){
        Node* a = new Node(word, pages);
        if (is_empty()){
            first = a;
            last = a;
        }
        else{
            Node *p = first, *pn;
            if (p->word.compare(a->word) >= 0){
                first = a; a->next = p;}
            else{
                pn = p->next;
                while (pn != nullptr){
                    if (pn->word.compare(a->word) >= 0){
                        p->next = a;
                        a->next = pn;
                        break;
                    }
                    pn = pn->next; p = p->next;
                }
                if (pn == nullptr) {
                    p->next = a; last = a;
                }
            }
        }
    }

    void search(string s){
        Node *p = first;
        while (p != nullptr){
            if (p->word == s){
                p->print();
                break;
            }
            p = p->next;
        }
    }

    void print(){
        if (!is_empty()){
            Node* p = first;
            while (p != nullptr){
                cout << p->word << p->pages << endl;
                p = p->next;
            }
        }
    }

    Node* operator [] (const int index){
        if (is_empty()){ return nullptr;};
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) {return nullptr;};
        };
        return p;
    }
};


int main(){
    List list;
    string word, pages;

    cin >> word;
    while (word != "0"){
        getline(cin, pages);
        list.add(word, pages);
        cin >> word;
    }

    list.print();
    cout << endl;

    cin >> word;
    while (word != "0"){
        list.search(word);
        cin >> word;
    }

}