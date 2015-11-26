#include "DirtyItems.h"

#include "mcpe/world/item/Item.h"

#include "ItemTest.h"
#include "ItemArmorTest.h"

#include <DirtyMod.h>

Item* DirtyItems::testItem;
Item* DirtyItems::testArmor;

std::map<std::string,int> DirtyItems::IDMap; 

void DirtyItems::initItems() {
	testItem = new ItemTest("testItem");
	registerItem(testItem);
	testArmor = new ItemArmorTest("testArmor");
	registerItem(testArmor);
	
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