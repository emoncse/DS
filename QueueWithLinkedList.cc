#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};

struct Node* fnt = NULL;
struct Node* bck = NULL;

void Enqueue(int x) {
	struct Node* temp = ( struct Node* ) malloc( sizeof( struct Node ));
	temp -> data = x;
	temp -> next = NULL;
	if(fnt == NULL && bck == NULL){
		fnt = bck = temp;
		cout << "Data insertion successfully." << endl;
		return;
	}
	bck->next = temp;
	bck = temp;
	cout << "Data insertion successfully." << endl;
}

void Dequeue() {
	struct Node* temp = fnt;
	if(fnt == NULL){
		printf("Queue is Empty\n");
		return;
	}
	if(fnt == bck) fnt = bck = NULL;
	else fnt = fnt->next;
	free(temp);
	cout << "Data has been deleted successfully." << endl;
}

int Front() {
	if( fnt == NULL ) {
		printf("Queue is empty\n");
		return '\0';
	}
	return fnt -> data;
}
void Print() {
	struct Node* temp = fnt;
	while(temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	printf("\n");
}

int Count(){
    int cnt = 0;
    struct Node* temp = fnt;
	while(temp != NULL) {
		cnt++;
		temp = temp -> next;
	}
	return cnt;
}
int main(){
    cout << "1. Insert an item" << "\n" << "2. Delete an Item" << "\n" << "3. Print fnt" << "\n" << "4. Get Length" << "\n" << "5. Print All" << endl;
    while(1){
        int tmp;
        cin >> tmp;
        switch( tmp ){
            case 1:{
                int x;
                cin >> x;
                Enqueue( x );
            }
            break;
            case 2:
                Dequeue();
                break;
            case 3:
                cout << "fnt = " << Front() << endl;
                break;
            case 4:
                cout << "Length = " << Count() << endl;
                break;
            case 5:
                Print();
                break;
        }
    }
	return 0;
}
