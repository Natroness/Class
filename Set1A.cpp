
//Nikesh Paudyal
// 2025FL COSC-1437-42001
// OCT 18, 2025
//This program will make a vector and array list and display it side by side 

// Question makes it pretty difficult to understand either the both list are same or different but the sentence  " to be printed side by side like below. "
// I interpreted  that food items and non food items are supposed to be different list - one in array and another in vector 
//  and then to be printed side by side 
// But It could mean the other way as well so just to make sure I don't lose my points off I will do it that way too.


//So I will use Two Cases Case - (1) will be the one where I will store food items and non food items on two different list - one in array and another in vector 
//Case -(2) will store the same things in  different array list and different Vector list


#include <iostream>
//to format
#include <iomanip>
//to use vector list 
#include <vector>


using namespace std;

int main ()
{

    //Case(1)
    //I will store food items and non food items on two different list - one in array and another in vector 
    /****************************************************************************************************************************************** */

    //declaring array
    //While using array we have to allocate memory early
    string arrayList[10] = 
    {   
        "Bread", "Bagel" ,"Hotdog", "Chili", "Cheese", "Bacon", "Chips", "Cat food", "Advil", "Nail file"
    };

    //declaring vector list
    //while declaring vector we don't have to declare early
    vector <string> vectorList{   "Cat toy", "Orange juice", "tea", "Butter", "lotion",
        "Eye wash", "soap", "Benadryl", "Pizza", "Cream cheese" };

    //making sure its mentioned as case 1
    cout << "List using Array and Vector (Case 1)" << endl << endl;

    //To display the list
    cout<<"List using array"<<endl<<endl; 

    //using for loop to iterate through every element in the list
    for (int count = 0 ; count<10;count++)
    {
        cout<<fixed<<setw(2)<<count+1<<". "<<arrayList[count]<<" "<<vectorList[count]<<endl;

    }
    
    cout<<endl<<endl;
    cout<<"list using vector"<<endl<<endl;
    //another for loop to display everything again
    for (int count = 0 ; count<10;count++)
    {
        cout<<fixed<<setw(2)<<count+1<<". "<<arrayList[count]<<" "<<vectorList[count]<<endl;

    }

    /****************************************************************************************************************************************** */
    //Case(2)
    //Storing both food items and non food items in arrays and vector
    /****************************************************************************************************************************************** */


    //declaring the arrayLists
    string arrayList2[10] =
    {   "Bread Cat toy","Bagel Orange juice","Hotdog  tea","Chili Butter",
        "Cheese lotion","Bacon Eye Wash","Chips Soap","Cat food Benadryl",
        "Advil Pizza","Nail file Cream cheese"
    };
    //declaring the vectorList
    vector<string> vectorList2
    {   "Bread Cat toy","Bagel Orange juice","Hotdog  tea","Chili Butter",
        "Cheese lotion","Bacon Eye Wash","Chips Soap","Cat food Benadryl",
        "Advil Pizza","Nail file Cream cheese"
    };

    //making sure its mentioned as case 2
    cout << endl<<endl<<"List using Array and Vector (Case 2)" << endl << endl;

    //To display the list
    cout<<"List using array"<<endl<<endl; 

    //using for loop to iterate through every element in the list
    for (int count = 0 ; count<10;count++)
    {
        cout<<fixed<<setw(2)<<count+1<<". "<<arrayList2[count]<<endl;

    }
    
    cout<<endl<<endl;
    cout<<"list using vector"<<endl<<endl;
    //another for loop to display everything again
    for (int count = 0 ; count<10;count++)
    {
        cout<<fixed<<setw(2)<<count+1<<". "<<vectorList2[count]<<endl;

    }



    return 0;
}





