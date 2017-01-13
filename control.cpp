#include <cstdlib>
#include <cstring>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
// need to get commands from cin statement to run, need to gen moves, fix definitions
/*
  Authored by Tristen K. Wentling, 2014.
    This is my implementation of a simple engine for computer Go, a.k.a. Wei-chi.
    For version 1 the logic is rather grossly undersophisticated, but should be
    adaptable for future use to easily make use of a stronger a.i. system.
*/


class Board{
    public:
        Board::Board(int X){
        //create simple mapping between letter and number position representation
            for(int i=1; i<X+2; i++){
                string lett = to_string(65 + i);
                int num = i;
                trans[lett] = num;
                inter[num] = lett;
            }
            //initialize board, outer edges are 1, else 0
            vector<int> top_vect;
            for (int p=0;p<X+2;p++){
                top_vect.push_back(1);
            }
            board.push_back(top_vect);
            for(int j=1;j<X+1;j++){
                vector<int> temp_vect;
                temp_vect.push_back(1);
                for (int k=1;k<X+2;k=++){
                    temp_vect.push_back(0);
                }
                temp_vect.push_back(1);
                board.push_back(temp_vect);
            }
            board.push_back(top_vect);
        }
        void make_move(string);
    private:
        int board_size; //to simplify some actions, array size is board_size+2, with outer edges unused for play
        map<string, int> trans;
        map<int, string> inter;
        vector<vector<string>> board;
};//---------------------------------------------------------------------------------------------END class Board

class Game{
    public:
        Game(int)
    private:
        Board cur_board(int);
        bool playing_game = true;


};//---------------------------------------------------------------------------------------END class Game

// @main functions
int protocol_version(){
//return version used of Go Text Protocol as int
    return 2;
}

string name(){
//return name of engine as string
    return "Ender's Go Engine";
}

string version(){
//return version number of engine as string
    return "1.0";
}

bool known_command(string command){
//check whether a command is known, returns boolean value
    array<string> com_list = {"protocol_version",
                        "name", 
                        "version", 
                        "known_command",
                        "list_commands",
                        "quit", 
                        "boardsize",
                        "clear_board",
                        "komi",
                        "play",
                        "genmove"};
    return any_of(com_list.begin(),com_list.end(), [](string a){return a == command});
}

string list_commands(){
    string comm = "protocol_version\nname\nversion\nknown_command\nlist_commands\nquit\nboardsize\nclear_board\nkomi\nplay\ngenmove";
    return comm;
}

void quit(){
//quit game
    playing_game = false;
}
void komi(){
//reset board to size int size
    bool wtf = false;
}
void clear_board(){
//reset board to empty, reset captured stones, empty move history
    bool wtf = false;
}

void komi(){
    bool wtf = false;
}

void play(string move){
//play stone of given color at given vertex
    bool wtf = false;
}

void genmove(string move){
//generate move of given color, pass and resign are valid returns in
//  place of returning the vertex of the move 
    bool wtf = false;
}

void run_engine(){
//runs the game engine until quit response received or timeout occurs
    string log = "";
    string next_command;
    while (playing_game){
        try{
        //run the game here
            cin >> next_command;
        }
        catch(std::exception& except){
        //check for timeout, wait for responses
            log = log + except.what() + "\n";  // disp. std. exception
            nanosleep((struct timespec[]){{0, 500000000}}, NULL);
        }
    }
}

void write_log(){
//output log of game to file

}

int main(){
    run_engine();

}//-----------------------------------------------------------------------------------------END funtion main

