#pragma once
class Block;

class DirtyBlocks {
public:
	static void initBlocks();

	static void registerBlocks();
	static void registerBlock(Block*);
	
	static void getNewRandomID();
	
	static Block* testBlock;
};
