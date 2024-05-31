# UNO!
#### Student Project for learning C++

## Methodologies
1. Array Pairs
   - Uses 2 synced pairs and a dictionary
     - ```p1[]```          : Contains the integer values of the Number of each Card in Player 1's deck, is synced with ```cp1[]```
     - ```cp1[]```         : Contains the integer values of the Colour of each Card in Player 1's deck, is synced with ```p1[]```
     - ```dictionary[]```  : Converts the integer values in ```p1[]``` and ```cp1[]``` to strings describing the features of the card
   - Discontinued due to data handling complexity
2. Custom Class
   - Uses a custom class ```Card```
     - All object with the class ```Card``` have integer values for ```Colour``` and a ```Number```
     - All objects with type Card have a built-in Ditcionary which describes the feature of the card when the functions ```printColour()``` and ```printNumber()``` are used
   - Former variation
     - Used multiple arrays
     - Switched to a single Universal Array
3. Custom Class with Universal Arrays
   - Uses a custom class ```Card```
     - All object with the class ```Card``` have integer values for ```Colour``` and a ```Number```
     - All objects with type Card have a built-in Ditcionary which describes the feature of the card when the functions ```printColour()``` and ```printNumber()``` are used
   - Uses a Universal Array instead of multiple different arrays
     - All cards are in a single Array called ```Piles[]```
     - ```Piles[]``` is seperated into six regions of 108 in the following order
       - Draw Pile
         - Red Cards
         - Blue Cards
         - Green Cards
         - Yellow Cards
         - Colourless Cards
       - Player 1
       - Player 2
       - Player 3
       - Player 4
       - Discard Pile
     - A function ```Offset()``` is used to obtain data using an index between 0 and 107 instead of 0 and 647. This makes it easier to perform card manipulation procedures
     - Former variation
       - Reformatted parameters and saved as UNO
4. UNO
   - The Final and completed CLI-based UNO Card Game

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
