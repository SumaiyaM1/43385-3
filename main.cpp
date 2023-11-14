#include "ExpressionManager.h"
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    // Created an ExpressionManager object
    ExpressionManager em;
    // Declared a string to store the user's expression
    string expression;

    // Started an infinite loop for user input
    while (true) {
        // Prompted the user for an infix expression
        cout << "Enter an infix expression or 'quit' to exit the program: ";
        // Got the user's input
        getline(cin, expression);

        // Checked if the user wanted to quit
        if (expression == "quit") {
            break;
        }

        // Checked if the parentheses in the expression were balanced
        if (em.checkBalance(expression)) {
            // Converted the infix expression to postfix
            string postfix = em.infixToPostfix(expression);
            // Displayed the postfix expression
            cout << "The postfix expression is: " << postfix;
            // Evaluated the postfix expression
            int result = em.evaluatePostfix(postfix);
            // Outputted the result
            cout << " = " << result << endl;
        } else {
            // If the parentheses were not balanced, output an error message
            cout << "The expression is invalid due to unbalanced parentheses." << endl;
        }
    }

    // Created a Queue object
    Queue queue;
    char ch;
    int choice, data;

    // Started a do-while loop for queue operations
    do {
        // Displayed the menu for queue operations
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Size\n5. Display all elements";
        cout << "\nEnter your choice: ";
        // Got the user's choice
        cin >> choice;

        // Switched based on the user's choice
        switch (choice) {
            case 1: // Enqueue operation
                cout << "\nEnter an integer number: ";
                // Got the data to enqueue
                cin >> data;
                // Enqueued the entered data
                queue.enqueue(data);
                cout << data << " has been enqueued ";
                break;

            case 2: // Dequeue operation
                // Checked if the queue was not empty
                if (!queue.isEmpty()) {
                    // Dequeued and displayed the dequeued data
                    cout << "The data dequeued is: " << queue.dequeue() << "\n";
                } else {
                    cout << "Queue is empty" << "\n";
                }
                break;

            case 3: // Front operation
                // Checked if the queue was not empty
                if (!queue.isEmpty()) {
                    // Displayed the front element of the queue
                    cout << "Front of the queue is: " << queue.front() << "\n";
                } else {
                    cout << "Queue is empty" << "\n";
                }
                break;

            case 4: // Size operation
                // Displayed the size of the queue
                cout << "Size of queue is: " << queue.size() << "\n";
                break;

            case 5: // Display operation
                // Displayed all elements in the queue
                queue.display();
                break;

            default:
                cout << "An invalid choice!!!\n\n";
        }

        // Asked the user if they wanted to continue
        cout << "Do you want to continue? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y'); // Continued asking for operations until the user said no

    return 0;
}
