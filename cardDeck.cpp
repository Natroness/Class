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
        //I am making this so that user can chose if they want to play again or no
        char play = 'Y';
    
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
//and then we will save that to again temporary list then we add it to array to make it shuffle again
void shuffle()
{
    string temp;

    srand(time(0));


    for (int i =0 ; i<remaining;i++)
    {
        int r = rand() % remaining;
        //again saving all the left cards in temp
        temp = cards[i];
        //now 
        cards[i]=cards[r];
        cards[r]=temp;
    }
}

string dealing()
{

    if (remaining == 0)
    {
        cout<< "We have no cards. Do you want to start it again?\nPress 'Y' or 'y' for Yes.\n" ;
        cin>>play;

        if (play == 'Y' || play =='y' )
        {
            totalCards();
            shuffle();
            remaining = 52;
        }
        else
        {
            return "";
        }
    }
    remaining -- ;
    return cards[remaining];

}


int getRemaining()
{
    return remaining;
}
};
//end of class
int main(){

    deck d;
    d.totalCards();
    d.shuffle();

    cout << " Dealing 3 cards: \n";

    for (int i = 0 ; i<3;i++)
    {
        string card = d.dealing();
        cout<<d.dealing()<<endl;

    }
    cout<<endl;
    cout<<"Remaining Cards :"<<d.getRemaining()<<endl;
    return 0;

    
}