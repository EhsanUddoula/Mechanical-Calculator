#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct CTri{
    TTF_Font* sfont=NULL;

    bool initial(){
        bool suc=true;
        if(TTF_Init()<0){
            printf("Did not succeed\n");
            suc=false;
        }
        //SDL_StartTextInput();
        return suc;
    }

    void stop(){
        TTF_CloseFont(sfont);
        sfont=NULL;
        TTF_Quit();
    }
}ctr;
//7.2
void Cal_Inertia_2_Triangle(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,int &mouse_x,int &mouse_y){

    if(!ctr.initial()){
        printf("Did not Initial\n");
        return;
    }

    double m, l, I;
    string ss1,ss2;
    /*  m = mass of each side
        l = length of each side
        I = inertia about the center axis  */

    m=stod(st1);
    l=stod(st2);

    //formula
    I=m*l*l/3;

    ss1=to_string(I);
    ss1+="  kgm2";

    //Output Surface
    ctr.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Color color1={0,0,0};
    int run=1;
    SDL_Event e;
    int x=0;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //inertia
        surface= TTF_RenderText_Solid(ctr.sfont,"I-Inertia about the Center axis:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,265,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(ctr.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //back button
        srect[3]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[3]);
        surface = TTF_RenderText_Solid(ctr.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[4]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[4]);


		//mouse event
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    run=0;
                    break;
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    case SDL_BUTTON_LEFT:
                        if((mouse_x>0&&mouse_x<100)&&(mouse_y>0&&mouse_y<50))
                        run=0;
                    break;
            }
        }


        //Animation - circulation

        //img1
        if(x%20==0||x%20==1||x%20==2||x%20==3||x%20==4){
        srect[5]={380,200,500,500};
        SDL_RenderCopy(render,img[46],NULL,&srect[5]);
        }
        //img2
        else if(x%20==5||x%20==6||x%20==7||x%20==8||x%20==9){
        srect[6]={380,200,500,500};
        SDL_RenderCopy(render,img[47],NULL,&srect[6]);
        }
        //img3
        else if(x%20==10||x%20==11||x%20==12||x%20==13||x%20==14){
        srect[7]={380,200,500,500};
        SDL_RenderCopy(render,img[48],NULL,&srect[7]);
        }
        //img4
        else if(x%20==15||x%20==16||x%20==17||x%20==18||x%20==19){
        srect[8]={380,200,500,500};
        SDL_RenderCopy(render,img[49],NULL,&srect[8]);
        }

        x++;


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    ctr.stop();
}


