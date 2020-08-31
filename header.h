#include <iostream>
#include <string>
using namespace std;
struct run_game //holds all main variables for game running
{
    bool inword;//bool type for checking if a letter clicked is in the given word or not
    int x, y, i;// x and y are the coordinates of the mouse click, and i is for index
    char letter;
    bool new_cat, success;
    int press[26];//press is an array containing either 0 or 1 for each letter of the alphabet; if the letter at index i has been pressed before, a 1 will be at index i and not a 0
    int incorrect_counter, score, correct_checker;
    string word;//holds randomized word
    char guess[18];
    int selection;
    int press_counter[26];
    string text_check[25];
};
struct highscore//structure for highscore organizing
{
    char name[4];//hlds users name
    char record[5];//holds users score
    int ex, why; //x and y coordinates
};
class Game_Screen //almost all functions declarations for the game screen
{
private:

public:
    //ALPHABET DISPLAY
    void alphabet_grid();
    void a();
    void b();
    void c();
    void d();
    void e();
    void f();
    void g();
    void h();
    void i();
    void j();
    void k();
    void l();
    void m();
    void n();
    void o();
    void p();
    void q();
    void r();
    void s();
    void t();
    void u();
    void v();
    void w();
    void x();
    void y();
    void z();
    //HANGMAN PIECES
    void stand1();
    void stand2();
    void stand3();
    void stand4();
    void head();
    void body();
    void right_arm();
    void left_arm();
    void right_leg();
    void left_leg();
    //OTHER
    void lines(string word);
    void right_guess(string word, char letter);
    void highscore_lines();
};
//see functions for details
void display_alphabet(int press[]);//function to display the whole left side of game screen
void display_person(int ic);
void display_score(int *score, char s[5]);
void display_main_screen();
void display_selection_screen();
string word_randomizer(string text[]);
char letter_click(int x, int y, int press[], int press_counter[]);
void success_screen();
void failure_screen();
run_game highscore_enter_screen(run_game *play);
run_game reset(run_game *play);
run_game gameplay(run_game *play);
run_game opening(run_game *play);
highscore get_letter();
void bubble_sort(highscore *b, int con[]);
void quit();
void mouse_hover_selection_screen(run_game *play);
