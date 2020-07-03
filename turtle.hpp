#pragma once

#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <utility>
#define START_X 0.0
#define START_Y -1.0
#define START_ANGLE 90

using namespace std;

double toRad(double angle){ return (angle*M_PI)/180; }

class Turtle {
   double x, y, direction;

   void drawLine(double x, double y, double fX, double fY){
      glBegin(GL_LINES);
      glVertex2d(x, y);
      glVertex2d(fX, fY);
      glEnd();
      glFlush();
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

};