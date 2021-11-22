#include <iostream>
#include <vector>
#include <string>

#include "queue.hpp"

using namespace std;

int main(){
    cout << "Hello World" << endl;

    vector<string> msg{"Hello", "Vector", "String"};

    lock_free_queue<string> qq;

    for (const string& word : msg){
        cout << word << " ";
    }
    cout << endl;
    
    return 0;
}
