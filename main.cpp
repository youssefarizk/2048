#include <iostream> // remove possible from command functions
#include <cstdlib> // change all zero to the actual bool variable in the function
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>


using namespace std;

//functions relevant to down movement
int index(int row, int col); // function to provide the index of the square representation of the game in the vector
void commanddown(vector<int>& v1, vector<int>& v2);
bool no_zero(int column, vector<int>& v);
bool not_same(int column, vector<int>& v);
bool check_if_space_down(int column, vector<int>& v);
bool last_not_zero_down(int column, vector<int>& v);
void add_down(int row, vector<int>& v);
bool zero_in_between_down(int column, int row1, int row2, const vector<int>& v);
void check_if_same_entries_down(int column, vector<int>& v);
void movedown(vector<int>& v, int& col);
//functions relevant to up movement (some of the above apply here as well)
bool first_not_zero_up(int column, vector<int>& v);
bool check_if_space_up(int column, vector<int>& v);
void check_if_same_entries_up(int column, vector<int>& v);
void add_up(int row, vector<int>& v1);
void moveup(vector<int>& v, int& col);
void commandup(vector<int>& v1, vector<int>& v2);
//functions relevant to rightward movement
bool no_zero_horizontal(int row, vector<int>& v);
bool not_same_horizontal(int row, vector<int>& v);
bool left_not_zero_right(int row, vector<int>& v);
bool check_if_space_right(int row, vector<int>& v);
bool zero_in_between_right(int row, int col1, int col2, const vector<int>& v);
void check_if_same_entries_right(int row, vector<int>& v);
void add_right(int column, vector<int>& v1);
void moveright(vector<int>& v, int& row);
void commandright(vector<int>& v1, vector<int>& v2);
//functions relevant for leftward movement (some of the above apply here as well)
bool right_not_zero_left(int row, vector<int>& v);
bool check_if_space_left(int row, vector<int>& v);
void check_if_same_entries_left(int row, vector<int>& v);
void add_left(int column, vector<int>& v1);
void moveleft(vector<int>& v, int& row);
void commandleft(vector<int>& v1, vector<int>& v2);
//function to check whether the game is over or not
bool check_possibility(vector<int>& v);
void random(vector<int>& v);


int main (){
    srand(time(0)); //to ensure the generation of a different random number on each run
    vector<int> original, modified, aux; // aux is just a vector that is a temporary place holder. This comes about from the fact that original is not passed by const reference to the command functions.
    int temp;
    string inputfile, command;
    ifstream input;
    bool movement_possible = true;
    
    cout << "enter initial configuration file name:" << endl;
    cin >> inputfile;
    
    input.open(inputfile.c_str());
    
    if (input.is_open()) {
        while (input >> temp) {
            original.push_back(temp);
        }
    }
    
    else if (!input.is_open()){ // routine for setting up default configuration
        cout << "file not found, using default start configuration" << endl;
        for (int i = 0; i < 16; i++) {
            if(i < 15){
                original.push_back(0);
            }
            else if (i == 15){
                original.push_back(2);
            }
        }
    }
    
    cout << original[0] << "\t" << original[1] << "\t" << original[2] << "\t" << original[3] << endl;
    cout << original[4] << "\t" << original[5] << "\t" << original[6] << "\t" << original[7] << endl;
    cout << original[8] << "\t" << original[9] << " \t" << original[10] << "\t" << original[11] << endl;
    cout << original[12] << "\t" << original[13] << "\t" << original[14] << "\t" << original[15] << endl;
    
    
    while(movement_possible) {
        cin >> command;
        if (command == "a") {
            commandleft(original, modified);
            if (original != modified){
                random(modified);
                cout << modified[0] << "\t" << modified[1] << "\t" << modified[2] << "\t" << modified[3] << endl;
                cout << modified[4] << "\t" << modified[5] << "\t" << modified[6] << "\t" << modified[7] << endl;
                cout << modified[8] << "\t" << modified[9] << "\t" << modified[10] << "\t" << modified[11] << endl;
                cout << modified[12] << "\t" << modified[13] << "\t" << modified[14] << "\t" << modified[15] << endl;
            }
            original = modified; //so that the game may continue, always using modified as the vector with the latest changes
            movement_possible = check_possibility(original);
        }
        
        else if (command == "s"){
            commanddown(original, modified);
            if (original != modified){
                random(modified);
                cout << modified[0] << "\t" << modified[1] << "\t" << modified[2] << "\t" << modified[3] << endl;
                cout << modified[4] << "\t" << modified[5] << "\t" << modified[6] << "\t" << modified[7] << endl;
                cout << modified[8] << "\t" << modified[9] << "\t" << modified[10] << "\t" << modified[11] << endl;
                cout << modified[12] << "\t" << modified[13] << "\t" << modified[14] << "\t" << modified[15] << endl;
            }
            original = modified; //so that the game may continue, always using modified as the vector with the latest changes
            movement_possible = check_possibility(original);
        }
        
        else if (command == "d"){
            commandright(original, modified);
            if (original != modified){
                random(modified);
                cout << modified[0] << "\t" << modified[1] << "\t" << modified[2] << "\t" << modified[3] << endl;
                cout << modified[4] << "\t" << modified[5] << "\t" << modified[6] << "\t" << modified[7] << endl;
                cout << modified[8] << "\t" << modified[9] << "\t" << modified[10] << "\t" << modified[11] << endl;
                cout << modified[12] << "\t" << modified[13] << "\t" << modified[14] << "\t" << modified[15] << endl;
                }
            original = modified; //so that the game may continue, always using modified as the vector with the latest changes
            movement_possible = check_possibility(original);
        }
        
        else if (command == "w"){
            commandup(original, modified);
            if (original != modified){
                random(modified);
                cout << modified[0] << "\t" << modified[1] << "\t" << modified[2] << "\t" << modified[3] << endl;
                cout << modified[4] << "\t" << modified[5] << "\t" << modified[6] << "\t" << modified[7] << endl;
                cout << modified[8] << "\t" << modified[9] << "\t" << modified[10] << "\t" << modified[11] << endl;
                cout << modified[12] << "\t" << modified[13] << "\t" << modified[14] << "\t" << modified[15] << endl;
            }
            original = modified; //so that the game may continue, always using modified as the vector with the latest changes
            movement_possible = check_possibility(original);
        }
    }
    
    if (!movement_possible) {
        cout << "Game Over" << endl;
    }
    
    input.close();
    return 0;
}

