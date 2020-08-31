#include <iostream>
#include <graphics.h>
#include "header.h"
#include <string>
#include <fstream>
#include <time.h>
#include <Windows.h>
using namespace std;
string word_randomizer(string text[]){//returns a random number that is the index of the array of the chosen category
    srand((unsigned) time(NULL));
    int index=rand()%25;
    string word=text[index];
    return word;
}

char letter_click(int x, int y, int press[], int press_counter[]){ //for the click in the alphabet grid on the game screen
    char letter;
    if(x>=55 && x<=145 && y>=152 && y<=211 && press[0]==0){//A
        letter='A';
        press[0]=1; //press is a flag array; the index for a is 0, so then press[1] is for b and so on
        press_counter[0]++; //press_counter is a counter for the amount of times you click that letter on the screen; only goes through if you have clicked it once so it won't keep on registering that letter as another thing
    }
    if(x>=150 && x<=245 && y>=152 && y<=211 && press[1]==0){//B
        letter='B'; //see above
        press[1]=1;
        press_counter[1]++;
    }
    if(x>=250 && x<=345 && y>=152 && y<=211 && press[2]==0){//C
        letter='C';
        press[2]=1;
        press_counter[2]++;
    }
    if(x>=350 && x<=445 && y>=152 && y<=211 && press[3]==0){//D
        letter='D';
        press[3]=1;
        press_counter[3]++;
    }
    if(x>=55 && x<=145 && y>=216 && y<=275 && press[4]==0){//E
        letter='E';
        press[4]=1;
        press_counter[4]++;
    }
    if(x>=150 && x<=245 && y>=216 && y<=275 && press[5]==0){//F
        letter='F';
        press[5]=1;
        press_counter[5]++;
    }
    if(x>=250 && x<=345 && y>=216 && y<=275 && press[6]==0){//G
        letter='G';
        press[6]=1;
        press_counter[6]++;
    }
    if(x>=350 && x<=445 && y>=216 && y<=275 && press[7]==0){//H
        letter='H';
        press[7]=1;
        press_counter[7]++;
    }
    if(x>=55 && x<=145 && y>=280 && y<=339 && press[8]==0){//I
        letter='I';
        press[8]=1;
        press_counter[8]++;
    }
    if(x>=150 && x<=245 && y>=280 && y<=339 && press[9]==0){//J
        letter='J';
        press[9]=1;
        press_counter[9]++;
    }
    if(x>=250 && x<=345 && y>=280 && y<=339 && press[10]==0){//K
        letter='K';
        press[10]=1;
        press_counter[10]++;
    }
    if(x>=350 && x<=445 && y>=280 && y<=339 && press[11]==0){//L
        letter='L';
        cout<<letter<<endl;
        press[11]=1;
        press_counter[11]++;
    }
    if(x>=55 && x<=145 && y>=344 && y<=403 && press[12]==0){//M
        letter='M';
        press[12]=1;
        press_counter[12]++;
    }
    if(x>=150 && x<=245 && y>=344 && y<=403 && press[13]==0){//N
        letter='N';
        press[13]=1;
        press_counter[13]++;
    }
    if(x>=250 && x<=345 && y>=344 && y<=403 && press[14]==0){//O
        letter='O';
        press[14]=1;
        press_counter[14]++;
    }
    if(x>=350 && x<=445 && y>=344 && y<=403 && press[15]==0){//P
        letter='P';
        press[15]=1;
        press_counter[15]++;
    }
    if(x>=55 && x<=145 && y>=408 && y<=467 && press[16]==0){//Q
        letter='Q';
        press[16]=1;
        press_counter[16]++;
    }
    if(x>=150 && x<=245 && y>=408 && y<=467 && press[17]==0){//R
        letter='R';
        press[17]=1;
        press_counter[17]++;
    }
    if(x>=250 && x<=345 && y>=408 && y<=467 && press[18]==0){//S
        letter='S';
        press[18]=1;
        press_counter[18]++;
    }
    if(x>=350 && x<=445 && y>=408 && y<=467 && press[19]==0){//T
        letter='T';
        press[19]=1;
        press_counter[19]++;
    }
    if(x>=55 && x<=145 && y>=472 && y<=531 && press[20]==0){//U
        letter='U';
        press[20]=1;
        press_counter[20]++;
    }
    if(x>=150 && x<=245 && y>=472 && y<=531 && press[21]==0){//V
        letter='V';
        press[21]=1;
        press_counter[21]++;
    }
    if(x>=250 && x<=345 && y>=472 && y<=531 && press[22]==0){//W
        letter='W';
        press[22]=1;
        press_counter[22]++;
    }
    if(x>=350 && x<=445 && y>=472 && y<=531 && press[23]==0){//X
        letter='X';
        press[23]=1;
        press_counter[23]++;
    }
    if(x>=55 && x<=145 && y>=536 && y<=595 && press[24]==0){//Y
        letter='Y';
        press[24]=1;
        press_counter[24]++;
    }
    if(x>=150 && x<=245 && y>=536 && y<=595 && press[25]==0){//Z
        letter='Z';
        press[25]=1;
        press_counter[25]++;
    }
    if(!(x>=55 && x<445 && y<=595 && y>=152))//if the user doesn't click any letter, assign to null
        letter=0;
    return letter;
}

