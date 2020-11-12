/*
______________________________________________ discribtion _____________________________________________





###################################################### variables ########################################



___________________________________________________arrays and vectors ___________________________________


1) maze_level_one                                                        
and    maze_level_two                                                    
and maze_level_three                                                     
These variables are pacman maze backup and the numbers on it refers to:
	•	0 ->   food
	•	1 ->   wall
	•	2 ->  empty cell
	•	3 ->  pacman
	•	4 ->  energyfood
_________________________________________________________________________________


2) maze                                                                  

this array is made to hold a copy of the mazes that we talked about before 
according to the level number so we can work on it without affecting the original maze
_______________________________________________________________________________

3)tmp_maze                                                               

This array is used on the function findpath which we are going to explain later
_______________________________________________________________________________

4)walk                                                                   

This structure is used on the function findpath which we are going to explain later

___________________________________________________________________________________

5)target                                                                
This structure is used on the function findpath which we are going to explain later

____________________________________________________________________________________

6)BFSArray_blinky with data type walk and walk_queue_blinky with data type target      
these vectors are used on the function findpath which we are going to explain later

____________________________________________________________________________________

7)BFSArray_pinky with data type walk and walk_queue_pinky with data type target        
these vectors are used on the function findpath which we are going to explain later

_____________________________________________________________________________________

8)BFSArray_inky with data type walk and walk_queue_inky with data type target          
these vectors are used on the function findpath which we are going to explain later

_____________________________________________________________________________________

9)BFSArray_cludy with data type walk and walk_queue_cludy with data type target      
these vectors are used on the function findpath which we are going to explain later

______________________________________________________________________________________

10)_rank with data type pair of int and string                                        
this vector is responsible for sorting the rank
______________________________________________________________________________________

11)_rank with data type pair of int and string                                       
this vector is responsible for sorting the rank

______________________________________________________________________________________

12)rankq
this map is role is to provid repeted names on the rank


*/




















#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<math.h>
#include<cmath>
#include <ctime>
#include <cstdlib>
#include<sstream>
#include<istream>
#include<iostream>
#include<windows.h>
#include <conio.h>
#include <vector>
#include <map>
#include<algorithm>
#include <fstream>
#include <list>
using namespace sf;
using namespace std;

//####################################      variables       ##########################################


int maze_level_one[21][25]
{
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, // 1
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, // 2
	1, 4, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 4, 1, // 3
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, // 4
	1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, // 5
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, // 6
	1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, // 7
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, // 8
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 5, 5, 5, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, // 9
	1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, // 10
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, // 11
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, // 12
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, // 13
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, // 14
	1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, // 15
	1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, // 16
	1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, // 17
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, // 18
	1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, // 19
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, // 20
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 // 21
};

int maze_level_two[42][50]
{
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 4, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 4, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 5, 5, 5, 5, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 5, 5, 6, 5, 5, 5, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
	1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
	1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1

};

int maze_level_three[42][50]
{
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1,
	1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 1, 1, 1, 5, 5, 5, 1, 1, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0 ,1, 0, 0, 0, 1, 0, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1,
	1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
	1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1,
	1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
	1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,
	1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

};
int maze[42][50];
char tmp_maze[42][50];

//_________________________________________________________________________________________________________________________________________________________

struct walk {
	int  walk_count;
	int back;
	int x;
	int y;
};



struct target {
	int x;
	int y;
};





vector<walk> BFSArray_blinky;
vector<target> walk_queue_blinky;

vector<walk> BFSArray_pinky;
vector<target> walk_queue_pinky;


vector<walk> BFSArray_inky;
vector<target> walk_queue_inky;


vector<walk> BFSArray_cludy;
vector<target> walk_queue_cludy;


vector < pair < int, string >> _rank;

//_________________________________________________________________________________________________________________________________________________________

map <string, int > rankp;

//_______________________________________________________________________________________________________________________________________________________
//pacman himself
Texture pac_man_photo2;
Sprite sprite2;

//pacman himself
Texture pac_man_photo3;
Sprite sprite3;




Texture fri_;
Sprite fri;



//pacman himself
Texture pac_man_photo4;
Sprite sprite4;


//pacman himself
Texture pac_man_photo5;
Sprite sprite5;


//pacman himself
Texture pac_man_photo1;
Sprite sprite1;

Texture pac_man_photo6;
Sprite sprite6;





/*
Keeps the last direction the user has chosen
it will help to keep pacman moving on that direction when the user is not pressing any key

*/
//select levels
bool level1 = 1,
level2 = 0,
level3 = 0;
const int k = 42;
const int m = 50;
const int w = 21;
const int v = 25;
int speed;
int level_number = 1;
int last = 0;
int blx = 12,
bly = 11;


int ilx = 12,
ily = 11;

int clx = 12,
cly = 11;

int plx,
ply;
//counting score
int score = 0;
//loop music

int i;
//pacman position
int pacman_x = 12, pacman_y = 15;


// dots
CircleShape dot;

//pac_dots
CircleShape pac_dot;



//pacman himself
Texture pac_man_photo;
Sprite sprite;


// blue wall of the maze
RectangleShape wall;

//window
sf::RenderWindow window(sf::VideoMode(1050, 960, 32), "pacman");



//score photo
Texture score_photo;
Sprite score_sprite;

//pacman life
Texture life_tex[3];
Sprite life_spr[3];
vector < int > n;


Texture blinky_;
Sprite blinky;



Texture pinky_;
Sprite pinky;


Texture cludy_;
Sprite cludy;


Texture inky_;
Sprite inky;









bool menu_ = 1, game = 0, abo = 0, start = 0;
bool menu2_ = 0, game2 = 0;
bool sou = 0, sou1 = 0;
bool sou2 = 0, sou3 = 0;
bool sou4 = 0;
int frame = 0;
bool le1 = 0, le2 = 0, le3 = 0, le4 = 0, le5 = 0, le6 = 0;
sf::Vector2f pos_rotate;

int casep = 1;



bool q1 = 0, q2 = 0, q3 = 0, q4 = 0, q5 = 0, q6 = 0;

bool mood = 0;


bool el_shab7 = 0;
//##################################  the  end  #######################################






















//################################### functions #######################################
// Display Function
/*
this function will display the maze which was shown above
*/


void display_maze()
{

	window.clear();
	window.draw(score_sprite);
	if (!mood)
	{
		window.draw(pinky);
		window.draw(cludy);
		window.draw(inky);
		window.draw(blinky);

	}
	if (mood)
	{




	}
	for (int j = 0; j < 25 * level_number; j++)

	{
		for (int i = 0; i < 21 * level_number; i++)

		{
			if (maze[i][j] == 0)
			{
				dot.setPosition(j * (42 / level_number) + (10 / level_number), i * (42 / level_number) + (10 / level_number));
				window.draw(dot);

			}
			/*else*/ if (maze[i][j] == 1)
			{
				wall.setPosition(j * (42 / level_number), i * (42 / level_number));
				window.draw(wall);

			}
			/*else*/ if (maze[i][j] == 3)
			{

				pos_rotate = sprite.getPosition();
				sprite.setPosition(pos_rotate.x + 15 / level_number, pos_rotate.y + 15 / level_number);
				if (q1)
				{

					sprite1.setPosition(pos_rotate.x , pos_rotate.y );

					sprite1.setScale(0.036 / level_number, 0.036 / level_number);
					window.draw(sprite1);
				}
				else if (q2)
				{

					sprite2.setPosition(pos_rotate.x, pos_rotate.y );

					sprite2.setScale(0.025 / level_number, 0.025 / level_number);
					window.draw(sprite2);

				}
				else if (q3)
				{
					sprite3.setPosition(pos_rotate.x , pos_rotate.y );

					sprite3.setScale(0.02 / level_number, 0.02 / level_number);

					window.draw(sprite3);

				}
				else if (q4)
				{
					sprite4.setPosition(pos_rotate.x , pos_rotate.y);

					sprite4.setScale(0.085 / level_number, 0.085 / level_number);

					window.draw(sprite4);

				}
				else if (q5)
				{
					sprite5.setPosition(pos_rotate.x , pos_rotate.y);

					sprite5.setScale(0.08 / level_number, 0.08 / level_number);

					window.draw(sprite5);

				}
				else if (q6)
				{


					sprite.setScale(0.015 / level_number, 0.015 / level_number);

					window.draw(sprite);

				}
				sprite.setPosition(pos_rotate.x, pos_rotate.y);



			}
			else if (maze[i][j] == 4)
			{
				pac_dot.setPosition(j * (42 / level_number) + (5 / level_number), i * (42 / level_number) + (5 / level_number));
				window.draw(pac_dot);

			}




		}

	}

	stringstream ss;
	Text scoretext;
	Font font;
	font.loadFromFile("FFF Tusj Bold.ttf");
	scoretext.setFont(font);
	ss << score;
	scoretext.setString(ss.str());
	scoretext.setFillColor(Color::Yellow);
	scoretext.setCharacterSize(36);
	scoretext.setPosition(160, 900);
	window.draw(scoretext);


}




















