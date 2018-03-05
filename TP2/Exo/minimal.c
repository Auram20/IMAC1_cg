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
                        glVertex2f(-0.5, 0.5);
                        glVertex2f(-0.5, -0.5);
                        glVertex2f(+0.5, -0.5);
                        glVertex2f(+0.5, +0.5);
                      
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
    
             glBegin(GL_POINTS);
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




PointList list=NULL; 
float yellowx=400;
float  yellowy=300;
int i=0;
int currentTime=0;
int lastTime;
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
    
   
    
    
    /* Boucle d'affichage */
    int loop = 1;
    while(loop) {
        
         glClear(GL_COLOR_BUFFER_BIT);
        
        matriceIdentite();
        glTranslatef(0,0,0);
        
        drawLandMark(800/2,600/2);
        
      
        matriceIdentite();
        glTranslatef(1,2,0);
        drawCircle(231,62,1);
        
        
        matriceIdentite();
        glRotatef(45, 0.0, 0.0, 1.0);
        glTranslatef(2,0,0);     
        drawSquare(0,0,255,0,0);
        
        matriceIdentite();
        glTranslatef(2,0,0);   
        glRotatef(45, 0.0, 0.0, 1.0);
        drawSquare(0,0,102,0,153);
        
        currentTime=SDL_GetTicks();
        
        matriceIdentite();
        if (currentTime>lastTime+1000){
        randox=rand()%16 -8;
        randoy=rand()%12 -6;
        lastTime=currentTime;   
        }
        glTranslatef(randox,randoy,0);
        drawCircle(0,0,250);   
        
        matriceIdentite();
        glTranslatef(-8 + 16. * yellowx / WINDOW_WIDTH,- (-6 + 12. * yellowy / WINDOW_HEIGHT),0);
        glRotatef(i, 0.0, 0.0, 1.0);
        drawSquare(-0,0,254,248,108);
        
                
        
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
                    
                    /* Clic de souris - redessiner le carré jaune */
                  /* case SDL_MOUSEBUTTONUP:
                        yellowx=e.button.x;
                        yellowy=e.button.y;
                        glClear;
                    break;*/
                    
                    case SDL_MOUSEBUTTONDOWN:
                      bol=1;
                    break;
                    
                    
                    /* Mouvement de souris */
                    case SDL_MOUSEMOTION:
                    if (bol==1){
                        yellowx=e.button.x;
                        yellowy=e.button.y;
                        i++;
                        
                    }
                    
                    
                    break;
                    
                    
                    
                 case SDL_MOUSEBUTTONUP:
                        bol=0;
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