int index(int row, int col){ //function to return the index of a certain entry in the vector given the row and column where it can be found
    int index;
    index = ((row-1)*4 + (col - 1));
    return index;
}

//functions relevant for downwards movement

void commanddown(vector<int>& v1, vector<int>& v2){//function to achieve complete downward motion
    v2 = v1;//such that all operations are performed on v2 and v1 (the original) remains constant
    for (int j = 3; j > 0; j--) {//j represents rows
        add_down(j, v2);
    }
    for (int i = 1; i < 5 ; i++) { // i is columns
        movedown(v2, i);
    }
}

void movedown(vector<int>& v, int& col){//function to move all entries down
    int aux = 0;
    for (int j = 4; j > 0; j--) {//j represents rows
        if (v[index(j, col)] != 0) {
            v[index(4 - aux, col)] = v[index(j, col)];
            if ((4-aux) != j) {
                v[index(j, col)] = 0;
            }
            aux++;
        }
    }
}

void add_down(int row, vector<int>& v){
    // this is just concerned with the process of adding the similar entries in the game, but not actually moving them down yet
    
    for (int i = 1; i < 5; i++) { // i represents the column
        check_if_same_entries_down(i, v);
        if (v[index(row, i)] == v[index(row+1, i)]) {
            v[index(row+1, i)] = v[index(row+1, i)] + v[index(row, i)];
            v[index(row, i)] = 0;
        }
    }
    
}

void check_if_same_entries_down(int column, vector<int>& v){//checks if similar entries are in the same column separated by 0's and places them next to each other
    bool zero;
    for (int i = 1; i < 5; i++) { // i and j are two separate rows
        for (int j = 1; j < 5; j++) {
            if (i != j) {
                if (v[index(i, column)] == v[index(j, column)]) {
                    if (i<j){
                        zero = zero_in_between_down(column, i, j, v);
                        if (zero) {
                            v[index(j-1, column)] = v[index(i, column)];//moving them next to each other
                            v[index(i, column)] = 0;
                        }
                    }
                    else if (j<i){
                        zero = zero_in_between_down(column, j, i, v);
                        if (zero) {
                            v[index(i-1, column)] = v[index(j, column)];
                            v[index(j, column)] = 0;
                        }

                    }
                    
                }
            }
        }
    }
    
}

bool zero_in_between_down(int column, int row1, int row2, const vector<int>& v){ //checks if there are zeros in between two vertical entries
    bool zeroinbetween = false;
    if (row1+1 < row2) { // this if statement is necessary so that the variable is defined if the entries are adjacent
        zeroinbetween = true;
        for (int i = row1+1; (i < row2)&&(zeroinbetween); i++) {
            if(v[index(i, column)] == 0){
                zeroinbetween = true;
            }
            else {
                zeroinbetween = false;
            }
        }
        
    }
    return zeroinbetween;
}

