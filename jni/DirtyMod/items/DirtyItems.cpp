#include "GCItems.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

#include "ItemBasic.h"

Item* GCItems::basicItem;

std::map<std::string,int> GCItems::IDMap; 

void GCItems::initItems() {
	basicItem = new ItemBasic("basicItem", getNewRandomID(0));
	
	registerItems();
}

void GCItems::registerItems() {
	registerItem(basicItem);
}

void GCItems::registerItem(Item* item) {
	Item::mItems[item->itemId] = item;
}

int GCItems::getNewRandomID(int gcid) {
	if(IDList[gcid] != NULL) 
		return IDList[gcid];
	int id = 0;
	while(Item::mItems[id + 256] != NULL) {
		id++;
	}
	IDList[gcid] = id;
	return IDList[gcid];
}