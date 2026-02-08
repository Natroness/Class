//Nikesh Paudyal 
//DEC 6, 2025
//This program will display item number,description,cost per unit and number of units requested and also currency and the total cost in each USD and GBP.
#include<iostream>
#include<string>
using namespace std;

//creating class SalesOrder
class SalesOrder
{
    //private variables used by the class
    private:
        string itemNumber;
        string itemDescription;
        double costPerUnit;
        int unitsRequested;
        string currency;

    public:
    //constructor for SalesOrder class
        SalesOrder()
        {
            currency = "USD";
            costPerUnit = 0.0;
            unitsRequested = 0;
        }

    //setting the variables
        void setItemNumber(string num)
        {
            itemNumber = num;
        }

        void setItemDescription(string description)
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
            currency = money;
        }

    //getting variables
        string getItemNumber() const
        {
            return itemNumber;
        }

        string getItemDescription() const
        {
            return itemDescription;
        }

        double getCostPerUnit() const
        {
            return costPerUnit;
        }

        int getUnitsRequested() const
        {
            return unitsRequested;
        }

        string getCurrency() const
        {
            return currency;
        }

    //virtual method used for calculating total cost
        virtual double totalCost() const
        {
            return costPerUnit * unitsRequested * 1.0825;
        }
};

//creating SalesOrderBritain class that inherits from SalesOrder
class SalesOrderBritain : public SalesOrder
{
    public:
    //constructor for SalesOrderBritain
        SalesOrderBritain() : SalesOrder()
        {
            setCurrency("GBP");
        }

    //overriding totalCost method for British currency
        double totalCost() const override
        {
            return SalesOrder::totalCost() * 0.82;
        }
};

//function to print the sales report
void reportSales(const SalesOrder& order)
{
    cout << endl << "Sales Report" << endl;
    cout << "Item Number: " << order.getItemNumber() << endl;
    cout << "Item Description: " << order.getItemDescription() << endl;
    cout << "Cost Per Unit: " << order.getCostPerUnit() << endl;
    cout << "Units Requested: " << order.getUnitsRequested() << endl;
    cout << "Currency: " << order.getCurrency() << endl;
    cout << "Total Cost: " << order.totalCost() << endl;
}

//starting main function
int main()
{
    //creating object for US order
    SalesOrder usOrder;
    usOrder.setItemNumber("A100");
    usOrder.setItemDescription("Gaming Mouse");
    usOrder.setCostPerUnit(50.0);
    usOrder.setUnits(4);

    //creating object for UK order
    SalesOrderBritain ukOrder;
    ukOrder.setItemNumber("A100");
    ukOrder.setItemDescription("Gaming Mouse");
    ukOrder.setCostPerUnit(50.0);
    ukOrder.setUnits(4);

    //display sales reports
    reportSales(usOrder);
    reportSales(ukOrder);

    return 0;
}
