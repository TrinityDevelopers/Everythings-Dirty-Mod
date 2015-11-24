#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <string>
#include <memory>

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/Item.h"

#include "DirtyMod/blocks/DirtyBlocks.h"
#include "DirtyMod/items/DirtyItems.h"
#include "DirtyMod/creative/DirtyCreativeManager.h"

#define LOG_TAG "dirtymod"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))


void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();

	DirtyBlocks::initBlocks();
}

void (*_Item$initItems)();
void Item$initItems() {
	_Item$initItems();

	DirtyItems::initItems();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();

	DirtyCreativeManager::registerCreativeItems();
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	
	return JNI_VERSION_1_2;
}
