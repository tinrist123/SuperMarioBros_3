#pragma once
#include "GameObject.h"
#include "Mario.h"
//class CMario;

class CRedKoopa : public CGameObject
{
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

public:
	bool died;
	bool isSupine;
	bool isBeingHeld;
	
	CMario* player;
	
	CRedKoopa(CMario* mario);
	virtual void SetState(int state);
	void SetPositionAccordingToPlayer();
};