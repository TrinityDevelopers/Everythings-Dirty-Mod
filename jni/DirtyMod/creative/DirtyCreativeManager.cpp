#include "DirtyCreativeManager.h"
#include "mcpe/world/item/Item.h"
#include "../blocks/DirtyBlocks.h"
#include "../items/DirtyItems.h"

void DirtyCreativeManager::registerCreativeItems() {
	Item::addCreativeItem(DirtyBlocks::mudBlock, 0);
	Item::addCreativeItem(DirtyItems::testItem, 0);
}