// moving pacman function
/*
this function moves pacman form his position and updates the maze according to his moves
it tackes only one sing paramerter which is the diriction of his movment from the and it comes from the in put function
if the variable dir(dirction) rqales :
1 --> pacman will move upwords
2 --> pacman will move dawnwords
3 --> pacman will move to the right
4 --> pacman will move to the left
*/
void moving_pacman(int dir)
{
	sf::Vector2f pos = sprite.getPosition();
	if (dir == 1)
	{

		if (int((pos.y - 1) / (42 / level_number)) >= 0 && maze[int((pos.y - 1) / (42 / level_number))][int(pos.x / (42 / level_number))] != 1)
		{
			if (maze[int((pos.y - 1) / (42 / level_number))][int(pos.x / (42 / level_number))] == 0)
			{
				maze[int((pos.y - 1) / (42 / level_number))][int(pos.x / (42 / level_number))] = 2;
				score++;
			}
			if (maze[int((pos.y - 1) / (42 / level_number))][int(pos.x / (42 / level_number))] == 4)
			{
				maze[int((pos.y - 1) / (42 / level_number))][int(pos.x / (42 / level_number))] = 2;
				score += 50;
				mood = 1;
			}
			sprite.move(0, -speed);
			sprite.setRotation(270);

			pos_rotate = sprite.getPosition();
			sprite.setPosition(pos_rotate.x + 15 / level_number, pos_rotate.y + 15 / level_number);
			if (q1)
			{

				sprite1.setPosition(pos_rotate.x , pos_rotate.y );

				sprite1.setScale(0.036 / level_number, 0.036 / level_number);
				window.draw(sprite1);
			}
			else if (q2)
			{

				sprite2.setPosition(pos_rotate.x , pos_rotate.y );

				sprite2.setScale(0.025 / level_number, 0.025 / level_number);
				window.draw(sprite2);

			}
			else if (q3)
			{
				sprite3.setPosition(pos_rotate.x , pos_rotate.y );

				sprite3.setScale(0.02 / level_number, 0.02 / level_number);

				window.draw(sprite3);

			}
			else if (q4)
			{
				sprite4.setPosition(pos_rotate.x , pos_rotate.y );

				sprite4.setScale(0.085 / level_number, 0.085 / level_number);

				window.draw(sprite4);

			}
			else if (q5)
			{
				sprite5.setPosition(pos_rotate.x , pos_rotate.y );

				sprite5.setScale(0.08 / level_number, 0.08 / level_number);

				window.draw(sprite5);

			}
			else if (q6)
			{


				sprite.setScale(0.015 / level_number, 0.015 / level_number);

				window.draw(sprite);

			}
			sprite.setPosition(pos_rotate.x, pos_rotate.y);

		}

	}
	else if (dir == 2)
	{

		if (int((pos.y + 1) / (42 / level_number)) + 1 < (21 * level_number) && maze[int((pos.y + 1) / (42 / level_number)) + 1][int(pos.x / (42 / level_number))] != 1)
		{
			if (maze[int((pos.y + 1) / (42 / level_number)) + 1][int(pos.x / (42 / level_number))] == 0)
			{
				maze[int((pos.y + 1) / (42 / level_number)) + 1][int(pos.x / (42 / level_number))] = 2;
				score++;
			}
			if (maze[int((pos.y + 1) / (42 / level_number)) + 1][int(pos.x / (42 / level_number))] == 4)
			{
				maze[int((pos.y + 1) / (42 / level_number)) + 1][int(pos.x / (42 / level_number))] = 2;
				score += 50;
				mood = 1;
			}
			sprite.move(0, speed);
			sprite.setRotation(90);

			pos_rotate = sprite.getPosition();
			sprite.setPosition(pos_rotate.x + 15 / level_number, pos_rotate.y + 15 / level_number);
			if (q1)
			{

				sprite1.setPosition(pos_rotate.x , pos_rotate.y);

				sprite1.setScale(0.036 / level_number, 0.036 / level_number);
				window.draw(sprite1);
			}
			else if (q2)
			{

				sprite2.setPosition(pos_rotate.x , pos_rotate.y );

				sprite2.setScale(0.025 / level_number, 0.025 / level_number);
				window.draw(sprite2);

			}
			else if (q3)
			{
				sprite3.setPosition(pos_rotate.x / level_number, pos_rotate.y / level_number);

				sprite3.setScale(0.02 / level_number, 0.02 / level_number);

				window.draw(sprite3);

			}
			else if (q4)
			{
				sprite4.setPosition(pos_rotate.x , pos_rotate.y );

				sprite4.setScale(0.085 / level_number, 0.085 / level_number);

				window.draw(sprite4);

			}
			else if (q5)
			{
				sprite5.setPosition(pos_rotate.x , pos_rotate.y );

				sprite5.setScale(0.08 / level_number, 0.08 / level_number);

				window.draw(sprite5);

			}
			else if (q6)
			{


				sprite.setScale(0.015 / level_number, 0.015 / level_number);

				window.draw(sprite);

			}
			sprite.setPosition(pos_rotate.x, pos_rotate.y);
		}

		else if (int(pos.y + 1) % (42 / level_number) == 0)
		{
			sprite.move(0, speed);
			sprite.setRotation(90);

		}

	}
	else if (dir == 3)
	{
		if (maze[int(pos.y / (42 / level_number))][int((pos.x + 1) / (42 / level_number)) + 1] != 5)
		{
			if (int((pos.x + 1) / (42 / level_number)) + 1 < (25 * level_number) && maze[int(pos.y / (42 / level_number))][int((pos.x + 1) / (42 / level_number)) + 1] != 1)
			{
				if (maze[int(pos.y / (42 / level_number))][int((pos.x + 1) / (42 / level_number)) + 1] == 0)
				{
					maze[int(pos.y / (42 / level_number))][int((pos.x + 1) / (42 / level_number)) + 1] = 2;
					score++;
				}
				if (maze[int(pos.y / (42 / level_number))][int((pos.x + 1) / (42 / level_number)) + 1] == 4)
				{
					maze[int(pos.y / (42 / level_number))][int((pos.x + 1) / (42 / level_number)) + 1] = 2;
					score += 50;
					mood = 1;
				}
				sprite.move(speed, 0);
				sprite.setRotation(0);


				pos_rotate = sprite.getPosition();
				sprite.setPosition(pos_rotate.x + 15 / level_number, pos_rotate.y + 15 / level_number);
				if (q1)
				{

					sprite1.setPosition(pos_rotate.x , pos_rotate.y );

					sprite1.setScale(0.036 / level_number, 0.036 / level_number);
					window.draw(sprite1);
				}
				else if (q2)
				{

					sprite2.setPosition(pos_rotate.x , pos_rotate.y );

					sprite2.setScale(0.025 / level_number, 0.025 / level_number);
					window.draw(sprite2);

				}
				else if (q3)
				{
					sprite3.setPosition(pos_rotate.x , pos_rotate.y );

					sprite3.setScale(0.02 / level_number, 0.02 / level_number);

					window.draw(sprite3);

				}
				else if (q4)
				{
					sprite4.setPosition(pos_rotate.x , pos_rotate.y );

					sprite4.setScale(0.085 / level_number, 0.085 / level_number);

					window.draw(sprite4);

				}
				else if (q5)
				{
					sprite5.setPosition(pos_rotate.x , pos_rotate.y );

					sprite5.setScale(0.08 / level_number, 0.08 / level_number);

					window.draw(sprite5);

				}
				else if (q6)
				{


					sprite.setScale(0.015 / level_number, 0.015 / level_number);

					window.draw(sprite);

				}
				sprite.setPosition(pos_rotate.x, pos_rotate.y);
			}
			else if (int(pos.x + 1) % (42 / level_number) == 0)
			{
				sprite.move(speed, 0);
				sprite.setRotation(0);

			}
		}
	}
	else if (dir == 4)
	{
		if (maze[int(pos.y / (42 / level_number))][int((pos.x - 1) / (42 / level_number))] != 5)
		{
			if ((int(pos.x - 1) / (42 / level_number)) - 1 >= 0 && maze[int(pos.y / (42 / level_number))][int((pos.x - 1) / (42 / level_number))] != 1)
			{
				if (maze[int(pos.y / (42 / level_number))][int((pos.x - 1) / (42 / level_number))] == 0)
				{
					maze[int(pos.y / (42 / level_number))][int((pos.x - 1) / (42 / level_number))] = 2;
					score++;
				}
				if (maze[int(pos.y / (42 / level_number))][int((pos.x - 1) / (42 / level_number))] == 4)
				{
					maze[int(pos.y / (42 / level_number))][int((pos.x - 1) / (42 / level_number))] = 2;
					score += 50;
					mood = 1;
				}
				sprite.move(-speed, 0);
				sprite.setRotation(180);


				pos_rotate = sprite.getPosition();
				sprite.setPosition(pos_rotate.x + 15 , pos_rotate.y + 15 );
				if (q1)
				{

					sprite1.setPosition(pos_rotate.x , pos_rotate.y );

					sprite1.setScale(0.036 / level_number, 0.036 / level_number);
					window.draw(sprite1);
				}
				else if (q2)
				{

					sprite2.setPosition(pos_rotate.x / level_number, pos_rotate.y / level_number);

					sprite2.setScale(0.025 / level_number, 0.025 / level_number);
					window.draw(sprite2);

				}
				else if (q3)
				{
					sprite3.setPosition(pos_rotate.x , pos_rotate.y );

					sprite3.setScale(0.02 / level_number, 0.02 / level_number);

					window.draw(sprite3);

				}
				else if (q4)
				{
					sprite4.setPosition(pos_rotate.x , pos_rotate.y );

					sprite4.setScale(0.085 / level_number, 0.085 / level_number);

					window.draw(sprite4);

				}
				else if (q5)
				{
					sprite5.setPosition(pos_rotate.x , pos_rotate.y );

					sprite5.setScale(0.08 / level_number, 0.08 / level_number);

					window.draw(sprite5);

				}
				else if (q6)
				{


					sprite.setScale(0.015 / level_number, 0.015 / level_number);

					window.draw(sprite);

				}
				sprite.setPosition(pos_rotate.x, pos_rotate.y);

			}
		}
	}


}

















/*
2.	get diriction function
this function will get the diriction from the user and send it to "moving_pacman" function

how it works:
firstly it gets pacman position andchecks if its possible to move or not in this position
(note that : pacman can move only if its x and y position is divisible by 42
And that’s because I set a square of 42 x 42 pixels for each element as I said befor)

If the user pressed:
Up arrow
It will call the function which will move it upwards to move pacman (if its possible of course)
and to increment his scour if ther was a dot in that index

*/