bool check_if_space_down(int column, vector<int>& v){ //checks if there is any room for movement
    bool nothing_to_do, nozero, notsame, zeroatbeg;
    nozero = no_zero(column, v);
    notsame = not_same(column, v);
    zeroatbeg = last_not_zero_down(column, v);
    
    if (((notsame)&&(nozero))||((notsame)&&(zeroatbeg))) {
        nothing_to_do = true;
    }
    else{
        nothing_to_do = false;
    }
    
    return nothing_to_do;
}

bool no_zero(int column, vector<int>& v){ // function to check whether or  not there are any zeros in a given column
    bool no_zero = true;
    for (int j = 1; (j < 5)&&(no_zero); j++) {
        if (v[index(j, column)] != 0) {
            no_zero = true;
        }
        else if (v[index(j, column)] == 0){
            no_zero = false;
        }
    }
    return no_zero;
}

bool not_same(int column, vector<int>& v){ // function to check whether all adjacent entries in a column are the same or not
    bool not_same = true;
    for (int j = 1; (j < 4)&&(not_same); j++) {
        if (v[index(j, column)] != 0) { // since the 0 here represents a blank spot rather than a number
            if (v[index(j, column)] != v[index(j+1, column)]) {
                not_same = true;
            }
            else if (v[index(j, column)] == v[index(j+1, column)]){
                not_same = false;
            }
        }
    }
    return not_same;
}

bool last_not_zero_down(int column, vector<int>& v){ //checks that all the zeros in a given column are adjacent to each other at the top of the column
    bool zero_at_beginning = true;
    for (int j = 4; (j > 0)&&(zero_at_beginning); j--) { // j represents rows
        if (v[index(j, column)] == 0) {
            for (int i = j - 1; (i > 0)&&(zero_at_beginning); i--) {
                if (v[index(i, column)] == 0) {
                    zero_at_beginning = true;
                }
                else{
                    zero_at_beginning = false;
                }
            }
        }
    }
    return zero_at_beginning;
}

//functions relevant for upwards movement

bool first_not_zero_up(int column, vector<int>& v){
    bool zero_at_end = true;
    for (int j = 1; (j < 5)&&(zero_at_end); j++) { // j represents rows
        if (v[index(j, column)] == 0) {
            for (int i = j + 1; (i < 5)&&(zero_at_end); i++) {
                if (v[index(i, column)] == 0) {
                    zero_at_end = true;
                }
                else{
                    zero_at_end = false;
                }
            }
        }
    }
    return zero_at_end;
}

bool check_if_space_up(int column, vector<int>& v){
    bool nothing_to_do, nozero, notsame, zeroatend;
    nozero = no_zero(column, v);
    notsame = not_same(column, v);
    zeroatend = first_not_zero_up(column, v);
    
    if (((notsame)&&(nozero))||((notsame)&&(zeroatend))) {
        nothing_to_do = true;
    }
    else{
        nothing_to_do = false;
    }
    
    return nothing_to_do;
}

void check_if_same_entries_up(int column, vector<int>& v){//checks if similar entries are in the same column separated by 0's and places them next to each other
    bool zero;
    for (int i = 1; i < 5; i++) { // i and j are two separate columns
        for (int j = 1; j < 5; j++) {
            if (i != j) {
                if (v[index(i, column)] == v[index(j, column)]) {
                    if (i<j){
                        zero = zero_in_between_down(column, i, j, v);
                        if (zero) {
                            v[index(i+1, column)] = v[index(j, column)];
                            v[index(j, column)] = 0;
                        }
                    }
                    else if (j<i){
                        zero = zero_in_between_down(column, j, i, v);
                        if (zero) {
                            v[index(j+1, column)] = v[index(i, column)];
                            v[index(i, column)] = 0;
                        }
                        
                    }
                    
                }
            }
        }
    }
    
}

void add_up(int row, vector<int>& v1){
    // this is just concerned with the process of adding the similar entries in the game, but not actually moving them down yet
    for (int i = 1; i < 5; i++) { // i represents the column
        check_if_same_entries_up(i, v1);
        if (v1[index(row, i)] == v1[index(row+1, i)]) {
            v1[index(row, i)] = v1[index(row+1, i)] + v1[index(row, i)];
            v1[index(row+1, i)] = 0;
        }
    }
    
}

void moveup(vector<int>& v, int& col){
    int aux = 0;
    for (int j = 1; j < 5; j++) {//j represents rows
        if (v[index(j, col)] != 0) {
            v[index(aux + 1, col)] = v[index(j, col)];
            if ((aux+1)!=j) {
                v[index(j, col)] = 0;
            }
            aux++;
        }
    }
}

