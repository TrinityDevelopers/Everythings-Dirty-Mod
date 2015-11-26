#include "ItemArmorTest.h"

#include "DirtyItems.h"

ItemArmorTest::ItemArmorTest(std::string name) : ArmorItem(name, DirtyItems::getNewRandomID(name), ArmorItem::DIAMOND, 0, ArmorSlot::LEGGINGS) {
	setIcon("stick", 0);
	creativeCategory = 2;
}