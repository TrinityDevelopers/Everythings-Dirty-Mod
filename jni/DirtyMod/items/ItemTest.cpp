#include "ItemTest.h"

#include "DirtyItems.h"

ItemTest::ItemTest(std::string name) : Item(name, 190 /*DirtyItems::getNewRandomID(name)*/) {
	setIcon("string", 0);
	creativeCategory = 2;
}