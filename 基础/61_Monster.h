//
// Created by 张兴 on 2020-12-30.
//
#pragma once
#include <iostream>
#include <string>
#include "61_Weapon.h"
#include "61_Hero.h"

using namespace std;

class Hero;

class Monster
{
public:
    Monster();
    string m_Name;
    int m_Hp;
    int m_Atk;
    int m_Def;
    bool m_Hold;
    void Attack(Hero * hero);
};