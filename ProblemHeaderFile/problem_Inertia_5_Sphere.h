#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>

#include "calculate_Inertia_5_Sphere.h"

using namespace std;

struct Sphere{
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
}sp;
//7.5
void Inertia_5_Sphere(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y){

    if(!sp.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }

    //Input surface
    sp.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Color color1={230,245,0};
    SDL_Color color2={255,0,127};
    SDL_Color color3={0,0,0};
    SDL_Rect rect[20];
    int run=1;
    SDL_Event e;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //back button
        rect[0]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[0]);
        surface = TTF_RenderText_Solid(sp.font, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[1]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[1]);

        //image sphere_center
        rect[2]={200,10,350,300};
        SDL_RenderCopy(render,img[87],NULL,&rect[2]);

        //image sphere_tangent
        rect[3]={650,10,350,300};
        SDL_RenderCopy(render,img[88],NULL,&rect[3]);

        //type
        surface=TTF_RenderText_Solid(sp.font," Sphere",color2);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[4]={70,330,100,40};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[4]);

        //option 1
        surface=TTF_RenderText_Solid(sp.font,"1. Inertia about Center axis ",color1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[5]={70,390,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[5]);

        //option 2
        surface=TTF_RenderText_Solid(sp.font,"2. Inertia about Tangent axis ",color1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[6]={70,430,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[6]);

        //options
        surface=TTF_RenderText_Solid(sp.font,"  1 / 2  ? ",color1);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[17]={400,360,100,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[17]);

        //Option type box
        rect[7]={400,400,100,40};
        SDL_SetRenderDrawColor(render,0,180,210,200);
        SDL_RenderFillRect(render,&rect[7]);

        //mass
        surface=TTF_RenderText_Solid(sp.font," m - mass of the sphere (kg): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[8]={30,490,230,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[8]);
        rect[9]={350,490,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[9]);

        //radius
        surface= TTF_RenderText_Solid(sp.font," r - radius of the sphere (m): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[10]={30,530,230,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[10]);
        rect[11]={350,530,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[11]);

        //calculate button
        rect[12]={500,630,300,60};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&rect[12]);
        surface = TTF_RenderText_Solid(sp.font, " CALCULATE ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[13]={550,640,200,40};
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
                            if(!st1.size()||!st2.size()||!st3.size()||!(st1=="1"|| st1=="2"))
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box properly!",window);
                            else {
                                Cal_Inertia_5_Sphere(window,render,img,img_rect,st1,st2,st3,mouse_x,mouse_y);
                                st1.clear();st2.clear();st3.clear();
                            }
                        }
                        break;
                    }

                //keyboard event
                case SDL_TEXTINPUT:
                    if((mouse_x>=400&&mouse_x<=500)&&(mouse_y>=400&&mouse_y<=440)){
                        st1+=e.text.text;
                    }
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520))
                        st2+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=530&&mouse_y<=560))
                        st3+=e.text.text;
                    break;
                //backspace
                case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if((mouse_x>=400&&mouse_x<=500)&&(mouse_y>=400&&mouse_y<=450)&&st1.size())
					st1.pop_back();
					else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520)&&st2.size())
					st2.pop_back();
					else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=530&&mouse_y<=560)&&st3.size())
                    st3.pop_back();
				}
				break;
            }
        }


        //input 1
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(sp.font, st1.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[14]={410,400,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[14]);
        }

        //input 2
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(sp.font, st2.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[15]={360,490,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[15]);
        }

        //input 3
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(sp.font, st3.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[16]={360,530,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[16]);
        }


        SDL_RenderPresent(render);
        }
        sp.Pfinish();
}