void get_diriction(int& last)
{

	sf::Vector2f pos = sprite.getPosition();

	if (abs(pos.x - int(pos.x)) == 0 && abs(pos.y - int(pos.y)) == 0
		&& int(pos.y) % (42 / level_number) == 0 && int(pos.x) % (42 / level_number) == 0)
	{
		if (abs(pos.y - int(pos.y)) == 0 && int(pos.y) % (42 / level_number) == 0 && Keyboard::isKeyPressed(Keyboard::Up)
			&& int((pos.y - 1) / (42 / level_number)) >= 0 && maze[int((pos.y - 1) / (42 / level_number))][int(pos.x / (42 / level_number))] != 1)
		{
			moving_pacman(1);
			last = 1;
		}
		else if (abs(pos.y - int(pos.y)) == 0 && int(pos.y) % (42 / level_number) == 0 && Keyboard::isKeyPressed(Keyboard::Down)
			&& int((pos.y + 1) / (42 / level_number)) + 1 < (21 * level_number) && maze[int((pos.y + 1) / (42 / level_number)) + 1][int(pos.x / (42 / level_number))] != 1)
		{
			moving_pacman(2);
			last = 2;
		}
		else if (abs(pos.x - int(pos.x)) == 0 && Keyboard::isKeyPressed(Keyboard::Right)
			&& int((pos.x + 1) / (42 / level_number)) + 1 < (25 * level_number) && maze[int(pos.y / (42 / level_number))][int((pos.x + 1) / (42 / level_number)) + 1] != 1)
		{
			moving_pacman(3);
			last = 3;
		}
		else if (abs(pos.x - int(pos.x)) == 0 && int(pos.x) % (42 / level_number) == 0 && Keyboard::isKeyPressed(Keyboard::Left)
			&& (int(pos.x - 1) / (42 / level_number)) - 1 >= 0 && maze[int(pos.y / (42 / level_number))][int((pos.x - 1) / (42 / level_number))] != 1)
		{
			moving_pacman(4);
			last = 4;
		}
		else
		{
			moving_pacman(last);

		}
	}
	else
	{
		moving_pacman(last);

	}



}

//selecr level
void select_level(bool level10, bool level20, bool level30)

{
	if (level10 == 1 && level20 == 0 && level30 == 0)
	{
		maze[w][v];
		level_number = 1;
		speed = 3;
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				maze[i][j] = maze_level_one[i][j];

			}

		}


	}
	else if (level10 == 0 && level20 == 1 && level30 == 0)
	{
		maze[k][m];
		level_number = 2;
		speed = 3;
		// dots
		dot.setRadius(4 / level_number);

		//pac_dots
		pac_dot.setRadius(12 / level_number);



		blinky.setPosition(24 * 21, 14 * 21);
		window.draw(blinky);
		pinky.setPosition(24 * 21, 14 * 21);
		window.draw(pinky);
		inky.setPosition(24 * 21, 14 * 21);
		window.draw(inky);
		cludy.setPosition(24 * 21, 14 * 21);
		window.draw(cludy);




		//wall designe
		wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
		wall.setFillColor(Color(0, 0, 0));
		wall.setOutlineThickness(5 / (level_number));
		wall.setOutlineColor(sf::Color(0, 0, 2000000));
		blinky.setScale(0.15 / level_number, 0.15 / level_number);
		sprite.setScale(0.015 / level_number, 0.015 / level_number);

		inky.setScale(0.3 / level_number, 0.3 / level_number);
		cludy.setScale(0.3 / level_number, 0.3 / level_number);
		pinky.setScale(0.3 / level_number, 0.3 / level_number);
		fri.setScale(0.1 / level_number, 0.1 / level_number);

		sf::Vector2f pos_pinky = pinky.getPosition();
		sf::Vector2f pos_inky = pinky.getPosition();
		sf::Vector2f pos_cludy = pinky.getPosition();

		sf::Vector2f pos_rand = pinky.getPosition();
		pos_rand.x = pos_pinky.x / 42;
		pos_rand.y = pos_pinky.y / 42;

		sf::Vector2f pos_rand1 = inky.getPosition();
		pos_rand1.x = pos_inky.x / 42;
		pos_rand1.y = pos_inky.y / 42;


		sf::Vector2f pos_rand2 = cludy.getPosition();
		pos_rand2.x = pos_cludy.x / 42;
		pos_rand2.y = pos_cludy.y / 42;

		pos_rand.x = pos_pinky.x  * level_number / 42;
		pos_rand.y = pos_pinky.y  * level_number / 42;

		pos_rand1.x = pos_inky.x  * level_number / 42;
		pos_rand1.y = pos_inky.y  * level_number / 42;

		pos_rand2.x = pos_cludy.x * level_number / 42;
		pos_rand2.y = pos_cludy.y * level_number / 42;
		memcpy(maze, maze_level_two, sizeof(maze_level_two));
	}
	else if (level10 == 0 && level20 == 0 && level30 == 1)
	{
		maze[k][m];
		level_number = 2;
		speed = 3;

		// dots
		dot.setRadius(4 / level_number);

		//pac_dots
		pac_dot.setRadius(12 / level_number);


		blinky.setPosition(24 * 21, 14 * 21);
		window.draw(blinky);
		pinky.setPosition(24 * 21, 14 * 21);
		window.draw(pinky);
		inky.setPosition(24 * 21, 14 * 21);
		window.draw(inky);
		cludy.setPosition(24 * 21, 14 * 21);
		window.draw(cludy);



		//wall designe
		wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
		wall.setFillColor(Color(0, 0, 0));
		wall.setOutlineThickness(5 / (level_number));
		wall.setOutlineColor(sf::Color(0, 0, 2000000));
		blinky.setScale(0.15 / level_number, 0.15 / level_number);
		sprite.setScale(0.015 / level_number, 0.015 / level_number);
		inky.setScale(0.3 / level_number, 0.3 / level_number);
		cludy.setScale(0.3 / level_number, 0.3 / level_number);
		pinky.setScale(0.3 / level_number, 0.3 / level_number);
		fri.setScale(0.1 / level_number, 0.1 / level_number);

		sf::Vector2f pos_pinky = pinky.getPosition();
		sf::Vector2f pos_inky = pinky.getPosition();
		sf::Vector2f pos_cludy = pinky.getPosition();

		sf::Vector2f pos_rand = pinky.getPosition();
		pos_rand.x = pos_pinky.x / 42;
		pos_rand.y = pos_pinky.y / 42;

		sf::Vector2f pos_rand1 = inky.getPosition();
		pos_rand1.x = pos_inky.x / 42;
		pos_rand1.y = pos_inky.y / 42;


		sf::Vector2f pos_rand2 = cludy.getPosition();
		pos_rand2.x = pos_cludy.x / 42;
		pos_rand2.y = pos_cludy.y / 42;

		pos_rand.x = pos_pinky.x  * level_number / 42;
		pos_rand.y = pos_pinky.y  * level_number / 42;

		pos_rand1.x = pos_inky.x  * level_number / 42;
		pos_rand1.y = pos_inky.y  * level_number / 42;

		pos_rand2.x = pos_cludy.x * level_number / 42;
		pos_rand2.y = pos_cludy.y * level_number / 42;

		memcpy(maze, maze_level_three, sizeof(maze_level_three));
	}
	pacman_x = 12 * level_number;
	pacman_y = 15 * level_number;
}


void change_levels()
{
	if (level1 == 1 && level2 == 0 && level3 == 0 && casep==1 && score == 446)
	{
		level1 == 0;
		level2 == 1;
		level3 == 0;
		select_level(0, 1, 0);
		

	}
	else if (level1 == 0 && level2 == 1 && level3 == 0 && casep == 1&& score == (200 + 1037 + 446))
	{
		level1 == 0;
		level2 == 0;
		level3 == 1;
		select_level(0, 0, 1);
	}
	else if (level1 == 0 && level2 == 0 && level3 == 1 && casep == 1 && score == (200 + 1037 + 446 +200+ 1004))
	{
		level1 == 1;
		level2 == 0;
		level3 == 0;
		casep = 2;
		select_level(1, 0, 0);
	}
	else if (level1 == 1 && level2 == 0 && level3 == 0 && casep == 2 &&  score == (200 + 1037 + 446 +1004 + 200 + 446))
	{
		level1 == 0;
		level2 == 1;
		level3 == 0;
		casep = 2;
		select_level(0, 1, 0);

	}
	else if (level1 == 0 && level2 == 1 && level3 == 0 && casep == 2 && score == (200 + 1037 + 446 + 1004 + 200+ 446 + 200 + 1037))
	{
		level1 == 0;
		level2 == 0;
		level3 == 1;
		casep = 2;
		select_level(0, 0, 1);

	}
	else if (level1 == 0 && level2 == 0 && level3 == 1 && casep == 2 && score == (200 + 1037 + 446 + 1004 + 446 + 200 + 1037 + 200 + 200+ 1004))
	{
		cout << "law ragel e3mlha ya bash :) " << endl;
		el_shab7 = 1;
		select_level(1, 0, 0);
		score = 0;
	}
}






//function that make pacman lose life if the ghosts catches him






//############################################ the end ######################################################

void life() {
	n.push_back(0);
	n.push_back(50);
	n.push_back(100);
	for (int i = 0; i < 3; i++)

	{
		life_tex[i].loadFromFile("heart.jpg");
		life_spr[i].setTexture(life_tex[i]);
		life_spr[i].setScale(0.07, 0.07);
		life_spr[i].setPosition(970 - n[i], 900);

	}
}

