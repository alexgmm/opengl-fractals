#include <GL/glut.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "turtle.hpp"

#define DISTANCE 0.005

using namespace std;



void config();
void displayMe();

int main(int argc, char **argv){
   int n;
   char left;
   string right;
   cin >> n;
   for(n; n>0; n--){
      cin >> left;
      cin >> right;
      rules.push_back(make_pair(left, right));
   }

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
   t.draw();
}
