#include <GL/glut.h>
#include <iostream>
#include <string>
#include "turtle.hpp"

#define DISTANCE 0.005

using namespace std;

vector<pair<char, string>> rules;

void config();
void displayMe();

int main(int argc, char **argv){

   rules.push_back(make_pair('F',"FF"));
   rules.push_back(make_pair('X',"F-[+X]+[F]-F[-FX]+X"));
   
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
   // LINE COLOR
   glColor3f(0, 0, 1);
   // BG COLOR
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);
}

void displayMe(void){
   Turtle t;
   t.draw(rules);
}

