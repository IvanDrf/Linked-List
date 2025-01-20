#include "LinkedList.hpp"

constexpr const char* RESET = "\033[0m";
constexpr const char* RED = "\033[31m";
constexpr const char* GREEN = "\033[32m";

void TestPushBack() {
    LinkedList list;
    list.PushBack(1);
    list.PushBack(2);

    if (list.GetBegin()->GetValue() != 1 || list.GetEnd()->GetValue() != 2) {
        std::cerr << "TestPushBack " << RED << "failed" << RESET << '\n';
    } else {
        std::cout << "TestPushBack " << GREEN << "passed" << RESET << '\n';
    }
}

void TestInsertAtBeginning() {
    LinkedList list;
    list.PushBack(2);
    list.Insert(1, 0);

    if (list.GetBegin()->GetValue() != 1) {
        std::cerr << "TestInsertAtBeginning " << RED << "failed!" << RESET << '\n';
    } else {
        std::cout << "TestInsertAtBeginning " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestInsertAtMiddle() {
    LinkedList list;
    list.PushBack(1);
    list.PushBack(3);
    list.Insert(2, 1);

    if (list.GetBegin()->GetNext()->GetValue() != 2) {
        std::cerr << "TestInsertAtMiddle " << RED << "failed!" << RESET << '\n';
    } else {
        std::cout << "TestInsertAtMiddle " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestInsertInvalidPosition() {
    LinkedList list;

    try {
        list.Insert(1, 1);
        std::cerr << "TestInsertInvalidPosition " << RED << "failed!" << RESET << '\n';
    } catch (const std::runtime_error&) {
        std::cout << "TestInsertInvalidPosition " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestReplaceValidPosition() {
    LinkedList list;
    list.PushBack(1);
    list.PushBack(2);
    list.Replace(3, 1);

    if (list.GetBegin()->GetNext()->GetValue() != 3) {
        std::cerr << "TestReplaceValidPosition " << RED << "failed!" << RESET << '\n';
    } else {
        std::cout << "TestReplaceValidPosition " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestReplaceInvalidPosition() {
    LinkedList list;

    try {
        list.Replace(1, 0);
        std::cerr << "TestReplaceInvalidPosition " << RED << "failed!" << RESET << '\n';
    } catch (const std::runtime_error&) {
        std::cout << "TestReplaceInvalidPosition " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestDeleteValidPosition() {
    LinkedList list;
    list.PushBack(1);
    list.PushBack(2);
    list.Delete(0);

    if (list.GetBegin()->GetValue() != 2) {
        std::cerr << "TestDeleteValidPosition " << RED << "failed!" << RESET << '\n';
    } else {
        std::cout << "TestDeleteValidPosition " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestDeleteInvalidPosition() {
    LinkedList list;

    try {
        list.Delete(0);
        std::cerr << "TestDeleteInvalidPosition " << RED << "failed!" << RESET << '\n';
    } catch (const std::runtime_error&) {
        std::cout << "TestDeleteInvalidPosition " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestCopyConstructor() {
    LinkedList list;
    list.PushBack(1);
    list.PushBack(2);

    LinkedList copy(list);
    if (copy.GetBegin()->GetValue() != 1 || copy.GetEnd()->GetValue() != 2) {
        std::cerr << "TestCopyConstructor " << RED << "failed!" << RESET << '\n';
    } else {
        std::cout << "TestCopyConstructor " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestMoveConstructor() {
    LinkedList list;
    list.PushBack(1);
    list.PushBack(2);

    LinkedList moved(std::move(list));
    if (moved.GetBegin()->GetValue() != 1 || moved.GetEnd()->GetValue() != 2) {
        std::cerr << "TestMoveConstructor " << RED << "failed!" << RESET << '\n';
    } else {
        std::cout << "TestMoveConstructor " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestAssignmentOperator() {
    LinkedList list;
    list.PushBack(1);
    list.PushBack(2);

    LinkedList copy;
    copy = list;

    if (copy.GetBegin()->GetValue() != 1 || copy.GetEnd()->GetValue() != 2) {
        std::cerr << "TestAssignmentOperator " << RED << "failed!" << RESET << '\n';
    } else {
        std::cout << "TestAssignmentOperator " << GREEN << "passed!" << RESET << '\n';
    }
}

void TestMoveAssignmentOperator() {
    LinkedList list;
    list.PushBack(1);
    list.PushBack(2);

    LinkedList moved;
    moved = std::move(list);

    if (moved.GetBegin()->GetValue() != 1 || moved.GetEnd()->GetValue() != 2) {
        std::cerr << "TestMoveAssignmentOperator " << RED << "failed!" << RESET << '\n';
    } else {
        std::cout << "TestMoveAssignmentOperator " << GREEN << "passed" << RESET << '\n';
    }
}

int main(int, char**) {
    TestPushBack();

    TestInsertAtBeginning();
    TestInsertAtMiddle();
    TestInsertInvalidPosition();

    TestReplaceValidPosition();
    TestReplaceInvalidPosition();

    TestDeleteValidPosition();
    TestDeleteInvalidPosition();

    TestCopyConstructor();
    TestMoveConstructor();

    TestAssignmentOperator();
    TestMoveAssignmentOperator();

    return 0;
}