highscore get_letter(){ //for entering your name into highscore board
    int i, count=0;
    settextstyle(0, HORIZ_DIR, 6);
    highscore end;
    for(i=0; i<3; i++){ //can have 3 characters as your name
        while(!ismouseclick(WM_LBUTTONDOWN)){delay(100);}
        getmouseclick(WM_LBUTTONDOWN, end.ex, end.why);
        if(end.ex>=55 && end.ex<=145 && end.why>=152 && end.why<=211){//A
            outtextxy(552.5+(47*count), 250, "A"); //if the user chooses a, display a on the line
            end.name[i]='A'; //adds letter to name array
        }
        else if(end.ex>=150 && end.ex<=245 && end.why>=152 && end.why<=211){//B
            outtextxy(552.5+(47*count), 250, "B"); //see above
            end.name[i]='B';
        }
        else if(end.ex>=250 && end.ex<=345 && end.why>=152 && end.why<=211){//C
            outtextxy(552.5+(47*count), 250, "C");
            end.name[i]='C';
        }
        else if(end.ex>=350 && end.ex<=445 && end.why>=152 && end.why<=211){//D
            outtextxy(552.5+(47*count), 250, "D");
            end.name[i]='D';
        }
        else if(end.ex>=55 && end.ex<=145 && end.why>=216 && end.why<=275){//E
            outtextxy(552.5+(47*count), 250, "E");
            end.name[i]='E';
        }
        else if(end.ex>=150 && end.ex<=245 && end.why>=216 && end.why<=275){//F
            outtextxy(552.5+(47*count), 250, "F");
            end.name[i]='F';
        }
        else if(end.ex>=250 && end.ex<=345 && end.why>=216 && end.why<=275){//G
            outtextxy(552.5+(47*count), 250, "G");
            end.name[i]='G';
        }
        else if(end.ex>=350 && end.ex<=445 && end.why>=216 && end.why<=275){//H
            outtextxy(552.5+(47*count), 250, "H");
            end.name[i]='H';
        }
        else if(end.ex>=55 && end.ex<=145 && end.why>=280 && end.why<=339){//I
            outtextxy(552.5+(47*count), 250, "I");
            end.name[i]='I';
        }
        else if(end.ex>=150 && end.ex<=245 && end.why>=280 && end.why<=339){//J
            outtextxy(552.5+(47*count), 250, "J");
            end.name[i]='J';
        }
        else if(end.ex>=250 && end.ex<=345 && end.why>=280 && end.why<=339){//K
            outtextxy(552.5+(47*count), 250, "K");
            end.name[i]='K';
        }
        else if(end.ex>=350 && end.ex<=445 && end.why>=280 && end.why<=339){//L
            outtextxy(552.5+(47*count), 250, "L");
            end.name[i]='L';
        }
        else if(end.ex>=55 && end.ex<=145 && end.why>=344 && end.why<=403){//M
            outtextxy(552.5+(47*count), 250, "M");
            end.name[i]='M';
        }
        else if(end.ex>=150 && end.ex<=245 && end.why>=344 && end.why<=403){//N
            outtextxy(552.5+(47*count), 250, "N");
            end.name[i]='N';
        }
        else if(end.ex>=250 && end.ex<=345 && end.why>=344 && end.why<=403){//O
            outtextxy(552.5+(47*count), 250, "O");
            end.name[i]='O';
        }
        else if(end.ex>=350 && end.ex<=445 && end.why>=344 && end.why<=403){//P
            outtextxy(552.5+(47*count), 250, "P");
            end.name[i]='P';
        }
        else if(end.ex>=55 && end.ex<=145 && end.why>=408 && end.why<=467){//Q
            outtextxy(552.5+(47*count), 250, "Q");
            end.name[i]='Q';
        }
        else if(end.ex>=150 && end.ex<=245 && end.why>=408 && end.why<=467){//R
            outtextxy(552.5+(47*count), 250, "R");
            end.name[i]='R';
        }
        else if(end.ex>=250 && end.ex<=345 && end.why>=408 && end.why<=467){//S
            outtextxy(552.5+(47*count), 250, "S");
            end.name[i]='S';
        }
        else if(end.ex>=350 && end.ex<=445 && end.why>=408 && end.why<=467){//T
            outtextxy(552.5+(47*count), 250, "T");
            end.name[i]='T';
        }
        else if(end.ex>=55 && end.ex<=145 && end.why>=472 && end.why<=531){//U
            outtextxy(552.5+(47*count), 250, "U");
            end.name[i]='U';
        }
        else if(end.ex>=150 && end.ex<=245 && end.why>=472 && end.why<=531){//V
            outtextxy(552.5+(47*count), 250, "V");
            end.name[i]='V';
        }
        else if(end.ex>=250 && end.ex<=345 && end.why>=472 && end.why<=531){//W
            outtextxy(552.5+(47*count), 250, "W");
            end.name[i]='W';
        }
        else if(end.ex>=350 && end.ex<=445 && end.why>=472 && end.why<=531){//X
            outtextxy(552.5+(47*count), 250, "X");
            end.name[i]='X';
        }
        else if(end.ex>=55 && end.ex<=145 && end.why>=536 && end.why<=595){//Y
            outtextxy(552.5+(47*count), 250, "Y");
            end.name[i]='Y';
        }
        else if(end.ex>=150 && end.ex<=245 && end.why>=536 && end.why<=595){//Z
            outtextxy(552.5+(47*count), 250, "Z");
            end.name[i]='Z';
        }
        else{ //if the user doesn't click any letter
            count-=2;
            i--;
        }
        count+=2; //increase count so the next letter is printed on the following line
    }
    settextstyle(2, HORIZ_DIR, 14.6);
    outtextxy(100, 630, "The high score board is displayed in  \"highscore.txt\"");
    return end;
}

