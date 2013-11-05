/* 
 * File:   foes.hpp
 * Author: garys
 *
 * Created on October 24, 2013, 10:07 PM
 */

#ifndef FOES_HPP
#define	FOES_HPP

#include "gameengine.h"
#include "bullets.hpp"

class foe{
    short speed;
    bool dead;
    bool visible;
    bool landed;
public:
    short x, y, w, h;
    bool placed;
    
    foe(){
        dead = false;
        placed = false;
        visible = false;
        landed = false;
        speed = 1;
        x = -60;
        y = -60;
        w = 50;
        h = 50;
    }
    
    void place(short a, short b){
        x = a;
        y = b;
        placed = true;
        dead = false;
    }
    
    short get_x(){
        return x;
    }
    short get_w(){
        return w;
    }
    
    short get_h(){
        return y + h;
    }
    
    void set_speed(short a){
        speed = a;
    }
    
    bool die(bullet a){
        if (a.x > x && a.x < x + w && a.y > y && a.y < y + h && placed){
            //std::cout<<"I have died\n";
            dead = true;
            placed = false;
            return true;
        }else return false;
    }
    
    void kill(){
        dead = true;
        placed = false;
    }
    
    void fall(){
       if (placed && !landed){
            y = y + speed;
       }
    }
    
    void render(SDL_Surface* screen){
        if (y + h >= screen->h){
            landed = true;
        }
        if (placed){
            boxRGBA(screen, x, y, x+w, y+h, 128, 64, 0, 255);
        }
    }
};

#endif	/* FOES_HPP */

