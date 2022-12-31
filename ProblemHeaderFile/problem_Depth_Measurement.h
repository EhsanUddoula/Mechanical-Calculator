#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>

#include "calculate_Depth_Measurement.h"

using namespace std;

struct Depth{
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
}dep;
//3
void Depth_Measurement(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y){

    if(!dep.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }

    //Input surface
    dep.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
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

        //image
        rect[7]={300,10,350,300};
        SDL_RenderCopy(render,img[12],NULL,&rect[7]);

        // V/R/A -Volume/Radius/Area
        surface= TTF_RenderText_Solid(dep.font," Type here   V/R/A   (for volume/Radius/Area) ",color1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[6]={70,350,470,35};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[6]);

		//description
        surface= TTF_RenderText_Solid(dep.font," -by which bubble gets n times",color2);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[15]={70,400,300,20};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[15]);

        //V/R/A input box
        rect[18]={570,370,100,40};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[18]);

        //n
        surface=TTF_RenderText_Solid(dep.font," n - bubbles (how many times): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[2]={30,450,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[2]);
        rect[6]={350,450,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[6]);

        //p
        surface=TTF_RenderText_Solid(dep.font," P-Pressure above the surface (N/m2): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[10]={30,490,300,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[10]);
        rect[11]={350,490,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[11]);

        //Density-p
        surface= TTF_RenderText_Solid(dep.font," Density (kgm-3): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[0]={30,530,200,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[0]);
        rect[4]={350,530,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[4]);

        //g
        surface=TTF_RenderText_Solid(dep.font," g-Gravitational Acceleration (m/s2): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[1]={30,570,300,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[1]);
        rect[5]={350,570,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[5]);

        //calculate button
        rect[13]={500,630,300,60};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[13]);
        surface = TTF_RenderText_Solid(dep.font, " CALCULATE ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[16]={550,640,200,40};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[16]);

        //back button
        rect[14]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[14]);
        surface = TTF_RenderText_Solid(dep.font, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[17]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[17]);


		//mouse & keyboard event
        while(SDL_PollEvent(&e)){
            switch(e.type){
            	//quit button
                case SDL_QUIT:
                    st1.clear();st2.clear();st3.clear();st4.clear();st5.clear();
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
                            st1.clear();st2.clear();st3.clear();st4.clear();st5.clear();
                            run=0;
                        }
                        else if((mouse_x>=550&&mouse_x<=750)&&(mouse_y>=635&&mouse_y<=685)){
                            if(!st1.size()||!st2.size()||!st3.size()||!st4.size()||!st5.size()||!(st5=="V"|| st5=="R" || st5=="A"))
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box properly!",window);
                            else {
                                Cal_Depth_Measurement(window,render,img,img_rect,st1,st2,st3,st4,st5,mouse_x,mouse_y);
                                st1.clear();st2.clear();st3.clear();st4.clear();st5.clear();
                            }
                        }
                        break;
                    }

                //keyboard event
                case SDL_TEXTINPUT:
                    if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480)){
                        st1+=e.text.text;
                    }
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520))
                        st2+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=530&&mouse_y<=560))
                        st3+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=570&&mouse_y<=600))
                        st4+=e.text.text;
                        else if((mouse_x>=570&&mouse_x<=670)&&(mouse_y>=370&&mouse_y<=410))
                        st5+=e.text.text;
                    break;
                //backspace
                case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480)&&st1.size())
					st1.pop_back();
					else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520)&&st2.size())
					st2.pop_back();
					else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=530&&mouse_y<=560)&&st3.size())
                    st3.pop_back();
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=570&&mouse_y<=600)&&st4.size())
                    st4.pop_back();
                    else if((mouse_x>=570&&mouse_x<=670)&&(mouse_y>=370&&mouse_y<=410)&&st5.size())
                    st5.pop_back();
				}
				break;
            }
        }


        //input 1
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(dep.font, st1.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[3]={360,450,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[3]);
        }

        //input 2
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(dep.font, st2.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[8]={360,490,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[8]);
        }

        //input 3
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(dep.font, st3.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[9]={360,530,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[9]);
        }

        //input 4
        if ( st4.size() ) {
            surface = TTF_RenderText_Solid(dep.font, st4.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[12]={360,570,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[12]);
        }

        //input Option V/R/A
        if ( st5.size() ) {
            surface = TTF_RenderText_Solid(dep.font, st5.c_str(), color3);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[19]={580,370,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[19]);
        }


        SDL_RenderPresent(render);
        }
    dep.Pfinish();
}