void commandup(vector<int>& v1, vector<int>& v2){ // possible keeps track of basically whether the modified vector is the same as the original one or not
    v2 = v1;
    for (int j = 1; j < 4; j++) {//j represents rows
        add_up(j, v2);
    }
    
    for(int i = 4; i > 0; i--){
        moveup(v2, i);
    }
    
}
//functions relevant to rightward movement

bool no_zero_horizontal(int row, vector<int>& v){ // function to check whether or  not there are any zeros in a given column
    bool no_zero = true;
    for (int j = 1; (j < 5)&&(no_zero); j++) {//j here represents columns
        if (v[index(row, j)] != 0) {
            no_zero = true;
        }
        else if (v[index(row, j)] == 0){
            no_zero = false;
        }
    }
    return no_zero;
}

bool not_same_horizontal(int row, vector<int>& v){ // function to check whether all adjacent entries in a column are the same or not
    bool not_same = true;
    for (int j = 1; (j < 4)&&(not_same); j++) {//j represents columns
        if (v[index(row, j)] != 0) { // since the 0 here represents a blank spot rather than a number
            if (v[index(row, j)] != v[index(row, j+1)]) {
                not_same = true;
            }
            else if (v[index(row, j)] == v[index(row, j+1)]){
                not_same = false;
            }
        }
    }
    return not_same;
}

bool left_not_zero_right(int row, vector<int>& v){
    bool zero_at_left = true;
    for (int j = 4; (j > 0)&&(zero_at_left); j--) { // j represents columns
        if (v[index(row, j)] == 0) {
            for (int i = j - 1; (i > 0)&&(zero_at_left); i--) {
                if (v[index(row, i)] == 0) {
                    zero_at_left = true;
                }
                else{
                    zero_at_left = false;
                }
            }
        }
    }
    return zero_at_left;
}

bool check_if_space_right(int row, vector<int>& v){
    bool nothing_to_do, nozero, notsame, zeroatbeg;
    nozero = no_zero_horizontal(row, v);
    notsame = not_same_horizontal(row, v);
    zeroatbeg = left_not_zero_right(row, v);
    
    if (((notsame)&&(nozero))||((notsame)&&(zeroatbeg))) {
        nothing_to_do = true;
    }
    else{
        nothing_to_do = false;
    }
    
    return nothing_to_do;
}

bool zero_in_between_right(int row, int col1, int col2, const vector<int>& v){ //checks if there are zeros in between two vertical entries
    bool zeroinbetween = false;
    if (col1+1 < col2) { // this if statement is necessary so that the variable is defined if row2= row1+1
        zeroinbetween = true;
        for (int i = col1+1; (i < col2)&&(zeroinbetween); i++) {
            if(v[index(row, i)] == 0){
                zeroinbetween = true;
            }
            else {
                zeroinbetween = false;
            }
        }
        
    }
    return zeroinbetween;
}

void check_if_same_entries_right(int row, vector<int>& v){//checks if similar entries are in the same column separated by 0's and places them next to each other
    bool zero;
    for (int i = 1; i < 5; i++) { // i and j are two separate rows
        for (int j = 1; j < 5; j++) {
            if (i != j) {
                if (v[index(row, i)] == v[index(row, j)]) {
                    if (i<j){
                        zero = zero_in_between_right(row, i, j, v);
                        if (zero) {
                            v[index(row, j-1)] = v[index(row, i)];
                            v[index(row, i)] = 0;
                        }
                    }
                    else if (j<i){
                        zero = zero_in_between_right(row, j, i, v);
                        if (zero) {
                            v[index(row, i-1)] = v[index(row, j)];
                            v[index(row, j)] = 0;
                        }
                        
                    }
                    
                }
            }
        }
    }
    
}

void add_right(int column, vector<int>& v1){
    // this is just concerned with the process of adding the similar entries in the game, but not actually moving them down yet
    
    for (int i = 1; i < 5; i++) { // i represents a row
        check_if_same_entries_right(i, v1);
        if (v1[index(i, column)] == v1[index(i, column + 1)]) {
            v1[index(i, column + 1)] = v1[index(i, column + 1)] + v1[index(i, column)];
            v1[index(i, column)] = 0;
        }
    }
    
}

void commandright(vector<int>& v1, vector<int>& v2){
    v2 = v1;
    for (int j = 3; j > 0; j--) {//j represents rows
        add_right(j, v2);
    }
    for (int i = 1; i < 5 ; i++) { // i is columns
        moveright(v2, i);
    }
}

