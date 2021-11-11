#include <string>
#include <iostream>
using namespace std;

struct MovieNode {
    string title;
    MovieNode *next;
};

class MovieList {
public:
    MovieList();
    ~MovieList();
    void display(ostream& out);
    void addToTop(string title);
    void addToBottom(string title);
    bool remove(int position);
    bool moveToPosition(string title, int position);
    bool moveToTop(string title);
private:
    MovieNode* top;
};

MovieList::MovieList() {
    //MovieNode *top = NULL;
}

 MovieList::~MovieList(){
	MovieNode* p = top;
	while(top != NULL){
		p = top;
		top = top->next;
		delete p;
	}
}

void MovieList::display(ostream& out) {

    MovieNode *p; //temporary pointer (don’t use head for this)
    p = top; //p points to the first node

    int i = 0;

    while (p != NULL) {

        out << i << ": " << p->title << endl;
        p = p->next; //makes p point to the next node

        i++;

    }

    return;
}

void MovieList::addToTop(string title) {

    MovieNode *newNode = new MovieNode;
    newNode->title = title;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;

    return;
}

void MovieList::addToBottom(string title) {

    MovieNode *newNode = new MovieNode;
    newNode->title = title;
    newNode->next = NULL;
    MovieNode *p=top; 
    while (p->next!=NULL) {
    p = p->next; 
    }
    p->next = newNode;

    return;
}

bool MovieList::remove(int position) {

    return false;
}

bool MovieList::moveToPosition(string title, int position) {

    return false;
}

bool MovieList::moveToTop(string title) {

    return false;
}

/**

int main() {
    MovieList netflix;


    netflix.addToTop("fornite");
    netflix.addToTop("sussy");
    netflix.addToBottom("balls");
    //netflix.addToTop("sussy");
    //netflix.addToBottom("balls");
    netflix.display();
}

**/
