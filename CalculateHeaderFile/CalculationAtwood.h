#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;
int h1=555,h2=555;

struct Catwood{
    TTF_Font* sfont=NULL;
    string ss1,ss2,ss3;
    SDL_Rect srect[20];

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
}catw;

int Cal_atEvent(SDL_Window* window, SDL_Renderer* render,int run,SDL_Event e,int &m_x,int &m_y){
    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT:
                run=0;
                break;
            case SDL_MOUSEMOTION:
                m_x=e.motion.x;
                m_y=e.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                case SDL_BUTTON_LEFT:
                    if((m_x>0&&m_x<100)&&(m_y>0&&m_y<50))
                    run=0;
                break;
        }
    }
    //cout<<m_x<<' '<<m_y<<endl;
    return run;
}

void animationAtw(double mass1,double mass2,SDL_Renderer* render){
    if(mass1>mass2){
            SDL_SetRenderDrawColor(render,0,0,255,255);
            catw.srect[8].y++;
            SDL_RenderFillRect(render,&catw.srect[8]);
            SDL_RenderDrawLine(render,555,410,555,h1++);
            catw.srect[9].y--;
            SDL_RenderFillRect(render,&catw.srect[9]);
            SDL_RenderDrawLine(render,635,410,635,h2--);
            if(h1==685){
                catw.srect[8].y=555;
                catw.srect[9].y=555;
                h1=555;
                h2=555;
            }
        }
        else if(mass1<mass2){
            SDL_SetRenderDrawColor(render,0,0,255,255);
            catw.srect[8].y--;
            SDL_RenderFillRect(render,&catw.srect[8]);
            SDL_RenderDrawLine(render,555,410,555,h1--);
            catw.srect[9].y++;
            SDL_RenderFillRect(render,&catw.srect[9]);
            SDL_RenderDrawLine(render,635,410,635,h2++);
            if(h2==685){
                catw.srect[8].y=555;
                catw.srect[9].y=555;
                h1=555;
                h2=555;
            }
        }
        else {
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RenderFillRect(render,&catw.srect[8]);
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RenderFillRect(render,&catw.srect[9]);
            SDL_SetRenderDrawColor(render,0,0,0,255);
            SDL_RenderDrawLine(render,555,410,555,555);
            SDL_SetRenderDrawColor(render,0,0,0,255);
            SDL_RenderDrawLine(render,635,410,635,555);
        }
}

void Calataccten(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,int &m_x,int &m_y){
    if(!catw.initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass1,mass2,g,acc,tension;
    mass1=stod(st1);
    mass2=stod(st2);
    g=stod(st3);
    if(mass1>=mass2){
        acc=((mass1-mass2)*g)/(mass1+mass2*1.0);
        tension=(2*mass1*mass2*g)/(mass1+mass2*1.0);
    }
    else{
        acc=((mass2-mass1)*g)/(mass1+mass2*1.0);
        tension=(2*mass1*mass2*g)/(mass1+mass2*1.0);
    }
    catw.ss1=to_string(acc);
    catw.ss1+=" m/s2";
    catw.ss2=to_string(tension);
    catw.ss2+=" N";
    int run=1;
    catw.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Event e;
    //for block1
    catw.srect[8]={530,555,50,50};
    catw.srect[10]={555,555,1,245};
    //for block2
    catw.srect[9]={610,555,50,50};
    catw.srect[11]={635,555,1,245};
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for acceleration
        surface= TTF_RenderText_Solid(catw.sfont,"Value Of Acceleration (a): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        catw.srect[0]={30,150,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&catw.srect[0]);
        catw.srect[1]={300,150,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&catw.srect[1]);
        surface = TTF_RenderText_Solid(catw.sfont, catw.ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        catw.srect[2]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &catw.srect[2]);
        //for Tension
        surface= TTF_RenderText_Solid(catw.sfont,"Value Of Tension Force (T): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        catw.srect[4]={30,190,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&catw.srect[4]);
        catw.srect[5]={300,190,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&catw.srect[5]);
        surface = TTF_RenderText_Solid(catw.sfont, catw.ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        catw.srect[6]={300,190,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &catw.srect[6]);
        //for image
        SDL_RenderCopy(render,img[97],NULL,&img_rect[21]);
        ////back button
        catw.srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&catw.srect[7]);
        surface = TTF_RenderText_Solid(catw.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        catw.srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &catw.srect[16]);
        //for event
        run=Cal_atEvent(window,render,run,e,m_x,m_y);
        animationAtw(mass1,mass2,render);
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    catw.stop();
}
void Calatm1m2(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,int &m_x,int &m_y){
    if(!catw.initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass1,mass2,g,acc,tension;
    acc=stod(st1);
    tension=stod(st2);
    g=stod(st3);
    mass1=tension/abs(g-acc);
    mass2=tension/(g+acc);
    catw.ss1=to_string(mass1);
    catw.ss1+=" kg";
    catw.ss2=to_string(mass2);
    catw.ss2+=" kg";
    int run=1;
    catw.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Event e;
    //for block1
    catw.srect[8]={530,555,50,50};
    catw.srect[10]={555,555,1,245};
    //for block2
    catw.srect[9]={610,555,50,50};
    catw.srect[11]={635,555,1,245};
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for acceleration
        surface= TTF_RenderText_Solid(catw.sfont,"Value Of mass 1 (m1): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        catw.srect[0]={30,150,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&catw.srect[0]);
        catw.srect[1]={300,150,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&catw.srect[1]);
        surface = TTF_RenderText_Solid(catw.sfont, catw.ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        catw.srect[2]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &catw.srect[2]);
        //for Tension
        surface= TTF_RenderText_Solid(catw.sfont,"Value Of mass 2 (m2): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        catw.srect[4]={30,190,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&catw.srect[4]);
        catw.srect[5]={300,190,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&catw.srect[5]);
        surface = TTF_RenderText_Solid(catw.sfont, catw.ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        catw.srect[6]={300,190,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &catw.srect[6]);
       //for image
        SDL_RenderCopy(render,img[97],NULL,&img_rect[21]);
        ////back button
        catw.srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&catw.srect[7]);
        surface = TTF_RenderText_Solid(catw.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        catw.srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &catw.srect[16]);
        //for event
        run=Cal_atEvent(window,render,run,e,m_x,m_y);
        animationAtw(mass1,mass2,render);
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    catw.stop();
}

