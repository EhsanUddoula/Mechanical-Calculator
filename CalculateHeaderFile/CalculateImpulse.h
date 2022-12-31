#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Cimpulse{
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
}cimp;

int Cal_ImpEvent(SDL_Window* window, SDL_Renderer* render,int run,SDL_Event e,int &m_x,int &m_y){
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
    return run;
}

void animationImp(double theta_i,double theta_f,SDL_Renderer* render,SDL_FRect rect[],double vx[],double vy[],SDL_Texture* img[]){
            if(theta_i-0.0<=0.000001&&theta_f-0.0<=0.000001){
            SDL_RenderCopyF(render,img[6],NULL,&rect[0]);
            if(rect[0].x+50>=800)vx[0]=-vx[0];
            if(rect[0].x<350){
                rect[0].x=350.0;
                vx[0]=-vx[0];
            }
            rect[0].x+=vx[0];

            SDL_RenderPresent(render);
        }
        else if(theta_i>0.0&&theta_i<=30.0&&theta_f-0.0<=0.000001){
            SDL_RenderCopyF(render,img[6],NULL,&rect[1]);
            if(rect[1].x+50>=800){
                vx[1]=-vx[1];
                vy[0]=0;
            }
            if(rect[1].x<350){
                rect[1].x=350.0;
                vx[1]=-vx[1];
                vy[0]=0.73;
                rect[1].y=320.0;
            }
            rect[1].x+=vx[1];
            rect[1].y+=vy[0];

            SDL_RenderPresent(render);
        }
        else if(theta_i>30&&theta_i<=60.0&&theta_f-0.0<=0.000001){
            SDL_RenderCopyF(render,img[6],NULL,&rect[2]);
            if(rect[2].x+50>=800){
                vx[2]=-vx[2];
                vy[1]=0;
            }
            if(rect[2].x<350){
                rect[2].x=550.0;
                vx[2]=-vx[2];
                vy[1]=2.0;
                rect[2].y=320.0;
            }
            rect[2].x+=vx[2];
            rect[2].y+=vy[1];

            SDL_RenderPresent(render);
        }
        else if(theta_i>60&&theta_i<=90.0&&theta_f-0.0<=0.000001){
            SDL_RenderCopyF(render,img[6],NULL,&rect[3]);
            if(rect[3].x+50>=800.0){
                vx[3]=-vx[3];
                vy[2]=0;
            }
            if(rect[3].x<550){
                rect[3].x=650.0;
                vx[3]=-vx[3];
                vy[2]=3.73;
                rect[3].y=320.0;
            }
            rect[3].x+=vx[3];
            rect[3].y+=vy[2];

            SDL_RenderPresent(render);
        }
        else if(theta_i-0.0<=0.000001&&theta_f>0.0&&theta_f<=30.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[4]);
            if(rect[4].x+50>=800){
                vx[0]=-vx[0];
                vy[3]=0.73;
            }
            if(rect[4].x<350){
                rect[4].x=550.0;
                vx[0]=-vx[0];
                vy[3]=0;
                rect[4].y=450.0;
            }
            rect[4].x+=vx[0];
            rect[4].y+=vy[3];

            SDL_RenderPresent(render);
        }
        else if(theta_i>0&&theta_i<=30.0&&theta_f>0.0&&theta_f<=30.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[5]);
            if(rect[5].x+50>=800){
                vx[1]=-vx[1];
                vy[0]=0.73;
            }
            if(rect[5].x<350){
                rect[5].x=350.0;
                vx[1]=-vx[1];
                vy[0]=0.73;
                rect[5].y=350.0;
            }
            rect[5].x+=vx[1];
            rect[5].y+=vy[0];

            SDL_RenderPresent(render);
        }
        else if(theta_i>30.0&&theta_i<=60.0&&theta_f>0.0&&theta_f<=30.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[6]);
            if(rect[6].x+50>=800){
                vx[4]=-vx[1];
                vy[4]=0.73;
            }
            if(rect[6].x<350){
                rect[6].x=650.0;
                vx[4]=2.0;
                vy[4]=2.0;
                rect[6].y=350.0;
            }
            rect[6].x+=vx[4];
            rect[6].y+=vy[4];

            SDL_RenderPresent(render);
        }
        else if(theta_i>60.0&&theta_i<=90.0&&theta_f>0.0&&theta_f<=30.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[7]);
            if(rect[7].x+50>=800){
                vx[5]=-2.0;
                vy[5]=0.73;
            }
            if(rect[7].x<450){
                rect[7].x=700.0;
                vx[5]=1.0;
                vy[5]=3.73;
                rect[7].y=350.0;
            }
            rect[7].x+=vx[5];
            rect[7].y+=vy[5];

            SDL_RenderPresent(render);
        }
        else if(theta_i-0.0<=0.000001&&theta_f>30.0&&theta_f<=60.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[8]);
            if(rect[8].x+50>=800){
                vx[6]=-vx[2];
                vy[6]=2.0;
            }
            if(rect[8].x<350){
                rect[8].x=350.0;
                vx[6]=2.0;
                vy[6]=0.0;
                rect[8].y=450.0;
            }
            rect[8].x+=vx[6];
            rect[8].y+=vy[6];

            SDL_RenderPresent(render);
        }
        else if(theta_i>0.0&&theta_i<=30.0&&theta_f>30.0&&theta_f<=60.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[9]);
            if(rect[9].x+50>=800){
                vx[7]=-vx[2];
                vy[7]=2.0;
            }
            if(rect[9].x<350){
                rect[9].x=350.0;
                vx[7]=2.0;
                vy[7]=0.73;
                rect[9].y=400.0;
            }
            rect[9].x+=vx[7];
            rect[9].y+=vy[7];

            SDL_RenderPresent(render);
        }
        else if(theta_i>30.0&&theta_i<=60.0&&theta_f>30.0&&theta_f<=60.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[10]);
            if(rect[10].x+50>=800){
                vx[8]=-vx[2];
                vy[8]=2.0;
            }
            if(rect[10].x<500){
                rect[10].x=500.0;
                vx[8]=2.0;
                vy[8]=2.0;
                rect[10].y=350.0;
            }
            rect[10].x+=vx[8];
            rect[10].y+=vy[8];

            SDL_RenderPresent(render);
        }
        else if(theta_i>60.0&&theta_i<=90.0&&theta_f>30.0&&theta_f<=60.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[11]);
            if(rect[11].x+50>=800){
                vx[9]=-vx[2];
                vy[9]=2.0;
            }
            if(rect[11].x<500){
                rect[11].x=670.0;
                vx[9]=1.0;
                vy[9]=3.73;
                rect[11].y=350.0;
            }
            rect[11].x+=vx[9];
            rect[11].y+=vy[9];

            SDL_RenderPresent(render);
        }
        else if(theta_i-0.0<=0.000001&&theta_f>60.0&&theta_f<=90.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[12]);
            if(rect[12].x+50>=800){
                vx[10]=-1.0;
                vy[10]=3.73;
            }
            if(rect[12].x<450){
                rect[12].x=450.0;
                vx[10]=2.0;
                vy[10]=0.0;
                rect[12].y=350.0;
            }
            rect[12].x+=vx[10];
            rect[12].y+=vy[10];
            SDL_RenderPresent(render);
        }
        else if(theta_i>0.0&&theta_i<=30.0&&theta_f>60.0&&theta_f<=90.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[13]);
            if(rect[13].x+50>=800){
                vx[11]=-1.0;
                vy[11]=3.73;
            }
            if(rect[13].x<550){
                rect[13].x=550.0;
                vx[11]=2.0;
                vy[11]=0.73;
                rect[13].y=350.0;
            }
            rect[13].x+=vx[11];
            rect[13].y+=vy[11];

            SDL_RenderPresent(render);
        }
        else if(theta_i>30.0&&theta_i<=60.0&&theta_f>60.0&&theta_f<=90.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[14]);
            if(rect[14].x+50>=800){
                vx[12]=-1.0;
                vy[12]=3.73;
            }
            if(rect[14].x<570){
                rect[14].x=570.0;
                vx[12]=2.0;
                vy[12]=2.0;
                rect[14].y=350.0;
            }
            rect[14].x +=vx[12];
            rect[14].y +=vy[12];

            SDL_RenderPresent(render);
        }
        else if(theta_i>60.0&&theta_i<=90.0&&theta_f>60.0&&theta_f<=90.0){
            SDL_RenderCopyF(render,img[6],NULL,&rect[15]);
            if(rect[15].x+50>=800){
                vx[13]=-1.0;
                vy[13]=3.73;
            }
            if(rect[15].x<650){
                rect[15].x=670.0;
                vx[13]=1.0;
                vy[13]=3.73;
                rect[15].y=350.0;
            }
            rect[15].x+=vx[13];
            rect[15].y+=vy[13];

            SDL_RenderPresent(render);
        }
    SDL_Delay(10);
}

