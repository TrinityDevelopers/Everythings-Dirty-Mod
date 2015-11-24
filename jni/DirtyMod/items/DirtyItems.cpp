#include "DirtyItems.h"

#include "mcpe/world/item/Item.h"

#include "ItemTest.h"

#include <DirtyMod.h>

Item* DirtyItems::testItem;

std::map<std::string,int> DirtyItems::IDMap; 

void DirtyItems::initItems() {
	//testItem = new ItemTest("testItem", getNewRandomID("testItem"));
	
	//registerItems();
}

void DirtyItems::registerItems() {
	registerItem(testItem, "testItem");
}

void DirtyItems::registerItem(Item* item, std::string name) {
	Item::mItems[item->itemId] = item;
	ItemMap[name] = item;
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