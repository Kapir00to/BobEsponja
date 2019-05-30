#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

static int shoulder1 = 290, elbow1 = 150, fist1 = 0, shoulder2 = 250, elbow2 = -150, fist2 = 0, sight1 = 0, sight2 = 0, leg1 = 270, leg2 = 270,
 foot1 = 0,   foot2 = 0;
  float augx = 1.0f, augy = 1.5f, scale = 0.6f;

  float posX=0.0,posY=0.0,posZ=0.0;
  float transX=0.0,transY=0.0,transZ=0.0;

/*  TRABALHO FEITO POR LUCAS REZENDE BRUNO

    OBS: NÃO CONSEGUI FAZER A PERSPECTIVA 3D, FOI MAL. 

    */
void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void movimento(int key,int x,int y){
    //Movimento
    switch (key){
        //movimento para direita
        case GLUT_KEY_RIGHT:
          posY += 1.0;
        break;
        //movimento para esquerda.
        case GLUT_KEY_LEFT:
          posY -= 1.0;
        break;
        //identifica o movimento para cima
        case GLUT_KEY_UP:
          posX += 1.0;
        break;
        //identifica o movimento para baixo.
        case GLUT_KEY_DOWN:
          posX -= 1.0;
        break;

        case GLUT_KEY_F1:
          transZ += 0.5;
        break;

        case GLUT_KEY_F2:
          transZ -= 0.5;
        break;

        case GLUT_KEY_F3:
          transY += 0.5;
        break;

        case GLUT_KEY_F4:
          transY -= 0.5;
        break;

        case GLUT_KEY_F5:
          transX += 0.5;
        break;

        case GLUT_KEY_F6:
          transX -= 0.5;
        break;

        case GLUT_KEY_F7:
          transX = 0.0;
          transY = 0.0;
          transZ = 0.0;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}

void display(void){

   if (posX==360)
      posX=0;

    if (posY==360)
        posY=0;

      if (posZ==360)
        posZ=0;

      glClearColor(0.0f,0.4f,0.5f, 0);

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);

  glPushMatrix();
    
    glRotatef(posX,1.0,0.0,0.0);
    glRotatef(posY,0.0,1.0,0.0);
    glTranslatef(transX, transY, transZ);


    glPushMatrix();
      glTranslatef(0.0,0.4,0.5);
      glScalef(0.1f,0.1f,0.5f);
      glColor3f(1.0f,1.0f,0.0f);
      glutSolidCube(1);

    glPopMatrix();

    /* origem posicionada no ombro */
    glPushMatrix();
    
      glScalef(scale -0.2, scale -0.2, scale);
      glTranslatef(augx,augy,0.0);
      glColor3f(1.0f,1.0f,0.0f);
      glRotatef(shoulder1, 0.0, 0.0, 1.0);
      glutSolidSphere(0.3, 50, 50);
      glTranslatef(1.0, 0.0, 0.0);   //d1 = 2

      glPushMatrix();
          glScalef(0.85, 0.85, 0.85);
          
          glPushMatrix();     //braco
               
            glScalef(1.7, 0.3, 0.4);
            glColor3f(1.0f,1.0f,0.0f);
            glutSolidCube(1);
           
          glPopMatrix();


          glPushMatrix();  //cotovelo e antebraco
            
            glTranslatef(1.0,0.0,0.0);
            glColor3f(1.0f,1.0f,0.0f);
            glutSolidSphere(0.3, 50, 50);
            glRotatef(elbow1, 0.0, 0.0, 1.0);
            glTranslatef(1.0, 0.0, 0.0);   //d1 = 2

            glPushMatrix();
             
              glScalef(1.7, 0.3, 0.4);
              glColor3f(1.0f,1.0f,0.0f);
              glutSolidCube(1);
            
            glPopMatrix();
            
            glPushMatrix();
             
              glRotatef(fist1, 1.0, 0.0, 0.0);
              glTranslatef(1.0,0.0,0.0);
              glColor3f(1.0f,1.0f,0.0f);
              glutSolidCube(0.5);
           
            glPopMatrix();
          
          glPopMatrix();
      glPopMatrix();
    glPopMatrix();  


    glPushMatrix();
      
      glScalef(scale -0.2, scale - 0.2, scale);
      glTranslatef(-augx,augy,0.0);
      glColor3f(1.0f,1.0f,0.0f);
      glRotatef(shoulder2, 0.0, 0.0, 1.0);
      glutSolidSphere(0.3, 50, 50);
      glTranslatef(1.0, 0.0, 0.0);   //d1 = 2

      glPushMatrix();
      
        glScalef(0.85, 0.85, 0.85);
       
        glPushMatrix();     //braco
           
          glScalef(1.7, 0.3, 0.4);
          glColor3f(1.0f,1.0f,0.0f);
          glutSolidCube(1);
        
        glPopMatrix();

        glPushMatrix();  //cotovelo e antebraco
        
          glTranslatef(1.0,0.0,0.0);
          glColor3f(1.0f,1.0f,0.0f);
          glutSolidSphere(0.3, 50, 50);
          glRotatef(elbow2, 0.0, 0.0, 1.0);
          glTranslatef(1.0, 0.0, 0.0);   //d1 = 2

          glPushMatrix();
               
            glScalef(1.7, 0.3, 0.4);
            glColor3f(1.0f,1.0f,0.0f);
            glutSolidCube(1);
            
          glPopMatrix();
          
          glPushMatrix();
          
            glRotatef(fist2, 1.0, 0.0, 0.0);
            glTranslatef(1.0,0.0,0.0);
            glColor3f(1.0f,1.0f,0.0f);
            glutSolidCube(0.5);
          
          glPopMatrix();
        
        glPopMatrix();
          
      glPopMatrix();

    glPopMatrix();  

    glPushMatrix();
      
      glColor3f(1.0f,1.0f, 0.0f);
      glScalef(0.8,1.3,1.0);
      glTranslatef(0.0,0.3,0.0);
      glutSolidCube(1);
    
    glPopMatrix();

    glPushMatrix();
      
      glTranslatef(0.16, 0.67, 0.51);
        //Draw Circle
      glBegin(GL_POLYGON);
        
        glColor3f(1.0f,1.0f,1.0f);
        //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
        //Note that anything above 24 will have little affect on the circles appearance
        //Play with the numbers till you find the result you are looking for
        //Value 1.5 - Draws Triangle
        //Value 2 - Draws Square
        //Value 3 - Draws Hexagon
        //Value 4 - Draws Octagon
        //Value 5 - Draws Decagon
        //Notice the correlation between the value and the number of sides
        //The number of sides is always twice the value given this range
          
        for(double i = 0; i < 2 * PI; i += PI / 24) //<-- Change this Value
          glVertex3f(cos(i) * 0.1, sin(i) * 0.08, 0.0);
          
      glEnd();
    
    glPopMatrix();
    
    glPushMatrix();
        
      glTranslatef(-0.15, 0.67, 0.51);
        
      glBegin(GL_POLYGON);
            
        glColor3f(1.0f,1.0f,1.0f);
        //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
        //Note that anything above 24 will have little affect on the circles appearance
        //Play with the numbers till you find the result you are looking for
        //Value 1.5 - Draws Triangle
        //Value 2 - Draws Square
        //Value 3 - Draws Hexagon
        //Value 4 - Draws Octagon
        //Value 5 - Draws Decagon
        //Notice the correlation between the value and the number of sides
        //The number of sides is always twice the value given this range
          
        for(double i = 0; i < 2 * PI; i += PI / 24) //<-- Change this Value
          glVertex3f(cos(i) * 0.1, sin(i) * 0.08, 0.0);
        
      glEnd();
        
    glPopMatrix();
         
    glPushMatrix();
     
      glTranslatef(0.13, 0.67, 0.52);
     
      glBegin(GL_POLYGON);
       
        glColor3f(0.0f,0.0f,0.0f);
        //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
        //Note that anything above 24 will have little affect on the circles appearance
        //Play with the numbers till you find the result you are looking for  
        //Value 1.5 - Draws Triangle
        //Value 2 - Draws Square
        //Value 3 - Draws Hexagon
        //Value 4 - Draws Octagon
        //Value 5 - Draws Decagon
        //Notice the correlation between the value and the number of sides
        //The number of sides is always twice the value given this range
        for(double i = 0; i < 2 * PI; i += PI / 24) //<-- Change this Value
          glVertex3f(cos(i) * 0.03, sin(i) * 0.03, 0.0);
      
      glEnd();
          //Draw Circle
    glPopMatrix(); 

    glPushMatrix();
      
      glTranslatef(-0.12, 0.67, 0.52);
      
      glBegin(GL_POLYGON);
        
        glColor3f(0.0f,0.0f,0.0f);
        //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
        //Note that anything above 24 will have little affect on the circles appearance
        //Play with the numbers till you find the result you are looking for
        //Value 1.5 - Draws Triangle
        //Value 2 - Draws Square
        //Value 3 - Draws Hexagon
        //Value 4 - Draws Octagon
        //Value 5 - Draws Decagon
        //Notice the correlation between the value and the number of sides
        //The number of sides is always twice the value given this range
        for(double i = 0; i < 2 * PI; i += PI / 24) //<-- Change this Value
          glVertex3f(cos(i) * 0.03, sin(i) * 0.03, 0.0);
          
      glEnd();
          //Draw Circle
    glPopMatrix(); 

    glPushMatrix();
      
      glTranslatef(0.0, 0.22, 0.51);
      
      glBegin(GL_POLYGON);
        glColor3f(1.0f,0.0f,0.0f);
        //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
        //Note that anything above 24 will have little affect on the circles appearance
        //Play with the numbers till you find the result you are looking for
        //Value 1.5 - Draws Triangle
        //Value 2 - Draws Square
        //Value 3 - Draws Hexagon
        //Value 4 - Draws Octagon
        //Value 5 - Draws Decagon
        //Notice the correlation between the value and the number of sides
        //The number of sides is always twice the value given this range
        for(double i = 0; i > -PI; i -= PI / 24) //<-- Change this Value
              glVertex3f(cos(i) * 0.2, sin(i) * 0.1, 0.0);
          
      glEnd();
          //Draw Circle
    
    glPopMatrix(); 
   
    glPushMatrix();
      
      glScalef(scale -0.2, scale -0.2, scale);
      glTranslatef(augx,- augy + 0.9,0.0);
      glColor3f(1.0f,1.0f,0.0f);
      glRotatef(270, 0.0, 0.0, 1.0);
      glRotatef(sight1, 0.0, 1.0, 0.0);
      glutSolidSphere(0.3, 50, 50);
      glTranslatef(1.0, 0.0, 0.0);   //d1 = 2

      glPushMatrix();
      
        glScalef(1.0,1.0,1.5);
        glTranslatef(2.0,0.0,0.2);
        glColor3f(0.0f,0.0f,1.0f);
        //glRotatef(foot1, 1.0, 0.0, 0.0);
        glutSolidCube(0.5);   //pe
      
      glPopMatrix();

      glPushMatrix();
        
        glScalef(0.65, 1.05, 0.55);

        glPushMatrix();     //perna
        
          glScalef(2.2, 0.3, 0.4);
          glColor3f(0.6f,0.3f,0.0f);
          glutSolidCube(1);
        
        glPopMatrix();

        glPushMatrix();  //coxa
        
          glTranslatef(1.0,0.0,0.0);
          glColor3f(0.6f,0.3f,0.0f);
          glutSolidSphere(0.3, 50, 50);
          //glRotatef(, 0.0, 0.0, 1.0);
          glTranslatef(1.0, 0.0, 0.0);   //d1 = 2

          glPushMatrix();
          
            glScalef(2.2, 0.3, 0.4);
            glColor3f(1.0f,1.0f,0.0f);
            glutSolidCube(1);
          
          glPopMatrix();
            
            /*glPushMatrix();
            glRotatef(fist1, 1.0, 0.0, 0.0);
            glTranslatef(1.0,0.0,0.0);
            glColor3f(1.0f,1.0f,0.0f);
            glutSolidCube(0.5);
            glPopMatrix();*/
            
        glPopMatrix();
          
      glPopMatrix();
      
    glPopMatrix();

    glPushMatrix();
     
      glScalef(scale -0.2, scale -0.2, scale);
      glTranslatef(-augx,- augy + 0.9,0.0);
      glColor3f(1.0f,1.0f,0.0f);
      glRotatef(270, 0.0, 0.0, 1.0);
      glRotatef(sight2, 0.0, 1.0, 0.0);
      glutSolidSphere(0.3, 50, 50);
      glTranslatef(1.0, 0.0, 0.0);   //d1 = 2

      glPushMatrix();
      
        glScalef(1.0,1.0,1.5);
        glTranslatef(2.0,0.0,0.2);
        //glRotatef(foot2, 1.0, 0.0, 0.0);
        glColor3f(0.0f,0.0f,1.0f);
        glutSolidCube(0.5);
      
      glPopMatrix();

      glPushMatrix();
        
        glScalef(0.65, 1.05, 0.55);

          glPushMatrix();     //perna
            
              glScalef(2.2, 0.3, 0.4);
              glColor3f(0.6f,0.3f,0.0f);
              glutSolidCube(1);
          
          glPopMatrix();


        glPushMatrix();  //coxa
          
          glTranslatef(1.0,0.0,0.0);
          glColor3f(0.6f,0.3f,0.0f);
          glutSolidSphere(0.3, 50, 50);
          //glRotatef(leg2, 0.0, 0.0, 1.0);
          glTranslatef(1.0, 0.0, 0.0);   //d1 = 2

          glPushMatrix();
            
            glScalef(1.7, 0.3, 0.4);
            glColor3f(1.0f,1.0f,0.0f);
            glutSolidCube(1);
          
          glPopMatrix();
             
               /* glPushMatrix();
                  glRotatef(fist1, 1.0, 0.0, 0.0);
                  glTranslatef(1.0,0.0,0.0);
                  glColor3f(1.0f,1.0f,0.0f);
                  glutSolidCube(0.5);
                glPopMatrix();*/
              
        glPopMatrix();
      
      glPopMatrix();
    
    glPopMatrix();

  glPopMatrix();

  glutSwapBuffers();
}

