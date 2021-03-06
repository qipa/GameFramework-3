///////////////////////////////////////////////////////////////////////////////
// SgAnimatorWin32.h

#pragma once

// Includes
#include "BtTypes.h"
#include "SgAnimator.h"
#include "BaFileData.h"

const BtU32 MaxAnimationNodes = 1024;

class BaArchiveManager;
class SgBone;
class SgSkin;

// Class declaration
class SgAnimatorWinGL : public SgAnimator
{
public:

	SgAnimatorWinGL();

	SgAnimator					   *pDuplicate();

	void							FixPointers( BtU8* pFileData, BaArchive* pArchive );
	void							CreateOnDevice();
	void							Reset();
	void							Update( SgSkin* pSkin );
	void							Pause( BtBool bPause );
	void							Remove();

	// Accessors
	void							SetTime( BtFloat animTime );
	BtFloat							GetTime();
	void							SetFrame( BtU32 frameTime );

	BtBool							IsEnded() const;
	BtBool							IsPaused() const;

	BtFloat							GetDuration();
	BtU32							GetNumFrames();

private:

	friend class BaArchiveManager;

	BaSgAnimationFileData*			m_pFileData;
	BaSgAnimationTransformFileData*	m_pTransforms;
	BaSgAnimationTimeFileData*		m_pTimes;
	BtFloat							m_time;
	BtBool							m_bSetup;
	BtBool							m_bEnded;
	BtBool							m_bPaused;
	BtBool							m_isDuplicate;
};
