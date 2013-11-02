/* 
 * File:   foes.hpp
 * Author: garys
 *
 * Created on October 24, 2013, 10:07 PM
 */

#ifndef FOES_HPP
#define	FOES_HPP

#include "gameengine.h"

class foe{
    short x, y, w, h;
    short speed;
    bool dead;
    bool visible;
public:
    bool placed;
    
    foe(){
        dead = false;
        placed = false;
        visible = false;
        speed = 3;
        w = 50;
        h = 50;
    }
    
    void place(short a, short b){
        x = a;
        y = b;
        placed = true;
    }
    
    short get_x(){
        return x;
    }
    short get_w(){
        return w;
    }
    
    void set_speed(short a){
        speed = a;
    }
    
    void kill(){
        dead = true;
        placed = false;
    }
    
    void fall(){
        if (placed){
            y = y + speed;
            h = h + speed;
        }
    }
    
    void render(SDL_Surface* screen){
        if (visible){
            boxRGBA(screen, x, y, w, h, 128, 64, 0, 255);
        }
    }
};

#endif	/* FOES_HPP */

