#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<string>

#include "ProblemINP.h"
#include "ProblemImpulse.h"
#include "ProblemAtwood.h"

using namespace std;

TTF_Font* Ofont=NULL;
//int mouse_x,mouse_y;

bool Oinit(){
    bool suc=true;
    if(TTF_Init()<0){
        printf("Did not succeed\n");
        suc=false;
    }
    //SDL_StartTextInput();
    return suc;
}

void Ofinish(){
    //SDL_StopTextInput();
    TTF_CloseFont(Ofont);
    Ofont=NULL;
    TTF_Quit();
}



int Option_Ev(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int run,SDL_Event ev,int &mouse_x,int &mouse_y){
    while(SDL_PollEvent(&ev)){
        switch(ev.type){
            case SDL_QUIT:
                run=0;
                break;
            case SDL_MOUSEMOTION:
                mouse_x=ev.motion.x;
                mouse_y=ev.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                case SDL_BUTTON_LEFT:
                    if((mouse_x>530&&mouse_x<730)&&(mouse_y>480&&mouse_y<520))
                    INCP_acc(window,render,img,img_rect,mouse_x,mouse_y);
                    else if((mouse_x>530&&mouse_x<730)&&(mouse_y>530&&mouse_y<570))
                    INCP_friction(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>530&&mouse_x<730)&&(mouse_y>580&&mouse_y<620))
                    INCP_gravity(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>530&&mouse_x<730)&&(mouse_y>630&&mouse_y<670))
                    INCP_mass(window,render,img,img_rect,mouse_x,mouse_y);
                    /*else if ((mouse_x>530&&mouse_x<730)&&(mouse_y>680&&mouse_y<720))
                    INCP_mass(window,render,img,img_rect,mouse_x,mouse_y);*/
                    else if ((mouse_x>0&&mouse_x<100)&&(mouse_y>0&&mouse_y<50))
                    run=0;
                    break;
            }
    }
    //cout<<mouse_x<<" "<<mouse_y<<endl;
    return run;
}

