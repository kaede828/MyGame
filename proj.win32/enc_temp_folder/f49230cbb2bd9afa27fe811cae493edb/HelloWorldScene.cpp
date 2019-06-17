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

	// テクスチャファイル名を指定して、スプライトを作成
	sprite = Sprite::create("Sample01.png");
	// シーングラフにつなぐ
	this->addChild(sprite);

	sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	sprite->setScale(4.0f);
	//画像の基準点（アンカーポイント）を設定
	/*sprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	sprite->setRotation(135.0f);*/

	sprite->setColor(Color3B(255, 0, 0));
	opacity = 255.0f;

	//for (int r = 0; r <= 255; r++)
	//{
	//	for (int b = 0; b <= 255; b++)
	//	{
	//		sprite->setColor(Color3B(0, 0, b));
	//		sprite->setColor(Color3B(r, 0, 0));
	//		//opacity -= 255.0f / 180.0f;
	//		///*if (opacity < 0.0f)
	//		//{
	//		//	opacity = 0.0f;
	//		//}*/
	//		//sprite->setOpacity(opacity);
	//	}
	//}

	//反転
	//sprite->setFlippedX(true);

	//切り取り
	/*for (int i = 0; i < 3; i++)
	{

	}*/
	sprite->setTextureRect(Rect(0, 0, 32, 32));

	//表示座標を指定
	//sprite->setPosition(Vec2(1280, 720));

	//回転角を指定
	//sprite->setRotation(45.0f);


	//拡縮を指定(横３倍,縦４倍)
	//sprite->setScale(0.5f, 0.5f);

	//左右反転
	//sprite->setFlippedX(true);
	//上下反転
	//sprite->setFlippedY(true);
	//非表示にする
	//sprite->setVisible(false);
	//色合いを設定
	//sprite->setColor(Color3B(0xff, 0x00, 0x00));
	//不透明度を設定
	sprite->setOpacity(255);

	//update関数を呼ぶ
	this->scheduleUpdate();

	//左移動
	state = 0;

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
	/*float rot = sprite->getRotation();
	rot += float(-10.0f);
	sprite->setRotation(rot);*/


	//ここに毎フレーム処理を書く
	Vec2 pos = sprite->getPosition();
	////座標を移動させる
	//pos += Vec2(-1.0f, 0.0f);

	//unsigned char opacity = sprite->getOpacity();

	////5秒間で255減らす
	////300frameで255減らす

	opacity -= 255.0f / 180.0f;
	if (opacity < 0.0f)
	{
		sprite->setColor(Color3B(0, 0, 255));
	}
	sprite->setOpacity(opacity);



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
