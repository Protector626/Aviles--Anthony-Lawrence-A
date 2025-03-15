#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node *link;

}Node;

Node *createNode(string data){
    Node *newNode = new Node; 
    newNode->songName = data;
    newNode->link = NULL;
    return newNode;
}


void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName << "->" << endl;
        if(temp->link == NULL){
            cout << "NULL" << endl;
        }

        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;

    while(temp->link != NULL){
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}


Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" << endl;

    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "A new node has been added after" + after + "\n";
}

string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The linked list is empty \n";
    }
    if(head->link == NULL){
        delete head;
        return "The head has been deleted \n";
    }
    Node *temp = new Node;
    temp = head;

    while(temp->link->link != NULL){
        temp = temp->link;
    }
    temp->link = NULL;

    return "A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" << endl;
        return NULL;
    }
    if(head->link == NULL){
        delete head;
    }
    head = head->link;

    cout << "A node has been deleted from the beginning \n" << endl;
    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" << endl;
        return NULL;
    }

    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node " + givenNode + " has been deleted \n" << endl;
        return head;
    }
    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;

    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist. \n" << endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }
    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted. \n" << endl;
    return head;
}







int main(){

 


     Node *head = createNode("Sanctuary by Joji");

    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    
    head = insertAtEnd("Die with a Smile by Bruno Mars and Lady Gaga", head);
    head = insertAtEnd("Luther by Kendrick Lamar", head);
    head = insertAtEnd("APT by Rose and Bruno Mars", head);
    head = insertAtBeginning("Over and Over by Skye", head);
    head = insertAtBeginning("Worlds Smallest Violine by AJR", head);
    head = insertAtBeginning("See you Again Wiz Khalifa", head);
    head = insertAtBeginning("Sunshine by One Republic", head);

    string result = insertAfter("Sunshine by One Republic", "Pusong Bato by Jovit Baldivino",head);
    cout << result << endl;
    string result1 = insertAfter("Sunshine by One Republic", "Buko by Jireh Lim ",head);
    cout << result1 << endl;
    string result2 = insertAfter("Sunshine by One Republic", "Mabagal by Daniel Padilla and Moira Dela Torre",head);
    cout << result2 << endl;

    string END = deleteAtEnd(head);
    cout << END << endl;
    head = deleteFromBeginning(head);
    head = deleteFromGivenNode("Luther by Kendrick Lamar", head);
    traverse(head);





    return 0;

}