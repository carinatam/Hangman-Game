#include <iostream>
#include <graphics.h>
#include "header.h"
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
void Game_Screen::alphabet_grid(){ //prints out grid for alphabet on game screen
setfillstyle(SOLID_FILL, WHITE);
//outer box
bar(50, 152, 55, 600);
bar(445, 152, 450, 600);
bar(50, 147, 450, 152);
bar(50, 595, 450, 600);
//columns
bar(145, 152, 150, 600);
bar(245, 152, 250, 600);
bar(345, 152, 350, 600);
bar(445, 152, 450, 600);
//rows
bar(50, 147, 450, 152);
bar(50, 211, 450, 216);
bar(50, 275, 450, 280);
bar(50, 339, 450, 344);
bar(50, 403, 450, 408);
bar(50, 467, 450, 472);
bar(50, 531, 450, 536);
settextstyle(0, HORIZ_DIR, 60);
}
void Game_Screen::a(){ //letter placements on grid on screen
    outtextxy(87, 161, "A");
}
void Game_Screen::b(){ //see above
    outtextxy(187, 161, "B");
}
void Game_Screen::c(){
    outtextxy(287, 161,"C");
}
void Game_Screen::d(){
    outtextxy(387, 161, "D");
}
void Game_Screen::e(){
    outtextxy(87, 225, "E");
}
void Game_Screen::f(){
    outtextxy(187, 225, "F");
}
void Game_Screen::g(){
    outtextxy(287, 225, "G");
}
void Game_Screen::h(){
    outtextxy(387, 225, "H");
}
void Game_Screen::i(){
    outtextxy(87, 289, "I");
}
void Game_Screen::j(){
    outtextxy(187, 289, "J");
}
void Game_Screen::k(){
    outtextxy(287, 289, "K");
}
void Game_Screen::l(){
    outtextxy(387, 289, "L");
}
void Game_Screen::m(){
    outtextxy(87, 353, "M");
}
void Game_Screen::n(){
    outtextxy(187, 353, "N");
}
void Game_Screen::o(){
    outtextxy(287, 353, "O");
}
void Game_Screen::p(){
    outtextxy(387, 353, "P");
}
void Game_Screen::q(){
    outtextxy(87, 417, "Q");
}
void Game_Screen::r(){
    outtextxy(187, 417, "R");
}
void Game_Screen::s(){
    outtextxy(287, 417, "S");
}
void Game_Screen::t(){
    outtextxy(387, 417, "T");
}
void Game_Screen::u(){
    outtextxy(87, 481, "U");
}
void Game_Screen::v(){
    outtextxy(187, 481, "V");
}
void Game_Screen::w(){
    outtextxy(287, 481, "W");
}
void Game_Screen::x(){
    outtextxy(387, 481, "X");
}
void Game_Screen::y(){
    outtextxy(87, 545, "Y");
}
void Game_Screen::z(){
    outtextxy(187, 545, "Z");
}
void display_alphabet(int press[]){//shows alphabet; if it has been pressed, displays a black bar that covers the letter which appears as if the letter has disappeared on the screen
    Game_Screen show;
    show.alphabet_grid();
    if(press[0]!=1) //if it has not been pressed before, show the letter
        show.a();
    else{ //if it has been pressed, cover the letter
        setfillstyle(SOLID_FILL, BLACK);
        bar(55, 152, 145, 211);
    }
    if(press[1]!=1) //see above
        show.b();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(155, 152, 245, 211);
    }
    if(press[2]!=1)
        show.c();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(255, 152, 345, 211);
    }
    if(press[3]!=1)
        show.d();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(355, 152, 445, 211);
    }
    if(press[4]!=1)
        show.e();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(55, 216, 145, 275);
    }
    if(press[5]!=1)
        show.f();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(155, 216, 245, 275);
    }
    if(press[6]!=1)
        show.g();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(255, 216, 345, 275);
    }
    if(press[7]!=1)
        show.h();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(355, 216, 445, 275);
    }
    if(press[8]!=1)
        show.i();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(55, 280, 145, 339);
    }
    if(press[9]!=1)
        show.j();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(155, 280, 245, 339);
    }
    if(press[10]!=1)
        show.k();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(255, 280, 345, 339);
    }
    if(press[11]!=1)
        show.l();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(355, 280, 445, 339);
    }
    if(press[12]!=1)
        show.m();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(55, 344, 145, 403);
    }
    if(press[13]!=1)
        show.n();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(155, 344, 245, 403);
    }
    if(press[14]!=1)
        show.o();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(255, 344, 345, 403);
    }
    if(press[15]!=1)
        show.p();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(355, 344, 445, 403);
    }
    if(press[16]!=1)
        show.q();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(55, 408, 145, 467);
    }
    if(press[17]!=1)
        show.r();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(155, 408, 245, 467);
    }
    if(press[18]!=1)
        show.s();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(255, 408, 345, 467);
    }
    if(press[19]!=1)
        show.t();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(355, 408, 445, 467);
    }
    if(press[20]!=1)
        show.u();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(55, 472, 145, 531);
    }
    if(press[21]!=1)
        show.v();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(155, 472, 245, 531);
    }
    if(press[22]!=1)
        show.w();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(255, 472, 345, 531);
    }
    if(press[23]!=1)
        show.x();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(355, 472, 445, 531);
    }
    if(press[24]!=1)
        show.y();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(55, 536, 145, 595);
    }
    if(press[25]!=1)
        show.z();
    else{
        setfillstyle(SOLID_FILL, BLACK);
        bar(155, 536, 245, 595);
    }
}
void Game_Screen::stand1(){ //various graphics for hangman graphic
    setfillstyle(SOLID_FILL, WHITE);
    bar(550, 595, 750, 600);
}
void Game_Screen::stand2(){
    setfillstyle(SOLID_FILL, WHITE);
    bar(575, 150, 580, 600);

}
void Game_Screen::stand3(){
    setfillstyle(SOLID_FILL, WHITE);
    bar(575, 150, 725, 155);
}
void Game_Screen::stand4(){
    setfillstyle(SOLID_FILL, WHITE);
    bar(720, 150, 725, 200);
}
void Game_Screen::head(){
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(722.5, 250, 50);
    floodfill(725, 250, WHITE);
}
void Game_Screen::body(){
    setfillstyle(SOLID_FILL, WHITE);
    bar(720, 300, 725, 450);
}
void Game_Screen::right_arm(){
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, SOLID_FILL, 5);
    line(722.5, 325, 765, 400);
}
void Game_Screen::left_arm(){
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, SOLID_FILL, 6);
    line(722.5, 325, 680, 400);
}
void Game_Screen::right_leg(){
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, SOLID_FILL, 5);
    line(722, 445, 765, 525);
}
void Game_Screen::left_leg(){
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, SOLID_FILL, 5);
    line(722, 445, 680, 525);
}
void display_person(int ic){//ic is the parameter that represents the incorrect counter
    Game_Screen show;
    if(ic==1)//if user has entered one wrong letter
        show.stand1();//show first piece of hangman
    if(ic==2)//if user has entered two wrong letters
        show.stand2();//show second piece of hangman, etc.
    if(ic==3)
        show.stand3();
    if(ic==4)
        show.stand4();
    if(ic==5)
        show.head();
    if(ic==6)
        show.body();
    if(ic==7)
        show.right_arm();
    if(ic==8)
        show.left_arm();
    if(ic==9)
        show.right_leg();
    if(ic==10)
        show.left_leg();
}//user can enter 10 incorrect letters before failing the level and game
void display_score(int *score, char s[5]){ //shows score; turns into character to print out
    int i;
    if(*score<=9999 && *score>=1000){ //if the score is a 4 digit number
        s[3]=*score%10+'0';
        s[2]=(*score/10)%10+'0';
        s[1]=(*score/100)%10+'0';
        s[0]=(*score/1000)+'0';
    }
    else if(*score<1000 && *score>=100){ //if the score is a 3 digit number
        s[3]=*score%10+'0';
        s[2]=(*score/10)%10+'0';
        s[1]=(*score/100)%10+'0';
    }
    else if(*score<100 && *score>=10){ //if the score is a 2 digit number
        s[3]=*score%10+'0';
        s[2]=(*score/10)%10+'0';
    }
    else //if the score is a 1 digit number
        s[3]=*score%10+'0';
    settextstyle(0, HORIZ_DIR, 32);
    setfillstyle(SOLID_FILL, BLACK);
    bar(740, 605, 895, 695);
    outtextxy(750, 620, "score:");
    outtextxy(750, 650, s);
}
void success_screen(){ //prints when the user has successfully guessed a phrase
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(0,0,900,700);
    settextstyle(2, HORIZ_DIR, 75);
    setcolor(LIGHTGREEN);
    outtextxy(300, 225, "SUCCESS!");
    setcolor(WHITE);
    settextstyle(0, HORIZ_DIR, 60);
    outtextxy(200, 500, "Continue");
    outtextxy(550, 500, "Quit");
    outtextxy(190, 400, "Choose New Category");
}

