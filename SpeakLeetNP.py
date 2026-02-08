'''
Understanding the Problem: 
We are given a word or phrase. We will have to convert that phrase or word into 
"leet speak". 
first we should not replace any numbers or spaces
we should replace:
ER -> XOR
OR -> ZOR
AND,ANNED, and ANT -> &
ED -> *D
but these replacing letter should be end of a word 
to translate into above given letters or signs other wise 
we follow the chart.
all remaining in accordance with the chart.

Planning: 

first we will recieve word or the phrase from the user then we will split them into words
 using prebuilt split method in python. after that we can check from backwards in python using [-3:]
 if it meets the condition from above then we replace with the 
 instructed characters other wise we will replace them according to chart.
 Also, to check we can use prebuilt uppercase method in python.


 while spliting from backwards we will want to keep the word saved as core so thats it can be changed according to the table later.

'''

def leetChar(ch):
    ch = ch.upper()

    if ch == "A": return "4"
    elif ch == "B": return "8"
    elif ch == "C": return "["
    elif ch == "D": return ")"
    elif ch == "E": return "3"
    elif ch == "F": return "|="
    elif ch == "G": return "6"
    elif ch == "H": return "#"
    elif ch == "I": return "|"
    elif ch == "J": return "]"
    elif ch == "K": return "|<"
    elif ch == "L": return "1"
    elif ch == "M": return "^^"
    elif ch == "N": return "^"
    elif ch == "O": return "0"
    elif ch == "P": return "|o"
    elif ch == "R": return "2"
    elif ch == "S": return "5"
    elif ch == "T": return "7"
    elif ch == "U": return "(_)"
    elif ch == "V": return "\/"
    elif ch == "W": return "vv"
    elif ch == "X": return "><"
    elif ch == "Y": return "/"
    elif ch == "Z": return "%"
    #if not alphabet letter just return the same character
    return ch

#to start the while loop
userDecision = 'Y'
#this array will be used in the end to return the leet Words
result = []
while userDecision== 'Y':

    #getting input from the user
    phrase = input("Phrase: ")

    #using prebuilt method to split phrase into array
    words=phrase.split(" ")
    #making array for the final result
    result = []
    #iterating through each word in words
    for word in words:
        word =word.upper()

        #checking words if they are ending with the letters from the above characters
        if len(word) >=2 and word[-2:] == "ER":
            #word without the ER
            coreLetters= word[:-2]
            #we make ending changed for the ER condition
            endChange = "XOR"

        #same conditions for other characters    
        elif len(word) >= 2 and word[-2:] == "OR":
            coreLetters = word[:-2]
            endChange  = "ZOR"
        elif len(word)>=3 and word[-3:] == "AND":
            coreLetters = word[:-3]
            endChange  = "&"

        elif len(word) >= 5 and word[-5:] == "ANNED":
            coreLetters = word[:-5] 
            endChange = "&"
        elif len(word) >= 3 and word[-3:] == "ANT":
            coreLetters = word[:-3] 
            endChange = "&"
        elif len(word) >= 2 and word[-2:] == "ED":
            coreLetters = word[:-2] 
            endChange = "*D"
        else:
            coreLetters = word
            endChange=""
        
        #this will contain characters than have gone through the chart
        leetWord = ""
        for ch in coreLetters:
            leetWord += leetChar(ch)

        leetWord = leetWord + endChange
        #adding all the leetWords in the result array.
        result.append(leetWord)    
    #returning the joined result
    print(" ".join(result))
    #asking user if they want to run this program again
    userDecision = input("Run Again (Y/N): ")
    #making it uppercase in case user types in lowercase.
    userDecision = userDecision.upper()
