# UNO!
#### Student Project for learning C++

## Methodologies
1. Array Pairs
   - Uses 2 synced pairs and a dictionary
     - ```p1[]```          : Contains the integer values of the Number of each Card in Player 1's deck, is synced with ```cp1[]```
     - ```cp1[]```         : Contains the integer values of the Colour of each Card in Player 1's deck, is synced with ```p1[]```
     - ```dictionary[]```  : Converts the integer values in ```p1[]``` and ```cp1[]``` to strings describing the features of the card
2. Custom Class
   - Uses a custom class ```Card```
     - All object with the class ```Card``` have integer values for ```Colour``` and a ```Number```
     - All objects with type Card have a built-in Ditcionary which describes the feature of the card when the functions ```printColour()``` and ```printNumber()``` are used

## Target Description
- To initaialize the cards
- To input
  - The number of Players
  - The number of Cards each player should have
- To shuffle the Cards for each Player based on input
- To take 1 card from the remaining Draw pile and set it as the Discard pile
- To play the game in a clockwise manner {P1 - P4} until changed by a Reverse card
- To ensure the players can only put cards which match the top of the Discard pile by either Number or Colour
- To allow the player to draw a card from the Draw pile
- To complete appropriate processes for each action card
- To reset the Draw pile using the Discard pile if it is empty
- To declare "UNO!" if any of the players has only 1 card left
- To declare a "Player 1 has gotten n<sup>th</sup> Position" after the player has no cards remaining