void OptionINCP(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y){
    if(!Oinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    Ofont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Rect rect[16];
    SDL_Color c={255,255,255},c1={0,0,0};
    SDL_Event ev;
    while(run){
        SDL_RenderCopy(render,img[7],NULL,NULL);
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        //to calculate
        rect[8]={510,350,240,40};
        SDL_SetRenderDrawColor(render,0,180,210,100);
        SDL_RenderFillRect(render,&rect[8]);
        surface= TTF_RenderText_Solid(Ofont," To Calculate ",c);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[0]={525,355,200,30};
        SDL_RenderCopy(render,tex,NULL,&rect[0]);
        SDL_FreeSurface(surface);
        //for finding
        rect[9]={510,400,240,50};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&rect[9]);
        surface= TTF_RenderText_Solid(Ofont,"  SELECT ONE- ",c);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[1]={525,410,200,30};
        SDL_RenderCopy(render,tex,NULL,&rect[1]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for Acc
        rect[10]={530,480,200,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[10]);
        surface= TTF_RenderText_Solid(Ofont," Acceleration ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[2]={540,480,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[2]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for angle
        rect[11]={530,530,200,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[11]);
        surface= TTF_RenderText_Solid(Ofont," Friction ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[3]={540,530,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[3]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for friction
        rect[12]={530,580,200,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[12]);
        surface= TTF_RenderText_Solid(Ofont," Gravity ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[4]={540,580,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[4]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for gravity
        rect[13]={530,630,200,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[13]);
        surface= TTF_RenderText_Solid(Ofont," mass ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[5]={540,630,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[5]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for mass
        /*rect[14]={530,680,200,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[14]);
        surface= TTF_RenderText_Solid(Ofont," mass ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[6]={540,680,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[6]);
        SDL_FreeSurface(surface);
        surface=NULL;*/
        //back button
        rect[15]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[15]);
        surface = TTF_RenderText_Solid(Ofont, " BACK ", c);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[7]={10,6,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[7]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //event
        run=Option_Ev(window,render,img,img_rect,run,ev,mouse_x,mouse_y);
        SDL_RenderPresent(render);
    }
    Ofinish();
}

int OptionImpulse_Ev(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int run,SDL_Event ev,int &mouse_x,int &mouse_y){
    while(SDL_PollEvent(&ev)){
        switch(ev.type){
            case SDL_QUIT:
                run=0;
                break;
            case SDL_MOUSEMOTION:
                mouse_x=ev.motion.x;
                mouse_y=ev.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                case SDL_BUTTON_LEFT:
                    if((mouse_x>530&&mouse_x<730)&&(mouse_y>540&&mouse_y<580))
                    find_impulse(window,render,img,img_rect,mouse_x,mouse_y);
                    else if((mouse_x>530&&mouse_x<730)&&(mouse_y>600&&mouse_y<640))
                    find_2vel(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>0&&mouse_x<100)&&(mouse_y>0&&mouse_y<50))
                    run=0;
                    break;
        }
    }
    //cout<<mouse_x<<" "<<mouse_y<<endl;
    return run;
}

void OptionImpulse(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y){
    if(!Oinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    Ofont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Rect rect[10];
    SDL_Color c={255,255,255},c1={0,0,0};
    SDL_Event ev;
    while(run){
        SDL_RenderCopy(render,img[7],NULL,NULL);
        SDL_RenderCopy(render,img[1],NULL,&img_rect[1]);
        //to calculate
        rect[0]={510,400,240,40};
        SDL_SetRenderDrawColor(render,0,180,210,100);
        SDL_RenderFillRect(render,&rect[0]);
        surface= TTF_RenderText_Solid(Ofont," To Calculate ",c);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[1]={525,405,200,30};
        SDL_RenderCopy(render,tex,NULL,&rect[1]);
        SDL_FreeSurface(surface);
        //for finding
        rect[2]={510,450,240,50};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&rect[2]);
        surface= TTF_RenderText_Solid(Ofont,"  SELECT ONE- ",c);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[3]={525,460,200,30};
        SDL_RenderCopy(render,tex,NULL,&rect[3]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for impulse
        rect[4]={530,540,200,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[4]);
        surface= TTF_RenderText_Solid(Ofont," Impulse ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[5]={540,540,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[5]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for Velocities
        rect[6]={530,600,200,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[6]);
        surface= TTF_RenderText_Solid(Ofont," Velocities ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[7]={540,600,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[7]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //back button
        rect[8]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[8]);
        surface = TTF_RenderText_Solid(Ofont, " BACK ", c);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[9]={10,6,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[9]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //event
        run=OptionImpulse_Ev(window,render,img,img_rect,run,ev,mouse_x,mouse_y);
        SDL_RenderPresent(render);
    }

    Ofinish();
}

int OptionAtwood_Ev(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int run,SDL_Event ev,int &mouse_x,int &mouse_y){
    while(SDL_PollEvent(&ev)){
        switch(ev.type){
            case SDL_QUIT:
                run=0;
                break;
            case SDL_MOUSEMOTION:
                mouse_x=ev.motion.x;
                mouse_y=ev.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                case SDL_BUTTON_LEFT:
                    if((mouse_x>430&&mouse_x<830)&&(mouse_y>540&&mouse_y<580))
                    at_acc_ten(window,render,img,img_rect,mouse_x,mouse_y);
                    //else if((mouse_x>530&&mouse_x<730)&&(mouse_y>600&&mouse_y<640))
                    //at_m1_m2(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>0&&mouse_x<100)&&(mouse_y>0&&mouse_y<50))
                    run=0;
                    break;
        }
    }
    //cout<<mouse_x<<" "<<mouse_y<<endl;
    return run;
}

void OptionAtwood(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y){
    if(!Oinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    Ofont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Rect rect[10];
    SDL_Color c={255,255,255},c1={0,0,0};
    SDL_Event ev;
    while(run){
        SDL_RenderCopy(render,img[7],NULL,NULL);
        SDL_RenderCopy(render,img[2],NULL,&img_rect[2]);
        //to calculate
        rect[0]={510,400,240,40};
        SDL_SetRenderDrawColor(render,0,180,210,100);
        SDL_RenderFillRect(render,&rect[0]);
        surface= TTF_RenderText_Solid(Ofont," To Calculate ",c);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[1]={525,405,200,30};
        SDL_RenderCopy(render,tex,NULL,&rect[1]);
        SDL_FreeSurface(surface);
        //for finding
        rect[2]={510,450,240,50};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&rect[2]);
        surface= TTF_RenderText_Solid(Ofont,"  SELECT ONE- ",c);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[3]={525,460,200,30};
        SDL_RenderCopy(render,tex,NULL,&rect[3]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for acceleration
        rect[4]={430,540,400,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[4]);
        surface= TTF_RenderText_Solid(Ofont," Acceleration and Tension ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[5]={440,540,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[5]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //for mass
        /*rect[6]={530,600,200,40};
        SDL_SetRenderDrawColor(render,230,245,0,0);
        SDL_RenderFillRect(render,&rect[6]);
        surface= TTF_RenderText_Solid(Ofont," Mass ",c1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[7]={540,600,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[7]);
        SDL_FreeSurface(surface);
        surface=NULL;*/
        //back button
        rect[8]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[8]);
        surface = TTF_RenderText_Solid(Ofont, " BACK ", c);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[9]={10,6,surface->w,surface->h};
        SDL_RenderCopy(render,tex,NULL,&rect[9]);
        SDL_FreeSurface(surface);
        surface=NULL;
        //event
        run=OptionAtwood_Ev(window,render,img,img_rect,run,ev,mouse_x,mouse_y);
        SDL_RenderPresent(render);
    }

    Ofinish();
}
