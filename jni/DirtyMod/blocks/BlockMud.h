#pragma once
#include "mcpe/world/level/block/Block.h"

class BlockMud : public Block {
public:
	BlockMud(const std::string&, int);

	virtual bool use(Player&, const BlockPos&);
};
