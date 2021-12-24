/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*
*	This product contains software technology licensed from Id
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/

#pragma once

#include "particleman.h"

class IParticleMan_Active : public IParticleMan
{
public:
	void SetUp(cl_enginefunc_t* pEnginefuncs) override;
	void Update(void) override;
	void SetVariables(float flGravity, Vector vViewAngles) override;
	void ResetParticles(void) override;
	void ApplyForce(Vector vOrigin, Vector vDirection, float flRadius, float flStrength, float flDuration) override;
	void AddCustomParticleClassSize(unsigned long lSize) override;

	CBaseParticle* CreateParticle(Vector org, Vector normal, model_s* sprite, float size, float brightness, const char* classname) override;

	char* RequestNewMemBlock(int iSize) override;

	void CoreInitializeSprite(CCoreTriangleEffect* pParticle, Vector org, Vector normal, model_s* sprite, float size, float brightness) override;
	void CoreThink(CCoreTriangleEffect* pParticle, float time) override;
	void CoreDraw(CCoreTriangleEffect* pParticle) override;
	void CoreAnimate(CCoreTriangleEffect* pParticle, float time) override;
	void CoreAnimateAndDie(CCoreTriangleEffect* pParticle, float time) override;
	void CoreExpand(CCoreTriangleEffect* pParticle, float time) override;
	void CoreContract(CCoreTriangleEffect* pParticle, float time) override;
	void CoreFade(CCoreTriangleEffect* pParticle, float time) override;
	void CoreSpin(CCoreTriangleEffect* pParticle, float time) override;
	void CoreCalculateVelocity(CCoreTriangleEffect* pParticle, float time) override;
	void CoreCheckCollision(CCoreTriangleEffect* pParticle, float time) override;
	void CoreTouch(CCoreTriangleEffect* pParticle, Vector pos, Vector normal, int index) override;
	void CoreDie(CCoreTriangleEffect* pParticle) override;
	void CoreForce(CCoreTriangleEffect* pParticle) override;
	bool CoreCheckVisibility(CCoreTriangleEffect* pParticle) override;
	void SetRender(int iRender) override;
};