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

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	for(int i=0;i<5;i++)
	{
		sprite[i] = Sprite::create("Sample01.png");
		this->addChild(sprite[i]);
		sprite[i]->setPosition(Vec2(200 * i, visibleSize.height / 2.0f));
		sprite[i]->setScale(4.0f);

		MoveBy*action1 = MoveBy::create(1.0f, Vec2(400, 200));
		sprite[i]->runAction(action1);

		sprite[i]->setTextureRect(Rect(0, 0, 32, 32));
	}

	//// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("HelloWorld.png");
	//if (sprite == nullptr)
	//{
	//    problemLoading("'HelloWorld.png'");
	//}
	//else
	//{
	//    // position the sprite on the center of the screen
	//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//    // add the sprite as a child to this layer
	//    this->addChild(sprite, 0);
	//}

	//// テクスチャファイル名を指定して、スプライトを作成
	//sprite = Sprite::create("Sample01.png");
	//// シーングラフにつなぐ
	//this->addChild(sprite);
	//sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	//sprite->setScale(4.0f);


	//// テクスチャファイル名を指定して、スプライトを作成
	//sprite2 = Sprite::create("Sample09.png");
	//// シーングラフにつなぐ
	//this->addChild(sprite2);
	//sprite2->setPosition(Vec2(900, visibleSize.height / 2.0f));
	//sprite2->setScale(4.0f);

	//// action1の生成
	//MoveBy* action1 = MoveBy::create(1.0f, Vec2(400, 200));
	//sprite->runAction(action1);
	//sprite2->runAction(action1->clone());
	//action2の生成
	/*MoveBy* action2 = MoveBy::create(1.0f, Vec2(200, 100));
	sprite2->runAction(action2);*/



	/*sprite->setTextureRect(Rect(0, 0, 32, 32));
	sprite2->setTextureRect(Rect(0, 0, 32, 32));*/

	//不透明度を設定
	//sprite->setOpacity(255);

	//update関数を呼ぶ


	//左移動
	//state = 0;

	//スプライト(ノードの一種)の作成
	//sprite = Sprite::create("HellowWorld.png");
	//this->addChild(sprite);

	//アクションの作成(1秒かけて　右に200,上に100動く)

	//ScaleBy* action1 = ScaleBy::create(1.0f,5.0f);
	//JumpTo* action1 = JumpTo::create(1.0f, Vec2(200, 100),500.0f,2.0f);
	//ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(800, 700);
	//conf.controlPoint_2 = Vec2(1000, 700);
	//conf.endPosition = Vec2(1000, 360);
	//BezierTo* action1 = BezierTo::create(2.0f,conf);
	/*sprite->setOpacity(0);

	//FadeIn* action1 = FadeIn::create(1.0f);*/
	//アクションに対して、イージングをつけたアクションを生成する
	//EaseInOut*action2 = EaseInOut::create(action1, 2.0f);
	//イージング付きアクションの実行


	this->scheduleUpdate();
	return true;
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
