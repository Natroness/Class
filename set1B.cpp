// You are tasked with crating a grade sheet with 10 grades. 
// You will calculate the average and print out a report of each grade and the average. 
// Write a program that will print out 10 grades, and the average. 
// Average formula is (total/10). This project MUST use dynamic arrays to accomplish the task.




//Nikesh Paudyal
//2025FL COSC-1437-42001
//Set 1 part B
//This program will create a grade sheet with 10 grade and will calculate and display average 

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    //As from the given example the data entered is likely to be integar but still making total and average variable double
    int *grades = nullptr,
        students; // to store number of students 
    //declaring average and total variable to be double 
    double average,
           total = 0.0;

        cout<<"Enter number of students: ";
        cin>>students;
    //assigning memory to grades array
    grades = new int[students];
    //iterating through all the elements and asking the user to input grades
    for (int count = 0;count<students;count++)
    {
        cout<<"Please enter grade"<<right<<setw(2)<<count+1<<":"<<endl;
        cin>>grades[count];
        //condition if grades less than 0
        if (grades[count]<0)
        {
            cout<<"Grade is too low please try again."<<endl<<endl;
            cout<<"Please enter grade"<<right<<setw(2)<<count+1<<":"<<endl;
            cin>>grades[count];    
        }
        //condition if grades more than 100
        else if(grades[count]>100)
        {
            cout<<"Grade is too high"<<endl<<endl;
            cout<<"Please enter grade"<<right<<setw(2)<<count+1<<":"<<endl;
            cin>>grades[count];    
        }
            //make it look cleaner and starts new line
            cout<<endl;
            
    }
   //running for loop to iterate through every element and calculate total
    for (int count= 0;count <students;count++)
    {   
        //calculating total
        total +=grades[count];
    }

    //calculating the average
    average = total / students;

    //formatting

    cout<<"Grade report"<<endl;
    cout<<"============================================"<<endl<<endl;
    //for loop to iterate and go through every on them
    for (int count= 0;count < students;count++)
    {   
        //formatting just like the question asks us to
        cout<<fixed<<setw(5)<<"Grade"<<setw(2)<<count+1<<":"<<setw(3)<<grades[count]<<endl<<endl;
    }
    //formatting average just like the question asks us 
    // example shown in question is integar so i just rounded up the average
    cout<<right<<setw(12)<<"Average:"<<fixed<<setprecision(0)<<average;

    //to clean up the memory
    delete[] grades;

    return 0;
}


