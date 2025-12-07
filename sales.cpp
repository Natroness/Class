//Nikesh Paudyal
//DEC 6, 2025
//This program will display item number,descriotion,cost per unit and number of units requested and also currency and the total cost in each USD and GBP.



#include <iostream>
#include <string>
using namespace std;

//creating class salesOrder
class SalesOrder
{

//listing private variables 
    private:
        string itemNumber;
        string itemDescription;
        double costPerUnit;
        int unitsRequested;
        string currency;


    public:
        salesOrder()
        {
            currency ="USD";
            costPerUnit = 0.0;
            unitsRequested = 0;
        }

    //setting the variables
        void setItemNumber(string num)
        {
            itemNumber = num;
        }

        void setItemDescription (string description)
        {
            itemDescription = description;
        }
        void setCostPerUnit(double cost)
        {
            costPerUnit = cost;
        }
        void setUnits(int units)
        {
            unitsRequested = units;
        }
        void setCurrency(string money)
        {
            currency =  money;
        }

    //getting variables
        string  getItemNumber()
        const
        {
            return itemNumber;
        }

        string getItemDescription()
        const
        {
            return itemDescription;
        }

        double getCostPerUnit()
        const
        {
            return costPerUnit;
        }

        int getUnitsRequested()
        const
        {
            return unitsRequested;
        }
        string getCurrency()
        const
        {
            return currency;

        }

    //virtual Method
        virtual double totalCost()
        const
        {
            return costPerUnit * unitsRequested * 1.0825;
        }

};
//we will have to use inheritence in this part.We will inherit from salesOrder because almost everything is simlar except few.
//this is "is -a " relationship
//A salesOrderBritain is a SalesOrder
 class SalesOrderBritain: public SalesOrder

 {
    public :
        salesOrderBritain():salesOrder()
        {
            //Making the change in currency
            setCurrency("GBP");
        }
        
        double totalCost() const override
        {
            return SalesOrder::totalcost()*0.82;
        }
 };


 void reportSales(const SalesOrder& order)
 {
    cout <<endl<<"Sales Report"<<endl;
    cout<<"Item Number: "<<getItemNumber()<<endl;
    cout<<"Item Description: "<<getItemDescription()<<endl;
    cout<<"Cost Per Unit: "<< getCostPerUnit() << endl;
    cout << "Units Requested: " << getUnitsRequested() << endl;
    cout << "Currency: " << getCurrency() << endl;
    cout << "Total Cost: " << totalCost() << endl;
}

int main()
{
    salesOrder usOrder;
    usOrder.SetItemNumber("A100");
    usOrder.setItemDescription("Gaming Mouse");
    usOrder.setCostPerUnit("50.0");
    usOrder.SetUnitsRequested(4);

    SalesOrderBritain ukorder;
    ukOrder.setItemNumber("A100");
    ukOrder.setItemDescription("Gaming Mouse");
    ukOrder.setCostPerUnit(50.00);
    ukOrder.SetUnitsRequested(4);

    reportSales(usOrder);
    reportSales(ukOrder);

    return 0;

}








int main(){
    return 0;
}