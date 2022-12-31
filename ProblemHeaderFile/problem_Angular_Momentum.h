#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>

#include "calculate_Angular_Momentum.h"

using namespace std;

struct AngM{
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
}ang;
//2
void Angular_Momentum(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y){

    if(!ang.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }

    //Input surface
    ang.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Color color1={0,200,200};
    SDL_Color color2={0,180,180};
    SDL_Color color3={0,0,0};
    SDL_Rect rect[20];
    int run=1;
    SDL_Event e;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //for image
        rect[0]={300,10,350,300};
        SDL_RenderCopy(render,img[3],NULL,&rect[0]);

        //options
        surface= TTF_RenderText_Solid(ang.font," Type here   IW / IE / IL / WE / WL / EL ",color1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[1]={30,350,500,35};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[1]);

		//description
        surface= TTF_RenderText_Solid(ang.font," -for inserting values & get the values of others",color2);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[2]={70,400,300,20};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[2]);

        //input option box for IW/IE/IL/WE/WL/EL
        rect[3]={570,360,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[3]);

        //Inertia
        surface=TTF_RenderText_Solid(ang.font,"I -Inertia (kg m2):",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[4]={30,450,210,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[4]);

        //W-Angular velocity
        surface=TTF_RenderText_Solid(ang.font,"W -Angular velocity (rad/s): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[5]={30,490,300,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[5]);

        //E-Kinetic Energy
        surface= TTF_RenderText_Solid(ang.font,"E -Kinetic Energy (joule): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[6]={30,530,300,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[6]);

        //L-Angular momentum
        surface=TTF_RenderText_Solid(ang.font,"L -Angular momentum(kg rad/s): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[7]={30,570,340,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[7]);

        //Input1
        rect[8]={400,470,300,40};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[8]);

        //Input2
        rect[9]={400,540,300,40};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[9]);

        //calculate button
        rect[10]={500,630,300,60};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[10]);
        surface = TTF_RenderText_Solid(ang.font, " CALCULATE ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[11]={550,640,200,40};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[11]);

        //Back button
        rect[12]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[12]);
        surface = TTF_RenderText_Solid(ang.font, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[13]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[13]);


		//mouse & keyboard event
        while(SDL_PollEvent(&e)){
            switch(e.type){
            	//quit button
                case SDL_QUIT:
                    st1.clear();st2.clear();st3.clear();
                    run=0;
                    break;
                //mouse event
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    switch(e.button.button){
                        case SDL_BUTTON_LEFT:
                        if((mouse_x>=0&&mouse_x<=100)&&(mouse_y>=0&&mouse_y<=50)){
                            st1.clear();st2.clear();st3.clear();
                            run=0;
                        }
                        else if((mouse_x>=550&&mouse_x<=750)&&(mouse_y>=635&&mouse_y<=685)){
                            if(!st1.size()||!st2.size()||!st3.size()||!(st1=="IW"|| st1=="IE" || st1=="IL"||st1=="WE"|| st1=="WL" || st1=="EL"))
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box properly!",window);
                            else {
                                Cal_Angular_Momentum(window,render,img,img_rect,st1,st2,st3,mouse_x,mouse_y);
                                st1.clear();st2.clear();st3.clear();
                            }
                        }
                        break;
                    }

                //keyboard event
                case SDL_TEXTINPUT:
                    if((mouse_x>=570&&mouse_x<=670)&&(mouse_y>=360&&mouse_y<=410))
                        st1+=e.text.text;
                    else if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=470&&mouse_y<=510))
                        st2+=e.text.text;
                    else if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=540&&mouse_y<=580))
                        st3+=e.text.text;
                    break;
                //backspace
                case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if((mouse_x>=570&&mouse_x<=670)&&(mouse_y>=360&&mouse_y<=410)&&st5.size())
                    st1.pop_back();
                    else if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=470&&mouse_y<=510)&&st1.size())
					st2.pop_back();
					else if((mouse_x>=400&&mouse_x<=700)&&(mouse_y>=540&&mouse_y<=580)&&st2.size())
					st3.pop_back();
				}
				break;
            }
        }

        //option input
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(ang.font, st1.c_str(), color3);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[14]={580,360,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[14]);
        }

		//input 1
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(ang.font, st2.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[15]={410,470,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[15]);
        }

        //input 2
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(ang.font, st3.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[16]={410,540,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[16]);
        }


        SDL_RenderPresent(render);
        }
        ang.Pfinish();
}


