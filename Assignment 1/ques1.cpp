#include <iostream>
using namespace std;
int arr[50];
void create(int n){
    cout << "Enter elements of the array: " << endl;
    int i;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
}
void display(int n){
    cout << "Elements of the array are: " << endl;
    int i;
    for(i=0; i<n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}
void insert(int n, int pos, int ele)
{
    int i;
    for(i=n; i>pos; i-- )
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = ele;
    n++;
}
void delete_ele(int n, int pos)
{
    int i;
    for(i=pos; i<n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
}
void search(int n, int ele)
{
    int i, flag = -1;
    for(i=0; i<n; i++)
    {
        if(arr[i] == ele){
          flag = i;
          break;
        }
    }
    
    if(flag >= 0)
    {
        cout << "Element " << ele << " found at index " << flag << endl;
    }
    else 
    cout << "Element not found" << endl;
}
int main(){
    int choice;
    cout << "Menu : " << endl;
    cout << "Create" << endl;
    cout << "Display" << endl;
    cout << "Insert" << endl;
    cout << "Delete" << endl;
    cout << "Linear Search" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    cout << "Enter the number of elements in array: ";
    int n;
    cin >> n;
    int pos,ele;
    switch(choice)
    {
        case 1: 
        create(n);
        break;
        case 2:
        create(n);
        display(n);
        break;
        case 3:
        create(n);
        display(n);
        cout << "Enter the element you want to insert: " << endl;
        cin >> ele;
        cout << "Enter the position at which you want to insert the element: " << endl;
        cin >> pos;
        insert(n,pos,ele);
        n++;
        display(n);
        break;
        case 4:
        create(n);
        display(n);
        cout << "Enter the position from which you want to delete the element: " << endl;
        cin >> pos;
        delete_ele(n,pos);
        n--;
        display(n);
        break;
        case 5:
        create(n);
        display(n);
        cout << "Enter the element you want to search: " << endl;
        cin >> ele;
        search(n,ele);
        break;
        case 6:
        cout << "Exiting the program" << endl;
        break;
        default :
        cout << "Invalid choice";
    }
    return 0;
}