run_game opening(run_game *play){
    while(1){
        while(ismouseclick(WM_MOUSEMOVE)){ //for mouse hover
            getmouseclick(WM_MOUSEMOVE, play[0].x, play[0].y);
            if(play[0].x>=335 && play[0].x<=645 && play[0].y>=525 && play[0].y<=600){ //if the mouse is hovering over the play button have a box show up around "PLAY"
                setfillstyle(SOLID_FILL, WHITE);
                bar(335, 525, 645, 520);
                bar(335, 595, 645, 600);
                bar(335, 525, 340, 600);
                bar(640, 525, 645, 600);
            }
            else{ //if not, appear to display nothing
                setfillstyle(SOLID_FILL, BLACK);
                bar(335, 525, 645, 520);
                bar(335, 595, 645, 600);
                bar(335, 525, 340, 600);
                bar(640, 525, 645, 600);
            }
            delay(100);
        }
        getmouseclick(WM_LBUTTONDOWN, play[0].x, play[0].y); //get mouse coordinates of click
        if(play[0].x>=335 && play[0].x<=645 && play[0].y>=525 && play[0].y<=600){//if click is on or near the area of the play button
            setfillstyle(SOLID_FILL, BLACK);
            bar(0, 0, 900, 700);//clears screen
            break;
        }
    }
    return play[0];
}

