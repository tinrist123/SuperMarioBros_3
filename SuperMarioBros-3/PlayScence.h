#pragma once
#include "Game.h"
#include "Scence.h"
#include "GameObject.h"
#include "Portal.h"
#include "BrickContainsItem.h"
#include "BronzeBrick.h"
#include "Mario.h"
#include "Goomba.h"
#include "RedKoopa.h"
#include "TileMap.h"
#include "Floor.h"
#include "FirePiranha.h"
#include "GreenPiranha.h"
#include "Pipe.h"
#include "SuperLeaf.h"
#include "SuperMushroom.h"
#include "IceFlower.h"
#include "CoinEffect.h"
#include "P_Switch.h"


class CPlayScene: public CScene
{
protected: 
	CMario *player;					// A play scene has to have player, right? 
	TileMap* map;

	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> listBronzeBricks; // brick contains the item
	vector<LPGAMEOBJECT> listItems;
	vector<LPGAMEOBJECT> priorityListItems;

	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_ANIMATION_SETS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_TileMap(string line);

	
public: 
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	void DropItem(int itemType, float x, float y);

	CMario * GetPlayer() { return player; } 

	//friend class CPlayScenceKeyHandler;
};

class CPlayScenceKeyHandler : public CScenceKeyHandler
{
public:
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	CPlayScenceKeyHandler(CScene *s) :CScenceKeyHandler(s) {};
};

