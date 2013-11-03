/* 
 * File:   Game.hpp
 * Author: garys
 *
 * Created on October 26, 2013, 9:29 AM
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include "gameengine.h"
#include "guntypes.hpp"
#include "bullets.hpp"
#include "boosts.hpp"
#include "Weapon.hpp"
#include "foes.hpp"
#include "player.hpp"
#include "Menu.hpp"

class game{
    short screen_tag;
    //The keys array
    bool keys[323];
    //The selection tracker for the menus
    short selection;
    //The resizable array 
    boost::ptr_vector<foe> baddies;
    
    engine::pointer mouse;
    //These are the menus
    Main opening;
    //levels difficulty;
    //saves stored_games;
    settings options;
    visual resolution;
    character player;
    //The SDL info
    SDL_Event event;
    SDL_Surface* screen;
    SDL_Surface* buffer;
public:
    game(){
        screen_tag = 0;
        selection = 0;
        baddies.resize(1);
        
        for(short i = 0; i < 323; i++){
            keys[i] = false;
        }
        //Setting up the menus
        opening = Main();
        //difficulty = levels();
        //stored_games = saves();
        options = settings();
        resolution = visual();
        
    }
    
    bool init_video(){
        short screenw;
        short screenh;
        
        switch(screen_tag){
            case 0: screenw = 800; screenh = 600; break;
            case 1: screenw = 1024; screenh = 768; break;
            case 2: screenw = 1280; screenh = 960; break;
            case 3: screenw = 1280; screenh = 1024; break;
            case 4: screenw = 1440; screenh = 960; break;
            case 5: screenw = 1680; screenh = 1050; break;
            case 6: screenw = 2048; screenh = 1152; break;
        }
        screen = SDL_SetVideoMode(screenw, screenh, 32, SDL_HWSURFACE || SDL_SWSURFACE);
        buffer = SDL_CreateRGBSurface(screenw, screenh, 32, 0, 0, 0, 255, SDL_HWSURFACE || SDL_SWSURFACE);
    }
    
    void foe_placer(){
        baddies[0].place(player.getx(), -50);
        
        for(short i = 1; i < baddies.size(); i = i +2){
            if (i == 0){
                baddies[i].place(player.getx() - baddies[i].get_w(), -50);
            }
            else baddies[i].place(baddies[i-2].get_x() - baddies[i-2].get_w(), -50);
        }
        
        for (short i = 2; i < baddies.size(); i = i+ 2){
            if (i == 2){
                baddies[i].place(baddies[0].get_x() + baddies[0].get_w(), -50);
            }
            else baddies[i].place(baddies[i-2].get_x() + baddies[i-2].get_w(), -50);
        }
    }
    
    bool begin_game(){
        player.place(screen->w/2, screen->h - 100);
        foe_placer();
    }
    
    void render(){
        if (selection == 0){
            opening.render(screen);
        }
        else if (selection ==1){
            options.render(screen);
        }
        else if (selection == 2){
            resolution.render(screen);
        }
        else if (selection == 3){
            for (short i = 0; i < baddies.size(); i++){
                baddies[i].render(screen);
            }
            player.render(screen);
            
        }
    }
    
    int run_game(){
        SDL_Init(SDL_INIT_EVERYTHING);
        TTF_Init();
        init_video();
        bool done = false;
        //TEMPORARY
       // selection = 6;
        
        while(!done){
            while(SDL_PollEvent(&event)){
                engine::keystroke(keys, event);
                if (mouse.mouseinput(event) == 1){
                    if (selection == 0){
                        switch (opening.select(mouse)){
                            case 1: begin_game(); selection = 3; break;
                            case 2: selection = 1; break;
                            case 3: done = true; break;
                            default: break;
                        }
                    }
                    else if (selection == 1){
                        switch (options.select(mouse)){
                            case 0: std::cout<<"This feature is incomplete\n"; break;
                            case 2: selection = 2; break;
                            case 3: selection = 0; break;
                            default: break;
                        }
                    }
                    else if (selection == 2){
                        switch (resolution.select(mouse)){
                            case 0: screen_tag = 0; break;
                            case 1: screen_tag = 1; break;
                            case 2: screen_tag = 2; break;
                            case 3: screen_tag = 3; break;
                            case 4: screen_tag = 4; break;
                            case 5: screen_tag = 5; break;
                            case 6: screen_tag = 6; break;
                            case 7: init_video(); break;
                            case 8: selection = 1; break;
                            default: break;
                        }
                    }
                    
                }
                if (event.type == SDL_QUIT){
                        done = true;
                    }
            }
            
            if (selection == 3){
                if (keys[SDLK_a] || keys[SDLK_LEFT]){
                    player.move_left();
                }
                else if (keys[SDLK_d] || keys[SDLK_RIGHT] || keys[SDLK_e]){
                    player.move_right(screen);
                }

                for (short i = 0; i < baddies.size(); i++){
                    if (baddies[i].placed){
                        baddies[i].fall();
                    }
                }
            }
            boxRGBA(screen, 0, 0, screen->w, screen->h, 0, 0, 0, 255);
            render();
            SDL_Flip(screen);
            SDL_Delay(10);
        }
    }
    
};

#endif	/* GAME_HPP */