run_game reset(run_game *play){ //resets important run_game variables
    int i;
    setfillstyle(SOLID_FILL, BLACK);
    bar(0, 0, 900, 700);//clears screen
    for(i=0; i<26; i++){ //reset press for all letters
        play[0].press[i]=0;
        play[0].press_counter[i]=0;
    }
    for(i=0; i<18; i++) //reset guess array
        play[0].guess[i]='0';
    play[0].incorrect_counter=0;
    play[0].inword=false;
    return play[0];
}

void mouse_hover_selection_screen(run_game *play){
    while(ismouseclick(WM_MOUSEMOVE) || !ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_LBUTTONUP)){ //mouse hover
        if(ismouseclick(WM_MOUSEMOVE))
            getmouseclick(WM_MOUSEMOVE, play[0].x, play[0].y);
        else if(ismouseclick(WM_LBUTTONUP))
            getmouseclick(WM_LBUTTONUP, play[0].x, play[0].y);
        if(play[0].x>=275 && play[0].x<=585 && play[0].y>=150 && play[0].y<=225){ //hover over palindromes
            setfillstyle(SOLID_FILL, LIGHTGREEN);
            bar(275, 150, 585, 155);
            bar(275, 220, 585, 225);
            bar(275, 150, 280, 225);
            bar(580, 150, 585, 225);
        }
        else{ //not hovering over palindromes
            setfillstyle(SOLID_FILL, BLACK);
            bar(275, 150, 585, 155);
            bar(275, 220, 585, 225);
            bar(275, 150, 280, 225);
            bar(580, 150, 585, 225);
        }
        if(play[0].x>=245 && play[0].x<=625 && play[0].y>=240 && play[0].y<=335){ //hover over periodic table
            setfillstyle(SOLID_FILL, YELLOW);
            bar(245, 240, 625, 245);
            bar(245, 330, 625, 335);
            bar(245, 240, 250, 335);
            bar(620, 240, 625, 335);
        }
        else{ //not hovering over periodic table
            setfillstyle(SOLID_FILL, BLACK);
            bar(245, 240, 625, 245);
            bar(245, 330, 625, 335);
            bar(245, 240, 250, 335);
            bar(620, 240, 625, 335);
        }
        if(play[0].x>=305 && play[0].x<=560 && play[0].y>=345 && play[0].y<=430){ //hover over countries
            setfillstyle(SOLID_FILL, YELLOW);
            bar(305, 345, 560, 350);
            bar(305, 425, 560, 430);
            bar(305, 345, 310, 430);
            bar(555, 345, 560, 430);
        }
        else{ //not hovering over countries
            setfillstyle(SOLID_FILL, BLACK);
            bar(305, 345, 560, 350);
            bar(305, 425, 560, 430);
            bar(305, 345, 310, 430);
            bar(555, 345, 560, 430);
        }
        if(play[0].x>=335 && play[0].x<=540 && play[0].y>=445 && play[0].y<=530){ //hover over physics
            setfillstyle(SOLID_FILL, LIGHTRED);
            bar(335, 445, 540, 450);
            bar(335, 525, 540, 530);
            bar(335, 445, 340, 530);
            bar(535, 445, 540, 530);
        }
        else{ //not hovering over physics
            setfillstyle(SOLID_FILL, BLACK);
            bar(335, 445, 540, 450);
            bar(335, 525, 540, 530);
            bar(335, 445, 340, 530);
            bar(535, 445, 540, 530);
        }
        if(play[0].x>=220 && play[0].x<=655 && play[0].y>=545 && play[0].y<=630){ //hover over computer science
            setfillstyle(SOLID_FILL, LIGHTRED);
            bar(220, 545, 660, 550);
            bar(220, 625, 660, 630);
            bar(220, 545, 225, 630);
            bar(655, 545, 660, 630);
        }
        else{ //not hovering over computer science
            setfillstyle(SOLID_FILL, BLACK);
            bar(220, 545, 660, 550);
            bar(220, 625, 660, 630);
            bar(220, 545, 225, 630);
            bar(655, 545, 660, 630);
        }
        delay(100);
    }
}
run_game gameplay(run_game *play){
    string text[25]={""};//when a category is chosen, text fills up with each possible phrase
    char s[5]="0000"; //set starting score to 0
    if(play[0].new_cat==true){ //if player chooses to play a new category or if they just opened the game and is choosing the category
        display_selection_screen();//category selection screen
        mouse_hover_selection_screen(&play[0]); //for hover coordinates of mouse
        getmouseclick(WM_LBUTTONDOWN, play[0].x, play[0].y);//get mouse coordinates of click
        }
    setfillstyle(SOLID_FILL, BLACK);
    while(1){
        if((play[0].x>=275 && play[0].x<=585 && play[0].y>=150 && play[0].y<=225)||play[0].selection==1){//category chosen is palindrome
            if(play[0].selection!=1 || play[0].new_cat==true){ //play.selection is what category they choose or have chosen previously
                PlaySound(NULL, NULL, 0); //stop any previous sound
                PlaySound("Music\The Chaser.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //play on loop
            }
            play[0].selection=1;
            string text[25]={"MADAM, I AM ADAM", "RACECAR", "BIRD RIB", "CAMP MAC", "CIVIC", "DON'T NOD", "DENNIS SINNED", "DOOM MOOD", "EMU LOVE VOLUME", "EW! EAT A EWE?", "EVIL OLIVE", "GOD'S DOG", "HANNAH", "I PREFER PI", "KAYAK", "TACOCAT", "LION OIL", "LEVEL", "LLAMA MALL", "NO X IN NIXON", "YO! BANANA BOY", "OLSON IS IN OSLO", "STRESSED DESSERTS", "TO IDIOT", "WONTON? NOT NOW"};
            bar(0, 0, 900, 700);//clears screen
            setcolor(WHITE);
            display_alphabet(play[0].press);//3rd screen; shows alphabet grid on game screen
            settextstyle(0, HORIZ_DIR, 35);
            outtextxy(10, 675, "Category: Palindromes");//display category name at bottom left
            display_score(&play[0].score, s);//display score at bottom right
            play[0].word=word_randomizer(text);//get the answer word
            break;
        }
        else if((play[0].x>=245 && play[0].x<=625 && play[0].y>=240 && play[0].y<=335) ||play[0].selection==2){//chosen category is periodic table
            if(play[0].selection!=2 || play[0].new_cat==true){
                PlaySound(NULL, NULL, 0); //stop sound
                PlaySound("Music\Lullaby.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //play on loop
            }
            play[0].selection=2;
            string text[25]={"OXYGEN", "HYDROGEN", "SILVER", "CHLORINE", "POLONIUM", "HAFNIUM", "BARIUM", "POTASSIUM", "SODIUM", "IRON", "CHROMIUM", "ARSENIC", "ZIRCONIUM", "IODINE", "FLUORINE", "HELIUM", "NEON", "SCANDIUM", "MAGNESIUM", "LITHIUM", "RADIUM", "URANIUM", "TITANIUM", "LEAD", "GOLD"};
            bar(0, 0, 900, 700);
            setcolor(WHITE);
            display_alphabet(play[0].press); //see above
            settextstyle(0, HORIZ_DIR, 35);
            outtextxy(10, 675, "Category: Periodic Table");
            display_score(&play[0].score, s);
            play[0].word=word_randomizer(text);
            break;
        }
        else if((play[0].x>=305 && play[0].x<=560 && play[0].y>=345 && play[0].y<=430) ||play[0].selection==3){//chosen category is countries
            if(play[0].selection!=3 || play[0].new_cat==true){
                PlaySound(NULL, NULL, 0); //stop sound
                PlaySound("Music\Mashup.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //play on loop
            }
            play[0].selection=3;
            string text[25]={"CANADA", "UNITED STATES", "RWANDA", "CHINA", "JAPAN", "KOREA", "UKRAINE", "MEXICO", "ARGENTINA", "INDONESIA", "LAOS", "BULGARIA", "ALBANIA", "BRAZIL", "INDIA", "UNITED KINGDOM", "RUSSIA", "SAUDI ARABIA", "VATICAN CITY", "SWITZERLAND", "BANGLADESH", "GEORGIA", "ICELAND", "SOUTH AFRICA", "THAILAND"};
            bar(0, 0, 900, 700);
            setcolor(WHITE);
            display_alphabet(play[0].press);//see above
            settextstyle(0, HORIZ_DIR, 35);
            outtextxy(10, 675, "Category: Countries");
            display_score(&play[0].score, s);
            play[0].word=word_randomizer(text);
            break;
        }
        else if((play[0].x>=335 && play[0].x<=540 && play[0].y>=445 && play[0].y<=530)||play[0].selection==4){//chosen category is physics
            if(play[0].selection!=4 || play[0].new_cat==true){
                PlaySound(NULL, NULL, 0); //stop sound
                PlaySound("Music\Chained Up.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //play on loop
            }
            play[0].selection=4;
            string text[25]={"KINEMATICS", "NEWTON", "CENTRIFUGAL FORCE", "CENTRIPETAL FORCE", "GRAVITY", "ACCELERATION", "VELOCITY", "RESISTANCE", "DISPLACEMENT", "FORCE", "ENERGY", "ANGULAR MOMENTUM", "CIRCUIT", "PROJECTILE", "VECTOR", "ELECTRIC FIELDS", "TERMINAL VELOCITY", "WAVE", "OPTICS", "ANTIMATTER", "PHOTON", "WORK", "POTENTIAL ENERGY", "COULOMB", "MAGNETIC FORCE"};
            bar(0, 0, 900, 700);//clears screen
            setcolor(WHITE);
            display_alphabet(play[0].press);//see above
            settextstyle(0, HORIZ_DIR, 35);
            outtextxy(10, 675, "Category: Physics");
            display_score(&play[0].score, s);
            play[0].word=word_randomizer(text);
            break;
        }
        else if((play[0].x>=220 && play[0].x<=655 && play[0].y>=545 && play[0].y<=630) ||play[0].selection==5){//chosen category is computer science
            if(play[0].selection!=5 || play[0].new_cat==true){
                PlaySound(NULL, NULL, 0); //stop sound
                PlaySound("Music\Good Boy.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //play on loop
            }
            play[0].selection=5;
            string text[25]={"CLASS INHERITANCE", "ALGORITHM", "ASCII TABLE", "BINARY", "FOR LOOP", "IF ELSE STATEMENT", "STRUCTURE", "STRING", "INTEGER", "FLOAT", "CHAR", "POINTER", "ARRAY", "HEXADECIMAL", "DECIMAL", "FILE HANDLING", "STRING.SIZE()", "RECURSION", "FUNCTION", "MAIN", "ALGORITHM", "INDEX", "ARGUMENT COUNTER", "ARGUMENT VECTOR", "DATABASE"};
            bar(0, 0, 900, 700);
            setcolor(WHITE);
            display_alphabet(play[0].press);//see above
            settextstyle(0, HORIZ_DIR, 35);
            outtextxy(10, 675, "Category: Computer Science");
            display_score(&play[0].score, s);
            play[0].word=word_randomizer(text);
            break;
        }
        else{
            mouse_hover_selection_screen(&play[0]);
            getmouseclick(WM_LBUTTONDOWN, play[0].x, play[0].y);//get mouse coordinates of click
        }
    }
    Game_Screen show;
    for(play[0].i=0;play[0].i<play[0].word.size();play[0].i++){ //for loop for putting in spaces and punctuation into char character array guess that eventually displays all that the user has correctly guessed
        if(!(play[0].word[play[0].i]>='A' && play[0].word[play[0].i]<='Z')){
            play[0].guess[play[0].i]+=play[0].word[play[0].i]-48;
        }
    }
    show.lines(play[0].word);//prints lines in regard to the number of letters in word, also prints any punctuation necessary
    display_alphabet(play[0].press); //prints alphabet grid with letters not chosen
    display_person(play[0].incorrect_counter); //prints hangman person if applicable; if not, prints nothing
    display_score(&play[0].score, s); //displays score on bottom right corner
    while(!ismouseclick(WM_LBUTTONDOWN)){delay(100);}
    getmouseclick(WM_LBUTTONDOWN, play[0].x, play[0].y); //get mouse click
    play[0].letter=letter_click(play[0].x, play[0].y, play[0].press, play[0].press_counter); //get letter chosen from click
    while(1){//10 is the max number of errors possible, if it equals 11 the game is over
        for(play[0].i=0; play[0].i<play[0].word.size(); play[0].i++){ //for loop to go through all the characters in the word array
            if(play[0].word[play[0].i]==play[0].letter){ //if guessed letter is in the word
                play[0].guess[play[0].i]+=play[0].letter-48; //puts correct letter guessed into an array that will be compared to see if it matches the randomized word
                play[0].score+=10; //increase score
                display_score(&play[0].score, s); //show score on screen
                play[0].inword=true;
            }
            play[0].press[play[0].letter-65]=1; //sets press counter for letter to 1 so it will not be clicked again
            //show.lines(play[0].word); //print lines and letters + punctuation in game screen
            display_alphabet(play[0].press); //show alphabet
            show.right_guess(play[0].word, play[0].letter); //prints letters on lines on screen
            show.lines(play[0].word);
        }
        if(play[0].inword==false && play[0].letter!=0 && play[0].press_counter[play[0].letter-65]==1){ //if the letter guessed is not in the word
            play[0].incorrect_counter++; //increase incorrect counter
            display_person(play[0].incorrect_counter); //print person for the number of wrong guesses
            if(play[0].score-5>0) //if when you subtract 5 from the score it is less than 0, set score to 0; if not, subtract 5 from score
                play[0].score-=5;
            else
                play[0].score=0;
            display_score(&play[0].score, s);
            if(play[0].incorrect_counter==10){ //if the hangman is complete, break out of game
                display_score(&play[0].score, s);
                delay(250);
                break;
            }
        }
        for(play[0].i=0;play[0].i<play[0].word.size();play[0].i++){ //check if word guessed is the word generated
            if(play[0].word[play[0].i]!=play[0].guess[play[0].i]){
                play[0].correct_checker=1;
                break;
            }
        }
        if(play[0].correct_checker==0){
            delay(250);
            break;
        }
        play[0].correct_checker=0;
        while(!ismouseclick(WM_LBUTTONDOWN)){delay(100);}
        getmouseclick(WM_LBUTTONDOWN, play[0].x, play[0].y); //get input again
        show.lines(play[0].word);//prints lines in regard to the number of letters in word, also prints any punctuation necessary
        display_alphabet(play[0].press);
        display_person(play[0].incorrect_counter);
        display_score(&play[0].score, s);
        play[0].letter=letter_click(play[0].x, play[0].y, play[0].press, play[0].press_counter);
        play[0].inword=false;
    }
    return play[0];
}

void bubble_sort(highscore *b, int con[]){ //sorts highscore numbers and names; con is an array of all the highscores; index 10 is the user's score that is compared to all the other scores
    int i, length=11, t, top;
    highscore temp;
    bool sorted=false;
    for (top=length-1; top>0 && !sorted; top--){
        sorted=true;
        for(i=0; i<top; i++){
            if(con[i]<con[i+1]){
                sorted=false;
                temp=b[i];
                b[i]=b[i+1];
                b[i+1]=temp;
                t=con[i];
                con[i]=con[i+1];
                con[i+1]=t;
            }
        }
    }
}
