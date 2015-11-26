#include "ItemTest.h"

#include "DirtyItems.h"

ItemTest::ItemTest(std::string name) : Item(name, DirtyItems::getNewRandomID(name)) {
	setIcon("string", 0);
	creativeCategory = 2;
}