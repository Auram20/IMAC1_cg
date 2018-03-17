/* minimal.c pour mac */

#include <SDL/SDL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Dimensions de la fenêtre */
static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 600;

/* Nombre de bits par pixel de la fenêtre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

typedef struct Point{
float x, y; // Position 2D du point
unsigned char r, g, b; // Couleur du point
struct Point* next; // Point suivant à dessiner
} Point, *PointList;

Point* allocPoint(float x, float y, unsigned char r, unsigned char g, unsigned char b) {
  Point* point = (Point*) malloc(sizeof(Point));
  if(!point) {
    return NULL;
  }
  point->x = x;
  point->y = y;
  point->r = r;
  point->g = g;
  point->b = b;
  point->next = NULL;
  return point;
}


void addPointToList(Point* point, PointList *list){
    if (*list == NULL){
        *list=point;
    }
    else{
        addPointToList(point,&(*list)->next);
    }
}

void drawPoints(PointList list){
   while(list) {
    glColor3ub(list->r, list->g, list->b);
    glVertex2f(list->x, list->y);
    list = list->next;
  }}

/* Fonction pour projeter dans le new Viewport*/
  void reshape() {
  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-8, 8., -6., 6.);
}

/*Fonction qui actualise la fenetre avec redimen*/

void setVideoMode() {
  if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE)) {
    fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
    exit(EXIT_FAILURE);
  }
  reshape();
}


void drawSquare(x,y,r,v,b){
     glBegin(GL_QUADS);
                        glColor3ub(r, v, b  );
                        glVertex2f(-x, y);
                        glVertex2f(-x, -y);
                        glVertex2f(+x, -y);
                        glVertex2f(+x, +y);
                      
                      glEnd();
    
}

void drawLandMark(x,y){
     glBegin(GL_LINES);
                        glColor3ub(0, 255, 0);
                        glVertex2f(0, 1);
                        glVertex2f(0, 0);
                        glVertex2f(1, 0);
                        glVertex2f(0, 0);
                      
                      glEnd();
    
}

void drawCircle(r,v,b){
    
             glBegin(GL_POLYGON);
             glColor3ub(r, v, b);
             for(int i=0;i<1000;++i)
              {
              glVertex3f(cos(2*3.14159*i/1000.0),sin(2*3.14159*i/1000.0),0);
  }
 glEnd();
}