void failure_screen(){ //prints when the user has failed to guess a phrase/word
    setcolor(BLACK);
    bar(0, 0, 900, 700);
    settextstyle(2, HORIZ_DIR, 75);
    setcolor(LIGHTRED);
    outtextxy(300, 225, "FAILURE!");
    setcolor(WHITE);
    settextstyle(0, HORIZ_DIR, 60);
    outtextxy(175, 400, "Play Again");
    outtextxy(525, 400, "Quit");
}

void display_main_screen(){ //main screen with play button
    settextstyle(0, HORIZ_DIR, 85);
    outtextxy(100, 140, "HANGMAN");
    delay(3000);
    settextstyle(0, HORIZ_DIR, 90);
    outtextxy(280, 350, "by Alex and Carina");
    delay(2000);
    setcolor(RED);
    settextstyle(0, HORIZ_DIR, 85);
    outtextxy(350, 525, "P");
    outtextxy(425, 525, "L");
    outtextxy(500, 525, "A");
    outtextxy(575, 525, "Y");
}

void display_selection_screen(){ //selection screen with all the categories
    PlaySound("Music\Be Mine.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //play music
    settextstyle(0, HORIZ_DIR, 62);
    setcolor(WHITE);
    outtextxy(240, 60, "CATEGORIES");
    setcolor(LIGHTGREEN);//title heads for main categories
    settextstyle(0, HORIZ_DIR, 60);
    outtextxy(295, 160, "PALINDROMES");
    setcolor(YELLOW);
    outtextxy(260, 260, "PERIODIC TABLE");
    outtextxy(320, 360, "COUNTRIES");
    setcolor(LIGHTRED);
    outtextxy(350, 460, "PHYSICS");
    outtextxy(240, 560, "COMPUTER SCIENCE");
    settextstyle(0, HORIZ_DIR, 30);//difficulty level display
    setcolor(LIGHTGREEN);
    outtextxy(402.5, 200, "EASY");
    setcolor(YELLOW);
    outtextxy(387.5, 300, "MEDIUM");
    outtextxy(387.5, 400, "MEDIUM");
    setcolor(LIGHTRED);
    outtextxy(405, 500, "HARD");
    outtextxy(405, 600, "HARD");
}

void Game_Screen::lines(string word){ //lines for word at top of screen
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);
    int i, count=0;
    for(i=0; i<word.size(); i++){
        if(word[i]>='A' && word[i]<='Z') //print out lines if the character is a letter
            bar(22+(47*count), 75, 47+(47*count), 80);
        else if(word[i]=='.')
            outtextxy(22+(47*count), 50, ".");
        else if(word[i]==',')
            outtextxy(22+(47*count), 50, ",");
        else if(word[i]=='?')
            outtextxy(22+(47*count), 50, "?");
        else if(word[i]=='!')
            outtextxy(22+(47*count), 50, "!");
        else if(word[i]=='(')
            outtextxy(22+(47*count), 50, "(");
        else if(word[i]==')')
            outtextxy(22+(47*count), 50, ")");
        else if(word[i]==' ');
        else
            outtextxy(22+(47*count), 50, "'");
        count++;
    }
}

