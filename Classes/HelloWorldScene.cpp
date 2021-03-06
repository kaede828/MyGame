/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	///////////////////////////////
	//// 3. add your codes below...

	//// add a label shows "Hello World"
	//// create and initialize a label

	//auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	//if (label == nullptr)
	//{
	//	problemLoading("'fonts/Marker Felt.ttf'");
	//}
	//else
	//{
	//	// position the label on the center of the screen
	//	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
	//		origin.y + visibleSize.height - label->getContentSize().height));

	//	// add the label as a child to this layer
	//	this->addChild(label, 1);
	//}
	DelayTime*delay = DelayTime::create(1.0f);
	DelayTime*delay2 = DelayTime::create(2.0f);

	//関数呼び出しアクションの作成
	//CC_CALLBACK_0 第一引数:呼び出したいメンバ関数
	//CC_CALLBACK_0 台に引数:メンバ関数を呼び出すオブジェクト
	//CallFunc* action = CallFunc::create(CC_CALLBACK_0(HelloWorld::myFunction, this));
	CallFunc* callFunc = CallFunc::create(CC_CALLBACK_0(HelloWorld::myFunction, this,));
	CallFunc* callFunc2 = CallFunc::create(CC_CALLBACK_0(HelloWorld::myFunction2, this, "sample01.png"));
	Sequence* seq = Sequence::create(delay, callFunc,delay2,callFunc2, nullptr);

	//アクションを実行
	this->runAction(seq);

	this->scheduleUpdate();
	return true;
}

void HelloWorld::myFunction()
{
	//任意の処理
	Sprite* spr = Sprite::create("HelloWorld.png");
	this->addChild(spr);
	spr->setPosition(Vec2(500, 500));
}

void HelloWorld::myFunction2(std::string filename)
{
	//任意の処理
	Sprite* spr = Sprite::create("Sample01.png");
	this->addChild(spr);
	spr->setPosition(Vec2(900, 500));
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{







	//switch (state)
	//{
	//case 0:
	//	 pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0);
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)
	//	{
	//		state = 1;//下移動に切替
	//	}
	//	break;

	//case 1:
	//	pos = sprite->getPosition();
	//	pos += Vec2(0.0f, -5.0);
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100)
	//	{
	//		state = 1;//下移動に切替
	//	}
	//	break;

	//case 2:
	//	pos = sprite->getPosition();
	//	pos += Vec2(-1.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	if (pos.y <= -100)
	//	{
	//		state = 2;//下移動に切替
	//	}
	//	break;

	//case 3:
	//	pos += Vec2(0.0f, 1.0f);
	//	break;

	//}


	////移動後の座標を反映
	//sprite->setPosition(pos);
} 
