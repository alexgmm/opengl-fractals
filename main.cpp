#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include "turtle.hpp"

#define DISTANCE 0.005
#define LENGTH 7

using namespace std;

void config();
void displayMe();

void gen(int n, string &sequence){
   string r1("FF"), r2("F-[[X]+X]+F[+FX]-X");
   for (int i = 0; i < n; i++){
      char symbol = 'F';
      for (int i = sequence.size() - 1; i >= 0; i--)
            if (sequence[i] == symbol)
               sequence.replace(i, 1, r1);

      symbol = 'X';
      for (int i = sequence.size() - 1; i >= 0; i--)
            if (sequence[i] == symbol)
               sequence.replace(i, 1, r2);
   }
}

void draw(string symbols, double distance, Turtle t){
   vector<pair<double, double>> stackPos;
   vector<double> stackDir;

   for(int i=0; i<symbols.size()-1; i++){
      if(symbols[i] == 'F')
         t.forward(distance);
      else if(symbols[i] == '-')
         t.left(25);
      else if(symbols[i] == '+')
         t.right(25);
      else if(symbols[i] == '['){
         stackPos.push_back(t.getPosition());
         stackDir.push_back(t.getDirection());
      }
      else if(symbols[i] == ']'){
         t.setPosition(stackPos[stackPos.size()-1].first, stackPos[stackPos.size()-1].second);
         t.setDirection(stackDir[stackDir.size()-1]);
         stackDir.pop_back();
         stackPos.pop_back();
      }
   }
}

int main(int argc, char **argv){

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE);
   config();
   glutDisplayFunc(displayMe);
   glutMainLoop();
  
   return 0;
}

void config(){
   glutInitWindowSize(800, 800);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("turtle");
   glLineWidth(0.5);
   glColor3f(0, 0, 1);
}

void displayMe(void){
   string sequence("[X]");
   gen(LENGTH, sequence);
   Turtle t;
   draw(sequence, DISTANCE, t);
}

/* void replaceString(char symbol, string replacement, string &sequence){
   for (int i = sequence.size() - 1; i >= 0; i--){
      if (sequence[i] == symbol)
         sequence.replace(i, 1, replacement);
   }
}

string generate(int n, string result){
   string r1("FF"), r2("F-[[X]+X]+F[+FX]-X");
   for (int i = 0; i < n; i++){ 
      replaceString('F', r1, result);cout << i << endl;
      replaceString('X', r2, result); 
      cout << i << endl;
   }
} */