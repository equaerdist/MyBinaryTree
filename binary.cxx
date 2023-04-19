#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "binaryTree.h"
using namespace std;
int main() 
{
    auto example = new BinaryTree<int>();
    for(long long i=0; i < 4096 * 2500; i++) 
    {
        auto temp = (rand() % 20) + 10;
        example->Insert(temp);
    }
    if (example->Insert(96)) 
    {

        if (example->Find(96)) {
            cout << "Nice found\n";
        }
    }
    cout << "Current Count is " << example->GetLength() << "\n";
    auto start = chrono::high_resolution_clock::now();
    cout << example->Find(56);
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    return 0;
}