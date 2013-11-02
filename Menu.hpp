/* 
 * File:   Menu.hpp
 * Author: garys
 *
 * Created on October 26, 2013, 2:31 PM
 */

#ifndef MENU_HPP
#define	MENU_HPP

#include "button.hpp"
#include "gameengine.h"

class Main{
    clicker button[4];
    
public:
    Main(){
        button[0].label_button("Start Game", 20, 255, 255, 0);
        button[1].label_button("Load Game", 20, 255, 255, 0);
        button[2].label_button("Options", 20, 255, 255, 0);
        button[3].label_button("Quit", 20, 255, 255, 0);
        button[0].place_button(250, 220);
        button[1].place_button(250, 295);
        button[2].place_button(250, 370);
        button[3].place_button(250, 445);
        for (short i = 0; i < 4; i++){
            button[i].size_button(250, 50);
        }
        button[0].place_label(252, 222);
        button[1].place_label(252, 322);
        button[2].place_label(252, 422);
        button[3].place_label(252, 520);
    }
    
    short select(engine::pointer z){
        for(short i = 0; i < 4; i++){
            if (button[i].select_button(z) == true){
                return i;
                break;
            }
        }
    }
    
    void render(SDL_Surface* screen){
        for(short i = 0; i < 4; i++){
            button[i].draw_button(screen, 128, 64, 0);
        }
    }
    
};

/*class levels{
    clicker button[3];
    
    levels(){
        button[0].label_button("Easy", 20, 255, 255, 0);
        button[1].label_button("Medium", 20, 255, 255, 0);
        button[2].label_button("Hard", 20, 255, 255, 0);
        button[0].place_button(375, 360);
        button[1].place_button(375, 420);
        button[2].place_button(375, 480);
        
        for (short i = 0; i < 4; i++){
            button[i].size_button(50, 30);
        }
        
        button[0].place_label(380, 362);
        button[1].place_label(380, 422);
        button[2].place_label(380, 482);
    }
    
    short select(engine::pointer z){
        for(short i = 0; i < 3; i++){
            if (button[i].select_button(z) == true){
                return i;
                break;
            }
        }
    }
    
    void render(SDL_Surface* screen){
        for(short i = 0; i < 3; i++){
            button[i].draw_button(screen, 128, 64, 0);
        }
    }
};*/

/*class saves{
    int screenh, screenw;
    boost::ptr_vector< clicker > button;
    std::vector<std::string> name;
    SDL_Color wordcolor;
public:

    saves(){
        std::ifstream settings("config");
        if (settings != NULL){
            settings >> screenw;
            settings >> screenh;
        }
        button.resize(1);
	button[0].place_button(80, 470);
	button[0].size_button(400, 40);
	button[0].label_button("Back", 20, 0, 255, 255);
	button[0].place_label(85, 495);
	SDL_EnableUNICODE( SDL_ENABLE );
        wordcolor.r = 255;
        wordcolor.g = 255;
        wordcolor.b = 0;
        }
    
    int Select_slot(engine::pointer z){
        DIR *saves = opendir("./saves");
	std::string filename;
	int savenum = 0;
	if(saves){ 
	    struct dirent *ent; 
	    while((ent = readdir(saves)) != NULL){ 
		filename = ent->d_name;
                 if (button[0].select_button(z) == true){
                     return 8;
                     }
		if (filename.length() > 2){
		    savenum++;
		    button.resize(savenum);
		    name.resize(savenum);
		    if (button.size() > 1){
			button[savenum - 1].place_button(button[savenum-2].x, button[savenum-2].y + 40);
			button[savenum - 1].size_button(180, 30);
			button[savenum - 1].label_button(filename, 20, 255, 255, 255);
			button[savenum - 1].place_label(button[savenum -1].x + 5, button[savenum -1].y + 5);
			name[savenum-1] = filename;
		    }
		}
	    }   
	}
	else {std::cout << "Error opening directory\n"; }
    }
    
    void save_game(){
	
    }
    
    std::string select_project(engine::pointer z){
	for(int i = 0; i < button.size(); i++){
	    if (button[i].select_button(z) == true){
		return name[i];
	    }
	}
    }
    
    void Draw_saves(SDL_Surface* a){
	boxRGBA(a, 65, 115, 515, 535, 0, 0, 0, 255);
        for (int i = 0; i < button.size(); i++){
            button[i].draw_button(a, 128, 64, 24);
        }
    }
    
};*/

class settings{
    clicker button[2];
public:
    settings(){
        button[0].label_button("Audio", 25, 255, 255, 0);
        button[1].label_button("Video", 20, 255, 255, 0);
        button[0].place_button(375, 360);
        button[1].place_button(375, 420);
        for (short i = 0; i < 2; i++){
            button[i].size_button(50, 30);
        }
        button[0].place_label(380, 362);
        button[1].place_label(380, 422);
    }
    
    short select(engine::pointer z){
        if (button[0].select_button(z) == true){
            std::cout<<"Needs finishing up first\n";
        }
        else if (button[1].select_button(z)== true){
            return 2;
        }
        else return 0;
    }
    
    void render(SDL_Surface* screen){
        for(short i = 0; i < 2; i++){
            button[i].draw_button(screen, 128, 64, 0);
        }
    }
};

class visual{
    clicker button[8];
public:
    visual(){
        button[0].label_button("800 x 600", 20, 255, 255, 0);
        button[1].label_button("1024 x 768", 20, 255, 255, 0);
        button[2].label_button("1280 x 960", 20, 255, 255, 0);
        button[3].label_button("1280 x 1024", 20, 255, 255, 0);
        button[4].label_button("1440 x 960", 20, 255, 255, 0);
        button[5].label_button("1680 x 1050", 20, 255, 255, 0);
        button[6].label_button("2048 x 1152", 20, 255, 255, 0);
        button[7].label_button("Back", 20, 255, 255, 0);
        
        button[0].place_button(250, 350);
        button[1].place_button(250, 410);
        button[2].place_button(250, 470);
        button[3].place_button(250, 530);
        button[4].place_button(400, 350);
        button[5].place_button(400, 410);
        button[6].place_button(400, 470);
        button[7].place_button(325, 530);
        
        for(short i = 0; i < 8; i++){
            button[i].size_button(50, 30);
        }
        button[0].place_label(252, 355);
        button[1].place_label(252, 415);
        button[2].place_label(252, 475);
        button[3].place_label(252, 535);
        button[4].place_label(402, 355);
        button[5].place_label(402, 415);
        button[6].place_label(402, 475);
        button[7].place_label(330, 535);
    }
    
    short select(engine::pointer z){
        for(short i = 0; i < 8; i++){
            if (button[i].select_button(z) == true){
                return i;
                break;
            }
        }
    }
    
    void render(SDL_Surface* screen){
        for (short i = 0; i < 8; i++){
            button[i].draw_button(screen, 128, 64, 0);
        }
    }
};
#endif	/* MENU_HPP */
