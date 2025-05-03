#include <bits/stdc++.h>
using namespace std;

class LRParser {
public:
    LRParser() {
        stack.push(0);  // Initialize the parser with state 0
    }

    void parse(const std::vector<std::string>& tokens) {
        inputBuffer = tokens;
       
        while (!inputBuffer.empty()) {
            int state = stack.top();
            string token = inputBuffer.front();

            // Display current stack, input, and action
            printStatus("Initial state");

            // Check for error and handle it
            if ((state == 0 && (token == "+" || token == "*" || token == ")" || token == "$")) ||
                (state == 1 && token == ")") ||
                (state == 2 && token == ")") ||
                (state == 4 && token == ")") ||
                (state == 5 && token == ")")) {
                errorRecovery("e2");
                printStatus("Unbalanced right parenthesis\ne2 routine: Remove the right parenthesis from input");
            } else if ((state == 0 || state == 2 || state == 4 || state == 5) && token == "id") {
                shift(3);
            } else if (state == 3 && token == "+") {
                reduce();  // Perform a reduction in state 3
            } else if (state == 4 && token == "$") {
                // Perform a reduction instead of directly accepting end of input
                reduceToEnd();  // New reduction function for state 4 with $
            } else if ((state == 1 || state == 6) && (token == "id" || token == ")")) {
                errorRecovery("e3");
                printStatus("Missing operator\ne3 routine: Push state 4 after missing operator");
            } else if (state == 6 && token == "$") {
                errorRecovery("e4");
                printStatus("Missing right parenthesis\ne4 routine: Push state 9 for missing right parenthesis");
            } else {
                shiftOrReduce(state, token);
            }

            // Safety condition to prevent infinite loops in error handling
            if (inputBuffer.empty()) break;
        }
    }

private:
    stack<int> stack;
    vector<string> inputBuffer;

    void shift(int newState) {
        stack.push(newState);
        inputBuffer.erase(inputBuffer.begin());

        // Display action taken
        printStatus("Shifted to state " + std::to_string(newState));
    }

    void shiftOrReduce(int state, const std::string& token) {
        if (state == 0 && token == "id") {
            shift(3);
        } else if (state == 1 && token == "+") {
            shift(4);
        }
        // Additional shift/reduce cases could be added here if needed.
    }

    void reduce() {
        // Example reduction action for state 3
        stack.pop();  // Pop the state
        stack.push(1);  // Move to a new valid state after reduction
        printStatus("Performed reduction");
    }

    void reduceToEnd() {
        // Final reduction or exit condition for state 4 and $
        stack.pop();  // Pop current state (optional, depends on grammar)
        printStatus("Performed final reduction, parsed expression is complete.");
        inputBuffer.clear();  // Clear input to end parsing
    }

    void errorRecovery(const std::string& errorCode) {
        if (errorCode == "e1") {
            stack.push(3);  // Push state 3 for missing operand
            printStatus("Missing operand\ne1 routine: Push id3");
        } else if (errorCode == "e2") {
            inputBuffer.erase(inputBuffer.begin());  // Remove the unbalanced ')'
        } else if (errorCode == "e3") {
            stack.push(4);  // Push state 4 after missing operator
            if (!inputBuffer.empty() && inputBuffer.front() == "id") {
                inputBuffer.erase(inputBuffer.begin());  // Consume an id if found to avoid infinite loop
            }
        } else if (errorCode == "e4") {
            stack.push(9);  // Push state 9 for missing right parenthesis
        }
    }

    void printStatus(const string& action) {
        // Print stack contents
        cout << "Stack: ";
        std::stack<int> tempStack = stack;
        vector<int> stackContents;
        while (!tempStack.empty()) {
            stackContents.push_back(tempStack.top());
            tempStack.pop();
        }
        for (auto it = stackContents.rbegin(); it != stackContents.rend(); ++it) {
            cout << *it << " ";
        }

        // Print input buffer
        cout << "\tInput: ";
        for (const auto& token : inputBuffer) {
            cout << token;
        }

        // Print action
        cout << "\tAction: " << action << std::endl;
    }
};

int main() {
    // Example input that will trigger error recovery
    vector<string> tokens = {"id", "+", ")", "$"};
    LRParser parser;
    parser.parse(tokens);
    return 0;
}