void Game_Screen::right_guess(string word, char letter){ //prints out letter in correct place on screen
    setcolor(WHITE);
    int i;
    for(i=0; i<word.size(); i++){
        if(letter=='A' && letter==word[i])
            outtextxy(22+(47*i), 44, "A");
        else if(letter=='B' && letter==word[i])
            outtextxy(22+(47*i), 44, "B");
        else if(letter=='C' && letter==word[i])
            outtextxy(22+(47*i), 44, "C");
        else if(letter=='D' && letter==word[i])
            outtextxy(22+(47*i), 44, "D");
        else if(letter=='E' && letter==word[i])
            outtextxy(22+(47*i), 44, "E");
        else if(letter=='F' && letter==word[i])
            outtextxy(22+(47*i), 44, "F");
        else if(letter=='G' && letter==word[i])
            outtextxy(22+(47*i), 44, "G");
        else if(letter=='H' && letter==word[i])
            outtextxy(22+(47*i), 44, "H");
        else if(letter=='I' && letter==word[i])
            outtextxy(22+(47*i), 44, "I");
        else if(letter=='J' && letter==word[i])
            outtextxy(22+(47*i), 44, "J");
        else if(letter=='K' && letter==word[i])
            outtextxy(22+(47*i), 44, "K");
        else if(letter=='L' && letter==word[i])
            outtextxy(22+(47*i), 44, "L");
        else if(letter=='M' && letter==word[i])
            outtextxy(22+(47*i), 44, "M");
        else if(letter=='N' && letter==word[i])
            outtextxy(22+(47*i), 44, "N");
        else if(letter=='O' && letter==word[i])
            outtextxy(22+(47*i), 44, "O");
        else if(letter=='P' && letter==word[i])
            outtextxy(22+(47*i), 44, "P");
        else if(letter=='Q' && letter==word[i])
            outtextxy(22+(47*i), 44, "Q");
        else if(letter=='R' && letter==word[i])
            outtextxy(22+(47*i), 44, "R");
        else if(letter=='S' && letter==word[i])
            outtextxy(22+(47*i), 44, "S");
        else if(letter=='T' && letter==word[i])
            outtextxy(22+(47*i), 44, "T");
        else if(letter=='U' && letter==word[i])
            outtextxy(22+(47*i), 44, "U");
        else if(letter=='V' && letter==word[i])
            outtextxy(22+(47*i), 44, "V");
        else if(letter=='W' && letter==word[i])
            outtextxy(22+(47*i), 44, "W");
        else if(letter=='X' && letter==word[i])
            outtextxy(22+(47*i), 44, "X");
        else if(letter=='Y' && letter==word[i])
            outtextxy(22+(47*i), 44, "Y");
        else if(letter=='Z' && letter==word[i])
            outtextxy(22+(47*i), 44, "Z");
    }
}

