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
   - Discontinued due to data handling complexity
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
- To declare a "Player 1 has gotten n<sup>th</sup> Position" after the game has ended
<!-- - To reset the Draw pile using the Discard pile if it is empty
- To declare "UNO!" if any of the players has only 1 card left
- To declare a "Player 1 has gotten n<sup>th</sup> Position" after the game has ended -->

## Game Description
### Purpose
- This is the logic unit for a multiplayer UNO card game
- The code is built in such a way to allow it to be integrated to a GUI with only slight modifications
### Input Stream
- The Game uses only integers for inputs
- The first two inputs are pre-game inputs selecting the number of players who will be playing and the number of cards each player will start with
- Once the game starts it will take indexes as inputs
  - Each player can play a card in their deck by inputting the index of the card they want to play which can only be from 0-107
  - They can input ```-1``` to draw a card
  - They can input ```-2``` to indicate they have completed their turn
- Each player must have placed atleast one card or drawn 1 card before they can pass their turn
- **Valid Inputs during pre-game** : Players => ```1``` - ```4``` , Cards => ```1``` - ```21```
- **Valid Inputs during game** : Index => ```-2``` - ```107```
### Output Stream
- The game will generate properly described prompts whecn asking for each input
- The game will output each player's hands and the discard pile every time a player passes a turn
- The game will output a leaderboard when only 1 player is left
### Structure - master.cpp
![image not available](https://github.com/KingHowler/UNO_Card_Game/assets/68814294/e507c5ec-e446-496e-a2ce-64ec4051c871)


### Structure - buildUNO.cpp
![image not available](https://github.com/KingHowler/UNO_Card_Game/assets/68814294/35d525ec-c6bd-4a27-b1df-63f27037ae57)


### Structure - FDE.cpp
![image not available](https://github.com/KingHowler/UNO_Card_Game/assets/68814294/547581b9-1784-4fa7-af45-b70086d35ce2)


### State Diagram
![image not available](https://github.com/KingHowler/UNO_Card_Game/assets/68814294/f1905ed5-52f9-4144-ab84-c65cd917f7e4)
