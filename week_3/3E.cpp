#include <iostream>
#include <string>
#include <vector>

struct Stack {

  void Push(int n) {
    stack_.push_back(n);
    std::cout << "ok\n";
  }

  void Pop() {
    std::cout << stack_.back() << "\n";
    stack_.pop_back();
  }

  void Back() {
    std::cout << stack_.back() << "\n";
  }

  void Size() {
    std::cout << stack_.size() << "\n";
  }

  void Clear() {
    int size = stack_.size();
    for (int i = 0; i < size; i++) {
      stack_.pop_back();
    }
    std::cout << "ok\n";
  }

  void Exit() {
    std::cout << "bye\n";
  }

 private:
  std::vector<int> stack_;
};

int main() {
  int num = 0;
  std::cin >> num;
  Stack stack;
  for (int i = 0; i < num; i++) {
    std::string command;
    std::cin >> command;
    if (command.substr(0, 4) == "push") {
      int num = 0;
      std::cin >> num;
      stack.Push(num);
    } else if (command == "pop") {
      stack.Pop();
    } else if (command == "back") {
      stack.Back();
    } else if (command == "size") {
      stack.Size();
    } else if (command == "clear") {
      stack.Clear();
    } else if (command == "exit") {
      stack.Exit();
      break;
    }
  }
  return 0;
}