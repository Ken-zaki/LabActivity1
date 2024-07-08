    #include <iostream>
    #include <string>
    using namespace std;
    
    struct node {
        string data;
        node* next;
    };
    
    class link {
    private:
        node* head, * tail;
    public:
        link() {
            head = NULL;
            tail = NULL;
        }
    
        void lastNode(string value) {
            node* box = new node;
            box->data = value;
            box->next = NULL;
    
            if (head == NULL) {
                head = box;
                tail = box;
            }
            else {
                tail->next = box;
                tail = box;
            }
        }
    
        void startNode(string value) {
            node* box = new node;
            box->data = value;
            box->next = head;
            head = box;
            if (tail == NULL) {
                tail = head;
            }
        }
    
        void insertAfter(string target, string value) {
            node* current = head;
            while (current != NULL && current->data != target) {
                current = current->next;
            }
            if (current == NULL) {
                cout << "Node with value " << target << " not found." << endl;
                return;
            }
            node* box = new node;
            box->data = value;
            box->next = current->next;
            current->next = box;
            if (box->next == NULL) {
                tail = box;
            }
        }
    
        void deleteNode(string value) {
            if (head == NULL) {
                cout << "List is empty. Cannot delete node." << endl;
                return;
            }
    
            if (head->data == value) {
                node* temp = head;
                head = head->next;
                delete temp;
                if (head == NULL) {
                    tail = NULL;
                }
                return;
            }
    
            node* current = head;
            node* previous = NULL;
            while (current != NULL && current->data != value) {
                previous = current;
                current = current->next;
            }
            if (current == NULL) {
                cout << "Node with value " << value << " not found." << endl;
                return;
            }
            previous->next = current->next;
            if (current->next == NULL) {
                tail = previous;
            }
            delete current;
        }
    
        void display() {
            if (head == NULL) {
                cout << "List is empty." << endl;
                return;
            }
    
            node* box = head;
            while (box != NULL) {
                cout << box->data << " ";
                box = box->next;
            }
            cout << endl;
        }
    };
    
    void menu() {
        link a;
        int choice;
        string value, target;
    
        while (true) {
            cout << "Lab Activity (Node)" << endl;
            cout << "1. Add Node" << endl;
            cout << "2. Delete Node" << endl;
            cout << "3. Display" << endl;
            cout << "4. Exit" << endl;
            cout << "Choose from (1 - 4): ";
            cin >> choice;
    
            switch (choice) {
                case 1:
                    cout << "Enter the value: ";
                    cin >> value;
                    cout << "Pick where you want to add" << endl;
                    cout << "1. Insert at the start" << endl;
                    cout << "2. Insert at the end" << endl;
                    cout << "3. Insert after a specified node" << endl;
                    cout << "Pick the from (1 - 3): ";
                    cin >> choice;
                    if (choice == 1) {
                        a.startNode(value);
                    }
                    else if (choice == 2) {
                        a.lastNode(value);
                    }
                    else if (choice == 3) {
                        cout << "Enter target value: ";
                        cin >> target;
                        a.insertAfter(target, value);
                    }
                    else {
                        cout << "Invalid choice. Pick from the options." << endl;
                    }
                    break;
                case 2:
                    cout << "Enter the value of the node to delete: ";
                    cin >> value;
                    a.deleteNode(value);
                    break;
                case 3:
                    cout << " Linked list: "; 
                    a.display();
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
            cout << "\n";
            system("pause");
            system("cls");
        }
    }
    
    int main() {
        menu();
        return 0;
    }
