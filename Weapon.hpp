/* 
 * File:   Weapon.hpp
 * Author: garys
 *
 * Created on October 25, 2013, 8:09 AM
 */

#ifndef WEAPON_HPP
#define	WEAPON_HPP

#include "bullets.hpp"
#include "guntypes.hpp"
#include "gameengine.h"

class weapon{
    short cooldown;
    short damage;
    short version;
public:
    boost::ptr_vector<bullet> ammo;
    
    weapon(){
        ammo.resize(1);
        cooldown = 5;
        damage = 10;
    }
   
    void set_target(engine::pointer z){
        //cooltime();
        if (cooldown < 1){
            for(short i = 0; i < ammo.size(); i++){
                if (!ammo[i].fired){
                    ammo[i].fired = true;
                    break;
                }
            }
        }
    }
    
    void set_type(Uint32 type){
        switch (type){
            case man_Pistol: cooldown = 100; damage = 10; ammo.resize(10); break;
            case semi_Pistol: cooldown = 50; damage = 8; ammo.resize(30); break;
            case man_Rifle: cooldown = 150; damage = 20; ammo.resize(8); break;
            case semi_Rifle: cooldown = 75; damage = 18; ammo.resize(30); break;
            case auto_Rifle: cooldown = 20; damage = 15; ammo.resize(50); break;
            default: break;
        }
        version = type;
    }
    
    void reset_cooldown(){
        switch (version){
            case man_Pistol: cooldown = 100; break;
            case semi_Pistol: cooldown = 50; break;
            case man_Rifle: cooldown = 150; break;
            case semi_Rifle: cooldown = 75; break;
            case auto_Rifle: cooldown = 20; break;
            default: break;
        }
    }
    
    short cooltime(){
        cooldown = cooldown-2;
        return cooldown;
    }
    
    void show_cooldown(SDL_Surface* screen){
        boxRGBA(screen, screen->w -cooldown, screen->h - 30, screen->w, screen->h, 0, 128, 0, 255);
    }
    
};

#endif	/* WEAPON_HPP */

