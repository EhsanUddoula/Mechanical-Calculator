#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

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

int Cal_Event(SDL_Window* window, SDL_Renderer* render,int run,SDL_Event e,int &m_x,int &m_y){
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
                    if((m_x>0&&m_x<1000)&&(m_y>0&&m_y<50))
                    run=0;
                break;
        }
    }
    return run;
}

void animationINP(double theta,SDL_Renderer* render,SDL_FRect rect[]){
    if(theta>0.0&&theta<=10.0){
            double angle=85.0;
            SDL_SetRenderDrawColor(render,0,255,0,255);
            SDL_RenderDrawLine(render,400,690,650,690);
            SDL_RenderDrawLine(render,650,690,650,668);
            SDL_RenderDrawLine(render,400,690,650,668);
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RendererFlip flip=SDL_FLIP_NONE;

            SDL_Texture *tex= SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, 50, 50);
            SDL_SetRenderTarget(render, tex);
            SDL_RenderClear(render);
            SDL_SetRenderTarget(render, NULL);
            SDL_RenderCopyExF(render,tex,NULL,&rect[0],angle,NULL,flip);
            if(rect[0].x<=360.0&&rect[0].y>=640.0){
                rect[0].x=600.0;
                rect[0].y=618.0;
            }
            rect[0].x-=2;
            rect[0].y+=0.18;

            SDL_RenderPresent(render);
        }
        else if(theta>10.0&&theta<=20.0){
            double angle=75.0;
            SDL_SetRenderDrawColor(render,0,255,0,255);
            SDL_RenderDrawLine(render,400,690,650,690);
            SDL_RenderDrawLine(render,650,690,650,623);
            SDL_RenderDrawLine(render,400,690,650,623);
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RendererFlip flip=SDL_FLIP_NONE;

            SDL_Texture *tex= SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, 50, 50);
            SDL_SetRenderTarget(render, tex);
            SDL_RenderClear(render);
            SDL_SetRenderTarget(render, NULL);
            SDL_RenderCopyExF(render,tex,NULL,&rect[1],angle,NULL,flip);
            if(rect[1].x<=360.0&&rect[1].y>=640.0){
                rect[1].x=600.0;
                rect[1].y=577.0;
            }
            rect[1].x-=2;
            rect[1].y+=0.54;

            SDL_RenderPresent(render);
        }
        else if(theta>20.0&&theta<=40.0){
            double angle=60.0;
            SDL_SetRenderDrawColor(render,0,255,0,255);
            SDL_RenderDrawLine(render,400,690,650,690);
            SDL_RenderDrawLine(render,650,690,650,546);
            SDL_RenderDrawLine(render,400,690,650,546);
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RendererFlip flip=SDL_FLIP_NONE;

            SDL_Texture *tex= SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, 50, 50);
            SDL_SetRenderTarget(render, tex);
            SDL_RenderClear(render);
            SDL_SetRenderTarget(render, NULL);
            SDL_RenderCopyExF(render,tex,NULL,&rect[2],angle,NULL,flip);
            if(rect[2].x<=360.0&&rect[2].y>=640.0){
                rect[2].x=600.0;
                rect[2].y=502.0;
            }
            rect[2].x-=1;
            rect[2].y+=0.58;

            SDL_RenderPresent(render);
        }
        else if(theta>40.0&&theta<=50.0){
            double angle=45.0;
            SDL_SetRenderDrawColor(render,0,255,0,255);
            SDL_RenderDrawLine(render,400,700,600,700);
            SDL_RenderDrawLine(render,600,700,600,500);
            SDL_RenderDrawLine(render,400,700,600,500);
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RendererFlip flip=SDL_FLIP_NONE;

            SDL_Texture *tex= SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, 50, 50);
            SDL_SetRenderTarget(render, tex);
            SDL_RenderClear(render);
            SDL_SetRenderTarget(render, NULL);
            SDL_RenderCopyExF(render,tex,NULL,&rect[3],angle,NULL,flip);
            if(rect[3].x<=360.0&&rect[3].y>=650.0){
                rect[3].x=550.0;
                rect[3].y=455.0;
            }
            rect[3].x-=1;
            rect[3].y+=1;

            SDL_RenderPresent(render);
        }
        else if(theta>50.0&&theta<=80.0){
            double angle=30.0;
            SDL_SetRenderDrawColor(render,0,255,0,255);
            SDL_RenderDrawLine(render,400,750,550,750);
            SDL_RenderDrawLine(render,550,750,550,490);
            SDL_RenderDrawLine(render,400,750,550,490);
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RendererFlip flip=SDL_FLIP_NONE;

            SDL_Texture *tex= SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, 50, 50);
            SDL_SetRenderTarget(render, tex);
            SDL_RenderClear(render);
            SDL_SetRenderTarget(render, NULL);
            SDL_RenderCopyExF(render,tex,NULL,&rect[4],angle,NULL,flip);
            if(rect[4].x<=360.0&&rect[4].y>=700.0){
                rect[4].x=500.0;
                rect[4].y=455.0;
            }
            rect[4].x-=1;
            rect[4].y+=1.73;

            SDL_RenderPresent(render);
        }
        else if(theta>80.0&&theta<=89.0){
            double angle=10.0;
            SDL_SetRenderDrawColor(render,0,255,0,255);
            SDL_RenderDrawLine(render,400,750,450,750);
            SDL_RenderDrawLine(render,450,750,450,466);
            SDL_RenderDrawLine(render,400,750,450,466);
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RendererFlip flip=SDL_FLIP_NONE;

            SDL_Texture *tex= SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, 50, 50);
            SDL_SetRenderTarget(render, tex);
            SDL_RenderClear(render);
            SDL_SetRenderTarget(render, NULL);
            SDL_RenderCopyExF(render,tex,NULL,&rect[5],angle,NULL,flip);
            if(rect[5].x<=360.0&&rect[5].y>=700.0){
                rect[5].x=400.0;
                rect[5].y=430.0;
            }
            rect[5].x-=.5;
            rect[5].y+=2.84;

            SDL_RenderPresent(render);
        }
        else if(theta-90.0<=0.000001){
            double angle=0.0;
            SDL_SetRenderDrawColor(render,0,255,0,255);
            SDL_RenderDrawLine(render,400,700,650,700);
            SDL_RenderDrawLine(render,650,700,650,450);
            //SDL_RenderDrawLine(render,400,700,650,500);
            SDL_SetRenderDrawColor(render,0,0,255,255);
            SDL_RendererFlip flip=SDL_FLIP_NONE;

            SDL_Texture *tex= SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, 50, 50);
            SDL_SetRenderTarget(render, tex);
            SDL_RenderClear(render);
            SDL_SetRenderTarget(render, NULL);
            SDL_RenderCopyExF(render,tex,NULL,&rect[6],angle,NULL,flip);
            if(rect[6].y>=650.0){
                rect[6].y=450.0;
            }
            rect[6].y+=1.0;

            SDL_RenderPresent(render);
        }
    SDL_Delay(10);
}

