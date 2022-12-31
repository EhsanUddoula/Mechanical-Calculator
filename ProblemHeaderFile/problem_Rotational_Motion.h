#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>

#include "calculate _Rotational_Motion.h"

using namespace std;

struct Rotation{
    TTF_Font* font=NULL;
    bool Pinit(){
        bool suc=true;
        if(TTF_Init()<0){
            printf("Did not succeed\n");
            suc=false;
        }
        SDL_StartTextInput();
        return suc;
    }

    void Pfinish(){
        SDL_StopTextInput();
        TTF_CloseFont(font);
        font=NULL;
        TTF_Quit();
    }
}rot;

void ROTATIONAL_MOTION(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y){

    if(!rot.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }

    //Input surface
    rot.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,0,0,0,0);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Color color1={0,200,200};
    SDL_Rect rect[20];
    SDL_Event e;
    int run=1;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //for backButton
        rect[0]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[0]);
        surface = TTF_RenderText_Solid(rot.font, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[1]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[1]);

        //image
        SDL_RenderCopy(render,img[3],NULL,&img_rect[3]);
        //values
        surface= TTF_RenderText_Solid(rot.font,"Give the values of  ",color1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[3]={30,380,400,40};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[3]);

        //radius
        surface= TTF_RenderText_Solid(rot.font,"Radius (meter): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[4]={30,450,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[4]);
        rect[5]={400,450,300,40};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[5]);

        //Number of Rotations
        surface= TTF_RenderText_Solid(rot.font,"Number of Rotations: ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[6]={30,500,300,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[6]);
        rect[7]={400,500,300,40};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[7]);

        //Time for the Rotations
        surface= TTF_RenderText_Solid(rot.font,"Time for the Rotations (minutes): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[8]={30,550,300,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[8]);
        rect[9]={400,550,300,40};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[9]);

        //calculate Button
        rect[10]={500,600,300,60};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[10]);
        surface = TTF_RenderText_Solid(rot.font, " CALCULATE ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[11]={550,610,200,40};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[11]);

        //keyboard & mouse event
        while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT:
                st1.clear();st2.clear();st3.clear();
                run=0;
                break;
            case SDL_MOUSEMOTION:
                mouse_x=e.motion.x;
                mouse_y=e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(e.button.button){
                    case SDL_BUTTON_LEFT:
                    if((mouse_x>=550&&mouse_x<=750)&&(mouse_y>=610&&mouse_y<=650)){
                        if(!st1.size()||!st2.size()||!st3.size())
                        SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                        else {
                            CalROTATIONAL_MOTION(window,render,img,img_rect,st1,st2,st3,mouse_x,mouse_y);
                            st1.clear();st2.clear();st3.clear();
                        }
                    }
                    else if((mouse_x>=0&&mouse_x<=100)&&(mouse_y>=0&&mouse_y<=50)){
                        st1.clear();st2.clear();st3.clear();
                        run=0;
                    }
                    break;
                }

            //keyboard event
            case SDL_TEXTINPUT:
                if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=450&&mouse_y<=490)){
                    st1+=e.text.text;
                }
                else if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=500&&mouse_y<=540))
                    st2+=e.text.text;
                else if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=550&&mouse_y<=590))
                    st3+=e.text.text;
                break;
            case SDL_KEYDOWN:
            if (e.key.keysym.sym == SDLK_BACKSPACE) {
                if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=450&&mouse_y<=490)&&st1.size())
                st1.pop_back();
                else if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=500&&mouse_y<=540)&&st2.size())
                st2.pop_back();
                else if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=550&&mouse_y<=590)&&st3.size())
                st3.pop_back();
            }
            break;
            }
        }

        //input 1
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(rot.font, st1.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[16].x=400;
            rect[16].y=450;
            rect[16].w=surface->w;
            rect[16].h=surface->h;
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[16]);
        }

        //input 2
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(rot.font, st2.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[17]={400,500,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[17]);
        }

        //input 3
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(rot.font, st3.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[18]={400,550,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[18]);
        }


        SDL_RenderPresent(render);
    }

    rot.Pfinish();
}