void game_over()
{

	sf::Vector2f pos = sprite.getPosition();
	sf::Vector2f pos1 = blinky.getPosition();
	sf::Vector2f pos2 = pinky.getPosition();
	sf::Vector2f pos3 = inky.getPosition();
	sf::Vector2f pos4 = cludy.getPosition();


	if (pos.x * level_number / 42 == pos1.x * level_number / 42 && pos.y * level_number / 42 == pos1.y * level_number / 42
		|| pos.x * level_number / 42 == pos2.x * level_number / 42 && pos.y * level_number / 42 == pos2.y * level_number / 42
		|| pos.x * level_number / 42 == pos3.x * level_number / 42 && pos.y * level_number / 42 == pos3.y * level_number / 42
		|| pos.x * level_number / 42 == pos4.x * level_number / 42 && pos.y * level_number / 42 == pos4.y * level_number / 42
		|| el_shab7==1 )
	{


		blinky.setPosition(12 * 42, 14 * 21);
		window.draw(blinky);
		pinky.setPosition(22 * 21, 14 * 21);
		window.draw(pinky);
		inky.setPosition(26 * 21, 14 * 21);
		window.draw(inky);
		cludy.setPosition(22 * 21, 14 * 21);
		window.draw(cludy);


		if (n.size() > 1 && !el_shab7)
		{
			n.pop_back();
			sprite.setPosition(12 * 42, 15 * 42);
			start = 1;
		}
		else
		{
			if (n.size() <= 1)
				n.pop_back();
			life();
			
			sprite.setPosition(12 * 42, 15 * 42);

			window.clear();
			display_maze();
			for (int i = 0; i < n.size(); i++)
				window.draw(life_spr[i]);
			Texture ENQ_tex;
			Sprite ENQ_spr;
			ENQ_tex.loadFromFile("ENQ.PNG");
			ENQ_spr.setTexture(ENQ_tex);
			ENQ_spr.setScale(1, 1);
			ENQ_spr.setPosition(25, 15);




			RectangleShape rec;
			rec.setSize(sf::Vector2f(450, 35));
			rec.setFillColor(Color(0, 0, 0));
			rec.setOutlineThickness(5);
			rec.setOutlineColor(sf::Color(0, 0, 2000, 50));
			rec.setPosition(25, 60);

			Texture ok_tex;
			Sprite ok_spr;
			ok_tex.loadFromFile("ok.png");
			ok_spr.setTexture(ok_tex);
			ok_spr.setScale(1, 1);
			ok_spr.setPosition(300, 115);

			Texture ignore_tex;
			Sprite ignore_spr;
			ignore_tex.loadFromFile("ignore.png");
			ignore_spr.setTexture(ignore_tex);
			ignore_spr.setScale(1, 0.90);
			ignore_spr.setPosition(25, 105);
			string playername = " ";

			map<string, int> rank;
			RenderWindow ENwindow(VideoMode(500, 200, 32), "Enter name for the rank :) ");
			while (ENwindow.isOpen())
			{
				Event ENevent;

				while (ENwindow.pollEvent(ENevent))
				{
					if (ENevent.type == Event::Closed)
						ENwindow.close();

					ENwindow.display();
					ENwindow.clear();
					ENwindow.draw(ENQ_spr);
					ENwindow.draw(rec);
					ENwindow.draw(ok_spr);
					ENwindow.draw(ignore_spr);


					if (ENevent.key.code == sf::Keyboard::BackSpace)
					{
						if (!playername.empty())
						{
							playername.pop_back();
						}
					}
					else if (ENevent.type == sf::Event::TextEntered)
					{
						if (ENevent.text.unicode < 128)
							playername += static_cast<char>(ENevent.text.unicode);
					}
					stringstream input;
					string player;


					Text playerinput;
					Font fontplayer;
					fontplayer.loadFromFile("FFF Tusj Bold.ttf");
					playerinput.setFont(fontplayer);
					input << playername;
					playerinput.setString(input.str());
					playerinput.setFillColor(Color::Yellow);
					playerinput.setCharacterSize(28);
					playerinput.setPosition(25, 60);
					ENwindow.draw(playerinput);

				}

				if (ok_spr.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(ENevent.mouseButton.x, ENevent.mouseButton.y))))
				{
					if (playername.size() == 1)
					{
						start = 1;
						menu_ = 0;
						game = 0;
						menu2_ = 0;
						game2 = 1;
						sou = 0;
						sou1 = 0;
						sou2 = 0;
						sou3 = 0;
						sou4 = 0;
						frame = 0;
						le1 = 0;
						le2 = 0;
						le3 = 0;
						le4 = 0;
						le5 = 0;
						le6 = 0;
						score = 0;

						sprite.setPosition(12 * 42, 15 * 42);
						window.clear();
						ENwindow.close();
					}

					if (rankp[playername] < score)
					{
						rankp[playername] = score;
						
						_rank.clear();
						for (auto i = rankp.begin(); i != rankp.end(); ++i) {

							int a = i->second;
							string b = i->first;

							_rank.push_back({ a ,b });

						}
						sort(_rank.rbegin(), _rank.rend());
						ofstream outfile;
						outfile.open("LeaderBoard.txt");


						// write inputted data into the file.

						for (int i = 0; i < _rank.size(); ++i) {

							outfile << _rank[i].second << endl;
							outfile << _rank[i].first << endl;

						}
						outfile.close();

					}
					start = 1;
					menu_ = 0;
					game = 0;
					menu2_ = 0;
					game2 = 1;
					sou = 0;
					sou1 = 0;
					sou2 = 0;
					sou3 = 0;
					sou4 = 0;
					frame = 0;
					le1 = 0;
					le2 = 0;
					le3 = 0;
					le4 = 0;
					le5 = 0;
					le6 = 0;
					score = 0;

					sprite.setPosition(12 * 42, 15 * 42);
					window.clear();
					ENwindow.close();
				}
				else if (ignore_spr.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(ENevent.mouseButton.x, ENevent.mouseButton.y))))
				{
					start = 1;
					menu_ = 0;
					game = 0;
					menu2_ = 0;
					game2 = 1;
					sou = 0;
					sou1 = 0;
					sou2 = 0;
					sou3 = 0;
					sou4 = 0;
					frame = 0;
					le1 = 0;
					le2 = 0;
					le3 = 0;
					le4 = 0;
					le5 = 0;
					le6 = 0;
					score = 0;
					window.clear();
					ENwindow.close();
				}

			}
		}
	}
}









//################################# gostes ########################################







void AddArray(int x, int y, int walk_count, int back, vector<walk>& BFSArray) {
	if (tmp_maze[y][x] != 1)
	{

		tmp_maze[y][x] = 1;
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = walk_count;
		tmp.back = back;
		BFSArray.push_back(tmp);
	}
}



void FindPath(int blinky_x, int blinky_y, int pacman_x, int pacman_y, vector<walk> &BFSArray, vector<target>& walk_queue)
{

	for (int i = 0; i < 21 * level_number; i++)
	{
		for (int j = 0; j < 25 * level_number; j++)
		{
			tmp_maze[i][j] = maze[i][j];

		}

	}
	BFSArray.clear();
	walk tmp;
	tmp.x = blinky_x;
	tmp.y = blinky_y;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back(tmp);




	float i = 0;
	while (i < BFSArray.size())
	{
		target tmp2;
		if (BFSArray[i].x == pacman_x && BFSArray[i].y == pacman_y)
		{

			walk_queue.clear();
			target tmp2;
			while (BFSArray[i].walk_count != 0)
			{

				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back(tmp2);
				i = BFSArray[i].back;

			}
			break;

		}
		AddArray(BFSArray[i].x + 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i, BFSArray);
		AddArray(BFSArray[i].x - 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i, BFSArray);
		AddArray(BFSArray[i].x, BFSArray[i].y + 1, BFSArray[i].walk_count + 1, i, BFSArray);
		AddArray(BFSArray[i].x, BFSArray[i].y - 1, BFSArray[i].walk_count + 1, i, BFSArray);

		i++;

	}

	BFSArray.clear();
}























//############################################ the end ######################################################

