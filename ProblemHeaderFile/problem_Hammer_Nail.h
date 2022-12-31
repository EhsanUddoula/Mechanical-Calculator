#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>

#include "calculate_Hammer_Nail.h"

using namespace std;

struct Hammer{
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
}ham;
//5
void Hammer_Nail(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y){

    if(!ham.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }

    //Input Surface
    ham.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
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
    bool renderText=false;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //image
        rect[7]={300,10,450,330};
        SDL_RenderCopy(render,img[19],NULL,&rect[7]);

		//for values
        surface= TTF_RenderText_Solid(ham.font," Give the values of - ",color1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[6]={70,350,300,35};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[6]);

        //m-mass
        surface=TTF_RenderText_Solid(ham.font," m - mass of the hammer (kg) : ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[2]={30,450,300,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[2]);
        rect[6]={350,450,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[6]);

        //h-height
        surface=TTF_RenderText_Solid(ham.font," h- height of the hammer (m) : ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[10]={30,490,300,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[10]);
        rect[11]={350,490,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[11]);

        //l-lenghth
        surface= TTF_RenderText_Solid(ham.font," l- length of the nail (m) : ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[0]={30,530,280,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[0]);
        rect[4]={350,530,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[4]);

        //time
        surface=TTF_RenderText_Solid(ham.font," t- time of the contact (s) : ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[1]={30,570,280,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[1]);
        rect[5]={350,570,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[5]);

        //calculate button
        rect[13]={500,630,300,60};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[13]);
        surface = TTF_RenderText_Solid(ham.font, " CALCULATE ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[16]={550,640,200,40};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[16]);

        //back button
        rect[14]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[14]);
        surface = TTF_RenderText_Solid(ham.font, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[17]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[17]);


		//keyboard & mouse event
        while(SDL_PollEvent(&e)){
            switch(e.type){
            	//quit button
                case SDL_QUIT:
                    st1.clear();st2.clear();st3.clear();st4.clear();
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
                            st1.clear();st2.clear();st3.clear();st4.clear();
                            run=0;
                        }
                        else if((mouse_x>=550&&mouse_x<=750)&&(mouse_y>=635&&mouse_y<=685)){
                            if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box properly!",window);
                            else {
                                Cal_Hammer_Nail(window,render,img,img_rect,st1,st2,st3,st4,mouse_x,mouse_y);
                                st1.clear();st2.clear();st3.clear();st4.clear();
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
				}
				break;
            }
        }


		//input 1
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(ham.font, st1.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[3]={360,450,surface->w,surface->h};
            SDL_RenderCopy(render, tex, NULL, &rect[3]);
        }

        //input 2
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(ham.font, st2.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[8]={360,490,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[8]);
        }

        //input 3
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(ham.font, st3.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[9]={360,530,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[9]);
        }

        //input 4
        if ( st4.size() ) {
            surface = TTF_RenderText_Solid(ham.font, st4.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[12]={360,570,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[12]);
        }


        SDL_RenderPresent(render);
        }
        ham.Pfinish();
}