/*void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}*/

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 'z':
     if(!(shoulder1  % 360 == 80)){
          shoulder1 = (shoulder1 + 5) % 360;
          shoulder2 = (shoulder2 - 5) % 360;
          glutPostRedisplay();
        }
    break;
    
  case 'Z':
      if(!(shoulder1 % 360 == -80)){
          shoulder2 = (shoulder2 + 5) % 360;
          shoulder1 = (shoulder1 - 5) % 360;
          glutPostRedisplay();
       }
    break;
  /*case 'w':
  if((foot1 % 360) != 90){
      foot1 = (foot1 + 5) % 360;
      foot2 = (foot2 - 5) % 360;
      glutPostRedisplay();
    }  
      break;
  case 'W':
  if((foot1 % 360) != -90){
      foot1 = (foot1 - 5) % 360;
      foot2 = (foot2 + 5) % 360;
      glutPostRedisplay();
    }  
      break;*/

  case 'x':
    if(!((elbow1 % 360) == 170)){
      elbow1 = (elbow1 + 5) % 360;
      elbow2 = (elbow2 - 5) % 360;
      glutPostRedisplay();
     } 
    break;
  case 'X':
    if(!((elbow1 % 360) == 0)){
      elbow1 = (elbow1 - 5) % 360;
      elbow2 = (elbow2 + 5) % 360;
      glutPostRedisplay();
     } 
    break;
  /*case 'r':
      elbow2 = (elbow2 + 5) % 360;
      glutPostRedisplay();
      break;
  case 'R':
      elbow2 = (elbow2 - 5) % 360;
      glutPostRedisplay();
      break;*/
  /*case 't':
      fist1 = (fist1 + 5) % 360;
      glutPostRedisplay();
      break;
  case 'T':
      fist1 = (fist1 - 5) % 360;
      glutPostRedisplay();
      break;
  case 'y':
      fist2 = (fist2 + 5) % 360;
      glutPostRedisplay();
      break;
  case 'Y':
      fist2 = (fist2 - 5) % 360;
      glutPostRedisplay();
      break;*/

   case 'c':
      if(sight1 <= 45 && sight2 >= -45){
        sight1 = (sight1 + 5) % 360;
        sight2 = (sight2 - 5) % 360;
        glutPostRedisplay();
      }
      break;
  case 'C':
      if (sight1 >= -45 && sight2 <= 45){
        sight1 = (sight1 - 5) % 360;
        sight2 = (sight2 + 5) % 360;
        glutPostRedisplay();
      }
      break;
          
       
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

void inicializar(){

    /* set up depth-buffering */
    glEnable(GL_DEPTH_TEST);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //FovY, Aspect, zNear, ZFar
    gluPerspective(45,1,4,20);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  
  // eyeX, eyeY, eyeZ
  // Especifica a posicao do olho. Câmera
  //
  // centerX, centerY, centerZ
  // Especifica a posicao do ponto de referencia. Para onde a câmera aponta.
  //
  // upX, upY, upZ
  // Especifica a direção do vetor "Cima". Geralmente, Y.
    gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

/*int main(int argc, char** argv){
  glutInit(&argc, argv);
  //glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (1000, 1000);
  glutInitWindowPosition (0, 0);
  glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
  glutCreateWindow (argv[0]);
  //init ();
  glutDisplayFunc(display);
  inicializar();
  //glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(movimento);
  glutMainLoop();
  return 0;
}*/

int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
    /* create and set up a window */
    glutCreateWindow("bob");
    glutDisplayFunc(display);
    inicializar();
    glutSpecialFunc(movimento);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

