//
//  main.cpp
//  INFO450FINDGOLD
//
//  Created by Agni Earasi on 10/6/19.
//  Copyright © 2019 Agni Earasi. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;
const int ROW= 8;
const int COL= 8;
void printBoard(char board[ROW][COL]);
void initializeBoard(char board[ROW][COL]);
void selector(char board[ROW][COL]);

int main(int argc, const char * argv[]) {
    char myArray[ROW][COL];

    selector(myArray);
    
    
    
    return 0;
}

// Creation of the board with the gold and bomb placed.
void initializeBoard(char board[ROW][COL]){
    
    for (int i = 0; i<8; i++){
        for(int j=0;j<8;j++){
            board[i][j] = ' ';
        }
    }
    srand(time(0));
    int x = rand()%8;
    int y = rand()%8;
    
    board[x][y]= 'B';
    
    for (int i =0; i<5;i++){
        int x= rand()%8;
        int y= rand()%8;
        if (board[x][y]==' '){
            board[x][y]= 'G';
        }
        else i--;
    }
}
// This sets up the board by inserting spaces in each index of the board as well as helps to show the hidden and unhidden board later.
void printBoard(char board[ROW][COL], bool hidden){
    cout << "    " << " 1 2 3 4 5 6 7 8" << endl << "    ________________" << endl;
    for (int i = 0; i<8; i++){
        cout << i+1 << " | ";
        for(int j=0;j<8;j++){
            if(hidden) {
                cout << " ?";
            }
            else {
                cout<< " " << board[i][j];
            }
        }
        cout<<endl;
    }
}
//This function takes care of all the inputs and what the outcome of the selection is. It is the main part of the game that uses the printBoard function to also display the hidden and unhidden board. 
void selector(char board[ROW][COL]){
    int x,y;
    char input;
    int points=0;
    cout<<"Welcome to the Isle of Doom! Find the gold, but beware of the bomb. Good luck comrades. You have 5 tries!"<<endl;

    do{
        printBoard(board, true);
        initializeBoard(board);

        for( int i=0;i<5;i++){
            
            cout<<"Please enter an x coordinate between 1 and 8: ";
            cin>> x;
            x--;
            cout<<"Please enter an y coordinate between 1 and 8: ";
            cin>> y;
            y--;
            
            
            if(board[x][y]== ' '){
                cout<<"NOTHING BUT DIRT, FIND A NEW SPOT"<<endl;
                
            }
            else if( board[x][y]=='G'){
                cout<<"HOORAH, YOU'VE STRUCK GOLD!"<<endl;
                board[x][y] = 'F';
                points++;
            }
            else if(board[x][y]=='B'){
                cout<<"YOU HIT A BOMB, YOUR EQUIPMENT HAS BEEN BLOWN TO SMITHEREENS, YOUR GOLD HUNTING DAYS ARE OVER"<<endl;
                break;
            }
            else {
                cout<<"NOTHING BUT DIRT, FIND A NEW SPOT"<<endl;
            }
            cout<<"You have " << 4-i << " tries remaining!"<<endl;
        }
        printBoard(board, false);
        cout<<"Your expedition has ended with you selling your gold for "<< points<< " hundred thousand dollars!"<< endl;
        cout<<"Would you like to embark on a new adventure and try again? Y or N: ";
        cin>>input;
        
    }
    while (input == 'Y');
    
}