void CalInPacc(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string st1,string st2,string st3,string st4,int &m_x,int &m_y){
    if(!initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass,gravity,ang,fric,theta,acc,force;
    mass=stod(st1);
    gravity=stod(st2);
    theta=stod(st3);
    fric=stod(st4);
    ang=(M_PI*theta)/(180.0);
    acc=(mass*gravity*sin(ang)-fric)/(mass*1.0);
    force=(mass*gravity*cos(ang));
    ss1=to_string(acc);
    ss1+=" m/s2";
    ss2=to_string(force);
    ss2+=" N";
    int run=1;
    sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Event e;
    SDL_FRect rect[13];
    rect[0]={600.0,618.0,50.0,50.0};
    rect[1]={600.0,577.0,50.0,50.0};
    rect[2]={600.0,502.0,50.0,50.0};
    rect[3]={550.0,455.0,50.0,50.0};
    rect[4]={500.0,455.0,50.0,50.0};
    rect[5]={400.0,430.0,50.0,50.0};
    rect[6]={600.0,450.0,50.0,50.0};
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for acceleration
        surface= TTF_RenderText_Solid(sfont,"Value Of Acceleration (a): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,350,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,350,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        //for Normal
        surface= TTF_RenderText_Solid(sfont,"Value Of Normal Force (N): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[4]={30,390,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[4]);
        srect[5]={300,390,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[5]);
        surface = TTF_RenderText_Solid(sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[6]={300,390,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        ////back button
        srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[16]);
        //event
        run=Cal_Event(window,render,run,e,m_x,m_y);
        //cout<<m_x<<' '<<m_y<<endl;
        animationINP(theta,render,rect);
        }
    stop();
}
void CalInPtheta(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string st1,string st2,string st3,string st4,int &m_x,int &m_y){
    if(!initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass,gravity,ang,fric,theta,acc,force;
    mass=stod(st1);
    gravity=stod(st2);
    acc=stod(st3);
    fric=stod(st4);
    theta=asin(((mass*acc)+fric)/(mass*gravity));
    ang=(theta*180.0)/M_PI;
    force=(mass*gravity*cos(theta));
    ss1=to_string(ang);
    ss1+=" ";
    ss2=to_string(force);
    ss2+=" N";
    int run=1;
    sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Event e;
    SDL_FRect rect[13];
    rect[0]={600.0,618.0,50.0,50.0};
    rect[1]={600.0,577.0,50.0,50.0};
    rect[2]={600.0,502.0,50.0,50.0};
    rect[3]={550.0,455.0,50.0,50.0};
    rect[4]={500.0,455.0,50.0,50.0};
    rect[5]={400.0,430.0,50.0,50.0};
    rect[6]={600.0,450.0,50.0,50.0};
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for angle
        surface= TTF_RenderText_Solid(sfont,"Value Of Angle (): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,350,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,350,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        //for Normal
        surface= TTF_RenderText_Solid(sfont,"Value Of Normal Force (N): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[4]={30,390,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[4]);
        srect[5]={300,390,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[5]);
        surface = TTF_RenderText_Solid(sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[6]={300,390,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        ////back button
        srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[16]);
        //event
        run=Cal_Event(window,render,run,e,m_x,m_y);
        //cout<<m_x<<' '<<m_y<<endl;
        animationINP(theta,render,rect);
    }
    stop();
}

void CalInPfric(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string st1,string st2,string st3,string st4,int &m_x,int &m_y){
    if(!initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass,gravity,ang,fric,theta,acc,force;
    mass=stod(st1);
    gravity=stod(st2);
    theta=stod(st3);
    acc=stod(st4);
    ang=(M_PI*theta)/180.0;
    fric=mass*1.0*(acc+(gravity*sin(ang)));
    force=(mass*gravity*cos(ang));
    ss1=to_string(fric);
    ss1+="N";
    ss2=to_string(force);
    ss2+=" N";
    int run=1;
    sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Event e;
    SDL_FRect rect[13];
    rect[0]={600.0,618.0,50.0,50.0};
    rect[1]={600.0,577.0,50.0,50.0};
    rect[2]={600.0,502.0,50.0,50.0};
    rect[3]={550.0,455.0,50.0,50.0};
    rect[4]={500.0,455.0,50.0,50.0};
    rect[5]={400.0,430.0,50.0,50.0};
    rect[6]={600.0,450.0,50.0,50.0};
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for angle
        surface= TTF_RenderText_Solid(sfont,"Value Of Angle (): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,350,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,350,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        //for Normal
        surface= TTF_RenderText_Solid(sfont,"Value Of Normal Force (N): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[4]={30,390,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[4]);
        srect[5]={300,390,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[5]);
        surface = TTF_RenderText_Solid(sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[6]={300,390,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        ////back button
        srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[16]);
        //event
        run=Cal_Event(window,render,run,e,m_x,m_y);
        //cout<<m_x<<' '<<m_y<<endl;
        animationINP(theta,render,rect);
    }
    stop();
}

void CalInPgrav(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string st1,string st2,string st3,string st4,int &m_x,int &m_y){
    if(!initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass,gravity,ang,fric,theta,acc,force;
    mass=stod(st1);
    acc=stod(st2);
    theta=stod(st3);
    fric=stod(st4);
    ang=(M_PI*theta)/180.0;
    gravity=(((mass*acc)+fric)/(mass*sin(ang)));
    force=(mass*gravity*cos(ang));
    ss1=to_string(gravity);
    ss1+="ms^(-2)";
    ss2=to_string(force);
    ss2+=" N";
    int run=1;
    sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Event e;
    SDL_FRect rect[13];
    rect[0]={600.0,618.0,50.0,50.0};
    rect[1]={600.0,577.0,50.0,50.0};
    rect[2]={600.0,502.0,50.0,50.0};
    rect[3]={550.0,455.0,50.0,50.0};
    rect[4]={500.0,455.0,50.0,50.0};
    rect[5]={400.0,430.0,50.0,50.0};
    rect[6]={600.0,450.0,50.0,50.0};
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for angle
        surface= TTF_RenderText_Solid(sfont,"Value Of Angle (): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,350,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,350,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        //for Normal
        surface= TTF_RenderText_Solid(sfont,"Value Of Normal Force (N): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[4]={30,390,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[4]);
        srect[5]={300,390,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[5]);
        surface = TTF_RenderText_Solid(sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[6]={300,390,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        ////back button
        srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[16]);
        //event
        run=Cal_Event(window,render,run,e,m_x,m_y);
        //cout<<m_x<<' '<<m_y<<endl;
        animationINP(theta,render,rect);
        }
    stop();
}

void CalInPmass(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string st1,string st2,string st3,string st4,int &m_x,int &m_y){
    if(!initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass,gravity,ang,fric,theta,acc,force;
    fric=stod(st1);
    gravity=stod(st2);
    acc=stod(st3);
    theta=stod(st4);
    ang=(M_PI*theta)/(180.0);
    mass=(fric*1.0)/(acc+(gravity*sin(ang)));
    force=(mass*gravity*cos(ang));
    ss1=to_string(mass);
    ss1+=" kg";
    ss2=to_string(force);
    ss2+=" N";
    int run=1;
    sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Event e;
    //for box to animate
    SDL_FRect rect[13];
    rect[0]={600.0,618.0,50.0,50.0};
    rect[1]={600.0,577.0,50.0,50.0};
    rect[2]={600.0,502.0,50.0,50.0};
    rect[3]={550.0,455.0,50.0,50.0};
    rect[4]={500.0,455.0,50.0,50.0};
    rect[5]={400.0,430.0,50.0,50.0};
    rect[6]={600.0,450.0,50.0,50.0};
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for angle
        surface= TTF_RenderText_Solid(sfont,"Value Of Angle (): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,350,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,350,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);
        //for Normal
        surface= TTF_RenderText_Solid(sfont,"Value Of Normal Force (N): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[4]={30,390,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[4]);
        srect[5]={300,390,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[5]);
        surface = TTF_RenderText_Solid(sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[6]={300,390,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[6]);
        //for image
        SDL_RenderCopy(render,img[0],NULL,&img_rect[0]);
        ////back button
        srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[16]);
        //event
        run=Cal_Event(window,render,run,e,m_x,m_y);
        //cout<<m_x<<' '<<m_y<<endl;
        animationINP(theta,render,rect);
    }
    stop();
}




