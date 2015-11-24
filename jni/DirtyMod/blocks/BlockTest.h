#pragma once
#include "com/mojang/minecraftpe/world/level/block/Block.h"

class BlockTest : public Block {
public:
	BlockTest(const std::string&, int);

	virtual bool use(Player&, const BlockPos&);
};
