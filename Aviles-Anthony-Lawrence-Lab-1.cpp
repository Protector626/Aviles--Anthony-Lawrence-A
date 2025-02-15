#include <iostream>

using namespace std;


int myArray[30]; 
int numElem = 0;
int maxElem = 8;

void traverseArray(){
    cout << "Showing elements in my array \n";
    for(int i = 0; i< maxElem; i++){
        cout << to_string(myArray[i]) + " | ";
    }
    cout << "\n";
}



string InsertAtTheEnd(int num){
    if(numElem != maxElem){
        myArray[numElem] = num;
        numElem++;
        return "An element is succesfully inserted at the end! \n";
    }
    return "The array is full. Please remove elemts before inserting new one. \n";
}


string InsertAtBeginning(int num){
    if(numElem != maxElem){
        for(int i = numElem; i >= 0; i--){
            myArray[i+1] = myArray[i];
        }
        
        myArray[0] = num;
        numElem++;
        return "An element is succesfullyinserted at the beginning! \n";
    }
    return "The array is full. Please remove elements before inserting one. \n";
}

string InsertAtTheGivenPosition(int num, int ElementAfter){
    if(numElem != maxElem){
        int position;
        for(int i = 0; i <= maxElem; i++){
            if(myArray[i] == ElementAfter){
                position = i;
                break;
            }
        }
        
        for(int i = numElem; i>=position; i--){
            myArray[i+1] = myArray[i];
        } 
        myArray[position + 1] = num;
        numElem++; 
        return "An Element is succesfully inserted at the specified location \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

int main(){
    
    InsertAtBeginning(3);
    InsertAtTheEnd(7);
    InsertAtTheEnd(9);
    InsertAtBeginning(20);
    InsertAtTheGivenPosition(37, 7);
    InsertAtBeginning(256);
    InsertAtTheGivenPosition(128, 9);
    InsertAtBeginning(19);
    traverseArray();
    


    return 0;
}