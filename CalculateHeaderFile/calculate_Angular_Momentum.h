#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct CAngM{
    TTF_Font* sfont=NULL;

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
}cang;
//2
void Cal_Angular_Momentum(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,int &mouse_x,int &mouse_y){

    if(!cang.initial()){
    	printf("Did not Initial\n");
    	return;
    }

    double s2,s3,i,w,E,l;
    string ss1,ss2;

    /* s2,s3 = random variable
       i = Inertia
       w = Angular velocity
       E = Kinetic Energy
       l = Angular Momentum */

    s2=stod(st2);
    s3=stod(st3);


	//calculation

	//for input I,W
    if(st1=="IW"){
    	i=s2;
    	w=s3;

        //formula
        E=i*w*w/2;
        l=i*w;

        ss1=to_string(E);
        ss2=to_string(l);

        ss1+=" j";
        ss2+=" kg rad/s";
    }

	//for input I,E
    if(st1=="IE"){
        i=s2;
        E=s3;

        //formula
        w=sqrt(2*E/i);
        l=i*w;

        ss1=to_string(w);
        ss2=to_string(l);

        ss1+=" rad/s";
        ss2+=" kg rad/s";
    }

	//for input I,L
    if(st1=="IL"){
        i=s2;
        l=s3;

        //formula
        w=l/i;
        E=i*w*w/2;

        ss1=to_string(w);
        ss2=to_string(E);

        ss1+=" rad/s";
        ss2+=" j";
    }

	//for input W,E
    if(st1=="WE"){
        w=s2;
        E=s3;

        //formula
        i=2*E/(w*w);
        l=i*w;

        ss1=to_string(i);
        ss2=to_string(l);

        ss1+=" kg m2";
        ss2+=" kg rad/s";

    }

	//for input W,L
    if(st1=="WL"){
        w=s2;
        l=s3;

        //formula
        i=l/w;
        E=i*w*w/2;

        ss1=to_string(i);
        ss2=to_string(E);

        ss1+=" kg m2";
        ss2+=" j";
    }

	//for input E,L
    if(st1=="EL"){
        E=s2;
        l=s3;

        //formula
        w=2*E/l;
        i=l/w;

        ss1=to_string(w);
        ss2=to_string(i);

        ss1+=" kg rad/s";
        ss2+=" kg m2";
    }


	//Output surface
    cang.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Rect srect[20];
    int run=1;
    SDL_Event e;

    //for Rotation
    //starting point(x,y)=(x1,y1)=(500,500)
    //center (x,y) = (h,k)=(600,500)
    srect[18]={300,600,50,50};//sphere
    int r=200,speed=6;
    int flag=1,k=500;
    float p,h;
    h=300+r;
    int x1=srect[18].x;
    int y1=srect[18].y;



    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //back button
        srect[12]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[12]);
        surface = TTF_RenderText_Solid(cang.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[13]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[13]);


		//I,W
        if(st1=="IW"){
        //E-Kinetic Energy
        surface= TTF_RenderText_Solid(cang.sfont,"Kinetic Energy(E): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cang.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //L-Angular momentum
        surface= TTF_RenderText_Solid(cang.sfont,"Angular Momentum (L): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cang.sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);
        }


		//I,E
        if(st1=="IE"){
        //W-Angular velocity
        surface= TTF_RenderText_Solid(cang.sfont,"Angular Velocity(W): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cang.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //L-Angular Momentum
        surface= TTF_RenderText_Solid(cang.sfont,"Angular Momentum (L): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cang.sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);
        }


		//I,L
        if(st1=="IL"){
        //W-Angular Velocity
        surface= TTF_RenderText_Solid(cang.sfont,"Angular Velocity(W): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cang.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

		//E-Kinetic Energy
        surface= TTF_RenderText_Solid(cang.sfont,"Kinetic Energy(E): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cang.sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);
        }


		//W,E
        if(st1=="WE"){
        //I-Inertia
        surface= TTF_RenderText_Solid(cang.sfont,"Inertia (I): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cang.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //L-Angular Momentum
        surface= TTF_RenderText_Solid(cang.sfont,"Angular Momentum (L): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cang.sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);
        }


		//W,L
        if(st1=="WL"){
        //I-Inertia
        surface= TTF_RenderText_Solid(cang.sfont,"Inertia (I): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cang.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //E-Kinetic Energy
        surface= TTF_RenderText_Solid(cang.sfont,"Kinetic Energy(E): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cang.sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);
        }


		//E,L
        if(st1=="EL"){
        //W-Angular Velocity
        surface= TTF_RenderText_Solid(cang.sfont,"Angular Velocity(W): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cang.sfont, ss1.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //I-Inertia
        surface= TTF_RenderText_Solid(cang.sfont,"Inertia (I): ",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,250,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cang.sfont, ss2.c_str(), color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={300,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);
        }


        //mouse event
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    run=0;
                    break;
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    case SDL_BUTTON_LEFT:
                        if((mouse_x>0&&mouse_x<100)&&(mouse_y>0&&mouse_y<50))
                        run=0;
                    break;
            }
        }


        //Animation - sphere's rotation

        //sphere
        SDL_RenderCopy(render,img[6],NULL,&srect[18]);

        //circular ring

        SDL_RenderCopy(render,img[4],NULL,&srect[15]);
        int R;
        R=r+r/2+r/4;
        srect[15]={(h+25-R/2),(k+25-R/2),R,R}; //25= sphere's height/width's(50) half

		//center point
        SDL_RenderCopy(render,img[5],NULL,&srect[14]);
        srect[14]={h-10+25,k-10+25,20,20};

		//conditions for rotation
        if(flag==1 && srect[18].x>=x1 && srect[18].x<=x1+r+r){
            srect[18].x=srect[18].x+speed;
            p=srect[18].x-h;
            srect[18].y=sqrt((r*r)-(p*p))+k;

            if(srect[18].x>=x1+r+r)
                flag=0;
        }
        else if(flag==0){
            srect[18].x=srect[18].x-speed;
            p=srect[18].x-h;
            srect[18].y=-sqrt((r*r)-(p*p))+k;

            if(srect[18].x<=x1)
                flag=1;
        }


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    cang.stop();
}

