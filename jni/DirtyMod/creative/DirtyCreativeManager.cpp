#include "GCCreativeManager.h"
#include "../blocks/DirtyBlocks.h"

void GCCreativeManager::registerCreativeItems() {
	Item::addCreativeItem(DirtyBlocks::testBlock, 0);
}