int  main()
{


	string lol1, lolo1;
	ifstream infile;
	infile.open("LeaderBoard.txt");
	for (int i = 0; i < 10; ++i) {
		if (!infile.eof())
		{
			getline(infile, lol1);
			getline(infile, lolo1);
			int iu;

			std::istringstream(lolo1) >> iu;
			_rank.push_back({ iu ,lol1 });


		}



	}

	for (int i = 0; i < _rank.size(); i++)
	{
		int a = _rank[i].first;
		string b = _rank[i].second;
		rankp[b] = a;
	}






	// dots
	dot.setRadius(4 / level_number);

	//pac_dots
	pac_dot.setRadius(12 / level_number);


	//wall designe
	wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
	wall.setFillColor(Color(0, 0, 0));
	wall.setOutlineThickness(5 / (level_number));
	wall.setOutlineColor(sf::Color(0, 0, 2000000));

	//dot designe
	dot.setFillColor(Color::White);

	//pac_dot design
	pac_dot.setFillColor(Color::White);

	//gitting pac man photo and scaleing it



	pac_man_photo.loadFromFile("pacman-.png");
	sprite.setTexture(pac_man_photo);
	sprite.setScale(0.015 / level_number, 0.015 / level_number);
	sprite.setPosition(12 * 42, 15 * 42);
	sprite.setOrigin(30 * 42, 30 * 42 + 10);
	q1 = 1;

	blinky_.loadFromFile("redghost.JPEG");
	blinky.setTexture(blinky_);
	blinky.setScale(0.15 / level_number, 0.15 / level_number);


	pinky_.loadFromFile("pinky.jpeg");
	pinky.setTexture(pinky_);
	pinky.setScale(0.3, 0.3);


	inky_.loadFromFile("incky.jpeg");
	inky.setTexture(inky_);
	inky.setScale(0.3, 0.3);


	cludy_.loadFromFile("culdy.jpeg");
	cludy.setTexture(cludy_);
	cludy.setScale(0.3, 0.3);

	fri_.loadFromFile("fri.png");
	fri.setTexture(fri_);
	fri.setScale(0.1 / level_number, 0.1 / level_number);



	blinky.setPosition(24 * 21, 14 * 21);
	window.draw(blinky);
	pinky.setPosition(24 * 21, 14 * 21);
	window.draw(pinky);
	inky.setPosition(24 * 21, 14 * 21);
	window.draw(inky);
	cludy.setPosition(24 * 21, 14 * 21);
	window.draw(cludy);
	int blx = 24;
	int bly = 14;

	//three life of pacman
	/*void life() {
	n.push_back(0);
	n.push_back(50);
	n.push_back(100);
	for (int i = 0; i < 3; i++)

	{
		life_tex[i].loadFromFile("heart.jpg");
		life_spr[i].setTexture(life_tex[i]);
		life_spr[i].setScale(0.07, 0.07);
		life_spr[i].setPosition(970 - n[i], 900);

	}
}*/
	
	life();

	sf::Music music;
	if (!music.openFromFile("sound2.WAV"))
		return -1;
	/*Texture texturepa;
	textureBackground.loadFromFile("pa.PNG");
	Sprite spritepa;
	spritepa.setTexture(texturepa);
	spritepa.setPosition(0, 0);*/

	Texture pac;
	Sprite sp;
	pac.loadFromFile("name.PNG");
	sp.setTexture(pac);
	sp.setScale(0.5, 0.5);
	sp.setPosition(150, 5);



	Texture dev_;
	Sprite dev;
	dev_.loadFromFile("dev.PNG");
	dev.setTexture(dev_);
	dev.setScale(0.2, 0.2);
	dev.setPosition(400, 700);


	Texture pl;
	Sprite play;
	pl.loadFromFile("play.PNG");
	play.setTexture(pl);
	play.setScale(0.1, 0.1);
	play.setPosition(30 * 15, 30 * 10);

	Texture op;
	Sprite option;
	op.loadFromFile("option.PNG");
	option.setTexture(op);
	option.setScale(0.1, 0.1);
	option.setPosition(30 * 15, 30 * 15);

	Texture ra;
	Sprite rank;
	ra.loadFromFile("rank.PNG");
	rank.setTexture(ra);
	rank.setScale(0.1, 0.1);
	rank.setPosition(30 * 15, 30 * 20);

	Texture se;
	Sprite setting;
	se.loadFromFile("setting.PNG");
	setting.setTexture(se);
	setting.setScale(0.1, 0.1);
	setting.setPosition(30 * 15, 30 * 25);

	Texture s;
	Sprite about;
	s.loadFromFile("about.PNG");
	about.setTexture(s);
	about.setScale(0.1, 0.1);
	about.setPosition(30, 30 * 30);

	Texture ex;
	Sprite exit;
	ex.loadFromFile("exit.PNG");
	exit.setTexture(ex);
	exit.setScale(0.1, 0.1);
	exit.setPosition(30 * 29, 30 * 30);

	Texture l1;
	Sprite level1;
	l1.loadFromFile("level1.png");
	level1.setTexture(l1);
	level1.setScale(0.1, 0.1);
	level1.setPosition(60, 42 * 2);
	Texture l2;
	Sprite level2;
	l2.loadFromFile("level2.png");
	level2.setTexture(l2);
	level2.setScale(0.1, 0.1);
	level2.setPosition(60, 42 * 5);

	Texture l3;
	Sprite level3;
	l3.loadFromFile("level3.png");
	level3.setTexture(l3);
	level3.setScale(0.1, 0.1);
	level3.setPosition(60, 42 * 8);

	Texture l4;
	Sprite level4;
	l4.loadFromFile("level4.png");
	level4.setTexture(l4);
	level4.setScale(0.1, 0.1);
	level4.setPosition(60, 42 * 11);

	Texture l5;
	Sprite level5;
	l5.loadFromFile("level5.png");
	level5.setTexture(l5);
	level5.setScale(0.1, 0.1);
	level5.setPosition(60, 42 * 14);

	Texture l6;
	Sprite level6;
	l6.loadFromFile("level6.png");
	level6.setTexture(l6);
	level6.setScale(0.1, 0.1);
	level6.setPosition(60, 42 * 17);









	Texture ll1;
	Sprite lvel1;
	ll1.loadFromFile("1.png");
	lvel1.setTexture(ll1);
	lvel1.setScale(0.1, 0.1);
	lvel1.setPosition(800, 42 * 2);
	Texture ll2;
	Sprite lvel2;
	ll2.loadFromFile("2.png");
	lvel2.setTexture(ll2);
	lvel2.setScale(0.1, 0.1);
	lvel2.setPosition(800, 42 * 5);

	Texture ll3;
	Sprite lvel3;
	ll3.loadFromFile("2.png");
	lvel3.setTexture(ll3);
	lvel3.setScale(0.1, 0.1);
	lvel3.setPosition(800, 42 * 8);

	Texture ll4;
	Sprite lvel4;
	ll4.loadFromFile("1.png");
	lvel4.setTexture(ll4);
	lvel4.setScale(0.1, 0.1);
	lvel4.setPosition(800, 42 * 11);

	Texture ll5;
	Sprite lvel5;
	ll5.loadFromFile("2.png");
	lvel5.setTexture(ll5);
	lvel5.setScale(0.1, 0.1);
	lvel5.setPosition(800, 42 * 14);

	Texture ll6;
	Sprite lvel6;
	ll6.loadFromFile("2.png");
	lvel6.setTexture(ll6);
	lvel6.setScale(0.1, 0.1);
	lvel6.setPosition(800, 42 * 17);



	bool ma = 0, mo = 0, me = 0, mi = 0;



	Texture on;
	Sprite ON;
	on.loadFromFile("on.jpeg");
	ON.setTexture(on);
	ON.setScale(2, 2);
	ON.setPosition(20, 20);


	Texture off;
	Sprite OFF;
	off.loadFromFile("off.jpeg");
	OFF.setTexture(off);
	OFF.setScale(2, 2);
	OFF.setPosition(20, 20);


	Texture back;
	Sprite BACK;
	back.loadFromFile("pack.jpeg");
	BACK.setTexture(back);
	BACK.setScale(2, 2);
	BACK.setPosition(900, 5);
	int lol = 0;






	Texture k;
	Sprite CK;
	k.loadFromFile("lo.png");
	CK.setTexture(k);
	CK.setScale(0.9, 0.9);
	CK.setPosition(0, 100);

	//gitting pac man photo and scaleing it
	pac_man_photo1.loadFromFile("pacman1-.JPEG");
	sprite1.setTexture(pac_man_photo1);
	sprite1.setScale(0.25 / level_number, 0.25 / level_number);
	sprite1.setPosition(2 * 42, 8 * 42);


	//gitting pac man photo and scaleing it
	pac_man_photo2.loadFromFile("pacman2-.JPEG");
	sprite2.setTexture(pac_man_photo2);
	sprite2.setScale(0.15 / level_number, 0.15 / level_number);
	sprite2.setPosition(18 * 42, 8 * 42);


	//gitting pac man photo and scaleing it
	pac_man_photo3.loadFromFile("pacman3-.JPEG");
	sprite3.setTexture(pac_man_photo3);
	sprite3.setScale(0.15 / level_number, 0.15 / level_number);
	sprite3.setPosition(2 * 42, 15 * 42);

	//gitting pac man photo and scaleing it
	pac_man_photo4.loadFromFile("pacman4-.JPEG");
	sprite4.setTexture(pac_man_photo4);
	sprite4.setScale(0.45 / level_number, 0.45 / level_number);
	sprite4.setPosition(18 * 42, 15 * 42);

	//gitting pac man photo and scaleing it
	pac_man_photo5.loadFromFile("pacman5-.JPEG");
	sprite5.setTexture(pac_man_photo5);
	sprite5.setScale(0.45 / level_number, 0.45 / level_number);
	sprite5.setPosition(10 * 42, 15 * 42);



	//gitting pac man photo and scaleing it
	pac_man_photo6.loadFromFile("pacman-.png");
	sprite6.setTexture(pac_man_photo6);
	sprite6.setScale(0.06 / level_number, 0.06 / level_number);
	sprite6.setPosition(10 * 42, 8 * 42);


	int kira = 0;





	//the photo of the score
	score_photo.loadFromFile("score.PNG");
	score_sprite.setTexture(score_photo);
	score_sprite.setScale(0.40, 0.40);
	score_sprite.setPosition(5, 900);
	sf::Vector2f pos_pinky = pinky.getPosition();
	sf::Vector2f pos_inky = pinky.getPosition();
	sf::Vector2f pos_cludy = pinky.getPosition();

	sf::Vector2f pos_rand = pinky.getPosition();
	pos_rand.x = pos_pinky.x / 42;
	pos_rand.y = pos_pinky.y / 42;

	sf::Vector2f pos_rand1 = inky.getPosition();
	pos_rand1.x = pos_inky.x / 42;
	pos_rand1.y = pos_inky.y / 42;


	sf::Vector2f pos_rand2 = cludy.getPosition();
	pos_rand2.x = pos_cludy.x / 42;
	pos_rand2.y = pos_cludy.y / 42;


	while (window.isOpen())
	{




		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		if (event.key.code == sf::Keyboard::BackSpace)
		{
			if (lol % 2 == 0)
			{
				game = 0;
			}
			else
			{
				game = 1;
			}

			lol++;

		}
		/*

		*/

		if (menu_)
		{

			music.play();
			music.setLoop(i == 0);

			window.display();
			window.clear();
			window.draw(sp);
			window.draw(play);
			window.draw(option);
			window.draw(rank);
			window.draw(setting);
			window.draw(about);
			window.draw(exit);


			if (play.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{


				menu_ = 0;
				game = 1;
				bool level1 = 1, level2 = 0, level3 = 0;
				select_level(level1, level2, level3);
				level_number = 1;
				dot.setRadius(4 / level_number);

				//pac_dots
				pac_dot.setRadius(12 / level_number);

				//wall designe
				wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
				wall.setFillColor(Color(0, 0, 0));
				wall.setOutlineThickness(5 / (level_number));
				wall.setOutlineColor(sf::Color(0, 0, 2000000));


			}




			else if (option.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{


				menu_ = 0;
				menu2_ = 1;



			}

			else if (rank.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{


				menu_ = 0;
				game2 = 1;


			}
			else if (setting.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				menu_ = 0;
				sou = 1;



			}

			else if (exit.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{


				return 0;

			}
			else if (about.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{


				menu_ = 0;
				game = 0;
				abo = 1;

			}
		}
		if (menu2_)
		{
			window.display();
			window.clear();
			window.draw(level1);
			window.draw(level2);
			window.draw(level3);
			window.draw(level4);
			window.draw(level5);
			window.draw(level6);
			window.draw(lvel1);
			window.draw(lvel2);
			window.draw(lvel3);
			window.draw(lvel4);
			window.draw(lvel5);
			window.draw(lvel6);
			window.draw(BACK);


			if (BACK.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				menu2_ = 0;
				menu_ = 1;

			}
			if (level1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				 casep = 1;

				game = 1;
				menu2_ = 0;
				sou = 0;
				bool level1 = 1, level2 = 0, level3 = 0;
				select_level(level1, level2, level3);
				level_number = 1;
				// dots
				dot.setRadius(4 / level_number);

				//pac_dots
				pac_dot.setRadius(12 / level_number);



				blinky.setPosition(24 * 21, 14 * 21);
				window.draw(blinky);
				pinky.setPosition(24 * 21, 14 * 21);
				window.draw(pinky);
				inky.setPosition(24 * 21, 14 * 21);
				window.draw(inky);
				cludy.setPosition(24 * 21, 14 * 21);
				window.draw(cludy);



				//wall designe
				wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
				wall.setFillColor(Color(0, 0, 0));
				wall.setOutlineThickness(5 / (level_number));
				wall.setOutlineColor(sf::Color(0, 0, 2000000));
				blinky.setScale(0.15 / level_number, 0.15 / level_number);
				sprite.setScale(0.015 / level_number, 0.015 / level_number);
				inky.setScale(0.3 / level_number, 0.3 / level_number);
				cludy.setScale(0.3 / level_number, 0.3 / level_number);
				pinky.setScale(0.3 / level_number, 0.3 / level_number);
				fri.setScale(0.1 / level_number, 0.1 / level_number);

				pos_rand.x = pos_pinky.x  * level_number / 42;
				pos_rand.y = pos_pinky.y  * level_number / 42;

				pos_rand1.x = pos_inky.x  * level_number / 42;
				pos_rand1.y = pos_inky.y  * level_number / 42;

				pos_rand2.x = pos_cludy.x * level_number / 42;
				pos_rand2.y = pos_cludy.y * level_number / 42;





			}
			if (level2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				 casep = 1;

				game = 1;
				menu2_ = 0;
				bool level1 = 0, level2 = 1, level3 = 0;
				select_level(level1, level2, level3);
				level_number = 2;
				// dots
				dot.setRadius(4 / level_number);

				//pac_dots
				pac_dot.setRadius(12 / level_number);



				blinky.setPosition(24 * 21, 14 * 21);
				window.draw(blinky);
				pinky.setPosition(24 * 21, 14 * 21);
				window.draw(pinky);
				inky.setPosition(24 * 21, 14 * 21);
				window.draw(inky);
				cludy.setPosition(24 * 21, 14 * 21);
				window.draw(cludy);




				//wall designe
				wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
				wall.setFillColor(Color(0, 0, 0));
				wall.setOutlineThickness(5 / (level_number));
				wall.setOutlineColor(sf::Color(0, 0, 2000000));
				blinky.setScale(0.15 / level_number, 0.15 / level_number);
				sprite.setScale(0.015 / level_number, 0.015 / level_number);

				inky.setScale(0.3 / level_number, 0.3 / level_number);
				cludy.setScale(0.3 / level_number, 0.3 / level_number);
				pinky.setScale(0.3 / level_number, 0.3 / level_number);
				fri.setScale(0.1 / level_number, 0.1 / level_number);

				pos_rand.x = pos_pinky.x  * level_number / 42;
				pos_rand.y = pos_pinky.y  * level_number / 42;

				pos_rand1.x = pos_inky.x  * level_number / 42;
				pos_rand1.y = pos_inky.y  * level_number / 42;

				pos_rand2.x = pos_cludy.x * level_number / 42;
				pos_rand2.y = pos_cludy.y * level_number / 42;
			}
			if (level3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				 casep = 1;

				game = 1;
				menu2_ = 0;
				bool level1 = 0, level2 = 0, level3 = 1;
				select_level(level1, level2, level3);
				level_number = 2;
				// dots
				dot.setRadius(4 / level_number);

				//pac_dots
				pac_dot.setRadius(12 / level_number);


				blinky.setPosition(24 * 21, 14 * 21);
				window.draw(blinky);
				pinky.setPosition(24 * 21, 14 * 21);
				window.draw(pinky);
				inky.setPosition(24 * 21, 14 * 21);
				window.draw(inky);
				cludy.setPosition(24 * 21, 14 * 21);
				window.draw(cludy);



				//wall designe
				wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
				wall.setFillColor(Color(0, 0, 0));
				wall.setOutlineThickness(5 / (level_number));
				wall.setOutlineColor(sf::Color(0, 0, 2000000));
				blinky.setScale(0.15 / level_number, 0.15 / level_number);
				sprite.setScale(0.015 / level_number, 0.015 / level_number);
				inky.setScale(0.3 / level_number, 0.3 / level_number);
				cludy.setScale(0.3 / level_number, 0.3 / level_number);
				pinky.setScale(0.3 / level_number, 0.3 / level_number);
				fri.setScale(0.1 / level_number, 0.1 / level_number);

				pos_rand.x = pos_pinky.x  * level_number / 42;
				pos_rand.y = pos_pinky.y  * level_number / 42;

				pos_rand1.x = pos_inky.x  * level_number / 42;
				pos_rand1.y = pos_inky.y  * level_number / 42;

				pos_rand2.x = pos_cludy.x * level_number / 42;
				pos_rand2.y = pos_cludy.y * level_number / 42;

			}
			if (level4.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				 casep = 2;

				game = 1;
				menu2_ = 0;
				bool level1 = 1, level2 = 0, level3 = 0;
				select_level(level1, level2, level3);
				level_number = 1;
				// dots
				dot.setRadius(4 / level_number);

				//pac_dots
				pac_dot.setRadius(12 / level_number);



				blinky.setPosition(24 * 21, 14 * 21);
				window.draw(blinky);
				pinky.setPosition(24 * 21, 14 * 21);
				window.draw(pinky);
				inky.setPosition(24 * 21, 14 * 21);
				window.draw(inky);
				cludy.setPosition(24 * 21, 14 * 21);
				window.draw(cludy);



				//wall designe
				wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
				wall.setFillColor(Color(0, 0, 0));
				wall.setOutlineThickness(5 / (level_number));
				wall.setOutlineColor(sf::Color(0, 0, 2000000));
				blinky.setScale(0.15 / level_number, 0.15 / level_number);
				sprite.setScale(0.015 / level_number, 0.015 / level_number);
				inky.setScale(0.3 / level_number, 0.3 / level_number);
				cludy.setScale(0.3 / level_number, 0.3 / level_number);
				pinky.setScale(0.3 / level_number, 0.3 / level_number);
				fri.setScale(0.1 / level_number, 0.1 / level_number);

				pos_rand.x = pos_pinky.x  * level_number / 42;
				pos_rand.y = pos_pinky.y  * level_number / 42;

				pos_rand1.x = pos_inky.x  * level_number / 42;
				pos_rand1.y = pos_inky.y  * level_number / 42;

				pos_rand2.x = pos_cludy.x * level_number / 42;
				pos_rand2.y = pos_cludy.y * level_number / 42;


			}
			if (level5.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				casep = 2;

				game = 1;
				menu2_ = 0;
				bool level1 = 0, level2 = 1, level3 = 0;
				select_level(level1, level2, level3);
				level_number = 2;
				// dots
				dot.setRadius(4 / level_number);

				//pac_dots
				pac_dot.setRadius(12 / level_number);




				blinky.setPosition(24 * 21, 14 * 21);
				window.draw(blinky);
				pinky.setPosition(24 * 21, 14 * 21);
				window.draw(pinky);
				inky.setPosition(24 * 21, 14 * 21);
				window.draw(inky);
				cludy.setPosition(24 * 21, 14 * 21);
				window.draw(cludy);



				//wall designe
				wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
				wall.setFillColor(Color(0, 0, 0));
				wall.setOutlineThickness(5 / (level_number));
				wall.setOutlineColor(sf::Color(0, 0, 2000000));
				blinky.setScale(0.15 / level_number, 0.15 / level_number);
				sprite.setScale(0.015 / level_number, 0.015 / level_number);
				inky.setScale(0.3 / level_number, 0.3 / level_number);
				cludy.setScale(0.3 / level_number, 0.3 / level_number);
				pinky.setScale(0.3 / level_number, 0.3 / level_number);
				fri.setScale(0.1 / level_number, 0.1 / level_number);

				pos_rand.x = pos_pinky.x  * level_number / 42;
				pos_rand.y = pos_pinky.y  * level_number / 42;

				pos_rand1.x = pos_inky.x  * level_number / 42;
				pos_rand1.y = pos_inky.y  * level_number / 42;

				pos_rand2.x = pos_cludy.x * level_number / 42;
				pos_rand2.y = pos_cludy.y * level_number / 42;
			}
			if (level6.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				casep = 2;

				game = 1;
				menu2_ = 0;

				bool level1 = 0, level2 = 0, level3 = 1;

				select_level(level1, level2, level3);
				level_number = 2;
				// dots
				dot.setRadius(4 / level_number);

				//pac_dots
				pac_dot.setRadius(12 / level_number);



				blinky.setPosition(24 * 21, 14 * 21);
				window.draw(blinky);
				pinky.setPosition(24 * 21, 14 * 21);
				window.draw(pinky);
				inky.setPosition(24 * 21, 14 * 21);
				window.draw(inky);
				cludy.setPosition(24 * 21, 14 * 21);
				window.draw(cludy);



				//wall designe
				wall.setSize(sf::Vector2f(32 / (level_number), 32 / (level_number)));
				wall.setFillColor(Color(0, 0, 0));
				wall.setOutlineThickness(5 / (level_number));
				wall.setOutlineColor(sf::Color(0, 0, 2000000));
				blinky.setScale(0.15 / level_number, 0.15 / level_number);
				sprite.setScale(0.015 / level_number, 0.015 / level_number);
				inky.setScale(0.3 / level_number, 0.3 / level_number);
				cludy.setScale(0.3 / level_number, 0.3 / level_number);
				pinky.setScale(0.3 / level_number, 0.3 / level_number);
				fri.setScale(0.1 / level_number, 0.1 / level_number);

				pos_rand.x = pos_pinky.x  * level_number / 42;
				pos_rand.y = pos_pinky.y  * level_number / 42;

				pos_rand1.x = pos_inky.x  * level_number / 42;
				pos_rand1.y = pos_inky.y  * level_number / 42;

				pos_rand2.x = pos_cludy.x * level_number / 42;
				pos_rand2.y = pos_cludy.y * level_number / 42;
			}
		}








		


		if (BACK.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
		{
			game2 = 0;

			menu_ = 1;
			sou1 = 0;
			sou = 0;
		}

	



		if (sou)
		{
			if (OFF.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))

			{
				sou = 1;
				sou1 = 0;
				sou2 = 0;
			}
			if (ON.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))

			{
				sou = 0;
				sou1 = 1;
				sou2 = 1;
			}


			window.display();
			string pop = "YOU ARE USING : ";
			window.clear();
			window.draw(ON);


			stringstream input;

			Text ran;
			Font fontplayer;
			fontplayer.loadFromFile("FFF Tusj Bold.ttf");
			ran.setFont(fontplayer);
			input << pop;
			ran.setString(input.str());
			ran.setFillColor(Color::White);
			ran.setCharacterSize(40);
			ran.setPosition(1 * 42, 6 * 42);
			window.draw(ran);


			sprite1.setScale(0.25 / level_number, 0.25 / level_number);
			sprite2.setScale(0.15 / level_number, 0.15 / level_number);
			sprite3.setScale(0.15 / level_number, 0.15 / level_number);
			sprite4.setScale(0.45 / level_number, 0.45 / level_number);
			sprite5.setScale(0.45 / level_number, 0.45 / level_number);
			sprite6.setScale(0.06 / level_number, 0.06 / level_number);

			sprite6.setPosition(10 * 42, 10 * 42);
			sprite4.setPosition(18 * 42, 17 * 42);
			sprite3.setPosition(2 * 42, 17 * 42);
			sprite2.setPosition(18 * 42, 10 * 42);
			sprite1.setPosition(2 * 42, 10 * 42);
			sprite5.setPosition(10 * 42, 17 * 42);
			window.draw(BACK);
			window.draw(sprite1);
			window.draw(sprite2);
			window.draw(sprite3);
			window.draw(sprite4);
			window.draw(sprite5);
			window.draw(sprite6);
			if (q1)
			{
				sprite1.setPosition(18 * 42, 4 * 42);

				window.draw(sprite1);
			}
			else if (q2)
			{
				sprite2.setPosition(18 * 42, 4 * 42);
				window.draw(sprite2);

			}
			else if (q3)
			{

				sprite3.setPosition(18 * 42, 4 * 42);
				window.draw(sprite3);

			}
			else if (q4)
			{

				sprite4.setPosition(18 * 42, 4 * 42);
				window.draw(sprite4);

			}
			else if (q5)
			{

				sprite5.setPosition(18 * 42, 4 * 42);
				window.draw(sprite5);

			}
			else if (q6)
			{


				sprite6.setPosition(18 * 42, 4 * 42);

				window.draw(sprite6);

			}
			if (sprite1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				sprite1.setPosition(12 * 42, 15 * 42);

				q1 = 1;
				q2 = 0;
				q3 = 0;
				q4 = 0;
				q5 = 0;
				q6 = 0;

			}

			if (sprite2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				sprite2.setPosition(12 * 42, 15 * 42);

				q1 = 0;
				q2 = 1;
				q3 = 0;
				q4 = 0;
				q5 = 0;
				q6 = 0;

			}
			if (sprite3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				sprite3.setPosition(12 * 42, 15 * 42);

				q1 = 0;
				q2 = 0;
				q3 = 1;
				q4 = 0;
				q5 = 0;
				q6 = 0;


			}
			if (sprite4.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				sprite4.setPosition(12 * 42, 15 * 42);

				q1 = 0;
				q2 = 0;
				q3 = 0;
				q4 = 1;
				q5 = 0;
				q6 = 0;


			}
			if (sprite5.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				sprite5.setPosition(12 * 42, 15 * 42);

				q1 = 0;
				q2 = 0;
				q3 = 0;
				q4 = 0;
				q5 = 1;
				q6 = 0;


			}

			if (sprite6.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				sprite6.setPosition(12 * 42, 15 * 42);

				q1 = 0;
				q2 = 0;
				q3 = 0;
				q4 = 0;
				q5 = 0;
				q6 = 1;

			}



		}







		if (sou1)
		{
			window.display();
			window.clear();
			window.draw(OFF);
			window.draw(BACK);


		}

		if (sou2)
		{
			music.stop();
		}

		if (game2)
		{
			window.display();

			window.clear();
			window.draw(BACK);

			for (int i = 0; i < _rank.size() && i<5; i++)
			{

				if (_rank[i].first < 0)
				{
					continue;
				}
				stringstream input;

				Text ran;
				Font fontplayer;
				fontplayer.loadFromFile("FFF Tusj Bold.ttf");
				ran.setFont(fontplayer);
				input << _rank[i].second;
				ran.setString(input.str());
				ran.setFillColor(Color::Yellow);
				ran.setCharacterSize(60);
				ran.setPosition(150, i * 100 + 200);
				window.draw(ran);


				stringstream inputp;
				Text ranp;
				ranp.setFont(fontplayer);
				inputp << _rank[i].first;
				ranp.setString(inputp.str());
				ranp.setFillColor(Color::Yellow);

				ranp.setCharacterSize(60);
				ranp.setPosition(850, i * 100 + 200);
				window.draw(ranp);
			}

		}


		if (abo)
		{



			window.display();
			window.clear();
			if (BACK.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				menu_ = 1;
				abo = 0;
			}
			window.draw(CK);
			window.draw(BACK);
			window.draw(dev);


		}

		if (game)
		{

			change_levels();

			frame++;
			sf::Vector2f pos_blinky = blinky.getPosition();
			sf::Vector2f pos_pacman = sprite.getPosition();
			pos_pinky = pinky.getPosition();
			pos_inky = inky.getPosition();
			pos_cludy = cludy.getPosition();
			window.draw(score_sprite);
			window.display();
			window.clear();
			display_maze();
			for (int i = 0; i < n.size(); i++)
				window.draw(life_spr[i]);
			get_diriction(last);




			window.display();

			if (mood)
			{
				change_levels();

				window.display();


				kira++;
				cout << kira << endl;
				if (kira > 1000)
				{

					kira = 0;
					mood = 0;
					mo = 0;
					mi = 0;
					me = 0;
					ma = 0;

				}






				fri.setPosition((blx * 42 / level_number), (bly * 42 / level_number));
				window.draw(fri);

				if (pos_pacman.x * level_number / 42 == pos_blinky.x * level_number / 42 && pos_blinky.y * level_number / 42 == pos_pacman.y * level_number / 42)
				{
					mo = 1;
				}
				if (!mo)
				{
					FindPath(int(pos_blinky.x * level_number / 42), int(pos_blinky.y * level_number / 42), int(pos_pacman.x * level_number / 42), int(pos_pacman.y * level_number / 42), BFSArray_blinky, walk_queue_blinky);
				}
				if (mo)
				{
					FindPath(int(pos_blinky.x * level_number / 42), int(pos_blinky.y * level_number / 42), 12, 9, BFSArray_blinky, walk_queue_blinky);

				}
				if (frame % (40 / (casep + 5 * mo)) == 0 && walk_queue_blinky.size() != 0) {

					blx = walk_queue_blinky.back().x;
					bly = walk_queue_blinky.back().y;
					walk_queue_blinky.pop_back();
					blinky.setPosition((blx * 42 / level_number), (bly * 42 / level_number));
					fri.setPosition((blx * 42 / level_number), (bly * 42 / level_number));
					window.draw(fri);


				}

				fri.setPosition((blx * 42 / level_number), (bly * 42 / level_number));
				window.draw(fri);




				if (pos_pacman.x * level_number / 42 == pos_pinky.x * level_number / 42 && pos_pacman.y * level_number / 42 == pos_pinky.y * level_number / 42)
				{
					mi = 1;
				}
				if (!mi)
				{
					FindPath(int(pos_pinky.x * level_number / 42), int(pos_pinky.y * level_number / 42), int(pos_rand.x), int(pos_rand.y), BFSArray_pinky, walk_queue_pinky);

					if (pos_pinky.x * level_number / 42 == pos_rand.x && pos_pinky.y * level_number / 42 == pos_rand.y)
					{
						pos_rand.x = rand() % (24 * level_number);
						pos_rand.y = rand() % (20 * level_number);

						while (true)
						{
							if (maze[int(pos_rand.y)][int(pos_rand.x)] == 1)
							{
								pos_rand.x = rand() % (24 * level_number);
								pos_rand.y = rand() % (20 * level_number);
							}
							else
							{



								break;
							}
						}
						FindPath(int(pos_pinky.x * level_number / 42), int(pos_pinky.y * level_number / 42), int(pos_rand.x), int(pos_rand.y), BFSArray_pinky, walk_queue_pinky);
					}

		
				}
				if (mi)
				{
					FindPath(int(pos_pinky.x * level_number / 42), int(pos_pinky.y * level_number / 42), 12, 9, BFSArray_pinky, walk_queue_pinky);

				}
				if (frame % (40 / (casep + 5 * mi)) == 0 && walk_queue_pinky.size() != 0) {

					plx = walk_queue_pinky.back().x;
					ply = walk_queue_pinky.back().y;
					walk_queue_pinky.pop_back();
					pinky.setPosition(plx * 42 / level_number, ply * 42 / level_number);
					fri.setPosition(plx * 42 / level_number, ply * 42 / level_number);
					window.draw(fri);

				}


				fri.setPosition(plx * 42 / level_number, ply * 42 / level_number);
				window.draw(fri);







				if (pos_pacman.x * level_number / 42 == pos_inky.x * level_number / 42 && pos_pacman.y * level_number / 42 == pos_inky.y * level_number / 42)
				{
					me = 1;
				}

				if (!me)
				{
					FindPath(int(pos_inky.x * level_number / 42), int(pos_inky.y * level_number / 42), int(pos_rand1.x), int(pos_rand1.y), BFSArray_inky, walk_queue_inky);
					if (pos_inky.x * level_number / 42 == pos_rand1.x && pos_inky.y * level_number / 42 == pos_rand1.y)
					{
						pos_rand1.x = rand() % (20 * level_number);
						pos_rand1.y = rand() % (20 * level_number);

						while (true)
						{
							if (maze[int(pos_rand1.y)][int(pos_rand1.x)] == 1)
							{
								pos_rand1.x = rand() % (20 * level_number);
								pos_rand1.y = rand() % (10 * level_number) + (10 * level_number);
							}
							else
							{


								break;
							}
						}
						FindPath(int(pos_inky.x * level_number / 42), int(pos_inky.y * level_number / 42), int(pos_rand1.x), int(pos_rand1.y), BFSArray_inky, walk_queue_inky);

					}
				}

				if (me)
				{
					FindPath(int(pos_inky.x * level_number / 42), int(pos_inky.y * level_number / 42), 12, 9, BFSArray_inky, walk_queue_inky);

				}
				if (frame % (40 / (casep + 5 * me)) == 0 && walk_queue_inky.size() != 0) {

					ilx = walk_queue_inky.back().x;
					ily = walk_queue_inky.back().y;
					walk_queue_inky.pop_back();
					inky.setPosition(ilx * 42 / level_number, ily * 42 / level_number);
					fri.setPosition(ilx * 42 / level_number, ily * 42 / level_number);
					window.draw(fri);


				}


				fri.setPosition(ilx * 42 / level_number, ily * 42 / level_number);
				window.draw(fri);





				if (pos_pacman.x * level_number / 42 == pos_cludy.x * level_number / 42 && pos_pacman.y * level_number / 42 == pos_cludy.y * level_number / 42)
				{
					ma = 1;

				}

				if (!ma)
				{
					FindPath(int(pos_cludy.x * level_number / 42), int(pos_cludy.y * level_number / 42), int(pos_rand2.x), int(pos_rand2.y), BFSArray_cludy, walk_queue_cludy);

					if (pos_cludy.x* level_number / 42 == pos_rand2.x && pos_cludy.y * level_number / 42 == pos_rand2.y)
					{
						pos_rand2.x = rand() % (22 * level_number);
						pos_rand2.y = rand() % (20 * level_number);

						while (true)
						{
							if (maze[int(pos_rand2.y)][int(pos_rand2.x)] == 1)
							{
								pos_rand2.x = rand() % (22 * level_number);
								pos_rand2.y = rand() % (10 * level_number);
							}
							else
							{



								break;
							}
						}
						FindPath(int(pos_cludy.x * level_number / 42), int(pos_cludy.y * level_number / 42), int(pos_rand2.x), int(pos_rand2.y), BFSArray_cludy, walk_queue_cludy);
					}
					
				}
				if (ma)
				{
					FindPath(int(pos_cludy.x * level_number / 42), int(pos_cludy.y * level_number / 42), 12, 9, BFSArray_cludy, walk_queue_cludy);

				}
				if (frame % (40 / (casep + 5 * ma)) == 0 && walk_queue_cludy.size() != 0) {

					clx = walk_queue_cludy.back().x;
					cly = walk_queue_cludy.back().y;
					walk_queue_cludy.pop_back();
					cludy.setPosition(clx * 42 / level_number, cly * 42 / level_number);
					fri.setPosition(clx * 42 / level_number, cly * 42 / level_number);
					window.draw(fri);


				}


				fri.setPosition(clx * 42 / level_number, cly * 42 / level_number);
				window.draw(fri);



			}















			if (!mood)
			{



				change_levels();

				window.draw(blinky);




				FindPath(int(pos_blinky.x * level_number / 42), int(pos_blinky.y * level_number / 42), int(pos_pacman.x * level_number / 42), int(pos_pacman.y * level_number / 42), BFSArray_blinky, walk_queue_blinky);
				if (frame % (25 / (casep)) == 0 && walk_queue_blinky.size() != 0) {

					blx = walk_queue_blinky.back().x;
					bly = walk_queue_blinky.back().y;
					walk_queue_blinky.pop_back();
					blinky.move((blx * 42 / level_number) - (pos_blinky.x), (bly * 42 / level_number) - (pos_blinky.y));

				}







				window.display();


				if (pos_pinky.x * level_number / 42 == pos_rand.x && pos_pinky.y * level_number / 42 == pos_rand.y)
				{
					pos_rand.x = rand() % (24 * level_number);
					pos_rand.y = rand() % (20 * level_number);

					while (true)
					{
						if (maze[int(pos_rand.y)][int(pos_rand.x)] == 1)
						{
							pos_rand.x = rand() % (24 * level_number);
							pos_rand.y = rand() % (20 * level_number);
						}
						else
						{



							break;
						}
					}
					FindPath(int(pos_pinky.x * level_number / 42), int(pos_pinky.y * level_number / 42), int(pos_rand.x), int(pos_rand.y), BFSArray_pinky, walk_queue_pinky);

				}
				if (frame % (25 / (casep)) == 0 && walk_queue_pinky.size() != 0) {

					plx = walk_queue_pinky.back().x;
					ply = walk_queue_pinky.back().y;
					walk_queue_pinky.pop_back();
					pinky.setPosition(plx * 42 / level_number, ply * 42 / level_number);


				}


				FindPath(int(pos_pinky.x * level_number / 42), int(pos_pinky.y * level_number / 42), int(pos_rand.x), int(pos_rand.y), BFSArray_pinky, walk_queue_pinky);









				if (pos_inky.x * level_number / 42 == pos_rand1.x && pos_inky.y * level_number / 42 == pos_rand1.y)
				{
					pos_rand1.x = rand() % (20 * level_number);
					pos_rand1.y = rand() % (20 * level_number);

					while (true)
					{
						if (maze[int(pos_rand1.y)][int(pos_rand1.x)] == 1)
						{
							pos_rand1.x = rand() % (20 * level_number);
							pos_rand1.y = rand() % (10 * level_number) + (10 * level_number);
						}
						else
						{


							break;
						}
					}
					FindPath(int(pos_inky.x * level_number / 42), int(pos_inky.y * level_number / 42), int(pos_rand1.x), int(pos_rand1.y), BFSArray_inky, walk_queue_inky);

				}
				if (frame % (25 / (casep)) == 0 && walk_queue_inky.size() != 0) {

					ilx = walk_queue_inky.back().x;
					ily = walk_queue_inky.back().y;
					walk_queue_inky.pop_back();
					inky.setPosition(ilx * 42 / level_number, ily * 42 / level_number);


				}


				FindPath(int(pos_inky.x * level_number / 42), int(pos_inky.y * level_number / 42), int(pos_rand1.x), int(pos_rand1.y), BFSArray_inky, walk_queue_inky);








				if (pos_cludy.x* level_number / 42 == pos_rand2.x && pos_cludy.y * level_number / 42 == pos_rand2.y)
				{
					pos_rand2.x = rand() % (22 * level_number);
					pos_rand2.y = rand() % (20 * level_number);

					while (true)
					{
						if (maze[int(pos_rand2.y)][int(pos_rand2.x)] == 1)
						{
							pos_rand2.x = rand() % (22 * level_number);
							pos_rand2.y = rand() % (10 * level_number);
						}
						else
						{



							break;
						}
					}
					FindPath(int(pos_cludy.x * level_number / 42), int(pos_cludy.y * level_number / 42), int(pos_rand2.x), int(pos_rand2.y), BFSArray_cludy, walk_queue_cludy);

				}
				if (frame % (25 / (casep)) == 0 && walk_queue_cludy.size() != 0) {

					clx = walk_queue_cludy.back().x;
					cly = walk_queue_cludy.back().y;
					walk_queue_cludy.pop_back();
					cludy.setPosition(clx * 42 / level_number, cly * 42 / level_number);


				}
				FindPath(int(pos_cludy.x * level_number / 42), int(pos_cludy.y * level_number / 42), int(pos_rand2.x), int(pos_rand2.y), BFSArray_cludy, walk_queue_cludy);

				window.draw(pinky);
				window.draw(cludy);
				window.draw(inky);
				window.draw(blinky);

				game_over();

			}

		}



	}
	
	return 0;
}
