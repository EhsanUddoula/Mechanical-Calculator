#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Chammer{
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
}cham;

//5
void Cal_Hammer_Nail(SDL_Window* window, SDL_Renderer* render, SDL_Texture* img[],SDL_Rect img_rect[],string &st1,string &st2,string &st3,string &st4,int &mouse_x,int &mouse_y){

    if(!cham.initial()){
        printf("Did not Initial\n");
        return;
    }

    double m,h,l,t,f,F,Ft;
    string ss1,ss2,ss3;

    /*  m = mass of hammer
    	h = height of hammer
  	  	l = lengh of nail
   		t = time of cotact between hammer & nail
   		f = Opposing force
    	F = force on nail
    	Ft = Impulsive force on nail */

    m=stod(st1);
    h=stod(st2);
    l=stod(st3);
    t=stod(st4);

    //formula
    f=m*9.8*h/l;	//f=mgh/l
    F=m*(9.8+f/m);  //F=m(g+a) //a=f/m
    Ft=F*t;

    ss1=to_string(f);
    ss2=to_string(F);
    ss3=to_string(Ft);

    ss1+="  N";
    ss2+="  N";
    ss3+="  Ns";

	//Output surface
    cham.sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    SDL_Texture* tex=NULL;
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Color color1={0,0,0};
    SDL_Rect srect[20];
    SDL_FRect rect[2];
    int run=1;
    SDL_Event e;
    float y1=475,y2=725;
    int flag=0;


    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);

        //Opposing force
        surface= TTF_RenderText_Solid(cham.sfont,"f- Opposing force by the ground:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,100,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[0]);
        srect[1]={300,100,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(cham.sfont, ss1.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={310,100,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[2]);

        //Force
        surface= TTF_RenderText_Solid(cham.sfont,"F- Force acting on the nail:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={30,150,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[3]);
        srect[4]={300,150,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[4]);
        surface = TTF_RenderText_Solid(cham.sfont, ss2.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[5]={310,150,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[5]);

        //Impulsive Force
        surface= TTF_RenderText_Solid(cham.sfont,"F*t-Impulsive force on the nail:",color);
        tex=SDL_CreateTextureFromSurface(render,surface);
        srect[6]={30,200,260,30};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&srect[6]);
        srect[7]={300,200,300,40};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(cham.sfont, ss3.c_str(), color1);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[8]={310,200,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[8]);

        //back button
        srect[9]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[9]);
        surface = TTF_RenderText_Solid(cham.sfont, " BACK ", color);
        tex = SDL_CreateTextureFromSurface(render, surface);
        srect[10]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, tex, NULL, &srect[10]);


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


        //Animation

        //image1
        srect[11]={630-300,550+50,600,300}; //x3-h >> h=width3/2   //y3+k >> k= nails hight
        SDL_RenderCopy(render,img[20],NULL,&srect[11]);

        //image2
        rect[0]={550.0,y2-25.0,50.0,50.0}; //y2=725 //25=height/2
        SDL_RenderCopyF(render,img[21],NULL,&rect[0]);

        //image3
        rect[1]={555.0,y1-75.0,150.0,150.0}; //y1=475 //75=height/2
        SDL_RenderCopyF(render,img[22],NULL,&rect[1]);

        //conditions of movement
        if((flag==0)||(y1+150.0<=y2)){
            y1+=2.0;
        }

        if(y1+97.0>y2){
            flag=1;
        }
        else{
            flag=0;
        }

        if( flag==1 && (y2<=725+50.0)){
            y2+=2.0;
        }

        if(y2>725.0+50.0){
            y1=475.0;
            y2=725.0;
        }


        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    cham.stop();
}



