//Nikesh Paudyal
//Nov 22, 2025
//This program will have a deck of playing cards. cards can be represented as a
//It will be  able to shuffle the deck. ( randomize the array when card is delt)
//It will Remove the card is delt from the "deck"
#include <iostream>
//I figured out that we would also need a random to randomize the dealing of card.
//I had learned to make srand() in my Programming I class using cstdlib and ctime so i will use the same method
#include<cstdlib> //for srand()
#include<ctime> //for time()
using namespace std;

//creating a class called deck
class deck
{
    //First we want to create a array with the size of 52 as it has 13 types of card in 4 different shapes.
    //second we will also want to know the remaining number of cards to shuffle later.
    //Also, we wil want to keep this declaration inside the private as we only want memeber of class to change the values.

    private:
        //declaring the array with size 52
        string cards[52];
        //also declaring the size of the deck after dealing the cards
        int remaining = 52;
    
    public:
    //also array cannot be filled directly like python so we will need a string temporary list and then add it array iteratively.
    //Also i changed this to mainDeck as we might need it back after all the cards are dealt.
        string mainDeck[52] = {"[2H]", "[3H]", "[4H]", "[5H]", "[6H]", "[7H]", "[8H]", "[9H]", "[10H]", "[JH]", "[QH]", "[KH]", "[AH]",
                    "[2D]", "[3D]", "[4D]", "[5D]", "[6D]", "[7D]", "[8D]", "[9D]", "[10D]", "[JD]", "[QD]", "[KD]", "[AD]",
                    "[2C]", "[3C]", "[4C]", "[5C]", "[6C]", "[7C]", "[8C]", "[9C]", "[10C]", "[JC]", "[QC]", "[KC]", "[AC]",
                    "[2S]", "[3S]", "[4S]", "[5S]", "[6S]", "[7S]", "[8S]", "[9S]", "[10S]", "[JS]", "[QS]", "[KS]", "[AS]"};

    void totalCards()
    {
        //adding the card in array
        for (int i = 0;i<52;i++)
        {

            cards[i] = mainDeck[i];
        } 
        //end of for loop
    }


//Now we need a function to shuffle the card
//shuffle means we are changing the position of the cards in the random order
//Also, if we change directly from array it might create duplicates of the same card
//Which is something we dont want it to happen
// for this may be we shuffle meaning randomizing the position of the cards
//Then we only deal from the end of the array meaning the last cards
//and then we will save that to again temporary string then we change the position of array
void shuffle()
{
    //using string to store card and then move its position  
    string temp;
    //from what i learned in Programming I. this provides current time in sec which is changing constantly
    //thats why gives differnt sequence everytime.
    srand(time(0));
    //srand() is with  the starting position of rand() this makes different everytime.

    //looping through each remaining cards
    for (int i =0 ; i<remaining;i++)
    {   
        //r should be less than the remaining number
        int r = rand() % remaining;
        //again saving the card value in temp file
        temp = cards[i];
        //changing value in card[i] with card[r]
        cards[i]=cards[r];
        //putting the value in temp to card[r]
        cards[r]=temp;
    }
}
//declaring the function dealing() which will return card in string value.
//we want this function to give the card also while reducing the remaining number of cards
//since remaining is private member only class member can change it so dealing() has to be member of class.
string dealing()
{
    //I want my program to restart if there is no card so instead of ending and dealing last remaining cards 
    //i want program to return not enough cards
    if (remaining ==0)
    {   
        return "Not enough Cards!";
    }
    else
    {
    //if remaining card is still enough to deal
    //it decreases by 1
    remaining -- ;
    //displays the shuffled card at the end of the array
    return cards[remaining];
    }

}
//declaring function
// i will use this to reset the deck when it get less than the least number of card than can be dealt.
//returns integer
int getRemaining()
{
    //returns remaining number of cards
    return remaining;
}
//resetting deck after it gets  less than the least number of card than can be dealt.
//this function will just call the member functions totalcard(), change the value of remaining which is a private member.
//also calls another class function shuffle.
void resetDeck()
{
    //calling totalcards function
    totalCards();
    //changing value of number of remaining cards
    remaining= 52;
    //calling the shuffle function
    shuffle();
}

};
//end of class

//starting main function
int main()
{
    //declaing char variable to make play again feature.
    char play ='Y';
    //creates object d for class deck
    deck d;
    //callind totalCard function from class deck
    d.totalCards();
    //while player still wants to play we continue to play and deal the cards
    while(play == 'Y'||play == 'y')
    {
        //shuffling the card after every deal
        //although shuffle only takes place after a game but since its single player
        //we shuffle it every time
        d.shuffle();
        //displaying to the user about the upcoming cards
        cout << " Dealing 3 cards: \n";
        //dealing 3 cards 
        for (int i = 0 ; i<3;i++)
        {
            //prints the string returned by dealing() function in deck class
            cout<<d.dealing()<<endl;

        }
        cout<<endl;
        //displays the integar returned by getRemaining function in deck class
        cout<<"Remaining Cards :"<<d.getRemaining()<<endl;

        //asking user if they want to play again
        cout <<"Do you want to continue? \n Press 'Y' to start again: ";
        //taking input from the user
        cin>> play;
        cout<<endl;
        //if remaining card is less than 3. Starting another deck.
        if (d.getRemaining()<3)
        {
            cout<<"Not enough cards for another round. \n Starting another deck."<<endl;
            //calling resetDeck funciton from deck class.
            d.resetDeck();  
        }
    }
    return 0;    
}