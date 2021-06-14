#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    cout << "Hello World" << endl;

    vector<string> msg{"Hello", "Vector", "String"};

    for (const string& word : msg){
        cout << word << " ";
    }
    cout << endl;
    
    return 0;
}
