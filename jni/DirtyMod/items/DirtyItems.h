#pragma once
#include <map>
#include <string>
class Item;

class GCItems {
public:
	static Item* basicItem;
	
	static std::map<std::string,int> IDMap; // needed to store all item ID's due to multiple initItem calls

	static void initItems();
	
	static void registerItems();
	static void registerItem(Item*);
	
	static int getNewRandomID();
};
