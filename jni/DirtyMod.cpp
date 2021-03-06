#include "DirtyMod.h"

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/Item.h"

#include "DirtyMod/blocks/DirtyBlocks.h"
#include "DirtyMod/items/DirtyItems.h"
#include "DirtyMod/creative/DirtyCreativeManager.h"


void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();

	DirtyBlocks::initBlocks();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();

	DirtyItems::initItems();
	DirtyCreativeManager::registerCreativeItems();
}

Block* (*_Block$Block1)(Block*, const std::string&, int, const Material&);
Block* Block$Block1(Block* block, const std::string& name, int id, const Material& material) {
	Block::mBlocksHook[id] = block;
	
	return _Block$Block1(block, name, id, material);
}

Block* (*_Block$Block2)(Block*, const std::string&, int, TextureUVCoordinateSet, const Material&);
Block* Block$Block2(Block* block, const std::string& name, int id, TextureUVCoordinateSet tex, const Material& material) {
	Block::mBlocksHook[id] = block;
	
	return _Block$Block2(block, name, id, tex, material);
}

Block* (*_Block$Block3)(Block*, const std::string&, int, const std::string&, const Material&);
Block* Block$Block3(Block* block, const std::string& name, int id, const std::string& tex, const Material& material) {
	if(tex != "missing_tile")
		Block::mBlocksHook[id] = block;
	
	return _Block$Block3(block, name, id, tex, material);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* BlockConstructor1 = dlsym(RTLD_DEFAULT, "_ZN5BlockC2ERKSsiRK8Material");
	void* BlockConstructor2 = dlsym(RTLD_DEFAULT, "_ZN5BlockC2ERKSsi22TextureUVCoordinateSetRK8Material");
	void* BlockConstructor3 = dlsym(RTLD_DEFAULT, "_ZN5BlockC2ERKSsiS1_RK8Material");
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction(BlockConstructor1, (void*) &Block$Block1, (void**) &_Block$Block1);
	MSHookFunction(BlockConstructor2, (void*) &Block$Block2, (void**) &_Block$Block2);
	MSHookFunction(BlockConstructor3, (void*) &Block$Block3, (void**) &_Block$Block3);
	
	return JNI_VERSION_1_2;
}
