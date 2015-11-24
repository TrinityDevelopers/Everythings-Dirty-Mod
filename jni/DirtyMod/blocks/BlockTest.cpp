#include "BlockBasic.h"
#include "mcpe/world/entity/player/Player.h"
#include "../includes/leveledit.h"

BlockTest::BlockTest(const std::string& name, int blockId) :
	Block(name, blockId, "stone", Material::getMaterial(MaterialType::STONE)) {
	setDestroyTime(1.0F);
	setExplodeable(15.0F);
	setSoundType(SOUND_STONE);
	creativeCategory = 1;
}

bool BlockTest::use(Player& player, const BlockPos& pos) {
	Vec3& playerPos = player.getPos();
	player.setPos({playerPos.x, playerPos.y + 2.0F, playerPos.z});
}

