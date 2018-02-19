
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

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
  gluOrtho2D(-1., 1., -1., 1.);
}

/*Fonction qui actualise la fenetre avec redimen*/

void setVideoMode() {
  if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE)) {
    fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
    exit(EXIT_FAILURE);
  }
  reshape();
}


void drawSquare(x,y){
     glBegin(GL_QUADS);
                        glColor3ub(0, 0, 255);
                        glVertex2f(-0.5, 0.5);
                        glVertex2f(-0.5, -0.5);
                        glVertex2f(+0.5, -0.5);
                        glVertex2f(+0.5, +0.5);
                      
                      glEnd();
    
}

void drawLandMark(x,y){
     glBegin(GL_LINES);
                        glColor3ub(0, 255, 0);
                        glVertex2f(0, +0.5);
                        glVertex2f(0, 0);
                        glVertex2f(+0.5, 0);
                        glVertex2f(0, 0);
                      
                      glEnd();
    
}

void drawCircle(){
    
    glBegin(GL_POINTS);
 for(int i=0;i<1000;++i)
  {
  glVertex3f(cos(2*3.14159*i/1000.0),sin(2*3.14159*i/1000.0),0);
  }
 glEnd();
}


PointList list=NULL; 

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
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    /* Boucle d'affichage */
    int loop = 1;
    while(loop) {
                  
            
        
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
                        
                            
               
                    
                     case SDL_MOUSEBUTTONDOWN:
                      
                        drawSquare(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
                        drawLandMark(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
                        drawCircle();
                      
                            
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




