#pragma once

#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <string>
#include <map>
#include <memory>

#define LOG_TAG "dirtymod"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

class Item;
class Block;

static std::map<std::string, Item*> ItemMap;
static std::map<std::string, Block*> BlockMap;

void (*_Block$initBlocks)();
void (*_Item$initItems)();
void (*_Item$initCreativeItems)();
