#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXLINE=256;

class Board{ //Most definitions after main
    public:
        Board(int);
        int size(){ return board_size;}
        int get_val(int, int);
        void make_move(int,int,int);
        void show_game();
        void set_komi(int K){komi = K;}
        int get_komi(){ return komi;}
        bool valid_move(int x,int y,int color);
    private:
        int komi = 0;
        int board_size; //to simplify some actions, array size is board_size+2, with outer edges unused for play
        map<string, int> trans;
        map<int, string> inter;
        vector<vector<int>> board;
};//---------------------------------------------------------------------------------------------END class Board


// @main functions
int Dprotocol_version(){ //Done
//return version used of Go Text Protocol as int
    return 2;
}

string Dname(){ //Done
//return name of engine as string
    return "Ender's Go Engine";
}

string Dversion(){ //Done
//return version number of engine as string
    return "1.0";
}

bool Dknown_command(string command){ //Done
//check whether a command is known, returns boolean value
    bool value = false;
    map<string, bool> com_list;
    com_list["protocol_version"] = true;
    com_list["name"] = true;
    com_list["version"] = true; 
    com_list["known_command"] = true;
    com_list["list_commands"] = true;
    com_list["quit"] = true;
    com_list["boardsize"] = true;
    com_list["clear_board"] = true;
    com_list["komi"] = true;
    com_list["play"] = true;
    com_list["genmove"] = true;
    com_list["display"] = true;
    if (com_list.find(command) != com_list.end()){
        value = com_list[command];
    }
    return value;
}

void greeting(){ //Done
    cout << "\nEnder's Go Engine, Version 1.0 (in active development)\n" << endl;
    cout << "Authored by Tristen K.W. , Dec., 2014\n" << endl;
    cout << "Problems should be reported via email to Tristen at:\n" << endl;
    cout << "\ntristen.wentling@gmail.com\n" << endl;
    cout << "===============================================\n" << endl;
    cout << "#For a list of known commands enter \"help\" at any time\n" << endl; 
}

string Dlist_commands(){ //Done
    //string comm = "help\nprotocol_version\nname\nversion\nknown_command\nlist_commands\nquit\nboardsize\nclear_board\nkomi\nplay\ngenmove";
    string comm = "help\nprotocol_version\nname\nversion\nknown_command [commmand]\nlist_commands\nquit\nboardsize [int]\nclear_board\nkomi\nplay [alphanum_coord] [color] \ngenmove [color]\ndisplay";
    return comm;
}

void Dkomi(){
//reset board to size int size
    bool wtf = false;
}
void Dclear_board(){
//reset board to empty, reset captured stones, empty move history
    bool wtf = false;
}

void Dplay(string move){
//play stone of given color at given vertex
    bool wtf = false;
}

void Dgenmove(string move){
//generate move of given color, pass and resign are valid returns in
//  place of returning the vertex of the move 
    bool wtf = false;
}


