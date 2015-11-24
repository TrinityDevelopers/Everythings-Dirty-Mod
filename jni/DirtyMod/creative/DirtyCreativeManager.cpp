#include "DirtyCreativeManager.h"
#include "mcpe/world/item/Item.h"
#include "../blocks/DirtyBlocks.h"

void DirtyCreativeManager::registerCreativeItems() {
	Item::addCreativeItem(DirtyBlocks::testBlock, 0);
}
