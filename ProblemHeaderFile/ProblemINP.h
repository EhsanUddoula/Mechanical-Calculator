#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include "CalculateINP.h"

using namespace std;


TTF_Font* font=NULL;
string st1,st2,st3,st4,st5,st6;
SDL_Color color={255,255,255};
int flag;

void mass_inp(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
        surface= TTF_RenderText_Solid(font,"m-Give the value of mass (kg): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        //rect1={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect1);
        //rect2={300,350,300,30};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&rect2);
}

void grav_inp(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(font,"g-Give the value of gravitational acceleration(m/s2): ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,400,450,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={480,400,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}

void theta_inp(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(font,"Give the value of angle (deg): ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,450,300,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={350,450,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}

void fric_inp(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(font,"f-Give the value of friction (N): ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,490,300,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={350,490,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);

}
void acc_inp(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    surface=TTF_RenderText_Solid(font,"a-Give the value of acceleration (m/s2): ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,490,300,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={350,490,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);

}

void calc_button(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_SetRenderDrawColor(render,140,200,30,140);
    SDL_RenderFillRect(render,&rect1);
    surface = TTF_RenderText_Solid(font, " CALCULATE ", color);
    tex = SDL_CreateTextureFromSurface(render, surface);
    //rect2={550,610,200,40};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, tex, NULL, &rect2);
}

void back_button(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_SetRenderDrawColor(render,140,200,30,140);
    SDL_RenderFillRect(render,&rect1);
    surface = TTF_RenderText_Solid(font, " BACK ", color);
    tex = SDL_CreateTextureFromSurface(render, surface);
    rect2={10,6,surface->w,surface->h};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, tex, NULL, &rect2);
}

/*void input_INP(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect[]){

}*/

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

int INP_Event(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int run,SDL_Event e,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect[],int &mous_x,int &mous_y){
    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT:
                st1.clear();st2.clear();st3.clear();st4.clear();
                run=0;
                break;
            case SDL_MOUSEMOTION:
                mous_x=e.motion.x;
                mous_y=e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(e.button.button){
                    case SDL_BUTTON_LEFT:
                    if(flag==1&&(mous_x>=500&&mous_x<=700)&&(mous_y>=600&&mous_y<=640)){
                        if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                        SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                        else {
                            CalInPacc(window,render,img,img_rect,st1,st2,st3,st4,mous_x,mous_y);
                            st1.clear();st2.clear();st3.clear();st4.clear();
                        }
                    }
                    else if(flag==2&&(mous_x>=500&&mous_x<=700)&&(mous_y>=600&&mous_y<=640)){
                        if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                        SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                        else {
                            CalInPfric(window,render,img,img_rect,st1,st2,st3,st4,mous_x,mous_y);
                            st1.clear();st2.clear();st3.clear();st4.clear();
                        }
                    }
                    else if(flag==3&&(mous_x>=500&&mous_x<=700)&&(mous_y>=600&&mous_y<=640)){
                        if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                        SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                        else {
                            CalInPgrav(window,render,img,img_rect,st1,st2,st3,st4,mous_x,mous_y);
                            st1.clear();st2.clear();st3.clear();st4.clear();
                        }
                    }
                    else if(flag==4&&(mous_x>=500&&mous_x<=700)&&(mous_y>=600&&mous_y<=640)){
                        if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                        SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                        else {
                            CalInPmass(window,render,img,img_rect,st1,st2,st3,st4,mous_x,mous_y);
                            st1.clear();st2.clear();st3.clear();st4.clear();
                        }
                    }
                    /*else if(flag==5&&(mous_x>=500&&mous_x<=700)&&(mous_y>=600&&mous_y<=640)){
                        if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                        SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                        else {
                            CalInPmass(window,render,img,img_rect,st1,st2,st3,st4,mous_x,mous_y);
                            st1.clear();st2.clear();st3.clear();st4.clear();
                        }
                    }*/
                    else if((mous_x>=0&&mous_x<=100)&&(mous_y>=0&&mous_y<=50)){
                        st1.clear();st2.clear();st3.clear();st4.clear();
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
            }
            break;
        }
    }
    if ( st1.size() ) {
        surface = TTF_RenderText_Solid(font, st1.c_str(), color);
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
        surface = TTF_RenderText_Solid(font, st2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[8]={480,400,surface->w,surface->h};
        //SDL_DestroyTexture(tex);
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[8]);
    }
    if ( st3.size() ) {
        surface = TTF_RenderText_Solid(font, st3.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[9]={350,450,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[9]);
    }
    if ( st4.size() ) {
        surface = TTF_RenderText_Solid(font, st4.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        rect[12]={350,490,surface->w,surface->h};
        //SDL_DestroyTexture(tex);
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &rect[12]);
    }

    return run;
}

void INCP_acc(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mous_x,int &mous_y){
    if(!Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    flag=1;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Event ev;
    SDL_Rect rect[20];
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for mass
        rect[0]={30,350,250,25};
        rect[4]={300,350,300,30};
        mass_inp(render,surface,tex,rect[0],rect[4]);
        //for g
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        grav_inp(render,surface,tex,rect[1],rect[5]);
        //for theta
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        theta_inp(render,surface,tex,rect[2],rect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        //for friction
        rect[10]={30,490,300,25};
        rect[11]={350,490,300,30};
        fric_inp(render,surface,tex,rect[10],rect[11]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};

        back_button(render,surface,tex,rect[14],rect[17]);
        //cout<<mous_x<<' '<<mous_y<<endl;
        //for event handling
        run=INP_Event(window,render,img,img_rect,run,ev,surface,tex,rect,mous_x,mous_y);
        //input handle
        //input_INP(render,surface,tex,rect);
        SDL_RenderPresent(render);
    }
        Pfinish();
}

void INCP_theta(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mous_x,int &mous_y)
{
    if(!Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    flag=2;
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
        //for mass
        rect[0]={30,350,250,25};
        rect[4]={300,350,300,30};
        mass_inp(render,surface,tex,rect[0],rect[4]);
        //for g
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        grav_inp(render,surface,tex,rect[1],rect[5]);
        //for acceleration
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        acc_inp(render,surface,tex,rect[2],rect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        //for friction
        rect[10]={30,490,300,25};
        rect[11]={350,490,300,30};
        fric_inp(render,surface,tex,rect[10],rect[11]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        back_button(render,surface,tex,rect[14],rect[17]);
        //for event handling
        run=INP_Event(window,render,img,img_rect,run,ev,surface,tex,rect,mous_x,mous_y);
        //cout<<mous_x<<' '<<mous_y<<endl;
        //input handle
        //input_INP(render,surface,tex,rect);
        SDL_RenderPresent(render);
    }
        Pfinish();
}

void INCP_friction(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mous_x,int &mous_y)
{
    if(!Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    flag=2;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Rect rect[20];
    SDL_Event ev;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for mass
        rect[0]={30,350,250,25};
        rect[4]={300,350,300,30};
        mass_inp(render,surface,tex,rect[0],rect[4]);
        //for g
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        grav_inp(render,surface,tex,rect[1],rect[5]);
        //for angle
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        theta_inp(render,surface,tex,rect[2],rect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        //for acceleration
        rect[10]={30,500,300,25};
        rect[11]={350,490,300,30};
        acc_inp(render,surface,tex,rect[10],rect[11]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        back_button(render,surface,tex,rect[14],rect[17]);
        //for event handling
        run=INP_Event(window,render,img,img_rect,run,ev,surface,tex,rect,mous_x,mous_y);
        //cout<<mous_x<<' '<<mous_y<<endl;
        //input handle
        //input_INP(render,surface,tex,rect);
        SDL_RenderPresent(render);
    }
        Pfinish();
}


void INCP_gravity(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mous_x,int &mous_y)
{
    if(!Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    flag=3;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Rect rect[20];
    SDL_Event ev;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for mass
        rect[0]={30,350,250,25};
        rect[4]={300,350,300,30};
        mass_inp(render,surface,tex,rect[0],rect[4]);
        //for accelration
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        acc_inp(render,surface,tex,rect[1],rect[5]);
        //for angle
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        theta_inp(render,surface,tex,rect[2],rect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        //for friction
        rect[10]={30,500,300,25};
        rect[11]={350,490,300,30};
        fric_inp(render,surface,tex,rect[10],rect[11]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        back_button(render,surface,tex,rect[14],rect[17]);
        //for event handling
        run=INP_Event(window,render,img,img_rect,run,ev,surface,tex,rect,mous_x,mous_y);
        //cout<<mous_x<<' '<<mous_y<<endl;
        //input handle
        //input_INP(render,surface,tex,rect);
        SDL_RenderPresent(render);
    }
        Pfinish();
}



void INCP_mass(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],int &mous_x,int &mous_y)
{
    if(!Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    flag=4;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Event ev;
    SDL_Rect rect[20];
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for friction
        rect[0]={30,350,250,25};
        rect[4]={300,350,300,30};
        fric_inp(render,surface,tex,rect[0],rect[4]);
        //for g
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        grav_inp(render,surface,tex,rect[1],rect[5]);
        //for acceleration
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        acc_inp(render,surface,tex,rect[2],rect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        //for theta
        rect[10]={30,490,300,25};
        rect[11]={350,490,300,30};
        theta_inp(render,surface,tex,rect[10],rect[11]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        back_button(render,surface,tex,rect[14],rect[17]);
        //for event handling
        run=INP_Event(window,render,img,img_rect,run,ev,surface,tex,rect,mous_x,mous_y);
        //cout<<mous_x<<' '<<mous_y<<endl;
        //input handle
        //input_INP(render,surface,tex,rect);
        SDL_RenderPresent(render);
    }
        Pfinish();
}









