//
// Created by 张兴 on 2020-12-30.
//

#include "61_Knife.h"

Knife::Knife()
{
    this->m_BaseDamage = 10;
    this->m_WeaponName = "小刀";
}

int Knife::getBaseDamage()
{
    return this->m_BaseDamage;
}

int Knife::getSuckBlood()
{
    return 0;
}

bool Knife::getHold()
{
    return false;
}

bool Knife::getCrit()
{
    return false;
}