#include <iostream>
#include <graphics.h>
#include "header.h"
#include <string>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <Windows.h>
using namespace std;
int main(){
ofstream fout;
ifstream fin;
int i, j;
bool quit_game=false;
initwindow(900, 700);
Game_Screen show;//set up screen
PlaySound("Music\BDZ.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //play on loop
display_main_screen();//1st screen
run_game play;
highscore end[11];
for(i=0; i<26; i++){
    play.press[i]=0;
}
//play.press={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //implement variables
for(i=0; i<26; i++){
        play.press_counter[i]=0;
}
//play.press_counter={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
play.incorrect_counter=0;
play.score=0;
play.correct_checker=0;
for(i=0; i<26; i++){
    play.guess[i]='0';
}
//play.guess={'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
play.new_cat=true;
play.selection=0;
for(i=0; i<25; i++){
    play.text_check[i]="";
}
string starter="HIGHSCORES\n\n";//is compared to what is getchar-ed from the highscore.txt file
char ch;
string compare="";
for(i=0; i<11; i++){
    for(j=0; j<5; j++){
        end[i].record[j]='0';
    }
    //end[i].record={'0', '0', '0', '0'};
    for(j=0; j<4; j++){
        end[i].name[j]='0';
    }
    //end[i].name={'0', '0', '0'};
    end[i].ex=0;
    end[i].why=0;
}
play=opening(&play);
play=gameplay(&play);
while(quit_game==false){
    if(play.incorrect_counter!=10){
        play.success=true;
        success_screen();
        while(ismouseclick(WM_MOUSEMOVE) || !ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_LBUTTONUP)){
            if(ismouseclick(WM_MOUSEMOVE))
                getmouseclick(WM_MOUSEMOVE, play.x, play.y);
            else if(ismouseclick(WM_LBUTTONUP))
                getmouseclick(WM_LBUTTONUP, play.x, play.y);
            if(play.x>=185 && play.x<=415 && play.y>=490 && play.y<=545){ //hover over continue game
                setfillstyle(SOLID_FILL, WHITE);
                bar(185, 490, 415, 495);
                bar(185, 540, 415, 545);
                bar(185, 490, 190, 545);
                bar(410, 490, 415, 545);
            }
            else{ //not hovering over continue game
                setfillstyle(SOLID_FILL, BLACK);
                bar(185, 490, 415, 495);
                bar(185, 540, 415, 545);
                bar(185, 490, 190, 545);
                bar(410, 490, 415, 545);
            }
            if(play.x>=535 && play.x<=665 && play.y>=490 && play.y<=545){ //hover over quit game
                setfillstyle(SOLID_FILL, WHITE);
                bar(535, 490, 665, 495);
                bar(535, 540, 665, 545);
                bar(535, 490, 540, 545);
                bar(660, 490, 665, 545);
            }
            else{ //not hovering over quit game
                setfillstyle(SOLID_FILL, BLACK);
                bar(535, 490, 665, 495);
                bar(535, 540, 665, 545);
                bar(535, 490, 540, 545);
                bar(660, 490, 665, 545);
            }
            if(play.x>=175 && play.x<=680 && play.y>=390 && play.y<=445){ //hover over choose new category
                setfillstyle(SOLID_FILL, WHITE);
                bar(175, 390, 680, 395);
                bar(175, 440, 680, 445);
                bar(175, 390, 180, 445);
                bar(675, 390, 680, 445);
            }
            else{ //not hovering over choose new category
                setfillstyle(SOLID_FILL, BLACK);
                bar(175, 390, 680, 395);
                bar(175, 440, 680, 445);
                bar(175, 390, 180, 445);
                bar(675, 390, 680, 445);
            }
            delay(100);
        }
        getmouseclick(WM_LBUTTONDOWN, play.x, play.y);
        play.incorrect_counter=0;
        if(play.x>=185 && play.x<=415 && play.y>=490 && play.y<=545){//user picks continue with game
            play.new_cat=false;//user will NOT pick a new category
            play=reset(&play);//calls on reset function; which clears the screen, resets press and the guess array
            play=gameplay(&play);
            continue;
        }
        else if(play.x>=535 && play.x<=665 && play.y>=490 && play.y<=545){//user picks quit game
            play=reset(&play);
            play=highscore_enter_screen(&play);
            quit_game=true;
        }
        else if(play.x>=175 && play.x<=680 && play.y>=390 && play.y<=445){ //user picks choose new category
            play.new_cat=true;//user will pick a new category
            play.selection=0;//reset word selection (it has not been chosen yet)
            play=reset(&play);//see above
            play=gameplay(&play);
            continue;
        }
        else
            continue;
    }
    else{
        play.success=false;
        failure_screen();
        while(ismouseclick(WM_MOUSEMOVE) || !ismouseclick(WM_LBUTTONDOWN) || ismouseclick(WM_LBUTTONUP)){
            if(ismouseclick(WM_MOUSEMOVE))
                getmouseclick(WM_MOUSEMOVE, play.x, play.y);
            else if(ismouseclick(WM_LBUTTONUP))
                getmouseclick(WM_LBUTTONUP, play.x, play.y);
            if(play.x>=165 && play.x<=435 && play.y>=390 && play.y<=445){ //hover over play again
                setfillstyle(SOLID_FILL, WHITE);
                bar(165, 390, 435, 395);
                bar(165, 440, 435, 445);
                bar(165, 390, 170, 445);
                bar(430, 390, 435, 445);
            }
            else{ //not hovering over play again
                setfillstyle(SOLID_FILL, BLACK);
                bar(165, 390, 435, 395);
                bar(165, 440, 435, 445);
                bar(165, 390, 170, 445);
                bar(430, 390, 435, 445);
            }
            if(play.x>=515 && play.x<=635 && play.y>=390 && play.y<=445){ //hover over quit
                setfillstyle(SOLID_FILL, WHITE);
                bar(515, 390, 635, 395);
                bar(515, 440, 635, 445);
                bar(515, 390, 520, 445);
                bar(630, 390, 635, 445);
            }
            else{ //not hovering over quit
                setfillstyle(SOLID_FILL, BLACK);
                bar(515, 390, 635, 395);
                bar(515, 440, 635, 445);
                bar(515, 390, 520, 445);
                bar(630, 390, 635, 445);
            }
            delay(100);
        }
        setfillstyle(SOLID_FILL, BLACK);
        getmouseclick(WM_LBUTTONDOWN, play.x, play.y);
        if(play.x>=165 && play.x<=435 && play.y>=390 && play.y<=445){//play again
            play.new_cat=true;
            play=reset(&play);
            play=highscore_enter_screen(&play);
            end[10]=get_letter();//last in array is current player
            delay(3000);
            fin.open("highscore.txt", ios_base::in);
            while(fin.get(ch)){
                compare+=ch;
                if(compare==starter)
                    break;
            }
            for(i=0;i<10;i++){
                for(j=0; j<3; j++){
                    fin.get(ch);
                    end[i].name[j]=ch;
                }
                fin.get(ch);//gets tab character
                for(j=0;j<4;j++){
                    fin.get(ch);
                    end[i].record[j]=ch;
                }
                fin.get(ch); //enter
            }
            fin.close();
            compare="";
            int condense[11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for(i=0;i<11;i++){
                for(j=0; j<5; j++){
                    if(i<10){
                        if(j==0)
                            condense[i]=((end[i].record[j]-'0')*1000);
                        else if(j==1)
                            condense[i]=condense[i]+((end[i].record[j]-'0')*100);
                        else if(j==2)
                            condense[i]=condense[i]+((end[i].record[j]-'0')*10);
                        else if(j==3)
                            condense[i]=condense[i]+(end[i].record[j]-'0');
                    }
                }
                if(i==10)
                    condense[i]=play.score;
            }
            bubble_sort(end, condense);
                for (i=0; i<11; i++){
                    for(j=0; j<4; j++)
                        cout<<end[i].name[j]<<" ";
                    cout<<endl;
                    cout<<condense[i]<<" ";
                cout<<endl;
                }
            for(i=0; i<10; i++){
                if(condense[i]<=9999 && condense[i]>=1000){ //if the score is a 4 digit number
                    end[i].record[3]=condense[i]%10+'0';
                    end[i].record[2]=(condense[i]/10)%10+'0';
                    end[i].record[1]=(condense[i]/100)%10+'0';
                    end[i].record[0]=(condense[i]/1000)+'0';
                }
                else if(condense[i]<1000 && condense[i]>=100){ //if the score is a 3 digit number
                    end[i].record[3]=condense[i]%10+'0';
                    end[i].record[2]=(condense[i]/10)%10+'0';
                    end[i].record[1]=(condense[i]/100)%10+'0';
                    end[i].record[0]='0';
                }
                else if(condense[i]<100 && condense[i]>=10){ //if the score is a 2 digit number
                    end[i].record[3]=condense[i]%10+'0';
                    end[i].record[2]=(condense[i]/10)%10+'0';
                    end[i].record[1]='0';
                    end[i].record[0]='0';
                }
                else{ //if the score is a 1 digit number
                    end[i].record[3]=condense[i]%10+'0';
                    end[i].record[2]='0';
                    end[i].record[1]='0';
                    end[i].record[0]='0';
                }
            }
            fout.open("highscore.txt", ios_base::out | ios_base::trunc);
            fout<<starter;
            for(i=0; i<10; i++){
                for(j=0; j<3; j++)
                    fout<<end[i].name[j];
                fout<<"\t";
                for(j=0; j<4; j++)
                    fout<<end[i].record[j];
                fout<<endl;
            }
            fout.close();
            condense[10]=0;
            play=reset(&play);
            play.selection=0;
            display_main_screen();
            play=opening(&play);
            play=gameplay(&play);
            continue;
        }
        else if(play.x>=515 && play.x<=635 && play.y>=390 && play.y<=445){//quit
            play=reset(&play);
            play=highscore_enter_screen(&play);
            quit_game=true;
        }
        else
            continue;
    }
end[10]=get_letter();//last in array is current player
}
quit();
fin.open("highscore.txt", ios_base::in);
while(fin.get(ch)){
    compare+=ch;
    if(compare==starter)
        break;
}
for(i=0;i<10;i++){
    for(j=0; j<3; j++){
        fin.get(ch);
        end[i].name[j]=ch;
    }
    fin.get(ch);//gets tab character
    for(j=0;j<4;j++){
        fin.get(ch);
        end[i].record[j]=ch;
    }
    fin.get(ch); //enter
}
fin.close();
compare="";
int condense[11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
for(i=0;i<11;i++){
    for(j=0; j<5; j++){
        if(i<10){
            if(j==0)
                condense[i]=((end[i].record[j]-'0')*1000);
            else if(j==1)
                condense[i]=condense[i]+((end[i].record[j]-'0')*100);
            else if(j==2)
                condense[i]=condense[i]+((end[i].record[j]-'0')*10);
            else if(j==3)
                condense[i]=condense[i]+(end[i].record[j]-'0');
        }
    }
    if(i==10)
        condense[i]=play.score;
}
bubble_sort(end, condense);
for(i=0; i<11; i++){
    for(j=0; j<4; j++)
        cout<<end[i].name[j]<<" ";
    cout<<endl;
    cout<<condense[i]<<" ";
cout<<endl;
}
for(i=0; i<10; i++){
    if(condense[i]<=9999 && condense[i]>=1000){ //if the score is a 4 digit number
        end[i].record[3]=condense[i]%10+'0';
        end[i].record[2]=(condense[i]/10)%10+'0';
        end[i].record[1]=(condense[i]/100)%10+'0';
        end[i].record[0]=(condense[i]/1000)+'0';
    }
    else if(condense[i]<1000 && condense[i]>=100){ //if the score is a 3 digit number
        end[i].record[3]=condense[i]%10+'0';
        end[i].record[2]=(condense[i]/10)%10+'0';
        end[i].record[1]=(condense[i]/100)%10+'0';
        end[i].record[0]='0';
    }
    else if(condense[i]<100 && condense[i]>=10){ //if the score is a 2 digit number
        end[i].record[3]=condense[i]%10+'0';
        end[i].record[2]=(condense[i]/10)%10+'0';
        end[i].record[1]='0';
        end[i].record[0]='0';
    }
    else{ //if the score is a 1 digit number
        end[i].record[3]=condense[i]%10+'0';
        end[i].record[2]='0';
        end[i].record[1]='0';
        end[i].record[0]='0';
    }
}
fout.open("highscore.txt", ios_base::out | ios_base::trunc);
fout<<starter;
for(i=0; i<10; i++){
    for(j=0; j<3; j++)
        fout<<end[i].name[j];
    fout<<"\t";
    for(j=0; j<4; j++)
        fout<<end[i].record[j];
    fout<<endl;
}
fout.close();
condense[10]=0;
while(!getchar()){
    delay(200);
}

return 0;
}