void moveright(vector<int>& v, int& row){
    int aux = 0;
    for (int j = 4; j > 0; j--) {//j represents columns
        if (v[index(row, j)] != 0) {
            v[index(row, 4 - aux)] = v[index(row, j)];
            if ((4-aux)!=j) {
                v[index(row, j)] = 0;
            }
            aux++;
        }
    }
}

//functions relevant for leftward movement

bool right_not_zero_left(int row, vector<int>& v){
    bool zero_at_right = true;
    for (int j = 1; (j < 5)&&(zero_at_right); j++) { // j represents columns
        if (v[index(row, j)] == 0) {
            for (int i = j + 1; (i < 5)&&(zero_at_right); i++) {
                if (v[index(row, i)] == 0) {
                    zero_at_right = true;
                }
                else{
                    zero_at_right = false;
                }
            }
        }
    }
    return zero_at_right;
}

bool check_if_space_left(int row, vector<int>& v){
    bool nothing_to_do, nozero, notsame, zeroatend;
    nozero = no_zero_horizontal(row, v);
    notsame = not_same_horizontal(row, v);
    zeroatend = right_not_zero_left(row, v);
    
    if (((notsame)&&(nozero))||((notsame)&&(zeroatend))) {
        nothing_to_do = true;
    }
    else{
        nothing_to_do = false;
    }
    
    return nothing_to_do;
}

void check_if_same_entries_left(int row, vector<int>& v){//checks if similar entries are in the same column separated by 0's and places them next to each other
    bool zero;
    for (int i = 1; i < 5; i++) { // i and j are two separate rows
        for (int j = 1; j < 5; j++) {
            if (i != j) {
                if (v[index(row, i)] == v[index(row, j)]) {
                    if (i<j){
                        zero = zero_in_between_right(row, i, j, v);
                        if (zero) {
                            v[index(row, i+1)] = v[index(row, j)];
                            v[index(row, j)] = 0;
                        }
                    }
                    else if (j<i){
                        zero = zero_in_between_right(row, j, i, v);
                        if (zero) {
                            v[index(row, j+1)] = v[index(row, i)];
                            v[index(row, i)] = 0;
                        }
                        
                    }
                    
                }
            }
        }
    }
    
}

void add_left(int column, vector<int>& v1){
    // this is just concerned with the process of adding the similar entries in the game, but not actually moving them down yet
    
    for (int i = 1; i < 5; i++) { // i represents the row
        check_if_same_entries_left(i, v1);
        if (v1[index(i, column)] == v1[index(i, column + 1)]) {
            v1[index(i, column)] = v1[index(i, column + 1)] + v1[index(i, column)];
            v1[index(i, column + 1)] = 0;
        }
    }
    
}

void moveleft(vector<int>& v, int& row){
    int aux = 0;
    for (int j = 1; j < 5; j++) {//j represents columns
        if (v[index(row, j)] != 0) {
            v[index(row, aux + 1)] = v[index(row, j)];
            if ((aux + 1)!= j) {
                v[index(row, j)] = 0;
            }
            aux++;
        }
    }
}

void commandleft(vector<int>& v1, vector<int>& v2){ // possible keeps track of basically whether the modified vector is the same as the original one or not
    v2 = v1;
    for (int j = 1; j < 4; j++) {//j represents rows
        add_left(j, v2);
    }
    
    for(int i = 4; i > 0; i--){
        moveleft(v2, i);
    }
}


bool check_possibility(vector<int>& v){
    bool possible = false;
    for (int i = 1; (!possible)&&(i < 5); i++) { // i represents columns in this function
        possible = !check_if_space_down(i, v);// the inversion is because the check function returns true if there is no possibility for movement
    }
    for (int i = 1; (!possible)&&(i < 5); i++) { // i represents columns in this function
        possible = !check_if_space_up(i, v);
    }
    for (int j = 1; (!possible)&&(j < 5); j++) { // j represents rows in this function
        possible = !check_if_space_right(j, v);
    }
    for (int j = 1; (!possible)&&(j < 5); j++) { // j represents rows in this function
        possible = !check_if_space_left(j, v);
    }
    
    return possible;
}

void random(vector<int>& v){ // function to place a 2 in a random cell in the 4x4 square
    int n1 = rand() % 4 + 1;
    int n2 = rand() % 4 + 1;
    int temp1 = n1, temp2 = n2;
    if (v[index(temp1, temp2)] == 0) {
        v[index(temp1, temp2)] = 2;
    }
    else if (v[index(n1, n2)] != 0){
        random(v);
    }
}
