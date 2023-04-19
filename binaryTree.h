#pragma once
#include <iostream>
#include <stdlib.h>
using namespace  std;
template <typename T>
class BinaryTree {
    size_t Count;
public:
    struct Node
    {
        T value;
        Node* left;
        Node* right;
        Node(T Value, Node* Left, Node* Right)
        {
            this->value = Value;
            this->left = Left;
            this->right = Right;
        }
    };
private:
    enum result { equals, nullpointer, less, bigger };
    int Compare(Node* potential, T value)
    {
        if (potential == nullptr) {
            return nullpointer;
        }
        if (potential->value > value) {
            Compare(potential->left, value);
        }
        else if (potential->value < value) {
            Compare(potential->right, value);
        }
        else {
            return equals;
        }
    }
    Node* RootNode;
    bool insert(Node* potential, T value)
    {
        if (potential->value > value)
        {
            if (potential->left != nullptr)
            {
                insert(potential->left, value);
            }
            else {
                auto temporary = new Node(value, nullptr, nullptr);
                potential->left = temporary;
                return true;
            }
        }
        else if (potential->value < value) {
            if (potential->right != nullptr)
            {
                insert(potential->right, value);
            }
            else {
                auto temporary = new Node(value, nullptr, nullptr);
                potential->right = temporary;
                return true;
            }
        }
        else {
            return false;
        }
    }
    void ShowNode(Node* value)
    {
        if (value == nullptr)
        {
            throw new exception;
        }
        if (value->left != nullptr)
        {
            ShowNode(value->left);
        }
        cout << value->value << "\n";
        if (value->right != nullptr) {
            ShowNode(value->right);
        }
    }
public:
    BinaryTree()
    {
        RootNode = nullptr;
        Count = 0;
    }
    bool Insert(T value)
    {
        if (RootNode == nullptr) {
            auto temporary = new Node(value, nullptr, nullptr);
            RootNode = temporary;
            Count++;
            return true;
        }
        else
        {
            auto result = insert(RootNode, value);
            if (result) Count++;
            return result;
        }
    }
    void Show()
    {
        if (Count != 0)
            ShowNode(RootNode);
    }
    bool Find(T value)
    {
        auto result = Compare(RootNode, value);
        switch (result) {
        case equals:
            return true;
        case nullpointer:
            return false;
        }
    }
    T Pop()
    {
        if (Count == 0 || RootNode == NULL) {
            throw new exception{ "You can't pop empty tree" };
        }
        auto temporary = RootNode;
        Node* prev = nullptr;
        int counter = 0;
        while (temporary != nullptr)
        {
            if (temporary->left == nullptr)
            {
                if (counter == 0)
                {
                    Node* right = temporary->right;
                    auto value = temporary->value;
                    delete temporary;
                    RootNode = right;
                    Count--;
                    return value;
                }
                auto value = temporary->value;
                Node* right = temporary->right;
                auto oldValue = 0;
                if (right != nullptr)
                    oldValue = right->value;
                delete right;
                delete temporary;
                prev->left = nullptr;
                if (right != nullptr)
                {
                    insert(prev, oldValue);
                }
                Count--;
                return value;
            }
            else {
                counter++;
                prev = temporary;
                temporary = temporary->left;
            }
        }
    }
    size_t GetLength() const {
        return Count;
    }
};