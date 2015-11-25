#include "DirtyBlocks.h"

#include <algorithm>

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/BlockItem.h"

#include "BlockMud.h"

Block* DirtyBlocks::mudBlock;

void DirtyBlocks::initBlocks() {
	mudBlock = new BlockMud("mudBlock", getNewRandomID());

	registerBlocks();
}

void DirtyBlocks::registerBlocks() {
	registerBlock(mudBlock);
}

void DirtyBlocks::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
	Item::mItems[block->blockId] = new BlockItem(block->getDescriptionId(), block->blockId - 0x100);
}

int DirtyBlocks::getNewRandomID() {
	int id = 0;
	while(Block::mBlocksHook[id] != NULL) {
		if(id < 256)
			id++;
		else 
			return NULL;
	}	
	return id;
}