void matriceIdentite(){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void drawRoundedSquare()
{


glPushMatrix();   
      glTranslatef(0,0,0);
      drawSquare(1.2,2,102,0,153);
      drawSquare(2,1.2,102,0,153);
glPopMatrix();

glPushMatrix();
      glTranslatef(1,1,0);
      drawCircle(102,0,153);
glPopMatrix();

glPushMatrix();
      glTranslatef(1,-1,0);
      drawCircle(102,0,153);
glPopMatrix();

glPushMatrix();
      glTranslatef(-1,-1,0);
      drawCircle(102,0,153);
glPopMatrix();

glPushMatrix();
      glTranslatef(-1,1,0);
      drawCircle(102,0,153);
glPopMatrix();
}


void drawFirstArm(){

glPushMatrix();
      glTranslatef(4,0,0); // il ne devrais pas y avoir de translate pour la première rotule
      glScalef(2,2,2); 
      drawCircle(0,0,153);
glPopMatrix();



glPushMatrix();
    glTranslatef(7,0,0);

      glBegin(GL_POLYGON); // Draw A Quad

          glColor3ub(0,0,153);
          glVertex3f(-3,2.01,0); // Top Left
          glVertex3f(3.1,1,0); // Top Right
          glVertex3f(3.1,-1,0); // Bottom Right
          glVertex3f(-3,-2.01,0); // Bottom Left
      glEnd();
glPopMatrix();



glPushMatrix();
      glTranslatef(10,0,0);
      drawCircle(0,0,153);
glPopMatrix();



}



void drawSecondArm(){
      // dessine la première rotule au point de départ
      glPushMatrix();
      glTranslatef(10,0,0); // il ne devrais pas y avoir de translate pour la première rotule
      glScalef(0.5,0.5,0);
      drawRoundedSquare();
      glPopMatrix();


      // dessine la barre du bras,( on se déplace à la moitié de la longueur du bras et on étire un carré )
      glPushMatrix();
      glTranslatef(14,0,0);
      glScalef(0.1,0.1,0);  
      drawSquare(46,6,255,0,0);
      glPopMatrix();


      // dessine la rotule au bout du bra (on se déplace de la longueur du bras et on dessine la rotule)
      glPushMatrix();
      glTranslatef(18,0,0);
      glScalef(0.5,0.5,0);
      drawRoundedSquare();
      glPopMatrix();
}


// même méthode que second bras
void drawThirdArm(){
      glPushMatrix();
      glTranslatef(26,0,0); // il ne devrais pas y avoir de translate pour la première rotule
      glScalef(0.8,0.8,0);  
      drawCircle(0,255,0);
      glPopMatrix();
      
      glPushMatrix();
      glTranslatef(22,0,0);
      glScalef(0.1,0.1,0);  
      drawSquare(40,4,255,0,0);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(18,0,0);
      glScalef(0.3,0.3,0);  
      drawRoundedSquare();
      glPopMatrix();
}


void drawArm(a,b,c)
{     
        // sauvegarde de l'espace initiale
        glPushMatrix();

        // angle du premier segement par rapport à l'axe X
        glRotatef(a,0.0,0.0,1.0);
        
        // dessin du premier segement
        drawFirstArm();

        // on se déplace au bout du premier segement, sur le point de rotation du second segment 
        glTranslatef(1,0,0);

        // angle du second segment par rapport au premier segment
        glRotatef(b,0.0,0.0,1.0);

        // dessin du second segment
        drawSecondArm();
        
        // on se déplace au bout du second segment, sur le point de rotation du troisieme segment
        glTranslatef(1,0,0);

        // angle du troisième segment par rapport au second segment
        glRotatef(c,0.0,0.0,1.0);

        // dessin du troisème segment
        drawThirdArm();

        // retour a l'espace initiale
        glPopMatrix();
}

PointList list=NULL; 
float yellowx=400;
float  yellowy=300;
int i=0;
int bol=0;
float randox=0;
float randoy=0;

int main(int argc, char** argv) {

    /* Initialisation de la SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    /* Ouverture d'une fenêtre et création d'un contexte OpenGL */
    
    if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL  | SDL_RESIZABLE )) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    
    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);
  
    setVideoMode();
    SDL_WM_SetCaption("Ceci est un Titre", NULL);
    

        float a=45;
        float b=-10;
        float c=35;
   

    
    /* Boucle d'affichage */
    int loop = 1;
    while(loop) {
        
        glClear(GL_COLOR_BUFFER_BIT);
    
        matriceIdentite();



/*Dessin du bras*/
      glPushMatrix();
      glScalef(0.2,0.2,0);
      glTranslatef(-14,0,0);

     
      
      drawArm(a=45,b=-10,c=35);
      glPopMatrix();
    

        
                
        
        /* Récupération du temps au début de la boucle */
        Uint32 startTime = SDL_GetTicks();
        

        /* Boucle traitant les evenements */
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
                
        
            /* L'utilisateur ferme la fenêtre : */
            if(e.type == SDL_QUIT) {
                loop = 0;
                break;
            }
            /* Quelques exemples de traitement d'evenements : */
            switch(e.type) {
                
                    /*On redimensionne le viewport*/        
                case SDL_VIDEORESIZE:
                    WINDOW_WIDTH = e.resize.w;
                    WINDOW_HEIGHT=e.resize.h;
                    setVideoMode();
                    break;
                    

                /* Touche clavier */
                case SDL_KEYDOWN:
                    printf("touche pressée (code = %d)\n", e.key.keysym.sym);
                    
                    if (e.key.keysym.sym=='q'){
                         loop=0;
                    }
                    break;

                default:
                    break;
            }
        }

        /* Calcul du temps écoulé */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;

        /* Si trop peu de temps s'est écoulé, on met en pause le programme */
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
        
        SDL_GL_SwapBuffers();
    }

    /* Liberation des ressources associées à la SDL */ 
        SDL_Quit();

    return EXIT_SUCCESS;
}




