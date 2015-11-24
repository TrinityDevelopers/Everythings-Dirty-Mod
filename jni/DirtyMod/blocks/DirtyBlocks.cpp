#include "DirtyBlocks.h"
#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/BlockItem.h"

#include "BlockTest.h"

Block* DirtyBlocks::testBlock;

void DirtyBlocks::initBlocks() {
	testBlock = new BlockTest("testBlock", getNewRandomID());

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
	while(Block::mOwnedBlocks[std::unique_ptr<Block>(Block::mBlocks[id])] != NULL) {
		if(id < 256)
			id++;
		else 
			return NULL;
	}	
	return id;
}
