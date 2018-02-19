



#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>


/*Structure du point*/

typdef struct Point{
    float x,y; 
    unsigned char r, g, b;
    struct Point* next;     
    } Point, *PointList;

Point* AllocPointLink(float x, float y, unsigned char r, unsigned char g, unsigned char b);


/* Dimensions de la fenêtre */
static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 600;

/* Nombre de bits par pixel de la fenêtre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

Point* allocPoint(float x, float y, unsigned char r, unsigned char g, unsigned char b){
    Point *point=malloc(sizeof(*Point));
    
    
    
}


int main(int argc, char** argv) {

    /* Initialisation de la SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    /* Ouverture d'une fenêtre et création d'un contexte OpenGL */
    
    if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE )) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    
    
    /* Titre de la fenêtre */
    SDL_WM_SetCaption("Ceci est un Titre", NULL);
    
    
    /* Boucle d'affichage */
    int loop = 1;
    while(loop) {
              
        
            
        
        /* Récupération du temps au début de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /* Placer ici le code de dessin 
         glClear(GL_COLOR_BUFFER_BIT);*/
        
        /* Echange du front et du back buffer : mise à jour de la fenêtre */
       
        
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
                    SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE |SDL_GL_DOUBLEBUFFER );
                   glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
                    glMatrixMode(GL_PROJECTION);
                    glLoadIdentity();
                    gluOrtho2D(-1., 1., -1., 1.);
                    break;
                      
                  
                    
                    
                    
          
           
                /* Touche clavier */
                if(e.type==SDL_KEYDOWN){
                    printf("touche pressée (code = %d)\n", e.key.keysym.sym);
                    
                      /* Dessins de primitives */
                        if (e.key.keysym.sym=='p'){
                            e.type=SDL_MOUSEBUTTONUP;
                            if(e.type == SDL_MOUSEBUTTONUP){
                                glBegin(GL_POINTS);
                                glColor3ub(255, 0, 0);
                                glVertex2f(-1 + 2. * e.button.x / WINDOW_WIDTH, - (-1 + 2. * e.button.y / WINDOW_HEIGHT));
                                glEnd();
                                }
                            break;
                    }
                    }
                    
                     if (e.key.keysym.sym=='l'){

                                glBegin(GL_LINES);
                                glColor3ub(255, 0, 0);
                                    glVertex2f(-1 + 2. * e.button.x / WINDOW_WIDTH, - (-1 + 2. * e.button.y / WINDOW_HEIGHT));
                                    glVertex2f(0, 1);
                                glEnd();
                            break;
                    }
                    
                    
                    
                    
                     /* On quitte le paint */
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
