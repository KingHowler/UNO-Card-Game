# Dictionary
<br><br>
| Variable/Array/Type/Object/Function              | Meaning                                                                                                                                                 |
|--------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| ```Card```                                       | A custom class, declares objects which have a Colour and Number, includes built-in translation to String for user Output                                |
| ```r0```, ```r1```, ```r2``` ...... ```noCard``` | Card type Objects for playing                                                                                                                           |
| ```Red[25]```                                    | An Ordered Array containing only Red coloured Cards, Part of the Draw Pile, Used for ```DrawCard()``` function                                          |
| ```Blue[25]```                                   | An Ordered Array containing only Blue coloured Cards, Part of the Draw Pile, Used for ```DrawCard()``` function                                         |
| ```Green[25]```                                  | An Ordered Array containing only Green coloured Cards, Part of the Draw Pile, Used for ```DrawCard()``` function                                        |
| ```Yellow[25]```                                 | An Ordered Array containing only Yellow coloured Cards, Part of the Draw Pile, Used for ```DrawCard()``` function                                       |
| ```Colourless[25]```                             | An Ordered Array containing only Colourless coloured Cards, Part of the Draw Pile, Used for ```DrawCard()``` function                                   |
| ```p1[108]```                                    | Array containing the cards in Player 1's Deck                                                                                                           |
| ```p2[108]```                                    | Array containing the cards in Player 2's Deck                                                                                                           |
| ```p3[108]```                                    | Array containing the cards in Player 3's Deck                                                                                                           |
| ```p4[108]```                                    | Array containing the cards in Player 4's Deck                                                                                                           |
| ```DiscardPile[108]```                           | Array containing the cards which have been played                                                                                                       |
| ```Draw Pile```                                  | Conceptual Pile, This is where the player draw cards from, represented in code as ```Red[]```,```Blue[]```, ...... etc                                  |
| ```cardsRemaining[]```                           | Array containing the number of cards left in the Draw pile, organized by their Colours                                                                  |
| ```players```                                    | No of Players playing                                                                                                                                   |
| ```cards```                                      | No of Cards each player is given at the start of the game                                                                                               |
| ```CreateCard()```                               | A function used to initialize the Arrays and the Card Objects                                                                                           |
| ```DrawCard(playerNo,index)```                   | A function for Drawing a Card from the Draw pile and adding it to the pile specified as ```playerNo```, adds the card at ```index```                    |
| &gt;&gt; playerNo = 1                            | Player 1                                                                                                                                                |
| &gt;&gt; playerNo = 2                            | Player 2                                                                                                                                                |
| &gt;&gt; playerNo = 3                            | Player 3                                                                                                                                                |
| &gt;&gt; playerNo = 4                            | Player 4                                                                                                                                                |
| &gt;&gt; playerNo = 9                            | ```DiscardPile[]```                                                                                                                                     |
| ```DrawCard()``` &gt;&gt; ```colour```           | Placeholder for the colour of the card being drawn                                                                                                      |
| ```DrawCard()``` &gt;&gt; ```Number```           | Placeholder for a randomly generated number, This is manipulated and then turned into an index for selecting Colour and Number of the card being used   |
| &gt;&gt; colour = 0                              | Red                                                                                                                                                     |
| &gt;&gt; colour = 1                              | Blue                                                                                                                                                    |
| &gt;&gt; colour = 2                              | Green                                                                                                                                                   |
| &gt;&gt; colour = 3                              | Yellow                                                                                                                                                  |
| &gt;&gt; colour = 4                              | Colourless                                                                                                                                              |
| ```ShuffleCards(players,cards)```                | A function that iterates the ```DrawCard()``` function appropiately in order to shuffle cards of Number ```cards``` for players of number ```players``` |
| ```StartGame()```                                | A function that initializes the necessities to start the game                                                                                           |
| ```DisplayPlayerCards(playerNo)```               | A function that displays the cards of ```playerNo```                                                                                                    |
| &gt;&gt; playerNo = 0                            | All Players                                                                                                                                             |
| &gt;&gt; playerNo = 1                            | Player 1                                                                                                                                                |
| &gt;&gt;playerNo = 2                             | Player 2                                                                                                                                                |
| &gt;&gt; playerNo = 3                            | Player 3                                                                                                                                                |
| &gt;&gt; playerNo = 4                            | Player 4                                                                                                                                                |
| ```DisplayDrawPile()```                          | A function that displays the contents of the Draw pile                                                                                                  |
| ```DisplayDiscardPile()```                       | A function that displays the contents of the ```DiscardPile[]```                                                                                        |
