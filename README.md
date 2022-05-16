# M4OEP-Graphics1-tliang2
###### name: Tianyi Liang
This final project is a succession of the program I wrote on Module 4. Users will control a board to catch balls popping from 
the top of the screen. When a ball is successfully caught, the board will be extended and the 
dropping speed will be increased. A user wins the game when they have 20 combos 
If one ball is missing, the board will shorten to default length. If the board is currently default
length and the user missed a ball, the board will be continually shortened. When the board could no longer be
shortened, the game is over. Users can use A and D, or Left and Right, to control the board. Both work as intended. X 
is the key to start and also restart the game. 

There are five screens in the program. Initially, a user wll see a welcome page telling the rule and prompt the user
to press X to start the game. After that, there will be a difficulty selection screen. Users could use mouse to left click
the three buttons to choose different levels. Higher level will have the faster initial speed, a higher growth rate on speed,
and a bigger required number of combo for winning the game. After selecting the difficulty, 
the gameplay screen comes out. When the board length reaches 0, there will be a
lose game screen showing up. If the user reaches 15/25/35 combos, the will also be a winning screen. There will be a restart option
in both losing and winning screen.

The ball is drawn in a 3D style. The algorithm and detail is saved as a .png file in this project folder. Compare to the previous 
version of the program, other features are added. Background is set to be gradient color. The color will flow slowly over time.
Also, there are other types of ball falling down. Bombs will randomly drop while playing the game. If user by accident caught a 
bomb, the Game Over screen will come out, and there will still be option to continue play the game by pressing X. 
The frequency of bomb will also increase if a user picks a higher level. 

The bomb is drawn using 12 different circles and 4 rectangles. 
In order to draw the skeleton arm icon in the center of the bomb, I added a rotation method to the Rect class. 
This method uses trigonometric functions to draw the crosses skeleton arms after rotation. The required parameter is 
rotation angle ( By using radian).

## Concepts used
The different shape classes are connected ny is-A relationship which is a concept coming from Module 2. There are also different 
versions of draw function, which is implemented in Shape class as a pure virtual function. The whole program is written with visual 
elements coming from Module 4. There are mouse, cursor, keyboard normal and special key input implemented. All visual elements are associated 
with C++ class objects. 