run_game highscore_enter_screen(run_game *play){ //shows when you quit the game or you have failed a phrase; graphics to set up for inputting your name on the highsscore file
    PlaySound(NULL, NULL, 0); //stop sound
    PlaySound("Music\Me Gustas Tu.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //play on loop
    Game_Screen show;
    display_alphabet(play[0].press);
    show.highscore_lines();
    if(play[0].success==true)
        setcolor(LIGHTGREEN);
    else
        setcolor(LIGHTRED);
    settextstyle(2, HORIZ_DIR, 10);
    outtextxy(40, 67, "GAME OVER! ENTER YOUR NAME: ");
    setcolor(WHITE);
    return play[0];
}

void Game_Screen::highscore_lines(){ //function to display lines for name input
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);
    int i, count=0;
    for(i=1;i<4;i++){
        bar(550+(47*count), 300, 600+(47*count), 307.5);
        count+=2;
    }
}

void quit(){ //when the user quits the game, prints out an ending graphic
    delay(3000);
    setfillstyle(SOLID_FILL, BLACK);
    bar(0, 0, 900, 700);
    settextstyle(2, HORIZ_DIR, 30);
    setcolor(WHITE);
    outtextxy(210, 100, "T H A N K  Y O U");
    settextstyle(2, HORIZ_DIR, 29);
    outtextxy(180, 250, "F O R  P L A Y I N G");
    settextstyle(2, HORIZ_DIR, 50);
    outtextxy(450, 500, ":)");
}
