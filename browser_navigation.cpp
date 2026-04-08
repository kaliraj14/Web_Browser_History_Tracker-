#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

class Browser {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentPage;

public:
    Browser(string homepage) {
        currentPage = homepage;
    }

    void visit(string url) {
        backStack.push(currentPage);
        currentPage = url;
        while (!forwardStack.empty()) forwardStack.pop();
        cout << "Visited: " << currentPage << endl;
    }

    void goBack() {
        if (backStack.empty()) return;
        forwardStack.push(currentPage);
        currentPage = backStack.top();
        backStack.pop();
        cout << currentPage << endl;
    }

    void goForward() {
        if (forwardStack.empty()) return;
        backStack.push(currentPage);
        currentPage = forwardStack.top();
        forwardStack.pop();
        cout << currentPage << endl;
    }
};

int main() {
    Browser b("Home");
    b.visit("google.com");
    b.visit("youtube.com");
    b.goBack();
    b.goForward();
    return 0;
}