void Cal_find_impulse(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,string &st4,string &st5,int &m_x,int &m_y){
    if(!cimp.initial()){
        printf("Did not Initial\n");
        return;
    }

    double mass,veli,velf,ang_i,ang_f,momx,momy,imp,theta_i,theta_f;
    mass=stod(st1);
    veli=stod(st2);
    velf=stod(st3);
    theta_i=stod(st4);
    theta_f=stod(st5);
    ang_i=(M_PI*theta_i)/(180.0);
    ang_f=(M_PI*theta_f)/(180.0);
    momx=mass*veli*cos(ang_i)+mass*velf*cos(ang_f)*1.0;
    momy=mass*velf*sin(ang_f)-mass*veli*sin(ang_i)*1.0;
    imp=sqrt(momx*momx+momy*momy);
    cimp.ss1=to_string(momx);
    cimp.ss2=to_string(momy);
    cimp.ss3=to_string(imp);
    cimp.ss1+=" kgm/s";cimp.ss2+=" kgm/s";cimp.ss3+=" kgm/s";

    cimp.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    int run=1;
    SDL_Event e;
    //for ball movement
    SDL_FRect rect[20];
    double vx[30],vy[30];
    rect[0]={350.0,580.0,50.0,50.0};
    vx[0]=2.0;
    rect[1]={350.0,350.0,50.0,50.0};
    vx[1]=2.0;
    vy[0]=0.73;
    rect[2]={550.0,350.0,50.0,50.0};
    vx[2]=2.0;
    vy[1]=2.0;
    rect[3]={650.0,350.0,50.0,50.0};
    vx[3]=1.0;
    vy[2]=3.73;
    rect[4]={350.0,450.0,50.0,50.0};
    vy[3]=0.0;
    rect[5]={350.0,350.0,50.0,50.0};
    rect[6]={350.0,350.0,50.0,50.0};
    vx[4]=2.0;
    vy[4]=2.0;
    rect[7]={700.0,350.0,50.0,50.0};
    vx[5]=1.0;
    vy[5]=3.73;
    rect[8]={350.0,450.0,50.0,50.0};
    vx[6]=2.0;
    vy[6]=0.0;
    rect[9]={350.0,400.0,50.0,50.0};
    vx[7]=2.0;
    vy[7]=0.73;
    rect[10]={500.0,350.0,50.0,50.0};
    vx[8]=2.0;
    vy[8]=2.0;
    rect[11]={670.0,350.0,50.0,50.0};
    vx[9]=1.0;
    vy[9]=3.73;
    rect[12]={450.0,350.0,50.0,50.0};
    vx[10]=2.0;
    vy[10]=0.0;
    rect[13]={550.0,350.0,50.0,50.0};
    vx[11]=2.0;
    vy[11]=0.73;
    rect[14]={570.0,350.0,50.0,50.0};
    vx[12]=2.0;
    vy[12]=2.0;
    rect[15]={670.0,350.0,50.0,50.0};
    vx[13]=1.0;
    vy[13]=3.73;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for change in momentum in x axis
        surface= TTF_RenderText_Solid(cimp.sfont,"Change of momentum in x-axis P(x): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        cimp.srect[0]={30,200,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&cimp.srect[0]);
        cimp.srect[1]={300,200,300,30};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&cimp.srect[1]);
        surface = TTF_RenderText_Solid(cimp.sfont, cimp.ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        cimp.srect[2]={300,200,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &cimp.srect[2]);
        //for change in momentum in y axis
        surface= TTF_RenderText_Solid(cimp.sfont,"Change of momentum in y-axis P(y): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        cimp.srect[3]={30,240,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&cimp.srect[3]);
        cimp.srect[4]={300,240,300,30};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&cimp.srect[4]);
        surface = TTF_RenderText_Solid(cimp.sfont, cimp.ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        cimp.srect[5]={300,240,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &cimp.srect[5]);
        //for impulse
        surface= TTF_RenderText_Solid(cimp.sfont,"Change of momentum or Impulse (J): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        cimp.srect[6]={30,280,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&cimp.srect[6]);
        cimp.srect[7]={300,280,300,30};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&cimp.srect[7]);
        surface = TTF_RenderText_Solid(cimp.sfont, cimp.ss3.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        cimp.srect[8]={300,280,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &cimp.srect[8]);
        ////back button
        cimp.srect[9]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&cimp.srect[9]);
        surface = TTF_RenderText_Solid(cimp.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        cimp.srect[12]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &cimp.srect[12]);
        //wall
        cimp.srect[10]={800,340,60,480};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&cimp.srect[10]);
        SDL_SetRenderDrawColor(render,0,0,0,255);
        //for image
        //SDL_RenderCopy(render,img[1],NULL,&img_rect[1]);
        //event
        run=Cal_Event(window,render,run,e,m_x,m_y);
        //cout<<m_x<<' '<<m_y<<endl;
        animationImp(theta_i,theta_f,render,rect,vx,vy,img);
    }

    cimp.stop();
}

