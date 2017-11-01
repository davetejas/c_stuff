// Compiled with: g++ -Wall -std=c++14 -pthread

#include <cstdlib>
#include <iostream> 
#include <experimental/random>


using namespace std;

#define size 65535

class operations {
    private:
        int hashmap[size] = {-1};    // holds the index of element stored in array
        int array_elem[size] = {0};  // hold all elements inserted
        int max_element = 0;         // holds index of last element inserted in array
    
    public:
    void insert_element(int value) {
        if (value >= 0){
            hashmap[value] = max_element;
            array_elem[max_element] = value;
            max_element++;
        } else {
            cout << "incorrect input" << endl;
        }
    }
    void delete_element(int value){
        cout << "Deleting " << value << endl;
        if (value >= 0){
            
            int arr_idx = hashmap[value];
            int last_elem = array_elem[max_element];
            
            
            array_elem[arr_idx] = last_elem;                 //overwriting deleted element
            hashmap[last_elem] = arr_idx;                    //updating hashmap with new index
            hashmap[value] = -1;                             //resetting hashmap for deleted elem
            array_elem[max_element] = 0;                     //resetting last element      
            max_element--;                                   //decrementing total no. of elements
        } else {
            cout << "incorrect input" << endl;
        }        
    }
    int contains_element(int value){
        if (value >= 0){
            if (hashmap[value] != -1) {
                return hashmap[value];
            } else {
                return -1;
            }
        } else {
            cout << "incorrect input" << endl;
            return 0;
        } 
    }
    int random_element() {
        int range = std::experimental::randint(0, max_element);
        cout << "range is: " << range << endl;
        
        return array_elem[range]; 
    }
};

int main(){
    int input_array[5] = {1,2,4,3,8};
    
    operations tst;
    
    for (int i=0; i<5; i++) {
        cout << "Inserting " << input_array[i] << endl;
        tst.insert_element(input_array[i]);
    }
    
    tst.delete_element(2);
    
    cout << "index of value: "<<tst.contains_element(2) << endl;
    cout << "index of value: "<<tst.contains_element(3) << endl;
    cout << "Random value: "<< tst.random_element() << endl;
    
    return 0;
}

