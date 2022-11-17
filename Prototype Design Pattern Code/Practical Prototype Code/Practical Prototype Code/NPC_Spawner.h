#pragma once
#include "ShapeNPC.h"

class NPC_Spawner
{
public:
    NPC_Spawner(ShapeNPC* prototype)
        : prototype_(prototype)
    {}

    ShapeNPC* spawnMonster()
    {
        return prototype_->Clone();
    }

private:
    ShapeNPC* prototype_;
};