void Cal_find_2vel(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,string &st4,string &st5,int &m_x,int &m_y){
    if(!cimp.initial()){
        printf("Did not Initial\n");
        return;
    }

    double mass,theta_i,theta_f,ang_i,ang_f,px,py,d,dvf,dvi,pxm,pym,sini,sinf,cosi,cosf,vf,vi;
    mass=stod(st1);
    theta_i=stod(st2);
    theta_f=stod(st3);
    px=stod(st4);
    py=stod(st5);
    ang_i=(M_PI*theta_i)/(180.0);
    ang_f=(M_PI*theta_f)/(180.0);
    sini=sin(ang_i);
    sinf=sin(ang_f);
    cosi=cos(ang_i);
    cosf=cos(ang_f);
    pxm=px/mass*1.0;
    pym=py/mass*1.0;
    d=(cosf*sini*1.0)+(sinf*cosi*1.0);
    dvf=(pxm*sini)+(pym*cosi*1.0);
    dvi=(cosf*pym*1.0)-(sinf*pxm*1.0);
    vf=dvf/d;
    vi=dvi/d;
    cimp.ss1=to_string(vf);
    cimp.ss2=to_string(vi);
    cimp.ss1+=" m/s";cimp.ss2+=" m/s";
    cimp.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    int mouse_x,mouse_y;
    int run=1;
    SDL_Event e;
    //for ball movement
    SDL_FRect rect[20];
    double vx[30],vy[30];
    rect[0]={350.0,580.0,50.0,50.0};
    vx[0]=2.0;
    rect[1]={350.0,350.0,50.0,50.0};
    vx[1]=2.0;
    vy[0]=0.73;
    rect[2]={550.0,350.0,50.0,50.0};
    vx[2]=2.0;
    vy[1]=2.0;
    rect[3]={650.0,350.0,50.0,50.0};
    vx[3]=1.0;
    vy[2]=3.73;
    rect[4]={350.0,450.0,50.0,50.0};
    vy[3]=0.0;
    rect[5]={350.0,350.0,50.0,50.0};
    rect[6]={350.0,350.0,50.0,50.0};
    vx[4]=2.0;
    vy[4]=2.0;
    rect[7]={700.0,350.0,50.0,50.0};
    vx[5]=1.0;
    vy[5]=3.73;
    rect[8]={350.0,450.0,50.0,50.0};
    vx[6]=2.0;
    vy[6]=0.0;
    rect[9]={350.0,400.0,50.0,50.0};
    vx[7]=2.0;
    vy[7]=0.73;
    rect[10]={500.0,350.0,50.0,50.0};
    vx[8]=2.0;
    vy[8]=2.0;
    rect[11]={670.0,350.0,50.0,50.0};
    vx[9]=1.0;
    vy[9]=3.73;
    rect[12]={450.0,350.0,50.0,50.0};
    vx[10]=2.0;
    vy[10]=0.0;
    rect[13]={550.0,350.0,50.0,50.0};
    vx[11]=2.0;
    vy[11]=0.73;
    rect[14]={570.0,350.0,50.0,50.0};
    vx[12]=2.0;
    vy[12]=2.0;
    rect[15]={670.0,350.0,50.0,50.0};
    vx[13]=1.0;
    vy[13]=3.73;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for initial velocity
        surface= TTF_RenderText_Solid(cimp.sfont,"Value of the initial velocity : ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        cimp.srect[0]={30,200,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&cimp.srect[0]);
        cimp.srect[1]={300,200,300,30};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&cimp.srect[1]);
        surface = TTF_RenderText_Solid(cimp.sfont, cimp.ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        cimp.srect[2]={300,200,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &cimp.srect[2]);
        //for final velocity
        surface= TTF_RenderText_Solid(cimp.sfont,"Value of the final velocity: ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        cimp.srect[3]={30,240,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&cimp.srect[3]);
        cimp.srect[4]={300,240,300,30};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&cimp.srect[4]);
        surface = TTF_RenderText_Solid(cimp.sfont, cimp.ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        cimp.srect[5]={300,240,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &cimp.srect[5]);
        ////back button
        cimp.srect[9]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&cimp.srect[9]);
        surface = TTF_RenderText_Solid(cimp.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        cimp.srect[12]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &cimp.srect[12]);
        //wall
        cimp.srect[10]={800,340,60,480};
        SDL_SetRenderDrawColor(render,0,153,153,0);
        SDL_RenderFillRect(render,&cimp.srect[10]);
        SDL_SetRenderDrawColor(render,0,0,0,255);
        //for image
        //SDL_RenderCopy(render,img[1],NULL,&img_rect[1]);
        //event
        run=Cal_Event(window,render,run,e,m_x,m_y);
        //cout<<m_x<<' '<<m_y<<endl;
        animationImp(theta_i,theta_f,render,rect,vx,vy,img);

    }

    cimp.stop();
}

