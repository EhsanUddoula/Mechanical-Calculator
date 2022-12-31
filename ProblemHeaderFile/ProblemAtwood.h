#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>

#include "CalculationAtwood.h"

using namespace std;

struct Atwoood{
    TTF_Font* font=NULL;
    int flag=0;
    SDL_Color color={255,255,255};
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
}atw;

void mass1_at(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface= TTF_RenderText_Solid(atw.font,"m1-Give the value of mass 1 (kg): ",atw.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    rect1={30,350,250,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    rect2={300,350,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}

void mass2_at(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(atw.font,"m2-Give the value of mass 2 (kg): ",atw.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    rect1={30,400,250,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    rect2={460,400,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}

void gravity_at(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(atw.font,"g-Give the value of gravitational acceleration(m/s2): ",atw.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    rect1={30,450,300,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    rect2={350,450,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}

void acc_at(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
        surface= TTF_RenderText_Solid(atw.font,"a-Give the value of acceleration(m/s2): ",atw.color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect1={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect1);
        rect2={300,350,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect2);
}


void ten_at(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(atw.font,"T-Give the value of tension (N): ",atw.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    rect1={30,400,450,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    rect2={480,400,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}

void calc_button_at(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_SetRenderDrawColor(render,140,200,30,140);
    SDL_RenderFillRect(render,&rect1);
    surface = TTF_RenderText_Solid(atw.font, " CALCULATE ", atw.color);
    tex = SDL_CreateTextureFromSurface(render, surface);
    rect2={550,610,200,40};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, tex, NULL, &rect2);
}

void back_button_at(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_SetRenderDrawColor(render,140,200,30,140);
    SDL_RenderFillRect(render,&rect1);
    surface = TTF_RenderText_Solid(atw.font, " BACK ", atw.color);
    tex = SDL_CreateTextureFromSurface(render, surface);
    rect2={10,6,surface->w,surface->h};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, tex, NULL, &rect2);
}

int AtwoodEvent(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int run,SDL_Event e,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect[],string &st1,string &st2,string &st3,int &mouse_x,int &mouse_y){
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
                        if(atw.flag==1&&(mouse_x>=500&&mouse_x<=700)&&(mouse_y>=600&&mouse_y<=640)){
                            if(!st1.size()||!st2.size()||!st3.size())
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                            else {
                                Calataccten(window,render,img,img_rect,st1,st2,st3,mouse_x,mouse_y);
                                st1.clear();st2.clear();st3.clear();
                            }
                        }
                        else if(atw.flag==2&&(mouse_x>=500&&mouse_x<=700)&&(mouse_y>=600&&mouse_y<=640)){
                            if(!st1.size()||!st2.size()||!st3.size())
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                            else {
                                Calatm1m2(window,render,img,img_rect,st1,st2,st3,mouse_x,mouse_y);
                                st1.clear();st2.clear();st3.clear();
                            }
                        }
                        else if((mouse_x>=0&&mouse_x<=100)&&(mouse_y>=0&&mouse_y<=50)){
                            st1.clear();st2.clear();st3.clear();
                            run=0;
                        }
                        break;
                    }
                case SDL_TEXTINPUT:
                    if((mouse_x>=300&&mouse_x<=600)&&(mouse_y>=350&&mouse_y<=375)){
                        st1+=e.text.text;
                    }
                    else if((mouse_x>=480&&mouse_x<=780)&&(mouse_y>=400&&mouse_y<=430))
                        st2+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480))
                        st3+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520))
                        st4+=e.text.text;
                    break;
                case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if((mouse_x>=300&&mouse_x<=600)&&(mouse_y>=350&&mouse_y<=375)&&st1.size())
					st1.pop_back();
					else if((mouse_x>=480&&mouse_x<=780)&&(mouse_y>=400&&mouse_y<=430)&&st2.size())
					st2.pop_back();
					else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480)&&st3.size())
                    st3.pop_back();
				}
				break;
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(atw.font, st1.c_str(), atw.color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[3].x=300;
            rect[3].y=350;
            rect[3].w=surface->w;
            rect[3].h=surface->h;
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[3]);
        }
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(atw.font, st2.c_str(), atw.color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[8]={480,400,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[8]);
        }
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(atw.font, st3.c_str(), atw.color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[9]={350,450,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[9]);
        }
        return run;
}

void at_acc_ten(SDL_Window* window,SDL_Renderer* render,SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y)
{
    if(!atw.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    atw.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    atw.flag=1;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Rect rect[20];
    string st1,st2,st3,st4;
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Event ev;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for mass1
        rect[0]={30,400,450,25};
        rect[4]={300,350,300,30};
        mass1_at(render,surface,tex,rect[0],rect[4]);
        //for mass2
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        mass2_at(render,surface,tex,rect[1],rect[5]);
        //for gravity
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        gravity_at(render,surface,tex,rect[2],rect[6]);
        //for image
        SDL_RenderCopy(render,img[2],NULL,&img_rect[2]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button_at(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        back_button_at(render,surface,tex,rect[14],rect[17]);
        run=AtwoodEvent(window,render,img,img_rect,run,ev,surface,tex,rect,st1,st2,st3,mouse_x,mouse_y);
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }
        atw.Pfinish();
}

void at_m1_m2(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mouse_x,int &mouse_y)
{
    if(!atw.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    atw.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    atw.flag=2;
    string st1,st2,st3,st4;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Rect rect[20];
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Event ev;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for acceleration
        rect[0]={30,400,450,25};
        rect[4]={300,350,300,30};
        acc_at(render,surface,tex,rect[0],rect[4]);
        //for tension
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        ten_at(render,surface,tex,rect[1],rect[5]);
        //for gravity
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        gravity_at(render,surface,tex,rect[2],rect[6]);
        //for image
        SDL_RenderCopy(render,img[2],NULL,&img_rect[2]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        back_button(render,surface,tex,rect[14],rect[17]);
        run=AtwoodEvent(window,render,img,img_rect,run,ev,surface,tex,rect,st1,st2,st3,mouse_x,mouse_y);
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }
        atw.Pfinish();
}

