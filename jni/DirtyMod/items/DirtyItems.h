#pragma once
#include <map>
#include <string>
class Item;

class DirtyItems {
public:
	static Item* testItem;
	static Item* testArmor;
	
	static std::map<std::string,int> IDMap; // needed to store all item ID's due to multiple initItem calls

	static void initItems();
	static void registerItem(Item*);
	static int getNewRandomID(std::string);
};
