#include<iostream>
#include <vector>
#include<cmath>
using namespace std;

struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int val) : val(val), left(nullptr), right(nullptr) {}
    };


int mkTree(vector<char> arr){
    int j=0;

    while(j<arr.size()){
        int level = j;
        
        for (int i=j; i<pow(2,level);i++){
            cout << arr[i] << " " ;
            if(arr[2*i+1] != '\0'){
                cout << arr[2*i+1] << " " ;
            }
            if(arr[2*i+2]!= '\0'){
                cout << arr[2*i+2] << " " ;
            }

        }
    j++;
    }
    

}

int main(){
    vector<char> binaryTree = {'A', 'B', 'C', 'D', '\0', 'E', 'F', '\0', '\0', '\0', '\0', 'G', 'H', '\0', '\0', '\0'};

    mkTree(binaryTree);

    
}