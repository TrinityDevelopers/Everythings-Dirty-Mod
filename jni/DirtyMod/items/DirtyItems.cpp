#include "DirtyItems.h"

#include "mcpe/world/item/Item.h"

#include "ItemTest.h"

#include <DirtyMod.h>

Item* DirtyItems::testItem;

std::map<std::string,int> DirtyItems::IDMap; 

void DirtyItems::initItems() {
	testItem = new ItemTest("testItem");
	
	registerItems();
}

void DirtyItems::registerItems() {
	registerItem(testItem);
}

void DirtyItems::registerItem(Item* item) {
	Item::mItems[item->itemId] = item;
	ItemMap[item->name] = item;
}

int DirtyItems::getNewRandomID(std::string name) {
	if(IDMap[name] != NULL) 
		return IDMap[name];
	int id = 0;
	while(Item::mItems[id + 256] != NULL) {
		id++;
	}
	IDMap[name] = id;
	return IDMap[name];
}