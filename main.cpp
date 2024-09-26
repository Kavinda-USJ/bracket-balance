#include <iostream>
#include <string>

using namespace std;

struct Node {
    char bracket;
    Node *next;
};


class Stackarr {
private:
    Node *top;
    int size;
public:
    
     Stackarr() : top(nullptr), size(0) {}
    
    //check the stackk is empty
    bool Empty() const {
        return top == nullptr;
    }
   

    void push(char value) {
        Node *newnode = new Node;
        newnode->bracket = value;
        newnode->next = top;
        top = newnode;
        size++;
        
    }

    // Pop a value
    char pop() {
        if (top == nullptr) {
            cout << "Underflow" << endl;
            return -1;
        } else {
            Node *temp = top;
            top = top->next;
            char poppedValue = temp->bracket;
            delete temp;
            size--;
            return poppedValue;
        }
    }

   
    
};


// Match function to check if brackets match
bool Match(char left, char right) {
    return (left == '(' && right == ')') || (left == '{' && right == '}') ||
    (left == '[' && right == ']');
}

// Function to check if brackets are balanced
bool checkBalance(const string& expr) {
    Stackarr s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.Empty() || !Match(s.pop(), ch)) {
                return false;
            }
        }
    }
    return s.Empty();
}
// Main function
int main() {
    string expression;
    cout << "Enter the mathematical expression: ";
    getline(cin, expression);

    if (checkBalance(expression)) {
        cout << "Brackets are balanced." << endl;
    } else {
        cout << "Brackets are not balanced." << endl;
    }
}
