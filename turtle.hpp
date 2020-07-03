#pragma once

#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <utility>
#include <vector>
#define START_X 0.0
#define START_Y -1.0
#define START_ANGLE 90
#define DISTANCE 0.005

using namespace std;

int LENGTH = 7;
int LEFT_ANGLE = 15;
int RIGHT_ANGLE = 60;
string INITIAL = "[X]";

class Turtle {
   double x, y, direction;

   void right(double angle){ 
         direction -= angle; 
   }

   void left(double angle){ 
      direction += angle; 
   }

   void forward(double distance){
      double fX = x + distance*cos(toRad(direction)),
             fY = y + distance*sin(toRad(direction));

      drawLine(x, y, fX, fY);
      setPosition(fX, fY);
   }

   void drawLine(double x, double y, double fX, double fY){
      glBegin(GL_LINES);
      glVertex2d(x, y);
      glVertex2d(fX, fY);
      glEnd();
      glFlush();
   }

   double toRad(double angle){ return (angle*M_PI)/180; }

   string replaceString(char symbol, string replacement, string sequence){
      for(int i = sequence.size()-1; i>=0; i--){
         if(sequence[i] == symbol){
            if(i==sequence.size()-1)
               sequence = sequence.substr(0, i) + replacement;
            else if(i==0)
               sequence = replacement + sequence.substr(1);
            else
               sequence = sequence.substr(0,i) + replacement + sequence.substr(i+1);
         }
      }

      return sequence;
   }

   string gen(vector<pair<char, string>> rules){
      string sequence = INITIAL;

      for (int i = 0; i < LENGTH; i++)
         for(pair<char, string> rule : rules)
            sequence = replaceString(rule.first, rule.second, sequence);
      return sequence;
   }

public:

   Turtle():x(START_X),y(START_Y),direction(START_ANGLE){}
   Turtle(double vX, double vY){
      setPosition(vX, vY);
   }

   void setPosition(double vX,double vY){
      x = vX;
      y = vY;
   }

   pair <double, double> getPosition(){
      pair <double, double> pos(x,y);
      return pos;
   }

   void setDirection(double angle){
      direction = angle;
   }

   double getDirection(){
      return direction;
   }

   void draw(vector<pair<char, string>> rules){
      string symbols = gen(rules);

      vector<pair<double, double>> stackPos;
      vector<double> stackDir;

      for(int i=0; i<symbols.size()-1; i++){
         if(symbols[i] == 'F')
            forward(DISTANCE);
         else if(symbols[i] == '-')
            left(LEFT_ANGLE);
         else if(symbols[i] == '+')
            right(RIGHT_ANGLE);
         else if(symbols[i] == '['){
            stackPos.push_back(getPosition());
            stackDir.push_back(direction);
         }
         else if(symbols[i] == ']'){
            setPosition(stackPos[stackPos.size()-1].first, stackPos[stackPos.size()-1].second);
            setDirection(stackDir[stackDir.size()-1]);
            stackDir.pop_back();
            stackPos.pop_back();
         }
      }
   }
};