int main(){
    greeting();
	int seed = time(NULL);  // seed value for pseudo-random number generator
	srand(seed); //initialize pRNG
    Board current_board(9); //Initializes with default value of 9x9 game board
    map<string, int> comm_list;
    comm_list["protocol_version"] = 1;
    comm_list["name"] = 2;
    comm_list["version"] = 3; 
    comm_list["known_command"] = 4;
    comm_list["list_commands"] = 5;
    comm_list["boardsize"] = 6;
    comm_list["clear_board"] = 7;
    comm_list["komi"] = 8;
    comm_list["play"] = 9;
    comm_list["genmove"] = 10;
    comm_list["display"] = 11;
    string boardsz;
    int board_size=9;
    bool playing = true; //changing this won't let the game play....
    
    while (playing){
        string pos;
        string newKomi;
        string color;
        string y_alpha;
        string command;
        string oneline;
        string parameter;
        bool trying = true;
        int x_pos,y_pos,new_komi;
        char x_alpha;
        queue<string> com_queue;
        cin >> oneline;
        if ((string)oneline == (string)"quit"){
            playing = false;
        }
        else if ((string)oneline == (string)"help"){
            string all = Dlist_commands();
            cout << "\n\nCommand list" << endl;
            cout << "============\n" << endl;
            cout << all << "\n" << endl;
            cout << "\nPlease separate all commands and parameters by a single space\n" << endl;
            cout << "\nIndexing is given as an alphanumeric coordinate, e.g. B11 or F5\n" << endl;
        }
        else{
            com_queue.push(oneline);   
            command = com_queue.front();
            com_queue.pop();
            if (Dknown_command(command)){
                switch(comm_list[command]){
                    case 1: //output protocol version
                        cout << Dprotocol_version() << endl;break;
                    case 2: //output engine name
                        cout << Dname() << endl;break;
                    case 3: //output engine version number
                        cout << Dversion() << endl;break;
                    case 4: //check if a command is known, pass by known_command <command>
                        cin >> parameter;
                        if (Dknown_command(parameter)){
                            cout << "true" << endl;
                        }
                        else {
                            cout << "false" << endl;
                        }break;
                    case 5: //list all known commands
                        cout << "\n" << Dlist_commands() << endl;break;
                    case 6: //boardsize
                        cin >> boardsz;
                        board_size = stoi(boardsz);
                        current_board = Board(board_size);break;
                        current_board.show_game();
                    case 7: //clear_board
                        for (int i=0; i<current_board.size(); ++i){
                            for (int j=0; j<current_board.size(); ++j){
                                current_board.make_move(i,j,0);
                            }
                        }break;
                    case 8: //komi
                        cin >> newKomi;
                        new_komi = stoi(newKomi);
                        current_board.set_komi(new_komi);break;
                    case 9: //play
                        pos = "";
                        cin >> pos;
                        cin >> color;
                        x_alpha = pos[0];
                        y_alpha = pos.substr(1);
                        x_pos = int(x_alpha)-64;
                        y_pos = stoi(y_alpha);
                        if (color == "black" and current_board.valid_move(x_pos,y_pos,8)){
                            current_board.make_move(x_pos, y_pos, 8);
                        }
                        else if (color == "white" and current_board.valid_move(x_pos,y_pos,4)){
                            current_board.make_move(x_pos, y_pos, 4);
                        }
                        else{
                            cout << "\nInvalid move. Please make another selection or try again\n" << endl;
                        }break;
                    case 10: //genmove
                        cin >> color;
                        while(trying){
                            x_pos = rand() % current_board.size();
                            y_pos = rand() % current_board.size();
                            if (color == "black" and current_board.valid_move(x_pos,y_pos,8)){
                            current_board.make_move(x_pos, y_pos, 8);
                            trying = false;
                            }
                            else if (color == "white" and current_board.valid_move(x_pos,y_pos,4)){
                                current_board.make_move(x_pos, y_pos, 4);
                                trying = false;
                            }
                        }
                        trying = true; //resets for next time
                        break;
                    case 11: //display
                        current_board.show_game();break;
                    default:
                        cout << "\nUnknown command\n" << endl;break;
                }
            }
            else {
                cout << "\nunknown command\n" << endl;
            }
        }
    }
    cout << "\nThanks for playing, goodbye!\n" << endl;
}//end main

Board::Board(int X){
//create simple mapping between letter and number position representation
    board_size = X;
    for(int i=1; i<X+2; i++){
        string lett = to_string(65 + i);
        int num = i;
        trans[lett] = num;
        inter[num] = lett;
    }
    //initialize board, outer edges are 1, else 0
    vector<vector<int>> all_rows;
    vector<int> top_bottom;
    vector<int> row_vec;
    //Top and bottom rows made from here
    for (int k=0; k<X+2; k++){// "X" is the actual boardsize, I'm using an oversized array for easier bounds checking
        top_bottom.push_back(1);
    }
    //All middle rows made from here
    for (int j=0; j<X+2; j++){
        if (j==0 || j==X+1){
            row_vec.push_back(1);
        }
        else{
            row_vec.push_back(0);
        }
    }
    all_rows.push_back(top_bottom); //Top
    for (int i=1; i<X+1; i++){  //Middle Rows
        all_rows.push_back(row_vec);  
    }
    all_rows.push_back(top_bottom);//Bottom
    board = all_rows;
    show_game();
}

void Board::show_game(){
    ///* //Display current status of game
    for (auto it: board){
        for (auto jt: it){
            if (jt == 1){
                cout << "# ";
            }
            else if (jt == 0){
                cout << "+ ";
            }
            else if (jt == 8){
                cout << "B ";
            }
            else if (jt == 4){
                cout << "W ";
            }
            else {
                cout << "- ";
            }
        }
        cout << "\n";
    //*/
    }
}

bool Board::valid_move(int x,int y,int color){
/*Here is the main reason why I used an oversized array to represent the board,
now I can check if an adjacent entry is a border number or a piece instead of
trying to check whether each given position is on an edge or in a corner and the
same logic will apply if I count edge blocks as "blocking" a move or play    */
    int num_blocking = 0;
    if (get_val(x-1, y) == (1 || 8 || 4)){
        num_blocking++;
    }
    else if (get_val(x+1, y) == (1 || 8 || 4)){
        num_blocking++;
    }
    else if (get_val(x, y-1) == (1 || 8 || 4)){
        num_blocking++;
    }
    else if (get_val(x, y+1) == (1 || 8 || 4)){
        num_blocking++;
    }
    if ( (get_val(x,y)!=0) || (num_blocking == 4) ){
        return false;
    }
    else {
        return true;
    }
}

int Board::get_val(int X, int Y){
    return board[X][Y];
}

void Board::make_move(int X, int Y, int Color){
    //Note: X,Y indexing is done from 1 to boardsize
    board.at(X).at(Y) = Color;
}
