#include<SDL2/SDL.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>

#include "CalculateImpulse.h"

using namespace std;

struct Impulse{
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
}imp;

void mass(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface= TTF_RenderText_Solid(imp.font,"Give the value of mass  (m): ",imp.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,350,250,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={300,350,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}
void vel_in(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(imp.font,"Give the value of initial velocity (Vi):",imp.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,400,250,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={350,400,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}
void vel_fin(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(imp.font,"Give the value of final velocity (Vf): ",imp.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,450,300,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={350,450,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);

}
void theta_in(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(imp.font,"Give the value of initial angle: ",imp.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,490,300,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={350,490,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);

}
void theta_fin(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface= TTF_RenderText_Solid(imp.font,"Give the value of final angle: ",imp.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,350,250,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={300,350,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}


void impul_x(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(imp.font,"Give the value of impulse in x axis: ",imp.color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,450,300,25};;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={480,400,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}


void calc_button_imp(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect1);
    surface = TTF_RenderText_Solid(imp.font, " CALCULATE ", imp.color);
    tex = SDL_CreateTextureFromSurface(render, surface);
    rect2={550,610,200,40};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, tex, NULL, &rect2);
}

void back_button_imp(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
   SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect1);
    surface = TTF_RenderText_Solid(imp.font, " BACK ", imp.color);
    tex = SDL_CreateTextureFromSurface(render, surface);
    rect2={10,6,surface->w,surface->h};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, tex, NULL, &rect2);
}

int Impulse_Event(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int run,SDL_Event e,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect[],string &st1,string &st2,string &st3, string &st4, string &st5,int &mous_x,int &mous_y){
    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT:
                st1.clear();st2.clear();st3.clear();st4.clear();st5.clear();
                run=0;
                break;
            case SDL_MOUSEMOTION:
                mous_x=e.motion.x;
                mous_y=e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(e.button.button){
                    case SDL_BUTTON_LEFT:
                    if(imp.flag==1&&(mous_x>=500&&mous_x<=700)&&(mous_y>=600&&mous_y<=640)){
                        if(!st1.size()||!st2.size()||!st3.size()||!st4.size()||!st5.size())
                        SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                        else {
                            Cal_find_impulse(window,render,img,img_rect,st1,st2,st3,st4,st5,mous_x,mous_y);
                            st1.clear();st2.clear();st3.clear();st4.clear();st5.clear();
                        }
                    }
                    else if(imp.flag==2&&(mous_x>=500&&mous_x<=700)&&(mous_y>=600&&mous_y<=640)){
                        if(!st1.size()||!st2.size()||!st3.size()||!st4.size()||!st5.size())
                        SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                        else {
                            Cal_find_2vel(window,render,img,img_rect,st1,st2,st3,st4,st5,mous_x,mous_y);
                            st1.clear();st2.clear();st3.clear();st4.clear();st5.clear();
                        }
                    }
                    else if((mous_x>=0&&mous_x<=100)&&(mous_y>=0&&mous_y<=50)){
                        st1.clear();st2.clear();st3.clear();st4.clear();st5.clear();
                        run=0;
                    }
                    break;
                }
            case SDL_TEXTINPUT:
                if((mous_x>=300&&mous_x<=600)&&(mous_y>=350&&mous_y<=375)){
                    st1+=e.text.text;
                }
                else if((mous_x>=480&&mous_x<=780)&&(mous_y>=400&&mous_y<=430))
                    st2+=e.text.text;
                else if((mous_x>=350&&mous_x<=650)&&(mous_y>=450&&mous_y<=480))
                    st3+=e.text.text;
                else if((mous_x>=350&&mous_x<=650)&&(mous_y>=490&&mous_y<=520))
                    st4+=e.text.text;
                else if((mous_x>=350&&mous_x<=600)&&(mous_y>=520&&mous_y<=550))
                    st5+=e.text.text;
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if((mous_x>=300&&mous_x<=600)&&(mous_y>=350&&mous_y<=375)&&st1.size())
                    st1.pop_back();
                    else if((mous_x>=480&&mous_x<=780)&&(mous_y>=400&&mous_y<=430)&&st2.size())
                    st2.pop_back();
                    else if((mous_x>=350&&mous_x<=650)&&(mous_y>=450&&mous_y<=480)&&st3.size())
                    st3.pop_back();
                    else if((mous_x>=350&&mous_x<=650)&&(mous_y>=490&&mous_y<=520)&&st4.size())
                    st4.pop_back();
                    else if((mous_x>=350&&mous_x<=600)&&(mous_y>=530&&mous_y<=560)&&st5.size())
                    st5.pop_back();
                }
            break;
            }
        }
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(imp.font, st1.c_str(), imp.color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[12].x=300;
            rect[12].y=350;
            rect[12].w=surface->w;
            rect[12].h=surface->h;
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[12]);
        }
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(imp.font, st2.c_str(), imp.color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[13]={480,400,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[13]);
        }
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(imp.font, st3.c_str(), imp.color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[14]={350,450,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[14]);
        }
        if ( st4.size() ) {
            surface = TTF_RenderText_Solid(imp.font, st4.c_str(), imp.color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[15]={350,490,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[15]);
        }
        if ( st5.size() ) {
            surface = TTF_RenderText_Solid(imp.font, st5.c_str(), imp.color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[16]={350,530,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[16]);
        }
    return run;
}
void find_impulse(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mous_x,int &mous_y){
    if(!imp.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    imp.flag=1;
    imp.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    string st1,st2,st3,st4,st5,st6;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,0,0,0,0);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Rect rect[20];
    SDL_Event ev;
    int run=1;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for mass
        rect[0]={30,350,250,25};
        rect[1]={300,350,300,30};
        mass(render,surface,tex,rect[0],rect[1]);
        //for initial velocity
        rect[2]={30,400,450,25};
        rect[3]={480,400,300,30};
        vel_in(render,surface,tex,rect[2],rect[3]);
        //for final velocity
        rect[4]={30,450,300,25};
        rect[5]={350,450,300,30};
        vel_fin(render,surface,tex,rect[4],rect[5]);
        //for initial angle
        rect[6]={30,490,300,25};
        rect[7]={350,490,300,30};
        theta_in(render,surface,tex,rect[6],rect[7]);
        //for final angle
        rect[8]={30,530,250,25};
        rect[9]={350,530,250,30};
        theta_fin(render,surface,tex,rect[8],rect[9]);
        //for backButton
        rect[10]={0,0,100,50};
        back_button_imp(render,surface,tex,rect[10],rect[17]);
        //for calculationButton
        rect[11]={500,600,300,60};
        rect[18]={550,610,200,40};
        calc_button_imp(render,surface,tex,rect[11],rect[18]);
        //for image
        SDL_RenderCopy(render,img[1],NULL,&img_rect[1]);
        //for event handling
        run=Impulse_Event(window,render,img,img_rect,run,ev,surface,tex,rect,st1,st2,st3,st4,st5,mous_x,mous_y);
        SDL_RenderPresent(render);
    }

    imp.Pfinish();
}


void find_2vel(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mous_x,int &mous_y){
    if(!imp.Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    imp.flag=2;
    imp.font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    string st1,st2,st3,st4,st5,st6;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,0,0,0,0);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Rect rect[20];
    SDL_Event ev;
    int run=1;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for mass
        rect[0]={30,350,250,25};
        rect[1]={300,350,300,30};
        mass(render,surface,tex,rect[0],rect[1]);
        //for initial angle
        rect[2]={30,400,450,25};
        rect[3]={480,400,300,30};
        theta_in(render,surface,tex,rect[2],rect[3]);
        //for final angle
        rect[4]={30,450,300,25};
        rect[5]={350,450,300,30};
        theta_fin(render,surface,tex,rect[4],rect[5]);
        //for impulse along x axis
        rect[6]={30,490,300,25};
        rect[7]={350,490,300,30};
        impul_x(render,surface,tex,rect[6],rect[7]);
        //for impulse along y axis
        surface= TTF_RenderText_Solid(imp.font,"Give the impulse along y axis: ",imp.color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[8]={30,530,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[8]);
        rect[9]={350,530,250,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect[9]);
        //for back button
        rect[10]={0,0,100,50};
        back_button_imp(render,surface,tex,rect[10],rect[17]);
        //for calculationButton
        rect[11]={500,600,300,60};
        rect[18]={550,610,200,40};
        calc_button_imp(render,surface,tex,rect[11],rect[18]);
        //for image
        SDL_RenderCopy(render,img[1],NULL,&img_rect[1]);
        //for event handling
        run=Impulse_Event(window,render,img,img_rect,run,ev,surface,tex,rect,st1,st2,st3,st4,st5,mous_x,mous_y);
        SDL_RenderPresent(render);
    }

    imp.Pfinish();
}

