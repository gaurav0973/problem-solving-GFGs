class Solution {
  private:
    string doc;
    stack<char> undoStack;
    stack<char> redoStack;

  public:
    void append(char x) {
        doc.push_back(x);
        undoStack.push(x);
        while (!redoStack.empty()) redoStack.pop(); // clear redo history
    }

    void undo() {
        if (undoStack.empty()) return;
        char c = undoStack.top();
        undoStack.pop();
        doc.pop_back();
        redoStack.push(c);
    }

    void redo() {
        if (redoStack.empty()) return;
        char c = redoStack.top();
        redoStack.pop();
        doc.push_back(c);
        undoStack.push(c);
    }

    string read() {
        return doc;
    }
};
