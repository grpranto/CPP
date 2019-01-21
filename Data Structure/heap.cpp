#include<iostream>
#include<algorithm>
#include<windows.h>
#define SIZE 8
using namespace std;

//Assuming size as 8
int SIZE1 = 8;
int arr[SIZE];
int parent;
bool flag = false;

void heapAdd();
void heapDelete();
void showHeap();

int main(){
    cout << "Here, assuming size = 8\n";
    cout << "enter the data : ";
    for(int i=0; i<SIZE; i++)
        cin >> arr[i];

    for(;;){
        if (flag == false) cout << "\nPress,    1 to add data into heap\n";
        else cout << "\nPress,    \n";
        cout << "          2 to delete parent from heap\n";
        cout << "          3 to show heap\n";
        cout << "          4 to exit\n\n";

        int num;
        cout << "Enter your choice : ";
        cin >> num;

        if(num == 1)  {heapAdd(); flag = true; cout << "Data added into heap successfully\n";}
        else if(num == 2)  {heapDelete(); cout << "Parent deleted successfully\n";}
        else if(num == 3)  showHeap();
        else if(num == 4)  return 0;
        else cout << "Wrong choice\n";

    }

    return 0;
}

void heapAdd(){
    for(int i=1; i<SIZE; i++){
        while(1){
            parent = (i-1) / 2;
            if(arr[parent] < arr[i]){
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else  break;
        }
    }
}

void heapDelete(){
    swap(arr[0], arr[SIZE1 - 1]);
    SIZE1--;
    for(int i=1; i<SIZE1; i++){
        parent = (i-1) / 2;
        while(1){
            if(arr[parent] < arr[i]){
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else  break;
        }
    }
}

void showHeap(){
    cout << "Displaying heap : ";
    for(int i=0; i<SIZE1; i++)
        cout << arr[i] << " ";
}
