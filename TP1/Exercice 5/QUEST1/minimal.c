



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
        
        /* Placer ici le code de dessin */
         glClear(GL_COLOR_BUFFER_BIT);
        
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
                        
                    
          
                
                /* Mouvement de souris */
                case SDL_MOUSEMOTION:
                  
                    glClearColor((e.button.x%255)/255.0,((e.button.y%255)/255.0),0,1);
                    
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
