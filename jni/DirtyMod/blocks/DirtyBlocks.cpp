#include "DirtyBlocks.h"

#include <algorithm>

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/BlockItem.h"

#include "BlockTest.h"

Block* DirtyBlocks::testBlock;

void DirtyBlocks::initBlocks() {
	testBlock = new BlockTest("testBlock", 210/*getNewRandomID()*/);

	registerBlocks();
}

void DirtyBlocks::registerBlocks() {
	registerBlock(testBlock);
}

void DirtyBlocks::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
	Item::mItems[block->blockId] = new BlockItem(block->getDescriptionId(), block->blockId - 0x100);
}

int DirtyBlocks::getNewRandomID() {
	int id = 0;
	while(std::find(Block::mOwnedBlocks.begin(), Block::mOwnedBlocks.end(), std::unique_ptr<Block>(Block::mBlocks[id])) == Block::mOwnedBlocks.end()) {
		if(id < 256)
			id++;
		else 
			return NULL;
	}	
	return id;
}
